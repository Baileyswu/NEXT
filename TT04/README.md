# Dynamic Programming

## 记忆化
把搜索过程中重复计算的结果存储起来。

## 动态规划
定义**状态**：形容问题和子问题。  
推理**状态转移**，注意初始条件。  

***
## 多重背包
### TODO 状态压缩解法  
### TODO 单调队列优化解法  

***
## Spectating Villages
[2019 F](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666b)

V 个村庄用 V-1 条边相邻。每个村庄有自己的美丽值 Bi（可能为负）。当村庄或该村庄的邻居被点亮时，就贡献了美丽值。问随意点灯能得到的最大的美丽值？

### 解答
每个村庄可能不被照亮、被邻居照亮、被自己照亮，这三种状态。即自己电灯或者邻居电灯都可能有影响。最开始需要剥离四面八方来的关系。以 1 号村庄为根节点，可以建立一棵树。对于其中的一个结点而言，只考虑以它为根节点的子树的美丽值，再将美丽值向上传递。

定义状态：dp[i][j] 表示村庄 i 为状态 j 时，以它为根节点的子树的最大美丽值。共计 dp[V][3].

推理转移：  
1. 村庄 i 不被照亮，则子树上的村庄 c 都不点灯，可能为 0 或 1。这里很容易漏掉 1 这种情况。邻居亮而不点灯，也是无法照亮 i 的。
```cpp
dp[i][0] = sum(max(dp[c][j]) for j in {0, 1}) for all c
```
2. 村庄 i 被子树 c 照亮（暂不考虑它被父亲照亮，因为考虑父亲的时候会有父亲照亮子树的情况）至少有一个子结点 d 从 2 号状态转移过来，其余的从任意状态转移过来。
```cpp
dp[i][1] = dp[d][2]
         + sum(max(dp[c][j]) for all j) for all c but != d
         + beauty[i]
```
3. 村庄 i 电灯，则其子树一定也被照亮，可能为 1 或 2，也可能是从 0 转换到 1.
```cpp
dp[i][2] = sum(max(dp[c][1], dp[c][2], dp[c][0]+beauty[c])) for all c
         + beauty[i]
```

***
## Plates
[2020 A](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb)

有 N 叠盘子，每叠 K 个，每个盘子有自己的价值，且要取某个盘子时，必须要拿上面的所有盘子。问要取 P 个盘子的价值之和最大是多少？

**Limits**  
1 ≤ T ≤ 100.  
1 ≤ K ≤ 30.  
1 ≤ P ≤ N * K.  
The beauty values are between 1 and 100, inclusive.  

Test set 1  
1 ≤ N ≤ 3. 

Test set 2  
1 ≤ N ≤ 50.

### 解答
由于取某个盘子时上面所有盘子都要取，新定义 (w, v) 表示取某个盘子时需要拿的盘子的总数和价值的总数为 sum，即前缀和。这样就变成了总体积为 P 的 0-1 背包问题。有所不同的是，来自于同一叠盘子的物品是互斥的。

定义状态：dp[i][w] 表示前 i 叠盘子一共取 w 个盘子时最多的价值和。共计 dp[N][P].  

状态转移
```cpp
dp[i][w] = max(dp[i-1][w], dp[i-1][w-j] + sum[i][j])
```

***
## Energy Stone
[2019 B](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050eda/00000000001198c3)

一个怪兽吃 N 块能量石，每块都有初始能量 Ei，能量随着时间衰减，每秒衰减 Li 直到为 0. 吃能量石花费时间 Si, 得到的能量为刚开始吃时该石头的能量. 问最多能得到多少能量?

**Limits**  
1 ≤ T ≤ 100.  
1 ≤ N ≤ 100.  
1 ≤ Si ≤ 100.  
1 ≤ Ei ≤ 10^5.  
0 ≤ Li ≤ 10^5.  

### 解答

状态定义: dp[i][j] 表示前 i 块能量石经过时间 j 后可吸取的能量.

状态转移:
```cpp
dp[i][j] = max(dp[i-1][j], dp[i-1][j-S[i]] + left[i])
left[i] = max(0, E[i]-(j-S[i])*L[i])
```
TODO wa

***
## Flattening
TODO 2019 F

***
## Catch Some
2019 C see [EP10](https://github.com/Baileyswu/NEXT/tree/master/EP10#catch-some)

***
## Lucky Dip
2018 A see [EP02](https://github.com/Baileyswu/NEXT/tree/master/EP02#lucky-dip)

***
## Cave Escape
2018 G see [EP08](https://github.com/Baileyswu/NEXT/tree/master/EP08#cave-escape)


