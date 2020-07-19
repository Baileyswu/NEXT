#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 20;
int a[N][N], n;
bool vis[N];
LL dfs(int id, int p, int m, int sum) {
    if(id == n) return p >= 3 && sum > 2*m;
    LL ret = dfs(id+1, p, m, sum);
    if(!vis[id]) for(int j = id+1;j < n;j++) if(!vis[j] && a[id][j]) {
        vis[id] = true;
        vis[j] = true;
        ret += dfs(id+1, p+1, max(m, a[id][j]), sum+a[id][j]);
        vis[id] = false;
        vis[j] = false;
    }
    return ret;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        memset(vis, false, sizeof(vis));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                cin >> a[i][j];
        LL ans = dfs(0, 0, 0, 0);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}