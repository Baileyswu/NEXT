# [2018 Round F](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e07)

## Common Anagrams
有两个字符串各长 L.  
问字符串 A 中有多少个子串与 B 中的字串相似。  
相似：一个字符串打乱以后可以变成另一个字符串，如 abbc 和 bcab.  
注：不同位置的子串即使内容一样也视为不同的子串。

**Limits**   
1 ≤ T ≤ 100.  
Time limit: 20 seconds per test set.  
Memory limit: 1 GB.  
1 ≤ L ≤ 50.  

### 解答
L 挺小的，可以枚举出所有的子串进行排序，再进行比较。  
可以联想到 2018 Round A 里的 Scrambled Words 的做法进行优化。把 A 的各种长度的子串 Hash 编码放入 `unordered_map`，再把 B 的各个长度的子串 Hash 编码放入 `set`。复杂度为 O(L^2).

***

## Specializing Villages
有 V 个村庄和 E 条路。每个村庄可以规划生产水果或蔬菜中的一种。生产水果的村庄会前往最近的生产蔬菜的村庄获取蔬菜，反之亦然。要使得各个村庄获取所需物资平均路程最短，可以有几种规划生产的方案？  
注：所给无向图中没有重边，每条边的长度都不一样。

1 ≤ T ≤ 100.  
Time limit: 20 seconds per test set.  
Memory limit: 1 GB.  
1 ≤ E ≤ min(1000, V * (V - 1) / 2).  
0 ≤ Li ≤ 105, for all i.  
Li ≠ Lj for all i ≠ j.  
1 ≤ Ai < Bi ≤ V, for all i.  
(Ai, Bi) ≠ (Aj, Bj) for all i ≠ j.  

### 解答
每个连通分量中的情况相互独立，服从乘法原理。  
最优方案（平均距离最短）必定会让每个村庄从相邻最近的村庄索取物资。  
由于每条边都不相等，在索取子图中不会形成环。因此索取图是一棵树。  
如果其中没有长度为 0 的边，会以交替的方式逐层选取水果或蔬菜。方案数为 2.  
如果其中有长度为 0 的边，说明两个村庄可以合体生产水果和蔬菜，其他与这两个村庄相邻的村庄可以任意选择生产水果或蔬菜。方案数量在原来的基础上 \*2.