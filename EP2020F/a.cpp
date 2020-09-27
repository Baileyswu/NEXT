#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
vector<pair<int,int>> a;
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        a.resize(n);
        for(int i = 0;i < n;i++) {
            int t; 
            cin >> t;
            a[i] = {(t-1)/x, i+1};
        }
        sort(a.begin(), a.end());
        printf("Case #%d:", ++o);
        // for(int i = 0;i < n;i++) cout << a[i].first << " " << a[i].second << endl; cout << endl;
        for(int i = 0;i < n;i++) cout << " " << a[i].second; cout << endl;
    }
    return 0;
}
