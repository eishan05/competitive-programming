Link to problem: https://www.hackerrank.com/challenges/kingdom-connectivity/problem

Note that there is a bit more to the problem than just topological sorting. There is a little Dynamic Programming involved as well. I use the `paths` vector to keep track of the number of paths to reach node `i`. The recurrence relation is `paths[i] = sum_of_all(path[j]) such that there is edge from j to i`. Also, we need to make sure that the path to node `N` does not _touch_ a cycle, otherwise there would be infinite number of paths to node `N`. The answer is simply the value of `paths[N]`. 