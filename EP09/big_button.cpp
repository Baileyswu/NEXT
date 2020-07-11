#include <bits/stdc++.h>
using namespace std;
#define N 110
#define LL long long
bool is_sub(string a, string b) {
    if(a.length() > b.length()) return false;
    for(int i = 0;i < a.length();i++)
        if(a[i] != b[i]) return false;
    return true;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, p;
        cin >> n >> p;
        
        vector<string> ban;
        bool flag[N];
        memset(flag, false, sizeof(flag));
        for(int i = 0;i < p;i++) {
            string s;
            cin >> s;
            ban.push_back(s);
        }
        sort(ban.begin(), ban.end());

        for(int i = 0;i < p;i++)
            for(int j = i+1;j < p;j++) if(!flag[j]){
                flag[j] = is_sub(ban[i], ban[j]);
                if(!flag[j]) break;
            }
        
        // for(int i = 0;i < p;i++)
        //     cout << flag[i] << " " << ban[i] << endl;
        
        LL ans = 0;
        for(int i = 0;i < p;i++) if (!flag[i]) {
            ans += 1LL<<(n-ban[i].size());
        }
        ans = (1LL<<n) - ans;
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}