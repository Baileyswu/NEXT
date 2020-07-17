# Search & Recursion 

## Eight Queens
八皇后：八个皇后放在 8*8 棋盘上，不在同一行同一列以及同一斜线的摆法有多少种？

递归

非递归

***

## Maze

***

## Robot Path Decoding
[2020 B](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc)

给定东南西北四个方向以及行走的步数，问最后的位置。给定步数时会采用 a(...) 表示括号里的指令重复了 a 次。

### 解答

判断出范式 A b(B) C 进行递归。A B C 中均可能空或有括号需要继续进行递归。

***

## Shifts
[2019 G](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e02/000000000018fd5e)

两个保安值守 N 个楼层，每个保安分别选择其中的某些层，要保证每层都有人选。不同的保安值守不同的楼层会有一个开心值。要满足每个保安的值守楼层的开心值之和不低于一个给定值，分配方案有多少种？

**Limits**  
Time limit: 40 seconds per test set.  
Memory limit: 1GB.  
1 ≤ T ≤ 100.  
0 ≤ H ≤ 10^9.  
0 ≤ Ai ≤ 10^9.  
0 ≤ Bi ≤ 10^9.  

Test set 1 (Visible)  
1 ≤ N ≤ 12.  

Test set 2 (Hidden)  
1 ≤ N ≤ 20.  

### 小数据解法
暴力 DFS，枚举所有可能。


***

## Stable Wall
2020 C

***

## Planet Distance

2018 C see [EP04](https://github.com/Baileyswu/NEXT/tree/master/EP04)

***
## Fairies and Witches

2018 C



***
## Milk Tea 

2018 E see [EP06](https://github.com/Baileyswu/NEXT/tree/master/EP06)