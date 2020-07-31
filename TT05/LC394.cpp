class Solution {
public:
    string decodeString(string s) {
        int d = 0;
        stack<pair<int,string>> stk;
        stk.push({1,""});
        for(auto c : s) {
            if(c == '[') {
                stk.push({d,""});
                d = 0;
            } else if(c>='0' && c<='9') {
                d *= 10;
                d += c-'0';
            } else if(c == ']') {
                string t = stk.top().second;
                int r = stk.top().first;
                // cout << r << " " << t << endl;
                for(int i = 1;i < r;i++) stk.top().second += t;
                t = stk.top().second;
                stk.pop();
                stk.top().second += t;
            } else stk.top().second += c;
        }
        return stk.top().second;
    }
};