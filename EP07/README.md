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
可以联想到 2018 Round A 里的 Scrambled Words 的做法。把 A 的各种长度的子串 Hash 编码放入 `unordered_map`，再把 B 的各个长度的子串 Hash 编码放入 `set`。复杂度为 O(L^2).