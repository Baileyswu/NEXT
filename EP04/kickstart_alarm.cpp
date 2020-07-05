#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e6 + 10;
const LL M = 1e9 + 7;
LL a[N];
LL poo(LL a, LL k) {
    LL res = 1;
    while(k) {
        if(k&1LL)
            res = res * a % M;
        a = a * a % M;
        k >>= 1;
    }
    return res;
}
LL get_pow_sum(LL a, LL k){
    assert(a > 0);
    if(a == 1)
        return k;
    // printf("%d * (%d^%d - 1) * (%d^%d)", a, a, k, a-1, M-2);
    LL res = a * (poo(a, k) - 1 + M) % M * poo(a-1, M-2) % M;
    // printf("=%lld\n", res);
    return res;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        LL x, y, C, D, E1, E2, F;
        cin >> n >> k >> x >> y >> C >> D >> E1 >> E2 >> F;
        for(int i = 0;i < n;i++) {
            a[i] = (x + y) % F;
            LL tx = (C*x + D*y + E1) % F;
            LL ty = (D*x + C*y + E2) % F;
            x = tx;
            y = ty;
        }
        LL ans = 0, s = 0;
        for(int i = 0;i < n;i++) {
            // printf("%d\n", a[i]);
            s += get_pow_sum(i+1, k);
            s %= M;
            ans += a[i] * (n-i) % M * s % M;
            ans %= M;
        }
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}