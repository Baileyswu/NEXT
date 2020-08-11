class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int ans = 0;
        int start = 0;
        int target = n-1; 
        // cout << "=====" << endl;
        while(start < target) {
            int step = nums[start];
            int nxt = start+step;
            if(nxt >= target) {
                ans++;
                break;
            }
            for(int i = 1;i < step;i++) {
                int j = start + i;
                if(j < n && j + nums[j] >= nxt + nums[nxt])
                    nxt = j;
            }
            ans++;
            start = nxt;
            // cout << start << " " << nums[start] << endl;
        }
        return ans;
    }
};