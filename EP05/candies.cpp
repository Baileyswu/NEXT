#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define LL long long
LL a[N], sum[N];
const LL INF = 1e17;
void show(multiset<LL> mt, int start) {
    for(multiset<LL>::iterator it = mt.begin(); it != mt.end();it++)
        cout << *it-start << " ";
    cout << "\n==============\n";

}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        multiset<LL> mt;
        multiset<LL>::iterator it;
        int n, O;
        LL D;
        LL x1, x2, A, B, C, M, L;
        cin >> n >> O >> D;
        cin >> x1 >> x2 >> A >> B >> C >> M >> L;
        a[1] = x1 + L;
        a[2] = x2 + L;
        sum[0] = 0;
        sum[1] = a[1];
        sum[2] = a[1] + a[2];
        for(int i = 3;i <= n;i++) {
            LL x = (A*x2 + B*x1 + C) % M;
            x1 = x2;
            x2 = x;
            a[i] = x + L;
            sum[i] = sum[i-1] + a[i];
        }
        // for(int i = 1;i <= n;i++)
        //     printf("%d%c", a[i], " \n"[i == n]);
        LL ans = -INF;
        int on = 0, r = 1;
        for(int i = 1;i <= n;i++) {
            while (r <= n && on + (a[r]&1) <= O) {
                on += a[r]&1;
                mt.insert(sum[r++]);
            }
            if(i >= r) {
                r = i+1;
                continue;
            }
            it = mt.lower_bound(D+sum[i-1]+1);
            // show(mt, sum[i-1]);
            if(it != mt.begin()) {
                it--;
                ans = max(ans, (*it)-sum[i-1]);
            }
            on -= a[i]&1;
            mt.erase(mt.find(sum[i]));
        }
        if(ans == -INF)
            printf("Case #%d: IMPOSSIBLE\n", ++o);
        else
        {
            printf("Case #%d: %lld\n", ++o, ans);
        }
    }
    return 0;
}