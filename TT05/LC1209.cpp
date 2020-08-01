class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk;
        stk.push_back({0, ' '});
        for(auto d : s) {
            // cout << d; 
            if(d == stk.back().second)
                stk.push_back({stk.back().first+1, d});
            else stk.push_back({1, d});
            if(stk.back().first >= k) {
                stk.erase(stk.end()-k, stk.end());
            }
            // string ans = ""; for(auto c : stk) ans = ans + c.second; cout << ans << endl;
        }
        string ans = "";
        for(auto c : stk) ans = ans + c.second;
        return ans.substr(1);
    }
};