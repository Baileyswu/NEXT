#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
vector<int> mp[N];
bool vis[N];
void dfs(int x, int &d) {
    vis[x] = true;
    // cout << x+1 << " " << d << endl;
    for(auto y : mp[x]) if(!vis[y]) {
        d++;
        dfs(y, d);
    }
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int black_num = 0;
        for(int i = 0;i < n;i++) mp[i].clear();
        memset(vis, false, sizeof(vis));
        for(int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(int i = 0;i < n;i++) if(!vis[i])
            dfs(i, black_num);

        int ans = black_num + 2 * (n-1-black_num);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
