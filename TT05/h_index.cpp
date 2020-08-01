#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
int c[N];
int lowbit(int x) {
    return x & -x;
}
int query(int x) {
    int ret = 0;
    while(x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void update(int x, int y) {
    while(x < N) {
        c[x] += y;
        x += lowbit(x);
    }
}
int cite(int s, int x) {
    return s - query(x-1);
}
int work(int s, int x) {
    update(x, 1);
    int l = 1, r = s+1;
    while(l+1 < r) {
        int mid = (l+r) >> 1;
        if(cite(s, mid) < mid) r = mid;
        else l = mid;
    }
    return l;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        printf("Case #%d:", ++o);
        int n; cin >> n;
        memset(c, 0, sizeof(c));
        for(int i = 0;i < n;i++) {
            int t;
            cin >> t;
            cout << " " << work(i+1, t);
        }
        cout << endl;
    }
    return 0;
}
