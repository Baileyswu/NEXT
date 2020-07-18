#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 26;
unordered_set<int> dependOn[N];
unordered_set<int> base[N];
string ans;
bool used[N];
void dfs(int id) {
    ans += id + 'A';
    used[id] = false;
    for(auto b : base[id]) {
        dependOn[b].erase(id);
        if(used[b] && dependOn[b].size() == 0)
            dfs(b);
    }
}
void init() {
    for(int i = 0;i < N;i++) {
        dependOn[i].clear();
        base[i].clear();
    }
    memset(used, false, sizeof(used));
    ans = "";
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        init();
        int n, m, count = 0;
        cin >> n >> m;
        char s[35][35];
        for(int i = 0;i < n;i++)
            cin >> s[i];
        for(int i = 0;i < n-1;i++)
            for(int j = 0;j < m;j++)
                if(s[i][j] != s[i+1][j]) {
                    int u = s[i][j]-'A', v = s[i+1][j]-'A';
                    dependOn[u].insert(v);
                    base[v].insert(u);
                    used[u] = true;
                    used[v] = true;
                }
        for(int j = 0;j < m;j++)
            used[s[n-1][j]-'A'] = true;
        for(int i = 0;i < N;i++)
            if(used[i]) count++;
        for(int i = 0;i < N;i++) 
            if(used[i] && dependOn[i].size() == 0) 
                dfs(i);
        printf("Case #%d: ", ++o);
        if(ans.length() != count) cout << "-1\n";
        else cout << ans << endl;
    }
    return 0;
}
