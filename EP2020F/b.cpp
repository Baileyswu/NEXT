#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
vector<pair<LL, LL>> a;
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        LL k;
        cin >> n >> k;
        a.clear();
        for(int i = 0;i < n;i++) {
            LL l, r;
            cin >> l >> r;
            a.push_back({l, r});
        }
        sort(a.begin(), a.end());
        LL ans = 0;
        LL s = -2*k;
        for(int i = 0;i < n;i++) {
            LL l = a[i].first, r = a[i].second;
            if(s + k <= l) {
                s = l;
                ans++;
                // printf("[%lld, %lld] [%lld, %lld]\n", l, r, s, s+k);
            }
            if (s+k < r) {
                LL stk = (r - s) / k - 1;
                // printf("(%lld-%lld)/%lld=%lld\n", r, s, k, stk);
                s += stk * k;
                ans += stk;
                // printf("[%lld, %lld] [%lld, %lld] +%lld\n", l, r, s, s+k, stk);
            }
            if(s+k < r) {
                s += k;
                ans++;
                // printf("[%lld, %lld] [%lld, %lld]\n", l, r, s, s+k);
            }
        }
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}
