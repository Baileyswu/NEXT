#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 55, M = 33;
const int P = 50*30 + 10;
int a[N][M];
LL dp[N][P];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m, p;
        cin >> n >> m >> p;
        memset(a, 0, sizeof(a));
        for(int i = 0;i < n;i++)
            for(int j = 1;j <= m;j++) {
                cin >> a[i][j];
                a[i][j] += a[i][j-1];
            }
        memset(dp, 0, sizeof(dp));
        for(int j = 1;j <= m;j++) 
            dp[0][j] = a[0][j];
        for(int i = 1;i < n;i++)
            for(int j = 0;j <= m;j++) 
                for(int w = p;w-j >= 0;w--) 
                    dp[i][w] = max(dp[i][w], max(dp[i-1][w], dp[i-1][w-j]+a[i][j]));
        printf("Case #%d: %lld\n", ++o, dp[n-1][p]);
    }
    return 0;
}
