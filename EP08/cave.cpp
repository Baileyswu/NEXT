#include <bits/stdc++.h>
using namespace std;
const int OBS = -100000;
int a[105][105];
int tid[105][105];
int dp[4][2] = {
    1,0,-1,0,0,1,0,-1
};
bool used[1<<16];
vector<pair<int, int>> trap;
int main() {
    int bits[16] = {1};
    for(int i = 1;i < 16;i++)
        bits[i] = 1<<i;
    
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m, E, sx, sy, tx, ty;
        memset(tid, -1, sizeof(tid));
        trap.clear();
        cin >> n >> m >> E >> sx >> sy >> tx >> ty;
        sx--; sy--; tx--; ty--;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) {
                cin >> a[i][j];
                if (a[i][j] < 0 && a[i][j] > OBS) {
                    trap.push_back(make_pair(i, j));
                    tid[i][j] = trap.size() - 1;
                }
            }
        
        int ans = -1;
        queue<int> tpq;
        memset(used, false, sizeof(used));
        tpq.push(0);
        used[0] = true;
        while(!tpq.empty()) {
            int tp = tpq.front(); tpq.pop();
            int mp[105][105];
            int cur = E;
            memcpy(mp, a, sizeof(a));
            for(int i = 0;i < trap.size();i++)
                if(tp & bits[i]) {
                    cur += mp[trap[i].first][trap[i].second];
                    mp[trap[i].first][trap[i].second] = 0;
                }

            // printf("\ntp = %d\n", tp);
            // for(int i = 0;i < n;i++)
            //     for(int j = 0;j < m;j++) {
            //         if(mp[i][j] != OBS) printf("%4d%c", mp[i][j], " \n"[j==m-1]);
            //         else printf(" ## %c", " \n"[j==m-1]);
            //     }
            
            queue<pair<int, int>> q;
            set<int> future;
            bool vis[105][105];
            memset(vis, 0, sizeof(vis));
            q.push(make_pair(sx, sy));
            vis[sx][sy] = true;
            while(!q.empty()) {
                auto c = q.front(); q.pop();
                int x = c.first, y = c.second;
                // printf("(%d, %d)", x, y);
                for(int i = 0;i < 4;i++) {
                    int ux = x + dp[i][0], uy = y + dp[i][1];
                    if(ux < 0 || ux >= n || uy < 0 || uy >= m || vis[ux][uy])
                        continue;
                    vis[ux][uy] = true;
                    if(mp[ux][uy] == OBS)
                        continue;
                    if(mp[ux][uy] >= 0) {
                        cur += mp[ux][uy];
                        q.push(make_pair(ux, uy));
                        continue;
                    }
                    future.insert(tid[ux][uy]);
                }
            }
            if(vis[tx][ty]) ans = max(ans, cur);
            for(auto f : future) {
                int next_trap_map = tp | bits[f];
                if (!used[next_trap_map] && cur + mp[trap[f].first][trap[f].second] >= 0) {
                    tpq.push(next_trap_map);
                    used[next_trap_map] = true;
                }
            }
            // printf("cur = %d\n", cur);
        }
        
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}