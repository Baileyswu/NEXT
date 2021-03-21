#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1010;
int a[N][N], dp[N][N][4];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin >> a[i][j];
        memset(dp, 0, sizeof(dp));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) {
                if(a[i][j]) {
                    if(i > 0) dp[i][j][0] = dp[i-1][j][0] + 1;
                    else dp[i][j][0] = 1;
                    if(j > 0) dp[i][j][1] = dp[i][j-1][1] + 1;
                    else dp[i][j][1] = 1;
                }
            }
        for(int i = n-1;i >= 0;i--)
            for(int j = m-1;j >= 0;j--) {
                if(a[i][j]) {
                    if(i < n-1) dp[i][j][2] = dp[i+1][j][2] + 1;
                    else dp[i][j][2] = 1;
                    if(j < m-1) dp[i][j][3] = dp[i][j+1][3] + 1;
                    else dp[i][j][3] = 1;
                }
            }
        // for(int k = 0;k < 4;k++) {
        //     printf("k=%d\n", k);
        //     for(int i = 0;i < n;i++)
        //         for(int j = 0;j < m;j++) {
        //             printf("%d%c", dp[i][j][k], " \n"[j==m-1]);
        //         }
        // }
                        
                
        LL ans = 0;
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                for(int k = 0;k < 4;k++) {
                    int p = (k+1) % 4;
                    int t = min(dp[i][j][k], dp[i][j][p]/2);
                    if(t > 1) ans += t-1;
                    t = min(dp[i][j][k]/2, dp[i][j][p]);
                    if(t > 1) ans += t-1;
                }
        printf("Case #%d: %lld\n", ++o, ans);            
    }
    return 0;
}
