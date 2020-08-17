class Solution {
public:
    vector<int> temp;
    int merge(vector<int> &nums, int l, int r, int s, int t) {
        int i = l, j = s, k = 0, ret = 0;
        while(i <= r && j <= t) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
                ret += j-s;
            } else temp[k++] = nums[j++];
        }
        ret += (j-s) * (r-i+1);
        while(i <= r) temp[k++] = nums[i++];
        while(j <= t) temp[k++] = nums[j++];
        for(int i = l;i <= t;i++) nums[i] = temp[i-l];
        return ret;
    }
    int work(vector<int> & nums, int l, int r) {
        if(l >= r) return 0;
        int mid = (l + r) >> 1;
        return work(nums, l, mid) + work(nums, mid+1, r) + merge(nums, l, mid, mid+1, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        temp.resize(n);
        return work(nums, 0, n-1);
    }
};