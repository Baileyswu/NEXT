#include<bits/stdc++.h>
using namespace std;
#define LL long long
typedef pair<LL, LL> P;
const int M = 1e9;
const int N = 2010;
int half[N];
char str[N];
P add(P a, P b) {
    return make_pair((a.first+b.first)%M, (a.second+b.second)%M);
}
P mult(int a, P b) {
    return make_pair(a*b.first%M, a*b.second%M);
}
P simple(char *s, int l, int r) {
    P z = make_pair(0, 0);
    for(int i = l;i <= r;i++) switch (s[i])
    {
    case 'N':
        z.first--;
        break;
    case 'S':
        z.first++;
        break;
    case 'E':
        z.second++;
        break;
    case 'W':
        z.second--;
        break;
    default:
        break;
    }
    z.first = (z.first % M + M) % M;
    z.second = (z.second % M + M) % M;
    // for(int i = l;i <= r;i++) putchar(s[i]); 
    // printf(" -- (%d, %d)\n", z.first, z.second);
    return z;
}
P f(char *s, int l, int r) {
    // for(int i = l;i <= r;i++) putchar(s[i]); putchar('\n');
    for(int i = l;i <= r;i++) if(s[i] == '(') {
        int j = half[i];
        int count = s[i-1] - '0';
        P ret = f(s, i+1, j-1);
        ret = mult(count, ret);
        if(l <= i-2)
            ret = add(simple(s, l, i-2), ret);
        if(j+1 <= r)
            ret = add(ret, f(s, j+1, r));
        return ret;
    }
    return simple(s, l, r);
}
P work(char *s) {
    vector<int> t;
    int len = strlen(s);
    memset(half, -1, sizeof(half));
    for(int i = 0;i < len;i++) {
        if(s[i] == '(') t.push_back(i);
        else if(s[i] == ')') {
            half[t.back()] = i;
            t.pop_back();
        }
    }
    return f(s, 0, len-1);
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> str;
        auto ans = work(str);
        printf("Case #%d: %d %d\n", ++o, ans.second+1, ans.first+1);
    }
    return 0;
}
