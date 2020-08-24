#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
int p[N];
int findParent(int x) {
    if(x == p[x]) return x;
    return p[x] = findParent(p[x]);
}
bool inSameSet(int x, int y) {
    findParent(x);
    findParent(y);
    return p[x] == p[y];
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int black_num = 0;
        for(int i = 0;i < n;i++) p[i] = i;
        for(int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(!inSameSet(u, v)) {
                black_num++;
                p[p[u]] = p[v];
            }
        }
        int ans = black_num + 2 * (n-1-black_num);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
