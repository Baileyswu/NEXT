#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 21;
LL a[N], b[N], h, p3[N] = {1};
int n;
LL dfs(int id, LL sa, LL sb) {
    if(id == n) {
        return sa >= h && sb >= h;
    }
    if(sa >= h && sb >= h)
        return p3[n-id];
    return dfs(id+1, sa+a[id], sb+b[id])
         + dfs(id+1, sa, sb+b[id])
         + dfs(id+1, sa+a[id], sb);

}
int main() {
    int T, o = 0;
    cin >> T;
    for(int i = 1;i < N;i++)
        p3[i] = p3[i-1] * 3;
    while(T--) {
        cin >> n >> h;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++)
            cin >> b[i];
        LL ans = dfs(0, 0, 0);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}
