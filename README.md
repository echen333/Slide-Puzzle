# Slide-Puzzle

Optimal solver to find smallest number of moves to reach the finished puzzle. 

The original 15-puzzle has 16!/2 = ~10^13 states, but we can speed it up with pruning.

With the Iterative Deepening A* algorithm, a version of the shortest-path A* algorithm, we find f(n)=g(n)+h(n), where g(n) is the cost to get to the current node and h(n) is an admissible heuristic(h(n)<=h*(n)), guaraneeting optimality. We only visit the node if it is less than our current minimum bound and continue iterating on this bound.

It also doesn't use much memory and only needs to keep track of nodes visited in the current path since we know the starting and destination node. To make comparisons easy, we use a custom hash function that can bidirectionally translate permutaitons and integers.

In this current version, we use the not-so-powerful manhattan distance as our heuristic. Thus, it takes 4 minutes to solve puzzles with a depth of 35 moves. 
