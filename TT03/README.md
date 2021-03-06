# Search & Recursion 

## Eight Queens
八皇后：八个皇后放在 8*8 棋盘上，不在同一行同一列以及同一斜线的摆法有多少种？

TODO 递归

TODO 非递归

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

两个保安值守 N 个楼层，每个保安分别选择其中的某些层，要保证每层都有人选。不同的保安值守不同的楼层会有一个开心值。要满足每个保安的值守楼层的开心值之和不低于一个给定值 H，分配方案有多少种？

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

剪枝：如果已经达到了 H 的开心值，后面还剩下 j 层，则直接返回 3^j 即可。

### 大数据解法
把楼层分为两部分，前 N/2 层保安的得分为 (p, q)，后 N-N/2 保安的得分为 (x, y). 现在要满足的条件有: x + p >= H, y + q >= H

对于 (p, q) 排序，对于 (x, y) 排序，则对于一个 (p, q) 而言，可以把满足的 x+p >= H 的数对都加入进来，看有哪几个是满足 y+q >= H 的。

问题等价于枚举 

1. 插入 y
2. 问有多少 y >= H-q

这部分可以使用：树状数组，线段树，AVL/红黑树/splay树/treap 等求区间和的数据结构。

又因为 y 的范围会到 1e9 ，要对它做离散化。

### DP 解法
二进制 i 表示出 A 值班的安排，对应位为 1 的楼层为值班，0 为不值班，记 f(i) ；则 0 为 B 必须值班的安排。并且 B 还可以在 A 值班的天数里再选择几天进行值班。现在预处理出所有可能的 B 的排班情况。

先枚举所有可能的二进制状态，其中位为 0 的表示 B 在这天值班。现在要做预处理，使得 B 还可以把一些 1 的子情况加入到其中。

***

## Stable Wall
[2020 C](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb)

给 26 种类型的积木，每次只给 1 个种类的，用完以后可以换一种。问是否可以搭成给出的形状？若可以，给出积木种类的顺序。

### 解答
上面的积木对紧挨着的下面的积木有依赖关系，建立依赖的有向图，按拓扑序输出答案。

***

## Planet Distance

2018 C see [EP04](https://github.com/Baileyswu/NEXT/tree/master/EP04#planet-distance)

***
## Fairies and Witches

2018 C see [EP04](https://github.com/Baileyswu/NEXT/tree/master/EP04#fairies-and-witches)

***
## Milk Tea 

2018 E see [EP06](https://github.com/Baileyswu/NEXT/tree/master/EP06)