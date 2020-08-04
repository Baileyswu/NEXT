# Data Structure

## Array

数组：连续的一段空间  
链表：用指针链接 node

常用技巧：

双指针   
滑动窗口  
前缀和

### 2sum

虽然是 Leetcode 的第一题，通过的姿势很多。但是这题的想法影响了下面的 3sum。

先对数组排序，用双指针分别指向头和尾再进行判断和移动。

### 3sum

[LC 15](https://leetcode-cn.com/problems/3sum/) 指定第一个数作为 2sum 的 target，同理进行移动。

### Reorder List
[LC 143](https://leetcode-cn.com/problems/reorder-list/) 用快慢指针找到中点位置折断，后半段 reverse，再将两段 merge。

***
## Stack

先进后出

常用技巧：

单调栈

### 最大矩形

[LC 84](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) 维持一个递增的单调队列是比较容易的。每个在队列里的值，即矩形的高度。唯一要确定的是这个矩形的左边界和右边界。如果能够直接被 push 进栈，则代表这个高度第一次出现，即是左边界。如果要先 pop 出一堆比它大的高度，再 push 进栈，则表示最后 pop 的位置才是它的左边界。右边界相对而言更好确定，即为了谁而 pop，谁的位置就是被 pop 高度的右边界。

为了最后可以清空整个栈，特意在高度数组加了一个元素 0 上去。另外为了保证这个栈是非空的，又在底部塞了一个 -1. 这样可以少写几行代码。

### 字符串解码

[LC 394](https://leetcode-cn.com/problems/decode-string/) 同 TT03 递归的 [Robot Path Decoding](https://github.com/Baileyswu/NEXT/tree/master/TT03#robot-path-decoding) 是一个道理。这里用栈模拟了加法（字符串拼接）和乘法（字符串重复）。

### 删除字符串中的所有相邻重复项

[LC 1209](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/) 可以依次把字符以及连续出现的次数放入栈中，如果到达 K 次则对栈进行一次清理操作。这样逐步计算可以得到最后的结果。

***

## Queue

前进先出

常用技巧：

双端队列，双向搜索  

### TODO 开转盘锁
LC 752

***

## Heap

大顶堆，小顶堆，优先队列

### TODO Workout
2020 A 

***

## Set

没有重复元素

交并差

***

## Hash

解决冲突：找下一个，或 Chaining

***

## Bit Manipulation

& | ^ ~ << >>

常用技巧：  
奇数     x&1  
double   x<<1  
2 的幂次 x&&(!(x&(x-1)))  

### TODO X or What
2019 D

***

## Tree

二叉树，遍历，LCA，递归

### Maximum Binary Tree

[LC 654](https://leetcode-cn.com/problems/maximum-binary-tree/) 用了之前 [Locked doors](https://github.com/Baileyswu/NEXT/tree/master/EP2020D#locked-doors) 中构造笛卡尔树的方法。复杂度为 O(n).

***

## Trie

字典树

### TODO Building

2020 A

***

## Segment Tree & Binary Indexed Tree

线段树区间查询。
```cpp
int getSum(node, l, r) {
    if range of the node is within [l, r) 
        return value in the node
    if range of the node is completely outside [l, r)
        return 0
    return getSum(node->left, l, r) + 
           getSum(node->right, l, r)
}
```

树状数组: 下标从 1 开始  
单点修改：父节点求法 `x = x + lowbit(x)`  
查询：父节点的前一个儿子 `x = x - lowbit(x)`

### H-index
[2019 H](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd/00000000001a274e) 

H-index 是指引用数超过 x 次的文章有 x 篇时，最大的 x。现在某人每年都会发一篇论文且有引用数，求每年的 H-index.

#### 思路

用标记数组记录引用数为 i 的论文有 a[i] 篇，那么可以求出引用数 <= i 的论文的篇数即为 a[i] 的前缀和。总的篇数减去前缀和，即为引用数过 i 的篇数，即 i 可能是一个 H-index. 要求最大的 i 才是 H-index，因此可以二分得到这个值。

由于每年都会加论文，这个前缀和需要不断被更新，因此使用树状数组进行单点更新，单点查询。

### Shifts

[2019 G](https://github.com/Baileyswu/NEXT/tree/master/TT03#shifts) 的大数据解法。

***

## Graph
存储方式：邻接表或邻接矩阵  
有向图，无向图，图上搜索  
最短路，最小生成树  
拓扑排序  

### 有向图 DFS

[LC 1462](https://leetcode-cn.com/problems/course-schedule-iv/) 记忆化搜索做的。
