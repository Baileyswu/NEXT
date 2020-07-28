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
2019 F see [EP2019F](https://github.com/Baileyswu/NEXT/tree/master/EP2019F#spectating-villages)

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

状态定义: `dp[i][j]` 表示前 i 块能量石经过时间 j 后可吸取的能量.

状态转移:
```cpp
dp[i][j] = max(dp[i-1][j], dp[i-1][j-S[i]] + left[i])
left[i] = max(0, E[i]-(j-S[i])*L[i])
```
但是这样转移会使得第 i 块石头一定排在前 i-1 块后面。不同顺序的结果显然是不同的。因此要先确定顺序。

如果选好了吃哪几块石头，那么先吃损失得比较快的，才能保证剩余的多。另外先吃耗时比较快的，才能保证消耗其他石头的少，剩余得多。这样保证了吃石头的顺序，只要确定要不要吃某块石头。就可以用上面的 DP 式子了。

具体怎么排序石头呢？假设有第 i,j 两块石头，先吃 i 或者先吃 j 会造成实际吃到的能量分别为 `Ei+Ej-Si*Lj` 和 `Ei+Ej-Sj*Li`，那应该优先让 `Si*Lj` 小的那项排在前面。 


***
## Flattening
2019 F see [EP2019F](https://github.com/Baileyswu/NEXT/tree/master/EP2019F#flattening)

***
## Catch Some
2019 C see [EP2019C](https://github.com/Baileyswu/NEXT/tree/master/EP2019C#catch-some)

***
## Lucky Dip
2018 A see [EP02](https://github.com/Baileyswu/NEXT/tree/master/EP02#lucky-dip)

***
## Cave Escape
2018 G see [EP08](https://github.com/Baileyswu/NEXT/tree/master/EP08#cave-escape)


