#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
int sum[N] = {0};
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int len = s.length() / 2 +  s.length() % 2;

        int ans = 0;
        for(int i = 1;i <= n;i++)
            sum[i] = sum[i-1] + s[i-1] - '0';
        for(int i = 0;i + len <= n;i++)
            ans = max(ans, sum[i+len]-sum[i]);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}