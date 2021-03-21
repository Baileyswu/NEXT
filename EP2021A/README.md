# [2021 Round A](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140)

Rank: 330/19841

Score: 66/100

***

## K-Goodness String

回文串模拟题。

***

## L Shaped Plots

求矩阵里L型的块有多少个。  
其中L的长边是短边的两倍。

### 解答

`dp[i][j][k]` 对于第`(i,j)`个块的四个方向分别进行预处理后求解。

***

## Rabbit House

使得一个非负矩阵相邻元素之间的差<=1，每次操作可对一个元素+1，问最少操作多少次能满足条件。

### 解答

优先队列 BFS

***

## Checksum

已知一个矩阵的 A 的 行异或和 R、列疑惑和 C。  
现在 A 出现了数据损坏。有些数据可以通过 R 和 C 进行修复，有些无法修复。  
因此可以求助于老板。老板给出了一个矩阵 B 说明了维修每个位置的价格。  
求最小的维修费。

**Limits**
Memory limit: 1 GB.  
1≤T≤100.  
−1≤Ai,j≤1, for all i,j.  
1≤Bi,j≤1000, for i,j where Ai,j=−1, otherwise Bi,j=0.  
0≤Ri≤1, for all i.  
0≤Cj≤1, for all j.  
It is guaranteed that there exist at least one way to replace −1 in A with 0 or 1 such that R and C as satisfied.  

**Test Set 1**  
Time limit: 20 seconds.  
1≤N≤4.  
**Test Set 2**  
Time limit: 35 seconds.  
1≤N≤40.  
**Test Set 3**  
Time limit: 35 seconds.  
1≤N≤500.  


### 解答

由于异或和的性质，如果有一行或者一列只有一个数据损坏，则必然可以恢复相应的数据。  

反之，如果有大于一个数据损坏，则必须要借助老板恢复。

小数据范围下共 2^(N*N) 个数据，可以用状态压缩求解。

大数据下不能状压。

![](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0pPtEOwsR2HMmYIl97yT1TQumpwxdTdFC16G-akSFzGIGp63EqCokGnsUXBj-mcZ1gnEo/checksum.png)

将行列表示成二分图，存在一条边即表示该行该列有一个数据损失。如果一条边的一个端点的度为 1，则表示这条边属于可修复数据。这条边即与叶子相连的边。

如果这个二分图是树，那么说明可以找到叶子，将与叶子相邻的边一条一条去掉，则可以将数据一个个修复。

所以如果给的二分图不是树，则叫老板修理掉一些边，使得它成为一棵树，这棵树是可修的。

为了让老板修的最少，则剩下的树要尽可能大，即最大生成树。

这题的构图以及情况转换很有意思，到最后会发现和 R C 无关。