#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 1e4+10;
const int INF = 1e9;
int a[N], dp[N][4];
int n;
int f(int x, int y) {
    if(x == y) return 0;
    return x > y ? 1 : -1;
}
int work() {
    if(n <= 1) return 0;
    int ret = 0;
    int p = f(a[1], a[0]);
    int len = 1;
    for(int i = 1;i < n;i++) {
        int q = f(a[i], a[i-1]);
        if(q == 0) continue;
        if(q == p) len++;
        else {
            ret += (len-1)/4;
            p = q;
            len = 2;
        }
        // printf("%d %d %d %d\n", a[i], p, q, len);
    }
    ret += (len-1)/4;
    return ret;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i<n;i++) 
            cin >> a[i];
        
        int ans = work();
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}