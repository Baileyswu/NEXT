#include <bits/stdc++.h>
using namespace std;
#define N 1010
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        printf("Case #%d:", ++o);
        int n;
        cin >> n;
        vector<int> g[N];
        queue<int> q;
        int dis[N], degree[N];
        memset(dis, 0, sizeof(dis));
        memset(degree, 0, sizeof(degree));

        for(int i = 0;i < n;i++) {
            int u, v;
            cin >> u >> v;
            g[u-1].push_back(v-1);
            g[v-1].push_back(u-1);
        }

        for(int i = 0;i < n;i++) {
            degree[i] = g[i].size();
            if(degree[i] == 1)
                q.push(i);
        }
        while(!q.empty()) {
            int s = q.front(); q.pop();
            dis[s] = -1;
            for(int i = 0;i < g[s].size();i++) {
                int t = g[s][i];
                degree[t]--;
                if(degree[t] == 1)
                    q.push(t);
            }
        }

        for(int i = 0;i < n;i++)
            if(dis[i] == 0)
                q.push(i);
        while(!q.empty()) {
            int s = q.front(); q.pop();
            for(int i = 0;i < g[s].size();i++) {
                int t = g[s][i];
                if(dis[t] == -1) {
                    dis[t] = dis[s] + 1;
                    q.push(t);
                }
            }
        }
        
        for(int i = 0;i < n;i++)
            printf(" %d", dis[i]);
        printf("\n");
    }
    return 0;
}