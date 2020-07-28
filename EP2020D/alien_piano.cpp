#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 1e4+10;
const int INF = 1e9;
int a[N], dp[N][4];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i<n;i++) 
            cin >> a[i];
        for(int i = 1;i < n;i++)
            for(int j = 0;j < 4;j++)
                dp[i][j] = INF;
        for(int j = 0;j < 4;j++)
            dp[0][j] = 0;
        for(int i = 1;i < n;i++)
            for(int j = 0;j < 4;j++) {
                for(int k = 0;k < 4;k++)
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);

                if(a[i-1] == a[i]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                } else if (a[i-1] < a[i]) {
                    for(int k = 0;k < j;k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                } else {
                    for(int k = j+1;k < 4;k++)
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
            }
        
        int ans = INF;
        for(int i = 0;i < 4;i++)
            ans = min(ans, dp[n-1][i]);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}