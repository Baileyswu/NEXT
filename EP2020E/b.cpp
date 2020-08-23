#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 110;

vector<int> work(int n, int left, int right, int mid) {
    // printf("%d l=%d r=%d m=%d\n", n, left, right, mid);
    vector<int> impossible;
    if(n < 1 || left < 0 || right < 0 || mid < 1 || left + right + mid > n) 
        return impossible;

    vector<int> a(mid, n);
    vector<int> one(n, 1);
    vector<int> two(n, 2);
    auto p1 = one.begin();
    auto p2 = two.begin();
    int hid = n - left - right - mid;

    if(n == 1) return a;
    if(n == 2) {
        if(hid > 0) return impossible;
        if(left > 0) a.insert(a.begin(), p1, p1+left);
        if(right > 0) a.insert(a.end(), p1, p1+right);
        return a;
    }
    if(left == 0 && right == 0 && mid == 1 && hid > 0) return impossible;
    if(left) a.insert(a.begin(), p2, p2+left);
    if(right) a.insert(a.end(), p2, p2+right);
    if(hid) a.insert(a.begin()+1, p1, p1+hid);
    return a;
}
bool check(vector<int> &build, int n, int a, int b, int c) {
    if(build.size() != n) return false;
    vector<bool> visa(n, false), visb(n, false);
    int ha = 0, hb = 0;
    for(int i = 0;i < n;i++) if(build[i] >= ha) {
        visa[i] = true;
        ha = build[i];
        a--;
    }
    for(int i = n-1;i >= 0;i--) if(build[i] >= hb) {
        visb[i] = true;
        hb = build[i];
        b--;
    }
    for(int i = 0;i < n;i++) if(visa[i] && visb[i]) c--;
    return a == 0 && b == 0 && c == 0;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        vector<int> ans = work(n, a-c, b-c, c);
        if(ans.size() == 0)
            printf("Case #%d: IMPOSSIBLE\n", ++o);
        else {
            printf("Case #%d:", ++o);
            for(auto x : ans) cout << " " << x;
            cout << endl;
            // assert(check(ans, n, a, b, c));
        }
    }
    return 0;
}
