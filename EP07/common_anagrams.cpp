#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const ULL HS = 52;
ULL hash_map(int len, int fre[]) {
    ULL res = len;
    for(int i = 0;i < 26;i++)
        res = res * HS + fre[i];
    return res;
}
int main(){
    int T, o = 0;
    cin >> T;
    while(T--) {
        int L;
        string a, b;
        cin >> L >> a >> b;

        unordered_map<ULL, int> keys;
        int f[26];
        for(int i = 0;i < L;i++) {
            memset(f, 0, sizeof(f));
            for(int j = i;j < L;j++) {
                f[a[j]-'A']++;
                ULL hn = hash_map(i-j+1, f);
                if(keys.find(hn) != keys.end()) keys[hn]++;
                else keys[hn] = 1;
            }
        }

        set<ULL> bs;
        for(int i = 0;i < L;i++) {
            memset(f, 0, sizeof(f));
            for(int j = i;j < L;j++) {
                f[b[j]-'A']++;
                ULL hn = hash_map(i-j+1, f);
                bs.insert(hn);
            }
        }

        int ans = 0;
        for(auto kp : keys) {
            if(bs.find(kp.first) != bs.end()) {
                ans += kp.second;
                bs.erase(kp.first);
            }
        }
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}