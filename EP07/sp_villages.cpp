#include <bits/stdc++.h>
using namespace std;
#define N 55
#define LL long long
vector< pair<int, int>> g[N];
bool vis[N];
void dfs(int id) {
    vis[id] = true;
    for(int i = 0;i < g[id].size();i++) {
        int v = g[id][i].first;
        if(!vis[v]) dfs(v);
    }
}
void update(int u, int v, int e) {
    if(g[u].size() < 1) {
        g[u].push_back(make_pair(v, e));
    } else if(g[u][0].second > e)
        g[u][0] = make_pair(v, e);
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;

        for(int i = 0;i < n;i++)
            g[i].clear();
        for(int i = 0;i < m;i++) {
            int u, v, e;
            cin >> u >> v >> e;
            u--; v--;
            update(u, v, e);
            update(v, u, e);
        }

        unordered_set< int> zeros;
        for(int i = 0;i < n;i++) if (g[i].size()) {
            int v = g[i][0].first;
            int e = g[i][0].second;
            if (g[i][0].second != g[v][0].second)
                g[v].push_back(make_pair(i, e));
            if (e == 0) {
                zeros.insert(i);
                zeros.insert(v);
            }
        }

        int part = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 0;i < n;i++) if(!vis[i]){
            dfs(i);
            part++;
        }

        int to_zeros = 0;
        if(zeros.size()) 
            for(int i = 0;i < n;i++) if (g[i].size()) {
                int v = g[i][0].first;
                if (zeros.find(i) == zeros.end() && zeros.find(v) != zeros.end())
                    to_zeros++;
            }
        
        // cout << part << " " << to_zeros << endl;

        LL ans = 1LL << (part + to_zeros);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}