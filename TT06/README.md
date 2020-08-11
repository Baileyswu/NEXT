# Greedy / String processing

## 处理字符串

### 模拟乘法
TODO LC 43 

### HASH
TODO LC 49

### Trie
TODO Implement Trie

### 回文字符串

### KMP
[The Knuth-Morris-Pratt Algorithm in my own words](http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/)

TODO template

### Backspace String Compare
[LC 844](https://leetcode-cn.com/problems/backspace-string-compare/) 双指针调节退格模拟栈。

***
## 处理数组

### 删除排好序的数组中重复的数字
双指针
TODO LC 26

### 旋转数组

[1,2,3,4,5,6,7] -> [5,6,7,1,2,3,4]
TODO LC 189

### 是否有重复的数字
TODO LC 217

### 是否有递增的三元组
TODO LC 334

### O(1) 插入删除和随机集合中的值
TODO LC 380
通过 HASH 和数组共同维护。

***

## 排序

Merge Sort 深度为 logN
Quick Sort 跟 pivot 比较分为两段继续递归 
Selection Sort
Insertion Sort
Bubble Sort
Counting Sort
Heap Sort

### 第 K 大的数
TODO LC 215

***
## 贪心

TODO LC 455
TODO LC 435
TODO 2020 Allocation
TODO 2019 Code-Eat Switcher

### Jump Game II
[LC 45](https://leetcode-cn.com/problems/jump-game-ii/) DP 的解法正确但是超时。思考了一下贪心的解法。如何选择下一步？如果走了这步能够使得下下步最远，那就选择这步作为下一步。道理就是：一步领先，步步领先，你无法找到比这个更快的。

### Is Subsequence
[LC 392](https://leetcode-cn.com/problems/is-subsequence/) 双指针贪心匹配。

### Non-overlapping Intervals
[LC 435](https://leetcode-cn.com/problems/non-overlapping-intervals/) 对所有课按照下课时间的先后进行排序。当前面已经排好课，结束时间为 t，轮到第 i 门课，它开始的时间比 t 早，则这门课被舍弃；否则被安排并更新 t。

为什么这样贪心是对的呢？因为已经对下课时间排好序，越先安排的课越早下课。在安排第 i 门课的时候，肯定希望前面几门课下课得越早越好。如果这样都不行，那其他的排序更不行。

## Homework

TODO LC 1438 Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

