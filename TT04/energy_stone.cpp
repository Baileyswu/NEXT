#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 105, TM = 105*105;
int dp[TM];
struct energy_st
{
    int s, e, l;
    energy_st(){}
    energy_st(int s, int e, int l) : s(s), e(e), l(l) {}
    bool operator<(const energy_st &b) {
        return s*b.l < b.s*l;
    }
    friend ostream &operator<<(ostream &out, energy_st a);
}st[N];

ostream &operator<<(ostream &out, energy_st a) {
    out << a.s << " " << a.e << " " << a.l;
    return out;
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++) {
            int s, e, l;
            cin >> s >> e >> l;
            st[i] = energy_st(s, e, l);
        }
        sort(st, st+n);
        // for(int i = 0;i < n;i++) cout << st[i] << endl;
        
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < n;i++) {
            for(int j = TM-1;j-st[i].s >= 0;j--) {
                int left = max(0, st[i].e-(j-st[i].s)*st[i].l);
                dp[j] = max(dp[j], dp[j-st[i].s]+left);
            }
        }
        
        int ans = 0;
        for(int i = 0;i < TM;i++) ans = max(ans, dp[i]);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
