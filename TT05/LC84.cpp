class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans = 0;
        int n = heights.size();
        stack<pair<int,int>> s;
        s.push({-1, -1});
        for(int i = 0;i < n;i++) {
            if(s.top().second < heights[i]) s.push({i, heights[i]});
            else {
                int l, r, h;
                while(s.top().second >= heights[i]) {
                    auto t = s.top();
                    l = t.first, r = i, h = t.second;
                    ans = max(ans, (r-l)*h);
                    s.pop();
                }
                s.push({l, heights[i]});
            }
        }
        return ans;
    }
};