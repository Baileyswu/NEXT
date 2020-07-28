#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 105, K = 105, INF = 1e9, C = 1005;
int a[N], dp[N][K], q[C][N];
unordered_set<int> st;
int query(int l, int r) {
    int count = 0;
    for(auto s : st) {
        count = max(count, q[s][r]-(l==0? 0 : q[s][l-1]));
    }
    return r-l+1-count;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        memset(dp, 0, sizeof(dp));
        memset(q, 0, sizeof(q));
        st.clear();
        cin >> n >> k;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        for(int i = 0;i < n;i++)
            for(int c = 0;c < C;c++)
                if(a[i] == c) q[c][i] = i==0 ? 1 : q[c][i-1]+1;
                else q[c][i] = i == 0 ? 0 : q[c][i-1];

        for(int i = 0;i < n;i++) dp[i][0] = query(0, i);
        for(int i = 1;i < n;i++)
            for(int z = 1;z <= k;z++) {
                dp[i][z] = INF;
                for(int j = 0;j < i;j++) {
                    dp[i][z] = min(dp[i][z], dp[j][z-1]+query(j+1, i));
                    // printf("i=%d z=%d j=%d query %d %d %d dp[i][z]=%d\n", i, z, j, j+1, i, query(j+1, i), dp[i][z]);
                }
            }
        printf("Case #%d: %d\n", ++o, dp[n-1][k]);
    }
    return 0;
}
