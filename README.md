# Slide-Puzzle

The [slide puzzle](https://slidingtiles.com/en) is a children's puzzle where the goal is to sort numbers in order by only sliding tiles around. An optimal solver attempts to find the smallest number of moves to reach the finished puzzle. 

The original 15-puzzle has $\frac{16!}{2} = ~10^{13}$ states, which would take ~24 hours to go through on a normal computer, but we can speed it up with pruning.

With the Iterative Deepening A* algorithm, a version of the shortest-path A* algorithm, we let $f(n)=g(n)+h(n)$, where $g(n)$ is the cost to get to the current node and $h(n)$ is an admissible heuristic, e.g. $h(n)<=h^*(n)$ such that we guarantee optimality. Then, we only visit the node if $f(n)$ is less than our current bound and continue iterating on this bound.

Since we know the starting and destination node, it is much less memory-intensive as only keep track of the nodes on the current path is necessary. To make comparisons easy, we use a custom hash function that can bidirectionally translate permutations and integers.

Using the not-so-powerful manhattan distance as our heuristic, it takes 30 minutes to solve puzzles. Instead, changing it to the [walking distance heuristic](http://www.ic-net.or.jp/home/takaken/nt/slide/solve15.html), the solve time decreases significantly to a few minutes in worst case time.

References used for this project:
- [ic-net.jp](http://www.ic-net.or.jp/home/takaken/nt/slide/solve15.html)
- [jurpolo.ru](https://web.archive.org/web/20141224035932/http://juropollo.xe0.ru/stp_wd_translation_en.htm)
- [IDA* - Richard E. Korf](https://cse.sc.edu/~mgv/csce580f11/gradPres/korf_IDAStar_1985.pdf)
