# from pacai.util import reflection
import random
from pacai.agents.capture.capture import CaptureAgent
from pacai.agents.capture.reflex import ReflexCaptureAgent
from pacai.core.directions import Directions
from pacai.util import util

class DummyAgent(CaptureAgent):
    """
    A Dummy agent to serve as an example of the necessary agent structure.
    You should look at `pacai.core.baselineTeam` for more details about how to create an agent.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    def registerInitialState(self, gameState):
        """
        This method handles the initial setup of the agent and populates useful fields,
        such as the team the agent is on and the `pacai.core.distanceCalculator.Distancer`.

        IMPORTANT: If this method runs for more than 15 seconds, your agent will time out.
        """

        super().registerInitialState(gameState)

        # Your initialization code goes here, if you need any.

    def chooseAction(self, gameState):
        """
        Randomly pick an action.
        """

        actions = gameState.getLegalActions(self.index)
        return random.choice(actions)
    
class OffensiveAgent(CaptureAgent):
    def __init__(self, index, **kwargs):
        super().__init__(index)

    def chooseAction(self, gameState):
        actions = gameState.getLegalActions(self.index)

        # Filter out actions that stop or reverse to avoid getting stuck.
        # actions = [a for a in actions if a != Directions.STOP and a != Directions.REVERSE[gameState.getAgentState(self.index).getDirection()]]

        values = [self.evaluate(gameState, a) for a in actions]

        if not actions:
            return Directions.STOP

        # Choose the action that maximizes the successor score.
        # bestAction = max(actions, key=lambda a: self.getFeatures(gameState, a).get('successorScore', float('-inf')))
        # return bestAction
        maxValue = max(values)
        bestActions = [a for a, v in zip(actions, values) if v == maxValue]

        return random.choice(bestActions)
    
    def evaluate(self, gameState, action):
        """
        Computes a linear combination of features and feature weights.
        """

        features = self.getFeatures(gameState, action)
        weights = self.getWeights(gameState, action)
        stateEval = sum(features[feature] * weights[feature] for feature in features)

        return stateEval

    def getFeatures(self, gameState, action):
        features = {}
        successor = self.getSuccessor(gameState, action)
        features['successorScore'] = self.getScore(successor)

        # Compute distance to the nearest food.
        foodList = self.getFood(successor).asList()

        # This should always be True, but better safe than sorry.
        if (len(foodList) > 0):
            myPos = successor.getAgentState(self.index).getPosition()
            minDistance = min([self.getMazeDistance(myPos, food) for food in foodList])
            features['distanceToFood'] = minDistance

        return features
    
    def getSuccessor(self, gameState, action):
        """
        Finds the next successor which is a grid position (location tuple).
        """

        successor = gameState.generateSuccessor(self.index, action)
        pos = successor.getAgentState(self.index).getPosition()

        if (pos != util.nearestPoint(pos)):
            # Only half a grid position was covered.
            return successor.generateSuccessor(self.index, action)
        else:
            return successor

    def getWeights(self, gameState, action):
        return {
            'successorScore': 100,
            'distanceToFood': -1
        }

# class ReflexiveOffensiveAgent(CaptureAgent):
#     def chooseAction(self, gameState):
#         myState = gameState.getAgentState(self.index)
#         myPos = myState.getPosition()
#         enemies = [gameState.getAgentState(i) for i in self.getOpponents(gameState)]

#         # If the agent is on its side and not carrying any food, move towards the closest food.
#         if myPos in self.getFood(gameState).asList() and gameState.data.agentStates[self.index].numCarrying == 0:
#             return "Stop"  # Stay in place to wait for food to appear.

#         foodDistances = [self.getMazeDistance(myPos, food) for food in self.getFood(gameState).asList()]
#         minFoodDistance = min(foodDistances)

#         # If the agent is carrying food, move towards the nearest border.
#         if gameState.data.agentStates[self.index].numCarrying > 0:
#             borderDistances = [self.getMazeDistance(myPos, border) for border in self.getBorder(gameState)]
#             return self.getDirectionToClosestLocation(myPos, borderDistances)

#         # If the agent is on the opponent's side, move towards the closest food to steal.
#         if not self.isHome(gameState, myPos):
#             return self.getDirectionToClosestLocation(myPos, foodDistances)

#         # If the agent is on its side and enemies are nearby, try to avoid them.
#         if any(enemy.getPosition() is not None and self.isHome(gameState, enemy.getPosition()) for enemy in enemies):
#             return self.evadeEnemies(gameState, myPos, enemies)

#         return "Stop"  # Default action if no specific condition is met.

#     def getBorder(self, gameState):
#         """
#         Returns the border between the red and blue sides of the map.
#         """
#         width = gameState.data.layout.width
#         if self.red:
#             return [(width // 2 - 1, i) for i in range(gameState.data.layout.height)]
#         else:
#             return [(width // 2, i) for i in range(gameState.data.layout.height)]

#     def isHome(self, gameState, pos):
#         """
#         Returns True if the given position is on the agent's side (home side).
#         """
#         return (self.red and pos[0] < gameState.data.layout.width // 2) or \
#                (not self.red and pos[0] >= gameState.data.layout.width // 2)

#     def evadeEnemies(self, gameState, myPos, enemies):
#         """
#         Choose an action to evade enemies if they are nearby.
#         """
#         escapeDirections = [direction for direction in gameState.getLegalActions(self.index)
#                             if gameState.generateSuccessor(self.index, direction).getAgentState(self.index).getPosition() != myPos]

#         return random.choice(escapeDirections)

#     def getDirectionToClosestLocation(self, myPos, distances):
#         """
#         Returns the direction to the location with the minimum distance.
#         """
#         minDistance = min(distances)
#         closestLocations = [loc for loc, dist in zip(self.getFood(gameState).asList(), distances) if dist == minDistance]
#         return self.getDirectionToTarget(myPos, closestLocations[0])

#     def getDirectionToTarget(self, source, target):
#         """
#         Returns the direction to the target from the source.
#         """
#         dx = target[0] - source[0]
#         dy = target[1] - source[1]

#         if dx > 0:
#             return "East"
#         elif dx < 0:
#             return "West"
#         elif dy > 0:
#             return "North"
#         elif dy < 0:
#             return "South"
#         else:
#             return "Stop"  # Stay in place if already at the target.

    
class DefensiveAgent(CaptureAgent):
    def __init__(self, index, **kwargs):
        super().__init__(index)
    
    def chooseAction(self, gameState):
        actions = gameState.getLegalActions(self.index)

        # Filter out actions that stop or reverse to avoid getting stuck.
        # actions = [a for a in actions if a != Directions.STOP and a != Directions.REVERSE[gameState.getAgentState(self.index).getDirection()]]

        if not actions:
            return Directions.STOP
        
        values = [self.evaluate(gameState, a) for a in actions]

        # Choose the action that maximizes the invader reachability.
        # bestAction = min(actions, key=lambda a: self.getFeatures(gameState, a).get('invaderDistance', float('inf')))
        minValue = max(values)
        bestActions = [a for a, v in zip(actions, values) if v == minValue]

        return random.choice(bestActions)
        # return bestAction
    
    def evaluate(self, gameState, action):
        features = self.getFeatures(gameState, action)
        weights = self.getWeights(gameState, action)
        stateEval = sum(features[feature] * weights[feature] for feature in features)

        return stateEval

    def getFeatures(self, gameState, action):
        features = {}

        successor = self.getSuccessor(gameState, action)
        myState = successor.getAgentState(self.index)
        myPos = myState.getPosition()

        # Computes whether we're on defense (1) or offense (0).
        features['onDefense'] = 1
        if (myState.isPacman()):
            features['onDefense'] = 0

        # Computes distance to invaders we can see.
        enemies = [successor.getAgentState(i) for i in self.getOpponents(successor)]
        invaders = [a for a in enemies if a.isPacman() and a.getPosition() is not None]
        features['numInvaders'] = len(invaders)

        if (len(invaders) > 0):
            dists = [self.getMazeDistance(myPos, a.getPosition()) for a in invaders]
            features['invaderDistance'] = min(dists)

        if (action == Directions.STOP):
            features['stop'] = 1

        rev = Directions.REVERSE[gameState.getAgentState(self.index).getDirection()]
        if (action == rev):
            features['reverse'] = 1

        return features
    
    def getSuccessor(self, gameState, action):
        """
        Finds the next successor which is a grid position (location tuple).
        """

        successor = gameState.generateSuccessor(self.index, action)
        pos = successor.getAgentState(self.index).getPosition()

        if (pos != util.nearestPoint(pos)):
            # Only half a grid position was covered.
            return successor.generateSuccessor(self.index, action)
        else:
            return successor

    def getWeights(self, gameState, action):
        return {
            'numInvaders': -1000,
            'onDefense': 100,
            'invaderDistance': -10,
            'stop': -100,
            'reverse': -2
        }

# class ReflexiveDefensiveAgent(CaptureAgent):
#     def chooseAction(self, gameState):
#         myState = gameState.getAgentState(self.index)
#         myPos = myState.getPosition()
#         invaders = [gameState.getAgentState(i) for i in self.getOpponents(gameState) if gameState.getAgentState(i).isPacman]

#         # If there are invaders on my side, move towards the closest invader.
#         if any(self.isHome(gameState, invader.getPosition()) for invader in invaders):
#             invaderDistances = [self.getMazeDistance(myPos, invader.getPosition()) for invader in invaders]
#             return self.getDirectionToClosestLocation(myPos, invaderDistances)

#         # If there are no invaders, move towards the border.
#         borderDistances = [self.getMazeDistance(myPos, border) for border in self.getBorder(gameState)]
#         return self.getDirectionToClosestLocation(myPos, borderDistances)

#     def getBorder(self, gameState):
#         """
#         Returns the border between the red and blue sides of the map.
#         """
#         width = gameState.data.layout.width
#         if self.red:
#             return [(width // 2 - 1, i) for i in range(gameState.data.layout.height)]
#         else:
#             return [(width // 2, i) for i in range(gameState.data.layout.height)]

#     def isHome(self, gameState, pos):
#         """
#         Returns True if the given position is on the agent's side (home side).
#         """
#         return (self.red and pos[0] < gameState.data.layout.width // 2) or \
#                (not self.red and pos[0] >= gameState.data.layout.width // 2)

#     def getDirectionToClosestLocation(self, myPos, distances):
#         """
#         Returns the direction to the location with the minimum distance.
#         """
#         minDistance = min(distances)
#         closestLocations = [loc for loc, dist in zip(self.getBorder(gameState), distances) if dist == minDistance]
#         return self.getDirectionToTarget(myPos, closestLocations[0])

#     def getDirectionToTarget(self, source, target):
#         """
#         Returns the direction to the target from the source.
#         """
#         dx = target[0] - source[0]
#         dy = target[1] - source[1]

#         if dx > 0:
#             return "East"
#         elif dx < 0:
#             return "West"
#         elif dy > 0:
#             return "North"
#         elif dy < 0:
#             return "South"
#         else:
#             return "Stop"  # Stay in place if already at the target.



def createTeam(firstIndex, secondIndex, isRed,
        first = 'pacai.agents.capture.dummy.DummyAgent',
        second = 'pacai.agents.capture.dummy.DummyAgent'):
    """
    This function should return a list of two agents that will form the capture team,
    initialized using firstIndex and secondIndex as their agent indexed.
    isRed is True if the red team is being created,
    and will be False if the blue team is being created.
    """

    # firstAgent = reflection.qualifiedImport(first)
    # secondAgent = reflection.qualifiedImport(second)

    firstAgent = OffensiveAgent(firstIndex)
    secondAgent = DefensiveAgent(secondIndex)

    return [
        firstAgent, secondAgent
        # firstAgent(firstIndex),
        # secondAgent(secondIndex),
    ]
