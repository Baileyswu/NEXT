class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> Q;
        set<string> used, dead;
        for(auto x : deadends) dead.insert(x);
        string start = "0000";
        if(dead.count(start)) return -1;
        Q.push({start, 0});
        used.insert(start);
        int dp[2] = {1, -1};
        while(!Q.empty()) {
            auto f = Q.front(); Q.pop();
            string cur = f.first;
            for(int i = 0;i < 4;i++) {
                for(int k = 0;k < 2;k++) {
                    string t = cur;
                    if(dp[k] == 1) t[i] = t[i] == '9' ? '0' : t[i] + 1;
                    else if(dp[k] == -1) t[i] = t[i] == '0' ? '9' : t[i] - 1;
                    if(used.count(t) || dead.count(t)) continue;
                    if(t == target) return f.second + 1;
                    Q.push({t, f.second+1});
                    used.insert(t);
                }
            }
        }
        return -1;
    }
};