#include <bits/stdc++.h>
using namespace std;
#define LL long long

vector<int> sep(LL t) {
    vector<int> num;
    while(t) {
        num.push_back(t%10);
        t /= 10;
    }
    return num;
}

LL to_num(vector<int> &d) {
    LL res = 0, t = 1;
    for(int i = 0;i < d.size();i++) {
        res += t * d[i];
        t *= 10;
    }
    return res;
}

LL find_low(LL x) {
    auto d = sep(x);
    int len = d.size();
    for(int i = len-1;i >= 0;i--) 
        if(d[i] & 1) {
            d[i]--;
            while(i>0) d[--i]=8;
            return to_num(d);
        }
    return x;
}

LL find_up(LL x) {
    auto d = sep(x);
    int len = d.size();
    for(int i = len-1;i >= 0;i--)
        if(d[i]&1) {
            d[i]++;
            d[i] %= 10;
            if(d[i] == 0) {
                int j = i+1;
                while(j < len) {
                    d[j] += 2;
                    if (d[j] < 10)
                        break;
                    d[j++] %= 10;
                }
                if(j >= len)
                    d.push_back(2);
            }
            while(i>0) d[--i] = 0;
            return to_num(d);
        }
    return x;
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        LL a;
        cin >> a;
        // printf("%lld %lld %lld\n", a, find_low(a), find_up(a));
        LL ans = min(a - find_low(a), find_up(a) - a);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}