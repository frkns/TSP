| source                   | wtf does it do? |
|--------------------------|-------|
| Random.cc                | random tour |
| NearestNeighbor.cc       | start at node 0, keep connecting nearest neigbhor |
| BruteNearestNeighbor.cc  | NearestNeighbor, but try many starting nodes |
| GreedyEdge.cc  | keep adding shortest OK edge |

Can combine with k-Opt, LK, etc. Not implemented.


Scores on https://optil.io/optilion/problem/2 (metric TSP)

| source                   | score |
|--------------------------|-------|
| Random.cc                | 5.05  |
| NearestNeighbor.cc       | 98.15 |
| BruteNearestNeighbor.cc  | 98.78 |


