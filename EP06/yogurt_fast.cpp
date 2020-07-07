#include <bits/stdc++.h>
using namespace std;
const int N = 5000+10;
int a[N], b[N], c[N];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int t = k;
        memset(c, 0, sizeof(c));
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            b[i] = t++/k;
            c[min(a[i], n)]++;
        }
        
        int s = n-1, ans = 0;
        for(int i = n;i > 0;i--) if(c[i]) {
            while(s >= 0 && c[i]) {
                if(b[s] <= i) {
                    ans++;
                    s--;
                    c[i]--;
                } else s--;
            }
            if(s < 0) break;
        }
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}