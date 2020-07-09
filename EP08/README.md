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

