#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
const LL INF = 1e18;
int n, a[N], state[N];
LL dp[N][3];
vector<int> neigh[N];
bool vis[N];
void init() {
    for(int i = 0;i < n;i++)
        neigh[i].clear();
    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));
}
void dfs(int x) {
    vis[x] = true;
    LL delta = -INF;
    for(auto y : neigh[x]) if(!vis[y]) {
        dfs(y);
        dp[x][0] += max(dp[y][0], dp[y][1]);
        dp[x][2] += max(dp[y][0]+a[y], max(dp[y][1], dp[y][2]));

        LL r = max(dp[y][0], max(dp[y][1], dp[y][2]));
        dp[x][1] += r;
        delta = max(delta, -r+dp[y][2]);
    }
    dp[x][1] += a[x] + delta;
    dp[x][2] += a[x];
    // printf("dfs %d: %lld %lld %lld\n", x+1, dp[x][0], dp[x][1], dp[x][2]);
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        init();
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        dfs(0);
        LL ans = -INF;
        for(int i = 0;i < 3;i++)
            ans = max(ans, dp[0][i]);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}
