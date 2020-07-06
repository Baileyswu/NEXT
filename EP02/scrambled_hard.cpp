#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int HSEED = 23333;
#define LL long long
#define ULL unsigned long long

ULL hash_map(char s, char t, int k[]) {
    ULL res = 0;
    res = s*HSEED + t;
    for(int i = 0;i < 26;i++) {
        res = res*HSEED + k[i];
    }
    return res;
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int dsize;
        cin >> dsize;

        vector<string> dict;
        for(int i = 0;i < dsize;i++){
            string str;
            cin >> str;
            dict.push_back(str);
        }

        string s1, s2, s;
        int n;
        LL A, B, C, D;
        cin >> s1 >> s2 >> n >> A >> B >> C >> D;
        s = s1 + s2;

        vector<int> x;
        x.push_back(s[0]);
        x.push_back(s[1]);
        for(int i = 2;i < n;i++) {
            x.push_back((A*x[i-1] + B*x[i-2] + C) % D);
            s += x[i] % 26 + 'a';
        }
        // cout << s << endl;

        int letter[26];
        set<int> lenset;
        unordered_map<ULL, int> mp;
        for(int i = 0;i < dsize;i++){
            memset(letter, 0, sizeof(letter));
            lenset.insert(dict[i].length());
            for(int j = 0;j < dict[i].length();j++) letter[dict[i][j]-'a']++;
            ULL dn = hash_map(dict[i][0], dict[i][dict[i].length()-1], letter);
            if(mp.find(dn) != mp.end())
                mp[dn]++;
            else
                mp[dn] = 1;   
            // cout << dict[i] << " " << dn << endl;         
        }
        // cout << " ================= \n";

        int ans = 0;
        for(auto ilen = lenset.begin(); ilen != lenset.end(); ilen++) {
            int len = *ilen;
            memset(letter, 0, sizeof(letter));
            if (len > s.length()) continue;
            for(int i = 0;i < len;i++) {
                letter[s[i]-'a']++;
            }
            for(int l = 0; l + len <= s.length();l++) {
                ULL hash_num = hash_map(s[l], s[l+len-1], letter);
                // cout << s.substr(l, len) << " " << hash_num << endl;
                if(mp.find(hash_num) != mp.end()) {
                    ans += mp[hash_num];
                    mp.erase(hash_num);
                }
                letter[s[l]-'a']--;
                if(l+len < s.length()) letter[s[l+len]-'a']++;
            }
        }
        printf("Case #%d: %d\n", ++o, ans);
    }

    return 0;
}