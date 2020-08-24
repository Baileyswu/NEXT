# Graph algorithm

## 拓扑排序
逐步删除度数为 0 的节点，按照删除的顺序进行排序就是拓扑排序。

可以发现图中的环。

### Planet Distance
2018 C see [EP04](https://github.com/Baileyswu/NEXT/tree/master/EP04#planet-distance)

***

## 最小生成树

### Prim 算法
贪心的思想。选择一个点开始，选择离它最近的点，加入到点集中。再以这个点集出发，选择**离它们**最近的点，加入到点集中。以此类推，直到加完为止。

### Kruskal 算法
贪心的思想。将所有的边的值进行排序，逐步加入到图中。如果加进去以后会生成环，则不加这条边，continue。

用并查集可以快速查询某条边的两个点是否在同一个集合里。在同一个集合里的点会有一样的 union parent。

### Cherries Mesh
2019 E

给出了 n 个点的完全图中 边权为 1 的边，剩下的都是边权为 2 的边，求最小生成树。

- Kruskal  
相当于不用排序了，直接把给出的边加入到生成树中，除非经过并查集是联通的则不加。得到 a 条边权为 1 的边后，剩下 n-1-a 条即为边权为 2 的边。
- Prim
从一个起点开始 dfs，得到遍历路径组成的树。如果中断则是个森林。

***

## 最短路

### Bellman Ford
Relax 操作。最多做 n-1 次。每次必然会使得一个点得到最短路。
```cpp
for each edge(u, v, w)
    dist[v] = min(dis[v], dis[u] + w)
```
不能有负环，否则会一直 relax 不能收敛。可以有负边。

### Dijkstra

初始化所有点的初始距离均为 INF，不断地加入**离源点**最近的点到出发点集中，并更新距离。  
不能有负边，否则会导致加入的点的距离错误。

### Floyd

可以计算多源最短路。

不停地开放新的中间站点 k。
```cpp
f[x][y] = min(f[i][k], f[j][k])
```
可以有负边。

### 单源最短路
[LC 743](https://leetcode-cn.com/problems/network-delay-time/) 从 K 点开始 dijstra 求单源最短路，再从答案里找到可达到的最大值。若有为达到的值则为 -1.