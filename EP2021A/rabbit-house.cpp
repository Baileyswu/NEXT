#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 310;
int a[N][N];
bool vis[N][N];
int dp[4][2] = {
    -1, 0, 1, 0, 0, -1, 0, 1
};
struct node{
    int x, y, h;
    node(){}
    node(int x, int y, int h): x(x), y(y), h(h) {}
};
bool operator < (const node &a, const node &b) {
    return a.h < b.h;
}
priority_queue<node> Q;
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m;
        LL ans = 0;
        cin >> n >> m;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) {
                cin >> a[i][j];
                Q.push(node(i, j, a[i][j]));
            }
        memset(vis, false, sizeof(vis));
        while(!Q.empty()) {
            auto ft = Q.top(); Q.pop();
            int x = ft.x, y = ft.y, h = ft.h;
            if(vis[x][y]) continue;
            vis[x][y] = true;
            // printf("x=%d y=%d h=%d\n", x, y, h);
            for(int k = 0;k < 4;k++) {
                int tx = x + dp[k][0];
                int ty = y + dp[k][1];
                if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if(!vis[tx][ty]) {
                    int delta = h - a[tx][ty];
                    if(delta > 1) {
                        ans += delta - 1;
                        a[tx][ty] += delta - 1;
                    }
                    Q.push(node(tx, ty, a[tx][ty]));
                }
            }
        }
        printf("Case #%d: %lld\n", ++o, ans);            
    }
    return 0;
}
