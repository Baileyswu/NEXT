class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> t(3);
        int n = nums.size();
        if(n < 3) return ret;
        sort(nums.begin(), nums.end());
        // for(auto i : nums) cout << i << " "; cout << endl;
        for(int i = 0;i < n-2;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r) {
                // printf("i=%d %d : %d %d\n", i, -nums[i], nums[l], nums[r]);
                int s = nums[l] + nums[r] + nums[i];
                if(s == 0) {
                    t[0] = nums[i];
                    t[1] = nums[l];
                    t[2] = nums[r];
                    ret.push_back(t);
                    do l++; while(l<n&&nums[l]==nums[l-1]);
                    do r--; while(r>=0&&nums[r]==nums[r+1]);
                } else if(s < 0) l++;
                else r--;
            }
        }
        return ret;
    }
};