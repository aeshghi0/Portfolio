"""
This file contains incomplete versions of some agents that can be selected to control Pacman.
You will complete their implementations.

Good luck and happy searching!
"""

import logging

from pacai.core.actions import Actions
from pacai.core.directions import Directions
from pacai.core.search import heuristic
from pacai.core.search.position import PositionSearchProblem
from pacai.core.search.problem import SearchProblem
from pacai.agents.base import BaseAgent
from pacai.agents.search.base import SearchAgent
# from pacai.student.search import aStarSearch
from pacai.util.priorityQueue import PriorityQueue

class CornersProblem(SearchProblem):
    """
    This search problem finds paths through all four corners of a layout.

    You must select a suitable state space and successor function.
    See the `pacai.core.search.position.PositionSearchProblem` class for an example of
    a working SearchProblem.

    Additional methods to implement:

    `pacai.core.search.problem.SearchProblem.startingState`:
    Returns the start state (in your search space,
    NOT a `pacai.core.gamestate.AbstractGameState`).

    `pacai.core.search.problem.SearchProblem.isGoal`:
    Returns whether this search state is a goal state of the problem.

    `pacai.core.search.problem.SearchProblem.successorStates`:
    Returns successor states, the actions they require, and a cost of 1.
    The following code snippet may prove useful:
    ```
        successors = []

        for action in Directions.CARDINAL:
            x, y = currentPosition
            dx, dy = Actions.directionToVector(action)
            nextx, nexty = int(x + dx), int(y + dy)
            hitsWall = self.walls[nextx][nexty]

            if (not hitsWall):
                # Construct the successor.

        return successors
    ```
    """

    def __init__(self, startingGameState):
        super().__init__()

        self.walls = startingGameState.getWalls()
        self.startingPosition = startingGameState.getPacmanPosition()
        top = self.walls.getHeight() - 2
        right = self.walls.getWidth() - 2

        self.corners = ((1, 1), (1, top), (right, 1), (right, top))
        for corner in self.corners:
            if not startingGameState.hasFood(*corner):
                logging.warning('Warning: no food in corner ' + str(corner))

        # *** Your Code Here ***
        # self.startingState = (self.startingPosition, self.corners)
        # raise NotImplementedError()
    
    # Function to return the starting state
    def startingState(self):
        return (self.startingPosition, self.corners)
    
    def isGoal(self, state):
        # Checks if all the corners have been visited
        # position, corners = state
        # return len(corners) == 0
        return not state[1]

    def actionsCost(self, actions):
        """
        Returns the cost of a particular sequence of actions.
        If those actions include an illegal move, return 999999.
        This is implemented for you.
        """

        if (actions is None):
            return 999999

        x, y = self.startingPosition
        for action in actions:
            dx, dy = Actions.directionToVector(action)
            x, y = int(x + dx), int(y + dy)
            if self.walls[x][y]:
                return 999999

        return len(actions)
    
    def successorStates(self, state):
        currentPosition, remainingCorners = state
        x, y = currentPosition

        successors = []

        for action in Directions.CARDINAL:
            dx, dy = Actions.directionToVector(action)
            next_x, next_y = int(x + dx), int(y + dy)

            if not self.walls[next_x][next_y]:
                nextPosition = (next_x, next_y)
                nextCorners = list(remainingCorners)

                # Check if the next position is one of the corners remaining
                if nextPosition in nextCorners:
                    nextCorners.remove(nextPosition)
                
                successors.append(((nextPosition, tuple(nextCorners)), action, 1))
        # position, corners = state
        # successors = []

        # for action in Actions.CARDINAL:
        #     dx, dy = Actions.directionToVector(action)
        #     next_x, next_y = int(position[0] + dx), int(position[1] + dy)

        #     if not self.walls[next_x][next_y]:
        #         new_position = (next_x, next_y)
        #         new_corners = list(corners)

        #         if new_position in corners:
        #             new_corners.remove(new_position)

        #         successors.append((new_position, action, 1))
        
        return successors

def cornersHeuristic(state, problem):
    """
    A heuristic for the CornersProblem that you defined.

    This function should always return a number that is a lower bound
    on the shortest path from the state to a goal of the problem;
    i.e. it should be admissible.
    (You need not worry about consistency for this heuristic to receive full credit.)
    """

    # Useful information.
    # corners = problem.corners  # These are the corner coordinates
    # walls = problem.walls  # These are the walls of the maze, as a Grid.

    # *** Your Code Here ***
    current_position, remaining_corners = state

    # Manhattan distance to the nearest corner
    if not remaining_corners:
        return 0    # All corners visited, no need to move
    
    min_distance = float('inf')
    # totalHeuristicValue = 0

    for corner in remaining_corners:
        problem.goal = corner
        # distance = abs(current_position[0] - corner[0]) + abs(current_position[1] - corner[1])
        # totalHeuristicValue += heuristic.euclidean(current_position, problem)
        distance = heuristic.manhattan(current_position, problem)
        
        if distance < min_distance:
            min_distance = distance

    # return totalHeuristicValue
    return min_distance
    # return heuristic.null(state, problem)  # Default to trivial solution

def foodHeuristic(state, problem):
    """
    Your heuristic for the FoodSearchProblem goes here.

    This heuristic must be consistent to ensure correctness.
    First, try to come up with an admissible heuristic;
    almost all admissible heuristics will be consistent as well.

    If using A* ever finds a solution that is worse than what uniform cost search finds,
    your heuristic is *not* consistent, and probably not admissible!
    On the other hand, inadmissible or inconsistent heuristics may find optimal solutions,
    so be careful.

    The state is a tuple (pacmanPosition, foodGrid) where foodGrid is a
    `pacai.core.grid.Grid` of either True or False.
    You can call `foodGrid.asList()` to get a list of food coordinates instead.

    If you want access to info like walls, capsules, etc., you can query the problem.
    For example, `problem.walls` gives you a Grid of where the walls are.

    If you want to *store* information to be reused in other calls to the heuristic,
    there is a dictionary called problem.heuristicInfo that you can use.
    For example, if you only want to count the walls once and store that value, try:
    ```
    problem.heuristicInfo['wallCount'] = problem.walls.count()
    ```
    Subsequent calls to this heuristic can access problem.heuristicInfo['wallCount'].
    """

    position, foodGrid = state

    # *** Your Code Here ***
    foodList = foodGrid.asList()

    if not foodList:
        return 0  # If there is no food left, we reached the goal
    
    # Manhattan distance to the nearest food pallet
    pacman_x, pacman_y = position
    min_distance = float('inf')

    for food_x, food_y in foodList:
        distance = abs(pacman_x - food_x) + abs(pacman_y - food_y)

        if distance < min_distance:
            min_distance = distance

    # totalDistance = 0

    # Calculate the Manhattan distance to the remaining foods
    # for food in foodList:
    #     distance_to_food = 0
    #     for food in foodList:
    #         problem.goal = food
    #         dist = heuristic.euclidean(position, problem)
    #         if distance_to_food == 0 or distance_to_food > dist:
    #             distance_to_food = dist
    #     # distance_to_food = min(heuristic.manhattan(position, problem.goal = food)
    #     #  for food in foodList)
    #     totalDistance += distance_to_food

    return min_distance

    # return heuristic.null(state, problem)  # Default to the null heuristic.

class ClosestDotSearchAgent(SearchAgent):
    """
    Search for all food using a sequence of searches.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)

    def registerInitialState(self, state):
        self._actions = []
        self._actionIndex = 0

        currentState = state

        while (currentState.getFood().count() > 0):
            nextPathSegment = self.findPathToClosestDot(currentState)  # The missing piece
            self._actions += nextPathSegment

            for action in nextPathSegment:
                legal = currentState.getLegalActions()
                if action not in legal:
                    raise Exception('findPathToClosestDot returned an illegal move: %s!\n%s' %
                            (str(action), str(currentState)))

                currentState = currentState.generateSuccessor(0, action)

        logging.info('Path found with cost %d.' % len(self._actions))

    def findPathToClosestDot(self, gameState):
        """
        Returns a path (a list of actions) to the closest dot, starting from gameState.
        """

        # Here are some useful elements of the startState
        # startPosition = gameState.getPacmanPosition()
        # food = gameState.getFood()
        # walls = gameState.getWalls()
        # problem = AnyFoodSearchProblem(gameState)

        # *** Your Code Here ***

        problem = AnyFoodSearchProblem(gameState)
        
        # A* search algorithm
        frontier = PriorityQueue()
        startState = gameState.getPacmanPosition()
        visited = set()
        frontier.push((startState, []), 0)

        while not frontier.isEmpty():
            (currentState, actions) = frontier.pop()

            if problem.isGoal(currentState):
                return actions
            
            if currentState not in visited:
                visited.add(currentState)
                
                for successor, action, _ in problem.successorStates(currentState):
                    if successor not in visited:
                        nextActions = actions + [action]
                        cost = len(nextActions)
                        frontier.push((successor, nextActions), cost)

        # food = gameState.getFood()
        # position = gameState.getPacmanPosition()
        # heuristic_value = min(heuristic.manhattan(position, problem) for dot in food.asList())
        # actions = aStarSearch(problem, heuristic_value)
        
        return []

        # raise NotImplementedError()

class AnyFoodSearchProblem(PositionSearchProblem):
    """
    A search problem for finding a path to any food.

    This search problem is just like the PositionSearchProblem,
    but has a different goal test, which you need to fill in below.
    The state space and successor function do not need to be changed.

    The class definition above, `AnyFoodSearchProblem(PositionSearchProblem)`,
    inherits the methods of `pacai.core.search.position.PositionSearchProblem`.

    You can use this search problem to help you fill in
    the `ClosestDotSearchAgent.findPathToClosestDot` method.

    Additional methods to implement:

    `pacai.core.search.position.PositionSearchProblem.isGoal`:
    The state is Pacman's position.
    Fill this in with a goal test that will complete the problem definition.
    """

    def __init__(self, gameState, start = None):
        super().__init__(gameState, goal = None, start = start)

        # Store the food for later reference.
        self.food = gameState.getFood()

    def isGoal(self, state):
        x, y = state  # The state is Pacman's position
        return self.food[x][y]


class ApproximateSearchAgent(BaseAgent):
    """
    Implement your contest entry here.

    Additional methods to implement:

    `pacai.agents.base.BaseAgent.getAction`:
    Get a `pacai.bin.pacman.PacmanGameState`
    and return a `pacai.core.directions.Directions`.

    `pacai.agents.base.BaseAgent.registerInitialState`:
    This method is called before any moves are made.
    """

    def __init__(self, index, **kwargs):
        super().__init__(index, **kwargs)
