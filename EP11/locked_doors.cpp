#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
const int INF = 1e9;
int n, root;
int a[N], ld[N], rd[N], pt[N], sum[N];
bool vis[N];
vector<int> v, open, path;
void pr(int a[], int l, int r) {
    for(int i = l; i<=r;i++)
        printf("%2d%c", a[i], " \n"[i==r]);
}
int run(int s, int pos) {
    // printf("\nrun %d ", s);
    int l = s, r = s, ret = s;
    while(--pos) {
        // printf("[%d, %d]", a[l-1], a[r]);
        if(a[l-1] < a[r]) {
            l--;
            ret = l;
        } else if(a[l-1] > a[r]) {
            r++;
            ret = r;
        }
        // printf("(%d) ", ret);
    }
    return ret;
}
int open_door(vector<int> door, vector<int> path, int x) {
    // printf("open %d-th door\n", x);
    int id = 0;
    for(int i = path.size()-1;i >= 0;i--) 
        if(path[i] <= x) {
            id = i;
            break;
        }
    if (x == path[id]) return door[id];
    int k = door[id+1] - door[id] > 0 ? 1 : -1;
    return door[id] + (x - path[id]) * k;
}
int find(int s, int k) {
    // printf("find %d %d\n", s, k);
    memset(vis, false, sizeof(vis));
    open.clear();
    path.clear();
    int x = a[s-1] < a[s] ? s-1: s;
    if (k == 1) return s;
    if (k == 2) return x^(x+1)^s;
    open.push_back(x);
    path.push_back(1);
    while(!vis[x] && path.back() < k) {
        // printf("x=%d -> %d\n", x, pt[x]);
        vis[x] = true;
        if(ld[x] && !vis[ld[x]]) {
            open.push_back(x-sum[ld[x]]);
            path.push_back(path.back() + sum[ld[x]]);
        } else if(rd[x] && !vis[rd[x]]) {
            open.push_back(x+sum[rd[x]]);
            path.push_back(path.back() + sum[rd[x]]);
        } 
        open.push_back(pt[x]);
        path.push_back(path.back() + 1);
        x = pt[x];
    }
    // for(auto i : path) printf("%2d ", i); cout << endl;
    // for(auto i : open) printf("%2d ", i); cout << endl;
    // for(auto i : open) printf("%2d ", a[i]); cout << endl;
    int u = open_door(open, path, k-2);
    int v = open_door(open, path, k-1);
    // printf("%d %d, %d %d", u, a[u], v, a[v]);
    return u < v ? v + 1 : v;
}
void prepare() {
    memset(ld, 0, sizeof(ld));
    memset(rd, 0, sizeof(rd));

    v.clear();
    v.push_back(0);
    for(int i = 1;i < n;i++) {
        while(a[i] > a[v.back()]) v.pop_back();
        ld[i] = v.back();
        v.push_back(i);
    }

    v.clear();
    v.push_back(n);
    for(int i = n-1;i > 0;i--) {
        while(a[i] > a[v.back()]) v.pop_back();
        rd[i] = v.back();
        v.push_back(i);
    }

    for(int i = 1;i < n;i++) {
        pt[i] = a[ld[i]] <= a[rd[i]] ? ld[i] : rd[i]; 
    }
    pt[root] = root;

    // for(int i = 0;i <= n;i++)
    //     sum[i] = i;
    // pr(sum, 1, n-1);
    // pr(a, 1, n-1);
    // printf("==============\n");
    // pr(ld, 1, n-1);
    // pr(rd, 1, n-1);
    // printf("==============\n");

    memset(ld, 0, sizeof(ld));
    memset(rd, 0, sizeof(rd));
    for(int i = 1;i < n;i++) {
        if(i < pt[i]) ld[pt[i]] = i;
        else rd[pt[i]] = i;
    }

    // pr(pt, 1, n-1);
    // pr(ld, 1, n-1);
    // pr(rd, 1, n-1);
}
int dfs(int x) {
    if(vis[x]) return sum[x];
    vis[x] = true;
    int ls = ld[x] == 0 ? 0 : dfs(ld[x]);
    int rs = rd[x] == 0 ? 0 : dfs(rd[x]);
    return sum[x] = ls + rs + 1;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        printf("Case #%d:", ++o);
        int q;
        cin >> n >> q;
        a[0] = a[n] = INF;
        root = 1;
        for(int i = 1;i < n;i++) {
            cin >> a[i];
            if(a[i] > a[root]) root = i;
        }
        prepare();
        memset(sum, 0, sizeof(sum));
        memset(vis, false, sizeof(vis));
        dfs(root);
        // pr(sum, 1, n-1);
        for(int i = 0;i < q;i++) {
            int u, v;
            cin >> u >> v;
            int s = find(u, v);
            cout << " " << s;
            // assert(run(u,v) == s);
        }
        cout << endl;
    }
    return 0;
}