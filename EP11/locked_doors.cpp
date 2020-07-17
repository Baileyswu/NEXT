#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
const int INF = 1e9;
const int P = 18;
int n, root;
int a[N], ld[N], rd[N], pt[N][P], sum[N], id[N];
bool vis[N];
vector<int> v;
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
int find(int s, int k) {
    printf("\nfind %d %d\n", s, k);
    memset(vis, false, sizeof(vis));
    int x = a[s-1] < a[s] ? s-1: s;
    if (k == 1) return s;
    if (k == 2) return x^(x+1)^s;
    k--;
    if(sum[x] >= k) return ld[x] ? x+1-k : x+k;

    int gap = P;
    int l = x, r = root, m;
    while(gap >= 0) {
        while(gap >= 0 && (m = pt[l][gap--]) == 0);
        if(sum[m] < k) l = m;
        else r = m;
    }
    if(r < x) cout << "r < x ";
    else cout << "r >=x ";
    printf("x=%d k=%d {%d %d %d} {%d %d %d}\n", x, k, l, a[l], sum[l], r, a[r], sum[r]);
    return r <= x ? r+1-(k-sum[rd[r]]) : r+(k-sum[ld[r]]);
}
int dfs(int x) {
    if(vis[x]) return sum[x];
    vis[x] = true;
    int ls = ld[x] == 0 ? 0 : dfs(ld[x]);
    int rs = rd[x] == 0 ? 0 : dfs(rd[x]);
    for(int i = 1;(1<<i) < n;i++)
        pt[x][i] = pt[pt[x][i-1]][i-1];
    return sum[x] = ls + rs + 1;
}
void prepare() {
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
        pt[i][0] = a[ld[i]] <= a[rd[i]] ? ld[i] : rd[i]; 
    }
    pt[root][0] = root;

    for(int i = 0;i <= n;i++)
        id[i] = i;
    pr(id, 1, n-1);
    pr(a, 1, n-1);
    printf("==============\n");
    pr(ld, 1, n-1);
    pr(rd, 1, n-1);
    printf("==============\n");

    for(int i = 1;i < n;i++) {
        if(i < pt[i][0]) ld[pt[i][0]] = i;
        else rd[pt[i][0]] = i;
    }
    dfs(root);

    pr(ld, 1, n-1);
    pr(rd, 1, n-1);
    printf("==============\n");
    pr(sum, 1, n-1);

}
void init() {
    memset(pt, 0, sizeof(pt));
    memset(vis, false, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    memset(ld, 0, sizeof(ld));
    memset(rd, 0, sizeof(rd));
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        init();
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
        
        for(int i = 0;i < q;i++) {
            int u, v;
            cin >> u >> v;
            int s = find(u, v);
            cout << " " << s;
            int t = run(u, v);
            printf("[%d]", t);
            // assert(s == t);
        }
        cout << endl;
    }
    return 0;
}