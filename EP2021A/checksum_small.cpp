#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int N = 5, B = 20, INF = 1e8;
ULL bits[B] = {1};
int n;
int a[N][N], b[N][N], R[N], C[N];
ULL cost[66000];
ULL state(){
    ULL ret = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) if(a[i][j] == -1) {
            ret += bits[i*n+j];
        }
    return ret;
}

bool check_single(ULL s, int d) {
    int bn = n * n;
    int x = d / n;
    int y = d % n;
    int qx = 0, qy = 0;
    for(int i = 0;i < bn;i++) if(i != d) {
        if(i/n == x) { 
            if(s & bits[i]) qx++;
        } if(i%n == y) {
            if(s & bits[i]) qy++;
        }
    }
    return qx == 0 || qy == 0;
}
int main() {
    for(int i = 1;i < B;i++)
        bits[i] = bits[i-1] << 1;
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) {
                cin >> a[i][j];
            }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) {
                cin >> b[i][j];
            }
        for(int i = 0;i < n;i++) cin >> R[i];
        for(int i = 0;i < n;i++) cin >> C[i];
        
        int bn = n*n;
        ULL states = 1 << bn;
        ULL endstate = state();
        // printf("endstate = %llu\n", endstate);

        cost[0] = 0;

        for(ULL s = 1; s < states;s++) {
            if((s | endstate) != endstate) continue;
            // printf("checkstate s = %llu\n", s);
            cost[s] = INF;
            for(int i = 0;i < bn;i++) {
                if(s & bits[i]) {
                    ULL last = s ^ bits[i];
                    if(check_single(s, i))  cost[s] = min(cost[s], cost[last]);
                    else cost[s] = min(cost[s], cost[last] + b[i/n][i%n]);
                }
            }
            // printf(" cost = %llu\n", cost[s]);
        }
        LL ans = cost[endstate];
        printf("Case #%d: %lld\n", ++o, ans);            
    }
    return 0;
}
