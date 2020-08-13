class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minq, maxq;
        int n = nums.size();
        int l = 0, ans = 0;
        for(int i = 0;i < n;i++) {
            while(!minq.empty() && nums[minq.back()] > nums[i]) minq.pop_back();
            while(!maxq.empty() && nums[maxq.back()] < nums[i]) maxq.pop_back();
            minq.push_back(i);
            maxq.push_back(i);

            while(nums[maxq.front()] - nums[minq.front()] > limit) {
                l = min(minq.front(), maxq.front()) + 1;
                while(!minq.empty() && minq.front() < l) minq.pop_front();
                while(!maxq.empty() && maxq.front() < l) maxq.pop_front();
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};