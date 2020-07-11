# [2019 Round C](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2)

## Wiggle Walk
一个机器人可以按照指令往东南西北四个方向走。如果遇到已经走过的点，则沿着该方向继续走，直到走到一个没有走到过的点。已知起点和方向指令，求终点。

Test set 2 (Hidden)  
Time limit: 60 seconds.  
1 ≤ N ≤ 5 × 10^4.  

### 解答
要越过给定方向的连续的点，用并查集的思想，将寻找的过程压缩。如：A 的东边的东边的点，是 A 的东边的点。只需要将最东边的点存储下来即可。可以将点映射到 id 的集合。点到点的映射转化为 id 到 id 的映射，即数组可以完成。

