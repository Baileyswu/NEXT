#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 2e5+10;
int a[N];
vector<int> vec;
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        a[0] = a[n+1] = -1;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        int ans = 0;
        vec.clear();
        vec.push_back(-1);
        for(int i = 1;i <= n;i++) {
            if (a[i] > vec.back()) {
                // cout << a[i] << " > " << vec.back() << endl;
                vec.push_back(a[i]);
                if(a[i] > a[i+1]) ans++;
            }
        }
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}