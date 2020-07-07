#include <bits/stdc++.h>
using namespace std;
const int N = 5000+10;
int a[N], b[N];
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int t = k;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            b[i] = t++/k;
        }
        sort(a, a+n);
        
        int i = 0, j = 0, ans = 0;
        while(i < n && j < n) {
            if(a[i] >= b[j]) {
                ans++;
                i++;
                j++;
            }
            else i++;
        }
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}