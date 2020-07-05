# [2018 Round C](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ee0)

## Planet Distance
在 N 个点 N 条边的图中存在自环，求不在自环上的点离自环的距离。

### 解答
类似拓扑排序，找到度为 1 的点不断删去，直到无法删除为止，剩下的为自环。实际操作中用数组记录度数，-1 即为删边。  
以自环为起点 BFS 计算到其他点的距离。

***

## Fairies and Witches
给定数组 A，对于 A 中的任意一个子序列，都可以计算 i 阶幂。现在要计算所有子序列的所有阶幂的和。

### 解答


*** 

## Kickstart Alarm