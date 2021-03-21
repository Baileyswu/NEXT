#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 510;
int a[N][N], b[N][N], R[N], C[N], p[N*2];
struct node{
    int x, y, v;
    node(){}
    node(int x, int y, int v): x(x), y(y), v(v) {}  
};
bool operator < (const node &a, const node&b) {
    return a.v < b.v;
}
priority_queue<node> Q;

int find(int x) {
    if(x == p[x]) return p[x];
    return p[x] = find(p[x]);
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        LL ans = 0;
        cin >> n;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) {
                cin >> a[i][j];
            }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) {
                cin >> b[i][j];
            }
        for(int i = 0;i < n;i++) cin >> R[i];
        for(int i = 0;i < n;i++) cin >> C[i];

        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) if(a[i][j] == -1) {
                Q.push(node(i, j+n, b[i][j]));
                ans += b[i][j];
            }

        for(int i = 0;i < (n<<1);i++) {
            p[i] = i;
        }

        while(!Q.empty()) {
            auto ft = Q.top(); Q.pop();
            int x = ft.x, y = ft.y, v = ft.v;
            // printf("x=%d y=%d v=%d\n", x, y, v);
            p[x] = find(x);
            p[y] = find(y);
            if(p[p[x]] != p[y]) {
                p[p[x]] = p[y];
                ans -= v;
            }
        }
        printf("Case #%d: %lld\n", ++o, ans);            
    }
    return 0;
}
