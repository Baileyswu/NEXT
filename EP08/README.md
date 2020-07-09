# [2018 Round G](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051066)

## Product Triplets
给 N 个数字，求出其中满足条件的三元组的数目。  
条件为：其中一个数字等于其他两个数字的乘积。

Large dataset (Test set 2 - Hidden)  
3 ≤ N ≤ 7000.  

### 解答
枚举其中的两个数字（不为 0 或 1），查找乘积是否存在，有几个。  
特判：  
0 * 0 = 0  
0 * x = 0 (x > 0)  
1 * 1 = 1  
1 * x = x (x > 1)  

### Hack 数据
inputs
```cpp
2
6
0 0 0 1 1 1
6
0 0 1 1 2 2
```

outputs
```cpp
Case #1: 11
Case #2: 6
```

***

## Combining Classes
有 N 个班级的成绩，每个班的成绩区间为 [Li, Ri]，(Ri-Li+1) 个学生每人一个不同的分数。现在把所有学生的成绩排序，询问第 K 高的分数的总和。  

**Limits**  
1 ≤ N ≤ 4 × 10^5.  
Li Ri 是由构造函数生成的，最大可能为 10^9  
询问数最多有 10^5 次。  

## 解答
学生的数目非常大，直接统计每个分数的个数太困难。但是每次会给一个区间，这个区间上的所有分数都对应着一个学生。因此可以线段离散化，只记录端点并排序。  
区间处理成左闭右开的区间，即 [Li, Ri + 1)