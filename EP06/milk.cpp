#include <bits/stdc++.h>
using namespace std;
#define TOPNUM 105
int a[100];
int n, m, p;

int work(set<string> &exc) {
    vector< pair<int, string> > v, nv;
    int c = 0;
    string s = "";
    v.push_back(make_pair(c, s));
    for(int i = 0;i < p;i++) {
        for(auto t : v) {
            nv.push_back(make_pair(t.first + n - a[i], t.second + '1'));
            nv.push_back(make_pair(t.first + a[i], t.second + '0'));
        }
        sort(nv.begin(), nv.end());
        if(nv.size() < TOPNUM) v = nv;
        else {
            v.clear();
            v.insert(v.begin(), nv.begin(), nv.begin() + TOPNUM);
        }
        nv.clear();
    }
    for(auto t : v) {
        if(exc.find(t.second) == exc.end()) {
            // cout << t.first << " " << t.second << endl;
            return t.first;
        }
    }
    return -1;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n >> m >> p;

        set<string> exc;
        string str;
        memset(a, 0, sizeof(a));
        for(int i = 0;i < n;i++) {
            cin >> str;
            for(int j = 0;j < p;j++)
                if(str[j] == '1')
                    a[j]++;
        }
        for(int i = 0;i < m;i++) {
            cin >> str;
            exc.insert(str);
        }

        // for(int i = 0;i < p;i++)
            // printf("%d%c", a[i], " \n"[i==p-1]);

        int ans = work(exc);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}