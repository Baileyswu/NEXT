#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 5e5+10;
int n, pt[N], gap[2], son[2][N];
vector<int> tree[N], path;
double f(double x, double y) {
    return 1-(1-x)*(1-y);
}
void init() {
    path.clear();
    memset(son, 0, sizeof(son));
    for(int i = 0;i < N;i++)
        tree[i].clear();
}
void dfs(int id) {
    // printf("dfs %d\n", id);
    path.push_back(id);
    for(int i = 0;i < tree[id].size();i++) {
        dfs(tree[id][i]);
    }
    path.pop_back();

    for(int i = 0;i < 2;i++) {
        son[i][id]++;
        int pre = path.size() - gap[i];
        if(pre > -1) son[i][path[pre]] += son[i][id];
    }
    // printf("id = %d -- ", id);
    // for(int i = 0;i < path.size();i++)
        // printf("%d%c", path[i], " \n"[i==path.size()-1]);
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        init();
        cin >> n >> gap[0] >> gap[1];
        pt[1] = 1;
        for(int i = 1;i < n;i++) {
            int t;
            cin >> t;
            pt[i+1] = t;
            tree[t].push_back(i+1);
        }
        dfs(1);
        double ans = 0;
        // for(int i = 1;i <= n;i++)
            // printf("%d%c", son[0][i], " \n"[i==n]);
        // for(int i = 1;i <= n;i++)
            // printf("%d%c", son[1][i], " \n"[i==n]);
        for(int i = 1;i <= n;i++) 
            ans += f(1.0*son[0][i]/n, 1.0*son[1][i]/n);
        printf("Case #%d: %.7f\n", ++o, ans);
    }
    return 0;
}