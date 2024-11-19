/**
 * Author:
 * Source: https://cp-algorithms.com/graph/flow_with_demands.html
 * Description: Add a new source $s'$ and sink $t'$, then set:
 * $c'(s', v) = \sum_{u \in V} d(u, v)$,
 * $c'(v', t) = \sum_{w \in W} d(v, w)$,
 * $c'(u, v) = c(u, v) - d(u, v)$,
 * $c'(t, s) = \infty$
 * If the network has a saturated flow, there exists a solution, and the actual flow can be found on the $(t, s)$ edge.
 * The max flow can be found by running flow again on the same network from the original source to original sink
 * and adding the new flow. The min flow can be found by binary search on the capacity of the $(t, s)$ edge.
 */
