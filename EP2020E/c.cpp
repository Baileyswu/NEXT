#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 13;
LL e[N], r[N];
int n, bits[N]={1};
int main() {
    int T, o = 0;
    cin >> T;
    for(int i = 1;i < N;i++) bits[i] = bits[i-1] << 1;
    // for(int i = 0;i < N;i++) cout << bits[i] << endl;
    while(T--) {
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> e[i] >> r[i];

        LL goodtime = 0;
        bool inf = false;
        int tot = 1<<n;
        int infremove = n;
        int limitremove = n;
        for(int s = 1;s < tot;s++) {
            LL sum = 0;
            int toyn = 0;
            for(int i = 0;i < n;i++) if(bits[i] & s) {
                sum += e[i];
                toyn++;
            }
            LL playtime = sum;
            for(int i = 0;i < n;i++) if(bits[i] & s) {
                if(sum-e[i] >= r[i]) playtime += e[i];
                else break;
            }
            // printf("s=%d toyn=%d sum=%d\n", s, toyn, sum);
            // printf("playtime = %d\n", playtime);
            if(playtime == sum + sum) {
                infremove = min(infremove, n-toyn);
                inf = true;
            } else if(!inf && playtime >= goodtime){
                if(goodtime == playtime) limitremove = min(limitremove, n-toyn);
                else limitremove = n-toyn;
                goodtime = playtime;
            }
        }

        if(inf)
            printf("Case #%d: %d INDEFINITELY\n", ++o, infremove);
        else 
            printf("Case #%d: %d %lld\n", ++o, limitremove, goodtime);
    }
    return 0;
}
