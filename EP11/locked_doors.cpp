#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+10;
const int INF = 1e9;
int a[N], n;
int run(int s, int pos) {
    // printf("\nrun %d ", s);
    int l = s, r = s, ret = s;
    while(--pos) {
        // printf("[%d, %d]", a[l-1], a[r]);
        if(a[l-1] < a[r]) {
            l--;
            ret = l;
        } else if(a[l-1] > a[r]) {
            r++;
            ret = r;
        }
        // printf("(%d) ", ret);
    }
    return ret;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        printf("Case #%d:", ++o);
        int q;
        cin >> n >> q;
        a[0] = a[n] = INF;
        for(int i = 1;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < q;i++) {
            int u, v;
            cin >> u >> v;
            cout << " " << run(u, v);
        }
        cout << endl;
    }
    return 0;
}