#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 21, M = 1<<20;
LL a[N], b[N], bits[N] = {1}, f[M];

int main() {
    for(int i = 1;i < N;i++)
        bits[i] = bits[i-1] << 1;
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, H;
        cin >> n >> H;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++)
            cin >> b[i];
        
        int states = 1<<n;
        memset(f, 0, sizeof(f));
        for(int i = 0;i < states;i++) {
            LL sum = 0;
            for(int j = 0;j < n;j++)
                if(!(i & bits[j]))
                    sum += b[j];
            if(sum >= H) f[i]++;
        }

        for(int j = 0;j < n;j++)
            for(int i = 0;i < states;i++)
                if(i & bits[j])
                    f[i] += f[i ^ bits[j]];

        LL ans = 0;
        for(int i = 0;i < states;i++) {
            LL sum = 0;
            for(int j = 0;j < n;j++)
                if(i & bits[j])
                    sum += a[j];
            if(sum >= H) ans += f[i];
        }
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}
