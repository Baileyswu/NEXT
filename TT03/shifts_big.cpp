#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 21, M = 1e5;
LL a[N], b[N], H, id[M], c[M];
int n, tot;
vector< pair<LL, LL> > va, vb;
map<LL, int> mp;

int lowbit(int x) {
    return x & -x;
}

void insert(int x, int y) {
    while(x <= tot) {
        c[x] += y;
        x += lowbit(x);
    }
}

LL query(int x) {
    int ret = 0;
    while(x > 0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

LL work() {
    int sa = va.size(), sb = vb.size();
    int i = 0, j = sb-1;
    LL ret = 0, sum = 0;
    while(i < sa && j >= 0) {
        if(va[i].first + vb[j].first >= H) {
            insert(mp[vb[j].second], 1);
            sum++;
            j--;
        } else {
            int pos = lower_bound(id, id+tot, H-va[i].second) - id;
            if(pos != tot)
                ret += sum - query(mp[id[pos]]-1);
            i++;
        }
    }
    while(i < sa) {
        int pos = lower_bound(id, id+tot, H-va[i].second) - id;
        if(pos != tot)
            ret += sum - query(mp[id[pos]]-1);
        i++;
    }
    return ret;
}

void prepare() {
    va.push_back({0, 0});
    vb.push_back({0, 0});
    for(int i = 0;i < n/2;i++) {
        int len = va.size();
        for(int j = 0;j < len;j++) {
            va.push_back({va[j].first + a[i], va[j].second});
            va.push_back({va[j].first, va[j].second + b[i]});
            va.push_back({va[j].first + a[i], va[j].second + b[i]});
        }
        va.erase(va.begin(), va.begin()+len);
    }
    for(int i = n/2;i < n;i++) {
        int len = vb.size();
        for(int j = 0;j < len;j++) {
            vb.push_back({vb[j].first + a[i], vb[j].second});
            vb.push_back({vb[j].first, vb[j].second + b[i]});
            vb.push_back({vb[j].first + a[i], vb[j].second + b[i]});
        }
        vb.erase(vb.begin(), vb.begin()+len);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    // cout << va.size() << " " << vb.size() << endl;
    // for(auto v : va) printf("va [%d, %d]\n", v.first, v.second);
    // for(auto v : vb) printf("vb [%d, %d]\n", v.first, v.second);

    for(auto v : vb) id[tot++] = v.second;
    sort(id, id+tot);
    tot = unique(id, id+tot) - id;
    for(int i = 0;i < tot;i++) mp[id[i]] = i+1;
}

void init() {
    tot = 0;
    memset(c, 0, sizeof(c));
    mp.clear();
    va.clear();
    vb.clear();
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n >> H;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++)
            cin >> b[i];
        
        init();
        prepare();
        LL ans = work();
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}
