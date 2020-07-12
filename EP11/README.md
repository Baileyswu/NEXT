# [2020 Round D](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08)

## Record Breaker
给定长为 N 的数列，求其中满足条件的数字有几个：  
1. 该数比前面所有的数字大
2. 该数比后面相邻的数字大

### 解答
扫一遍。保留前面最大的数字。

***

## Alien Piano
用四个音符模拟复杂的曲子。若原曲中本音符高于前一个音，则模拟音符也要让本音高于前音。低于、等于同理。当超过四个音则要中断，重新表示。问模拟的过程中最少中断几次。

### 解答

直接暴力，从左往右模拟答案错误。采用 dp 的想法。  
开 dp[N][4] 大小的数组。  
`dp[i][j]`: 第 i 个音为 j 这个音符时会中断的次数。

不考虑连贯性，则有 `dp[i][j] = min(dp[i-1][k] + 1) for k in range(4)`  
若考虑连贯性，则有
1. 高于前面的音 `dp[i][j] = min(dp[i-1][k]) for j > k`
2. 低于前面的音 `dp[i][j] = min(dp[i-1][k]) for j < k`
3. 等于前面的音 `dp[i][j] = min(dp[i-1][k]) for j < k`

***

## Beauty of tree
给定一棵树，随机访问其中的一个节点，并朝根节点走。甲每隔 A 步涂色，乙每隔 B 步涂色，涂色的编号为树的美丽值。问美丽值的期望。

### 解答
计算出每个节点会被几个儿子访问到。对于同一个节点 i，若甲有 p 个儿子可访问到，乙有 q 个儿子可访问到，则该点对美丽值的期望的贡献为 `i*(1-(p/n)*(1-q/n))`. 将所有贡献加起来即是总的期望。

***

## Locked Doors
有 N 个房间，N-1 扇门，每两个房间中间隔着一扇门。撞开一扇门要花 di 个力气。现在从某个房间进去，每次都选力气小的门撞开，会有个房间的访问序列。询问 Q 次，从 Si 房间开始访问到的第 Ki 个房间是几号房间。

### 解答
用并查集记录每个房间左边和右边的房间分别是几号。赛后我突然觉得这个思路真的没必要并查集啊(ˉ▽ˉ；)...这是个一维的维护左右边界就够了用什么并查集。2019 Round C Wiggle Walk 后遗症。