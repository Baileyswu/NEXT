#include <bits/stdc++.h>
using namespace std;
#define LL long long;
const int N = 5e5+10;
int pt[N];
int son[N][2];
double f(double x, double y) {
    return 1-(1-x)*(1-y);
}
void have_son(int id, int gap, int s) {
    int g = 0;
    int t = id;
    son[id][s]++;
    while(id != pt[id]) {
        id = pt[id];
        g++;
        if(g == gap) {
            son[id][s]++;
            g = 0;
        }
    }
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        pt[1] = 1;
        for(int i = 1;i < n;i++) {
            int t;
            cin >> t;
            pt[i+1] = t;
        }
        memset(son, 0, sizeof(son));
        for(int i = 1;i <= n;i++) {
            have_son(i, a, 0);
            have_son(i, b, 1);
        }
        // for(int i = 1;i <= n;i++)
        //     printf("%d%c", son[i][0], " \n"[i==n]);
        // for(int i = 1;i <= n;i++)
        //     printf("%d%c", son[i][0], " \n"[i==n]);
        double ans = 0;
        for(int i = 1;i <= n;i++)
            ans += f(1.0*son[i][0]/n, 1.0*son[i][1]/n);
        printf("Case #%d: %.7f\n", ++o, ans);
    }
    return 0;
}