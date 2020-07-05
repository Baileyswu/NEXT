#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
#define LL long long
LL sum[N];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for(int i = 0;i < n;i++) {
            int t;
            cin >> t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        sum[n] = 0;
        for(int i = n-1;i >= 0;i--)
            sum[i] = sum[i+1] + a[i];
        double dp = 1.0 * sum[0] / n;
        for(int i = 1;i <= k;i++) {
            int id = upper_bound(a.begin(), a.end(), dp) - a.begin();
            // int id = lower_bound(a.begin(), a.end(), dp[i-1]) - a.begin();
            dp = (id * dp + sum[id]) / n;
        }
        printf("Case #%d: %.7f\n", ++o, dp);
    }
    return 0;
}