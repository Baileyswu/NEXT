#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5+10;
int a[N];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        int ans = 1;
        int d = 0, len = 1;
        for(int i = 1;i < n;i++) {
            int s = a[i] - a[i-1];
            if(s == d) {
                len++;
            } else {
                d = s;
                len = 2;
            }
            ans = max(ans, len);
        }

        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
