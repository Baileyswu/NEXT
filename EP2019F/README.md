# [2019 Round F](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc)

## Flattening

有 N 个数字，要使从左往右最多有 K 次变化，最少需要改变其中的几个数字？

**Limits**   
Time limit: 15 seconds per test set.  
Memory limit: 1GB.  
1 ≤ T ≤ 100.  
1 ≤ Ai ≤ 1000, for all i.  
0 ≤ K ≤ N.  

Test set 1 (Visible)  
2 ≤ N ≤ 20.  

Test set 2 (Hidden)  
2 ≤ N ≤ 100.  

### 解答

即把数字分为连续的 K+1 段，每段的数字都相同。如果前面已经分了若干段，则后面与前面不相互干扰。因此可以用动态规划的想法。

定义状态：`dp[i][j]` 表示 `seq[0,i]` 中变化最多 j 次最少需要调整数字的个数。共计 `dp[N][K]`

推理转移：对于 `seq[0,i]` 的子串 `seq[0,w]` 最多变化了 j-1 次的情况进行遍历，假设 `seq[w+1,i]` 是最后一段，w 到 w+1 是最后一次变化，则一共进行了最多 j 次变化。当然，w 到 w+1 可能没有变，但这也被包含在最多 j 次的情形中。

```cpp
dp[i][j] = min(dp[w][j-1]+query(w+1, i)) for w < i
```

***

## Spectating Villages

V 个村庄用 V-1 条边相邻。每个村庄有自己的美丽值 Bi（可能为负）。当村庄或该村庄的邻居被点亮时，就贡献了美丽值。问随意点灯能得到的最大的美丽值？

### 解答
每个村庄可能不被照亮、被邻居照亮、被自己照亮，这三种状态。即自己电灯或者邻居电灯都可能有影响。最开始需要剥离四面八方来的关系。以 1 号村庄为根节点，可以建立一棵树。对于其中的一个结点而言，只考虑以它为根节点的子树的美丽值，再将美丽值向上传递。

定义状态：`dp[i][j]` 表示村庄 i 为状态 j 时，以它为根节点的子树的最大美丽值。共计 `dp[V][3]`.

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