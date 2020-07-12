#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 1e5+10;
const int INF = 1e9;
int n, q;
int a[N], len[N];
bool used[N];
vector<pair<int, int>> ques;
map<int, int> ans[N];
vector<int> order;
struct UF
{
    int p[N];
    void init() {
        memset(p, -1, sizeof(p));
    }
    int find(int x) {
        if(p[x] == -1 || p[x] == x)
            return x;
        return p[x] = find(p[x]);
    } 
    int join(int x, int y) {
        int px = find(x);
        int py = find(y);
        return p[px] = py; // p[px] = p[py] is wrong util p[x] = x as initialization
    }
}l, r;

void update(int id) {
    l.join(id, id-1);
    r.join(id, id+1);
}

void go(int &id) {
    update(id);
    int tol = l.find(id);
    int tor = r.find(id);
    if(tol != 0 && a[tol] < a[tor-1]) {
        l.join(id, tol);
        id = tol;
    } else if(tor != n+1 && a[tol] > a[tor-1]) {
        r.join(id, tor);
        id = tor;
    }
}

void prepare(int start) {
    // cout << "prepare " << start << endl;
    l.init();
    r.init();
    order.clear();
    order.push_back(start);
    int vn = len[start];
    while(--vn) {
        go(start);
        order.push_back(start);
    }

    // for(int i = 0;i < order.size();i++)
    //     cout << order[i] << " ";
    // cout << endl;
}
void init() {
    ques.clear();
    memset(len, 0, sizeof(len));
    for(int i = 0;i < N;i++)
        ans[i].clear();
    memset(used, false, sizeof(used));
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        printf("Case #%d:", ++o);
        // cout << endl;
        init();

        cin >> n >> q;
        a[0] = a[n] = INF;
        for(int i = 0;i < n-1;i++) {
            cin >> a[i+1];
        }
        for(int i = 0;i < q;i++) {
            int u, v;
            cin >> u >> v;
            ques.push_back(make_pair(u, v));
            ans[u][v] = -1;
            len[u] = max(len[u], v);
        }
        for(auto qs : ques) {
            if(used[qs.first]) continue;
            prepare(qs.first);
            for(auto as : ans[qs.first]) {
                ans[qs.first][as.first] = order[as.first-1];
            }
            used[qs.first] = true;
        }
        for(auto qs : ques) {
            printf(" %d", ans[qs.first][qs.second]);
        }
        printf("\n");
    }
    return 0;
}