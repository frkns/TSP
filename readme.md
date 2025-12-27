The programs are approximate solutions to the (metric) Traveling Salesman Problem

I/O format follows https://optil.io/optilion/problem/2


| source | wtf does it do? |
|-|-|
| Random.cc | random permutation of cities |
| NearestNeighbor.cc | start at node 0, keep connecting nearest neigbhor |
| BruteNearestNeighbor.cc | NearestNeighbor, but try many starting nodes |
| GreedyEdge.cc | keep adding shortest ok edge |

Can combine with k-Opt, LK, etc. Not implemented.

| source | score | time (s) |
|-|-|-|
| Random.cc | 5.05  | 0.00 |
| NearestNeighbor.cc | 98.15 | 0.00 |
| GreedyEdge.cc | 98.30 | 0.39 |
| BruteNearestNeighbor.cc | 98.78 | 27.25 |


