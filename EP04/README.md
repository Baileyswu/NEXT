# [2018 Round C](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ee0)

## Planet Distance
在 N 个点 N 条边的图中存在自环，求不在自环上的点离自环的距离。

### 解答
类似拓扑排序，找到度为 1 的点不断删去，直到无法删除为止，剩下的为自环。实际操作中用数组记录度数，-1 即为删边。  
以自环为起点 BFS 计算到其他点的距离。

***

## Kickstart Alarm
给定数组 A，对于 A 中的任意一个子序列，都可以计算 i 阶幂。现在要计算所有子序列的所有阶幂的和。

### 解答
举例 数组大小为 5 时，要计算的为：
```cpp
given i:
a[0] * 5 * (1^i)
a[1] * 4 * (1^i + 2^i)
a[2] * 3 * (1^i + 2^i + 3^i)
a[3] * 2 * (1^i + 2^i + 3^i + 4^i)
a[4] * 1 * (1^i + 2^i + 3^i + 4^i + 5^i)
```
对于括号里的系数，每项关于 i 求和，为等比数列。每行可以利用上一行求得的结果进行计算。

### 等比数列求和
当 $a\neq 1$时，
$$
a^1+a^2+\dots+a^k={a(a^k-1)\over a-1}
$$
别忘记考虑 $a=1$时，答案为 $k$  ╮(╯▽╰)╭

### 求逆元

#### 一般求法
求 a 关于 N 的逆元，即要解同余方程 $ax\equiv 1 (\mod N)$ 的解 x.

$$
ax\equiv 1(\mod N)\Leftrightarrow ax+Ny=1
$$

仅当 a 与 N 互质时，存在 a 的逆元，利用扩展欧几里得求解。
这里**N不必要是素数**
```cpp
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    LL r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
```
```
x = (x % N + N) % N
```

#### 费马小定理求逆元
**当N是素数**，有 $a^{p-1}\equiv 1(\mod p)$，则 $a^{-1}= a^{p-2}\%p$ 

当p比较大时，需要快速幂求解。非递归的写法是坠好的。
```cpp
#define LL long long
LL poo(LL a, int k, int m){
    LL res = 1;
    while(k){
        if(k & 1LL)
            res = res * a % m;
        k >>= 1;
        a = a*a%m;
    }
    return res;
}
```

#### 特殊情况
**当N是质数**，a是(N+1)的约数时，$a^{-1}={N+1\over a}$  
这点也很好理解。当N是质数，0 < a < N时，$(a,N)=1$，则 a 肯定存在逆元。  
而解出的 ${N+1\over a}$ 就满足 ${N+1\over a}·a\equiv 1(\mod N)$，故它是a的逆元。  

在[CF 696C](http://codeforces.com/problemset/problem/696/C)，$N=1000000007时$,
$$
2^{-1}={1000000007+1\over 2}=500000004$$
$$3^{-1}={1000000007+1\over 3}=333333336
$$

求解就灰常方便了...

#### 逆元打表
如果是求好多数的逆元，还是打个表比较方便，只要 O(N) 的复杂度。  
**当N是大素数**，求小于N的数的逆元。  
设这个数是$i，令P=it+k，其中t=i/N,~k=i\%N$  
则 $it\equiv -k(\mod P)$ 且 $i^2t^2\equiv k^2(\mod P)$  
令 $i$ 的逆元是 $i^{-1}$，有两种方法求 $i^{-1}$:

1. $i^{-1}\equiv -t·k^{-1}\equiv (P-t)k^{-1}\%P$
2. $i^{-1}\equiv it^2(k^{-1})^2\%P$

都是通过先求 $k^{-1}$ 来求 $i^{-1}$，两者结果都是一样的，别忘模 P 即可。注意：计算过程中可能会爆 `long long`。
```cpp
int rev[N];
void get_rev(){
	rev[1] = 1;
	for(int n = 2;n < N;n++){
		int k = P % n, t = P / n;
		rev[n] = 1LL*(P-t)*rev[k]%P;
	}
}
```