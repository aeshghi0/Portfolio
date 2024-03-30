from pacai.util.queue import Queue
from pacai.util.stack import Stack
from pacai.util.priorityQueue import PriorityQueue

"""
In this file, you will implement generic search algorithms which are called by Pacman agents.
"""

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first [p 85].

    Your search algorithm needs to return a list of actions that reaches the goal.
    Make sure to implement a graph search algorithm [Fig. 3.7].

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:
    """
    
    print("Start: %s" % (str(problem.startingState())))
    print("Is the start a goal?: %s" % (problem.isGoal(problem.startingState())))
    print("Start's successors: %s" % (problem.successorStates(problem.startingState())))

    # *** Your Code Here ***

    # Stack of starting state and an list for actions
    stack = Stack()
    stack.push((problem.startingState(), []))
    visited = set()  # Tracking visited states

    while stack:
        state, actions = stack.pop()

        if problem.isGoal(state):
            return actions
        
        if state not in visited:
            visited.add(state)
            successors = problem.successorStates(state)

            for next_state, action, _ in successors:
                if next_state not in visited:
                    new_actions = actions + [action]
                    stack.push((next_state, new_actions))

    return []  # Return emoty list if no solution was found
    # raise NotImplementedError()

def breadthFirstSearch(problem):
    """
    Search the shallowest nodes in the search tree first. [p 81]
    """

    # *** Your Code Here ***
    start_state = problem.startingState()

    if problem.isGoal(start_state):
        return []   # The initial state is the goal state
    
    # Queue of starting state and empty list of actions
    queue = Queue()
    queue.push((start_state, []))
    visited = set()  # Tracking visited states

    while queue:
        state, actions = queue.pop()

        if problem.isGoal(state):
            return actions
        
        if state not in visited:
            visited.add(state)
            successors = problem.successorStates(state)

            for next_state, action, _ in successors:
                if next_state not in visited:
                    new_actions = actions + [action]
                    queue.push((next_state, new_actions))

    return []
    # raise NotImplementedError()

def uniformCostSearch(problem):
    """
    Search the node of least total cost first.
    """
    # *** Your Code Here ***

    start_state = problem.startingState()
    start_node = (start_state, [], 0)
    visited = set()  # Track visited node
    priority_queue = PriorityQueue()

    priority_queue.push(start_node, 0)

    while not priority_queue.isEmpty():
        (current_state, actions, current_cost) = priority_queue.pop()

        if current_state in visited:
            continue    # Skip, already visited states with lower cost

        visited.add(current_state)

        if problem.isGoal(current_state):
            return actions
        
        successors = problem.successorStates(current_state)

        for next_state, action, step_cost in successors:
            if next_state not in visited:
                new_cost = current_cost + step_cost
                new_actions = actions + [action]
                priority_queue.push((next_state, new_actions, new_cost), new_cost)

    return []   # Return empty list if no solution is found
    # raise NotImplementedError()

def aStarSearch(problem, heuristic):
    """
    Search the node that has the lowest combined cost and heuristic first.
    """
    # *** Your Code Here ***

    # Priority queue with starting state, cost of 0, and a heuristic value
    start_state = problem.startingState()
    start_node = (start_state, [], 0)
    visited = {}    # Track visisted states and their cost
    priority_queue = PriorityQueue()

    priority_queue.push(start_node, heuristic(start_state, problem))

    while not priority_queue.isEmpty():
        current_state, actions, current_cost = priority_queue.pop()

        if current_state in visited and current_cost >= visited[current_state]:
            continue    # Skip state with equal or higher costs

        visited[current_state] = current_cost

        if problem.isGoal(current_state):
            return actions
        
        successors = problem.successorStates(current_state)

        for next_state, action, step_cost in successors:
            new_cost = current_cost + step_cost
            new_actions = actions + [action]
            new_heuristic = new_cost + heuristic(next_state, problem)
            next_node = (next_state, new_actions, new_cost)
            priority_queue.push(next_node, new_heuristic)
            # total_priority = new_cost + new_heuristic
            # priority_queue.push((next_state, new_actions, new_heuristic), total_priority)

    return None     # No Path found
    # raise NotImplementedError()
