#include <bits/stdc++.h>
using namespace std;
const int N = 7e3+10;
const int M = 2e5+10;
#define LL long long
int a[N], cnt[M];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a, a+n);
        
        LL ans = 0;
        int s = cnt[0] + cnt[1];
        for(int i = s;i < n;i++) 
            for(int j = i+1;j < n;j++) {
                LL m = 1LL*a[i] * a[j];
                if (m >= M || !cnt[m])
                    continue;
                ans += cnt[m];
                // printf("%d * %d = %d, %d, %d\n", a[i], a[j], m, cnt[m], ans);
            }
        // 0 * 0 = 0
        ans += 1LL*cnt[0] * (cnt[0]-1) * (cnt[0]-2) / 6;
        // 0 * x = 0 (x > 0)
        ans += 1LL*(n-cnt[0]) * cnt[0] * (cnt[0] - 1) / 2;
        // 1 * 1 = 1
        ans += 1LL*cnt[1] * (cnt[1]-1) * (cnt[1]-2) / 6;
        // 1 * x = x (x > 1)
        for(int i = 2;i < M;i++) 
            ans += 1LL*cnt[1] * cnt[i] * (cnt[i] - 1) / 2;

        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}