The programs are approximate solutions to the (metric) Traveling Salesman Problem

I/O format follows https://optil.io/optilion/problem/2. `ali535` is an example input.


| source | wtf does it do? |
|-|-|
| Random.cc | random permutation of cities |
| NearestNeighbor.cc | start at node 0, keep connecting nearest neigbhor |
| BruteNearestNeighbor.cc | NearestNeighbor, but try many starting nodes |
| GreedyEdge.cc | keep adding shortest ok edge |

Can combine with k-Opt, LK, etc. Not implemented.

| source | score (TSPLIB) | time (s) |
|-|-|-|
| Random.cc | 5.05  | 0.00 |
| NearestNeighbor.cc | 98.15 | 0.00 |
| GreedyEdge.cc | 98.30 | 0.39 |
| BruteNearestNeighbor.cc | 98.78 | 27.25 |

| source | distance (ali535), ± 95% CI |
|-|-|
| GreedyEdge.cc | 2405.57 |
| BruteNearestNeighbor.cc | 2434.00 |
| NearestNeighbor.cc | 2671.07 |
| Random.cc | 39357.46 ± 163.72 |


