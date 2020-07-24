#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 105, TM = 1e5;
int S[N], E[N], L[N];
int dp[TM];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> S[i] >> E[i] >> L[i];
        memset(dp, 0, sizeof(0));
        for(int i = 0;i < n;i++) {
            for(int j = TM-1;j-S[i] >= 0;j--) {
                dp[j] = max(dp[j], dp[j-S[i]]+max(0, E[i]-(j-S[i])*L[i]));
            }
        }
        int ans = 0;
        for(int i = 0;i < TM;i++) {
            ans = max(ans, dp[i]);
        }
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
