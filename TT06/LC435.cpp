class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        // for(auto x : intervals) cout << x[0] << " " << x[1] << endl; 
        int n = intervals.size();
        if(n < 2) return 0;
        int classover = intervals[0][1];
        int ans = 0;
        for(int i = 1;i < n;i++) {
            if(intervals[i][0] < classover) {
                ans++;
                // cout << "remove " << intervals[i][0] << " " << intervals[i][1] << endl;
            } else {
                classover = intervals[i][1];           
            }
        }
        return ans;
    }
};
