#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL pn[17] = {1};
LL no_nine(LL x) {
    // cout << "-----------no_nine " << x << endl;
    vector<int> num;
    LL t = x, res = 0;
    if (t == 0)
        num.push_back(0);
    while(t) {
        num.push_back(t%10);
        t /= 10;
    }
    int len = num.size();
    for(int i = len-1;i > 0;i--) {
        res += num[i] * pn[i-1] * 8;
        // printf("%d * 9^%d * 8 = %d\n", num[i], i-1, num[i] * pn[i-1] * 8);
        if (num[i] == 9)
            return res;
    }
    x -= num[0];
    for(int i = 0;i <= num[0] && i != 9;i++)
        if ((x + i) % 9)
            res++;
    return res;
}
int main() {
    int T, o = 0;
    for(int i = 1;i < 18;i++)
        pn[i] = pn[i-1]*9;
    cin >> T;
    while(T--) {
        LL l, r;
        cin >> l >> r;
        LL ans = no_nine(r) - no_nine(l-1);
        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}