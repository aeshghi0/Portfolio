import random

from pacai.agents.base import BaseAgent
from pacai.agents.search.multiagent import MultiAgentSearchAgent

# from pacai.core.search.heuristic import manhattan
from pacai.core import distance
from pacai.core.directions import Directions

class ReflexAgent(BaseAgent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.
    You are welcome to change it in any way you see fit,
    so long as you don't touch the method headers.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        `ReflexAgent.getAction` chooses among the best options according to the evaluation function.

        Just like in the previous project, this method takes a
        `pacai.core.gamestate.AbstractGameState` and returns some value from
        `pacai.core.directions.Directions`.
        """

        # Collect legal moves.
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions.
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices)  # Pick randomly among the best.

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current `pacai.bin.pacman.PacmanGameState`
        and an action, and returns a number, where higher numbers are better.
        Make sure to understand the range of different values before you combine them
        in your evaluation function.
        """

        successorGameState = currentGameState.generatePacmanSuccessor(action)

        # Useful information you can extract.
        # newPosition = successorGameState.getPacmanPosition()
        # oldFood = currentGameState.getFood()
        # newGhostStates = successorGameState.getGhostStates()
        # newScaredTimes = [ghostState.getScaredTimer() for ghostState in newGhostStates]

        # *** Your Code Here ***

        # Get pacman's new position after taking the action
        pacman_position = successorGameState.getPacmanPosition()

        # Get the list of the new ghost states
        new_ghost_states = successorGameState.getGhostStates()

        # Get the position of each ghost
        ghost_positions = [ghost.getPosition() for ghost in new_ghost_states]

        # Get the current food layout
        food_grid = successorGameState.getFood()
        # food_grid = food_grid.asList()

        # Initialize the score
        score = successorGameState.getScore()

        # Checking if pacman's new position hits a ghost
        for ghost_loc in ghost_positions:
            if pacman_position == ghost_loc:
                # assign a negative score to avoid this position
                score -= 1000

        # find the closest food pallet to pacman
        closest_food = float('inf')

        for i in range(food_grid._width):
            for j in range(food_grid._height):
                if food_grid[i][j]:
                    food_position = (i, j)
                    food_distance = distance.manhattan(pacman_position, food_position)
                    closest_food = min(closest_food, food_distance)

        # Assign a higher score if pacman is closer to the nearest food pallet
        if closest_food != float('inf'):
            score += 1 / (10 * closest_food)

        # Encouraging pacman to keep moving by adding bonus points to the remaining food pallets
        # remaining_foods = food_grid.count()
        # score += 10 * remaining_foods

        # return successorGameState.getScore()
        return score

class MinimaxAgent(MultiAgentSearchAgent):
    """
    A minimax agent.

    Here are some method calls that might be useful when implementing minimax.

    `pacai.core.gamestate.AbstractGameState.getNumAgents()`:
    Get the total number of agents in the game

    `pacai.core.gamestate.AbstractGameState.getLegalActions`:
    Returns a list of legal actions for an agent.
    Pacman is always at index 0, and ghosts are >= 1.

    `pacai.core.gamestate.AbstractGameState.generateSuccessor`:
    Get the successor game state after an agent takes an action.

    `pacai.core.directions.Directions.STOP`:
    The stop direction, which is always legal, but you may not want to include in your search.

    Method to Implement:

    `pacai.agents.base.BaseAgent.getAction`:
    Returns the minimax action from the current gameState using
    `pacai.agents.search.multiagent.MultiAgentSearchAgent.getTreeDepth`
    and `pacai.agents.search.multiagent.MultiAgentSearchAgent.getEvaluationFunction`.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    # Returns the evaluation function
    # def getEvaluationFunction(self):
    #    return self._evaluationFunction
    
    # Returns the depth of the tree
    def getTreeDepth(self):
        return self._treeDepth
    
    # Get the evaluation function
    def getEvaluationFunction(self):
        return self._evaluationFunction
    
    def getAction(self, state):
        """
        Returns the minimax action from the current gameState
        using alpha-beta pruning for any number of ghosts.
        """
        legal_actions = state.getLegalActions(0)  # Pac-Man's legal actions
        best_action = None
        best_value = float("-inf")

        for action in legal_actions:
            successorState = state.generateSuccessor(0, action)
            value = self.minValue(successorState, self.getTreeDepth(), 1, float("-inf"),
                                  float("inf"))
            if value > best_value:
                best_value = value
                best_action = action

        return best_action

    def maxValue(self, state, depth, alpha, beta):
        if depth == 0 or state.isWin() or state.isLose():
            return self.getEvaluationFunction()(state)

        legal_actions = state.getLegalActions(0)  # Pac-Man's legal actions
        value = float("-inf")

        for action in legal_actions:
            successor_state = state.generateSuccessor(0, action)
            value = max(value, self.minValue(successor_state, depth, 1, alpha, beta))
            if value > beta:
                return value
            alpha = max(alpha, value)

        return value

    def minValue(self, state, depth, ghost_index, alpha, beta):
        if depth == 0 or state.isWin() or state.isLose():
            return self.getEvaluationFunction()(state)

        legal_actions = state.getLegalActions(ghost_index)
        value = float("inf")

        for action in legal_actions:
            successor_state = state.generateSuccessor(ghost_index, action)
            if ghost_index < state.getNumAgents() - 1:
                value = min(value, self.minValue(successor_state, depth, ghost_index + 1,
                                                 alpha, beta))
            else:
                value = min(value, self.maxValue(successor_state, depth - 1, alpha, beta))
            if value < alpha:
                return value
            beta = min(beta, value)

        return value

    # # Returns the minimax action from the current gameState
    # def getAction(self, state):
    #     depth = self.getTreeDepth()
    #     # legal_actions = [a for a in state.getLegalActions(0) if a != Directions.STOP]

    #     # if not legal_actions:
    #     #    return Directions.STOP  # If no legal actions, return stop
        
    #     return self.minimaxDecision(state, depth)
    
    # # Using minimax to get the best next action
    # def minimaxDecision(self, state, depth):
    #     # legal_actions = state.getLegalActions(0)
    #     # Get the legal actions of pacman with agent index 0
    #     legal_actions = [a for a in state.getLegalActions(0) if a != Directions.STOP]
    #     best_action = None
    #     best_value = float("-inf")

    #     for action in legal_actions:
    #         successor_state = state.generateSuccessor(0, action)
    #         min_value = self.minValue(successor_state, 1, depth - 1)  # Ghost starts at index 1

    #         if min_value > best_value:
    #             best_value = min_value
    #             best_action = action

    #     return best_action
    
    # def maxValue(self, state, depth):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)
        
    #     v = ("-inf")
    #     legal_actions = state.getLegalActions(0)    # pacman's legal actions
    #     for action in legal_actions:
    #         successorState = state.generateSuccessor(0, action)
    #         v = max(v, self.minValue(successorState, 1, depth - 1))

    #     return v

    # def minValue(self, state, ghost_index, depth):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)
        
    #     v = float("inf")
    #     legal_actions = state.getLegalActions(ghost_index)

    #     for action in legal_actions:
    #         # if this is the last ghost, it's pacman's turn.
    #         if ghost_index == state.getNumAgents() - 1:
    #             successor_state = state.generateSuccessor(ghost_index, action)
    #             v = min(v, self.maxValue(successor_state, ghost_index + 1, depth))

    #     return v

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    A minimax agent with alpha-beta pruning.

    Method to Implement:

    `pacai.agents.base.BaseAgent.getAction`:
    Returns the minimax action from the current gameState using
    `pacai.agents.search.multiagent.MultiAgentSearchAgent.getTreeDepth`
    and `pacai.agents.search.multiagent.MultiAgentSearchAgent.getEvaluationFunction`.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    def getEvaluationFunction(self):
        return self._evaluationFunction
    
    # Returns the depth of the tree
    def getTreeDepth(self):
        return self._treeDepth
    
    def getAction(self, state):
        # legal_actions = state.getLegalActions(self.index)
        # legal_actions = [a for a in state.getLegalActions(self.index) if a != Directions.STOP]
        legal_actions = [a for a in state.getLegalActions(0) if a != Directions.STOP]
        best_action = None
        alpha = float("-inf")
        beta = float("inf")
        best_value = float("-inf")

        for action in legal_actions:
            # successor_state = state.generateSuccessor(self.index, action)
            successor_state = state.generateSuccessor(0, action)
            # value = self.minValue(successor_state, self.getTreeDepth(), agent_index, alpha, beta)
            value = self.minValue(successor_state, self.getTreeDepth(), 1, alpha, beta)
            if value > best_value:
                best_value = value
                best_action = action
            alpha = max(alpha, best_value)
        
        return best_action
    
    def maxValue(self, state, depth, alpha, beta):
        if depth == 0 or state.isWin() or state.isLose():
            return self.getEvaluationFunction()(state)
        
        legal_actions = state.getLegalActions(0)
        value = float("-inf")

        for action in legal_actions:
            # successor_state = state.generateSuccessor(agent_index, action)
            successor_state = state.generateSuccessor(0, action)
            # value = max(value, self.minValue(successor_state, depth, agent_index, alpha, beta))
            value = max(value, self.minValue(successor_state, depth, 1, alpha, beta))
            if value > beta:
                return value
            
            alpha = max(alpha, value)

        return value
    
    def minValue(self, state, depth, ghostIndex, alpha, beta):
        if depth == 0 or state.isWin() or state.isLose():
            return self.getEvaluationFunction()(state)

        legalActions = state.getLegalActions(ghostIndex)
        value = float("inf")

        for action in legalActions:
            successorState = state.generateSuccessor(ghostIndex, action)
            if ghostIndex < state.getNumAgents() - 1:
                value = min(value, self.minValue(successorState, depth, ghostIndex + 1,
                                                 alpha, beta))
            else:
                value = min(value, self.maxValue(successorState, depth - 1, alpha, beta))
            if value < alpha:
                return value
            beta = min(beta, value)

        return value

    # def minValue(self, state, depth, agent_index, alpha, beta):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)
        
    #     num_agents = state.getNumAgents()
    #     legal_actions = state.getLegalActions(agent_index)
    #     value = float("inf")

    #     next_agent_index = (agent_index + 1) % num_agents

    #     # if the next agent is the maximixing agent, reduce the depth
    #     if next_agent_index == self.index:
    #         depth -= 1
        
    #     for action in legal_actions:
    #         succesor_state = state.generateSuccessor(agent_index, action)
    #         value = min(value, self.getValue(succesor_state, depth, next_agent_index,
    # alpha, beta))
            
    #         if value < alpha:
    #             return value
            
    #         beta = min(beta, value)
        
    #     return value

    # def getValue(self, state, depth, agent_index, alpha, beta):
    #     if agent_index == self.index:
    #         return self.maxValue(state, depth, agent_index, alpha, beta)
    #     else:
    #         return self.minValue(state, depth, agent_index, alpha, beta)

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
    An expectimax agent.

    All ghosts should be modeled as choosing uniformly at random from their legal moves.

    Method to Implement:

    `pacai.agents.base.BaseAgent.getAction`:
    Returns the expectimax action from the current gameState using
    `pacai.agents.search.multiagent.MultiAgentSearchAgent.getTreeDepth`
    and `pacai.agents.search.multiagent.MultiAgentSearchAgent.getEvaluationFunction`.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    def getEvaluationFunction(self):
        return self._evaluationFunction
    
    # Returns the depth of the tree
    def getTreeDepth(self):
        return self._treeDepth
    
    # Returns the expectimax action using the expectimax algorithm from the current state
    def getAction(self, state):
        legal_actions = state.getLegalActions(self.index)
        best_action = None
        best_value = float("-inf")

        for action in legal_actions:
            successor_state = state.generateSuccessor(self.index, action)
            value = self.expectValue(successor_state, self.getTreeDepth(), 0)
            
            if value > best_value:
                best_value = value
                best_action = action

        return best_action
    
    def expectValue(self, state, depth, agentIndex):
        stack = [(state, depth, agentIndex)]
        value = 0.0

        while stack:
            state, depth, agentIndex = stack.pop()

            if depth == 0 or state.isWin() or state.isLose():
                value += self.getEvaluationFunction()(state)
            else:
                numAgents = state.getNumAgents()
                legalActions = state.getLegalActions(agentIndex)

                if agentIndex == self.index:
                    # Pac-Man's turn (maximizer)
                    max_value = float("-inf")
                    for action in legalActions:
                        successorState = state.generateSuccessor(agentIndex, action)
                        stack.append((successorState, depth, agentIndex))
                        value += max(max_value,
                                        self.expectValue(successorState, depth, agentIndex))
                    # value += max_value
                else:
                    # Ghost's turn (expected value)
                    prob = 1.0 / len(legalActions)  # Assuming uniform random choice
                    expected_value = 0.0
                    next_agent_index = (agentIndex + 1) % numAgents
                    for action in legalActions:
                        successorState = state.generateSuccessor(agentIndex, action)
                        stack.append((successorState, depth, next_agent_index))
                        expected_value += prob * self.expectValue(successorState,
                                                                  depth, next_agent_index)
                    value += expected_value

        return value

    # def expectValue(self, state, depth, agentIndex):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)

    #     numAgents = state.getNumAgents()
    #     legalActions = state.getLegalActions(agentIndex)
    #     value = 0.0

    #     for action in legalActions:
    #         successorState = state.generateSuccessor(agentIndex, action)

    #         if agentIndex == self.index:
    #             # Pac-Man's turn (maximizer)
    #             value = max(value, self.maxValue(successorState, depth, agentIndex))
    #         else:
    #             # Ghost's turn (expected value)
    #             prob = 1.0 / len(legalActions)  # Assuming uniform random choice
    #             value += prob * self.expectValue(successorState, depth,
    # (agentIndex + 1) % numAgents)

    #     return value

    # def maxValue(self, state, depth, agentIndex):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)

    #     legalActions = state.getLegalActions(agentIndex)
    #     value = float("-inf")

    #     for action in legalActions:
    #         successorState = state.generateSuccessor(agentIndex, action)
    #         value = max(value, self.expectValue(successorState, depth, (agentIndex + 1)
    # % state.getNumAgents()))

    #     return value
    
    # def expectValue(self, state, depth, agent_index):
    #     stack = [(state, depth, agent_index)]
    #     value = 0.0

    #     while stack:
    #         state, depth, agent_index = stack.pop()

    #         if depth == 0 or state.isWin() or state.isLose():
    #             value += self.getEvaluationFunction()(state)
    #         else:
    #             num_agents = state.getNumAgents()
    #             legal_actions = state.getLegalActions(agent_index)

    #             if agent_index == self.index:   # pacman's turn (maximizer)
    #                 max_value = float("-inf")
    #                 for action in legal_actions:
    #                     successor_state = state.generateSuccessor(agent_index, action)
    #                     next_agent_index = (agent_index + 1) % num_agents
    #                     stack.append((successor_state, depth, next_agent_index))
    #                     max_value = max(max_value, self.expectValue(successor_state,
    #                                                                 depth, next_agent_index))
    #                 value += max_value
    #             else:   # ghost's turn (expected value)
    #                 prob = 1.0 / len(legal_actions)  # assuming the uniform random choice
    #                 expected_value = 0.0
    #                 next_agent_index = (agent_index + 1) % num_agents
    #                 for action in legal_actions:
    #                     successor_state = state.generateSuccessor(agent_index, action)
    #                     stack.append((successor_state, depth, next_agent_index))
    #                     expected_value += prob * self.expectValue(successor_state,
    #                                                               depth, next_agent_index)
    #                 value += expected_value
        
    #     return value

    # def maxValue(self, state, depth, agent_index):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)
        
    #     legal_actions = state.getLegalActions(agent_index)
    #     value = float("-inf")

    #     for action in legal_actions:
    #         successor_state = state.generateSuccessor(agent_index, action)
    #         value = max(value, self.expectValue(successor_state, depth, agent_index))

    #     return value
    
    # def expectValue(self, state, depth, agent_index):
    #     if depth == 0 or state.isWin() or state.isLose():
    #         return self.getEvaluationFunction()(state)
        
    #     num_agents = state.getNumAgents()
    #     legal_actions = state.getLegalActions(agent_index)
    #     value = 0.0

    #     for action in legal_actions:
    #         successor_state = state.generateSuccessor(agent_index, action)

    #         if agent_index == self.index:   # pacman's turn (maximizer)
    #             value = max(value, self.maxValue(successor_state, depth, agent_index))
    #         else:   # ghost turn (expected value)
    #             prob = 1.0 / len(legal_actions) # Assuming the uniform random choice
    #             value += prob * self.expectValue(successor_state, depth,
    #  (agent_index + 1) % num_agents)

    #     return value


def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable evaluation function.

    DESCRIPTION:
        Evaluate the given game state to estimate its quality

        features:
            1 - Pac-man's current score
    """
    # Extracting information from the game state
    pacman_position = currentGameState.getPacmanPosition()
    food_list = currentGameState.getFood().asList()
    ghost_states = currentGameState.getGhostStates()

    # Initialize weight for each feature
    score_wight = 1.0
    food_distance_weight = -2.0
    remaining_food_weight = -5.0
    ghost_distance_weight = -10.0
    scared_time_weight = 5.0

    # Calculate the current game score
    score = currentGameState.getScore()

    # Calculate the distance to the nearest food pellet
    if len(food_list) > 0:
        min_food_distance = min([distance.manhattan(pacman_position, food) for food in food_list])
    else:
        min_food_distance = 0

    # Calculate the number of remaining food pellets
    remaining_food = len(food_list)

    # Calculate the distance to the nearest ghost and the total scared time of ghosts
    ghost_distances = [distance.manhattan(pacman_position, ghost.getPosition())
                       for ghost in ghost_states]
    nearest_ghost_dist = min(ghost_distances)
    scared_times = [ghost_state._scaredTimer for ghost_state in ghost_states]
    total_scared_time = sum(scared_times)

    # Calculating the evaluation using the linear combination of features and weights
    evaluation = (score_wight * score
                  + food_distance_weight / (min_food_distance + 1)  # to prevent division by 0
                  + remaining_food_weight * remaining_food
                  + ghost_distance_weight / (nearest_ghost_dist + 1)  # to prevent divistion by 0
                  + scared_time_weight * total_scared_time)

    return evaluation
    # return currentGameState.getScore()

class ContestAgent(MultiAgentSearchAgent):
    """
    Your agent for the mini-contest.

    You can use any method you want and search to any depth you want.
    Just remember that the mini-contest is timed, so you have to trade off speed and computation.

    Ghosts don't behave randomly anymore, but they aren't perfect either -- they'll usually
    just make a beeline straight towards Pacman (or away if they're scared!)

    Method to Implement:

    `pacai.agents.base.BaseAgent.getAction`
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)
