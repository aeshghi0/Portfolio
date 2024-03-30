# from pacai.util import reflection
import random
from pacai.agents.capture.capture import CaptureAgent
from pacai.agents.capture.reflex import ReflexCaptureAgent
from pacai.core.directions import Directions
from pacai.util import util
import math

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
        actions = [a for a in actions if a != Directions.STOP]

        bestValue = float('-inf')
        bestActions = []

        for action in actions:
            value = self.evaluate(gameState, action)

            if value > bestValue:
                bestValue = value
                bestActions = [action]
            elif value == bestValue:
                bestActions.append(action)

        return random.choice(bestActions) if bestActions else Directions.STOP
    
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

        if foodList:
            myPos = successor.getAgentState(self.index).getPosition()
            minDistance = min(self.getMazeDistance(myPos, food) for food in foodList)
            features['distanceToFood'] = minDistance

        # Add ghost stuff here next
        features['ghostDistance'] = self.getGhostDistance(successor)

        # Add capsule stuff here next
        features['capsuleDistance'] = self.getCapsuleDistance(successor)

        return features
    
    def getGhostDistance(self, gameState):
        """
        Computes the distance to the nearest ghost.
        """

        myPos = gameState.getAgentState(self.index).getPosition()
        enemies = [gameState.getAgentState(i) for i in self.getOpponents(gameState)]
        ghosts = [a for a in enemies if not a.isPacman() and a.getPosition() is not None]

        if ghosts:
            minDist = min(self.getMazeDistance(myPos, ghost.getPosition()) for ghost in ghosts)
            return math.log(minDist)

        return 0
    
    def getCapsuleDistance(self, gameState):
        """
        Computes the distance to the nearest capsule.
        """

        myPos = gameState.getAgentState(self.index).getPosition()
        capsules = self.getCapsules(gameState)

        if capsules:
            dists = [self.getMazeDistance(myPos, capsule) for capsule in capsules]
            return min(dists)

        return 0
    
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
            'distanceToFood': -5,
            'ghostDistance': 10,
            'capsuleDistance': -20
        }
    
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