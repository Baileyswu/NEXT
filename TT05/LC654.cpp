/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int l[n], r[n], a[n];
        int top = 0;
        a[top++] = 0;
        l[0] = 0;
        for(int i = 1;i < n;i++) {
            while(top && nums[a[top-1]] < nums[i]) top--;
            l[i] = top ? a[top-1] : i;
            a[top++] = i;
        }
        top = 0;
        a[top++] = n-1;
        r[n-1] = n-1;
        for(int i = n-2;i >= 0;i--) {
            while(top && nums[a[top-1]] < nums[i]) top--;
            r[i] = top ? a[top-1] : i;
            a[top++] = i;
        }
        // for(auto i : nums) cout << i << " "; cout << endl;
        // for(auto i : l) cout << i << " "; cout << endl;
        // for(auto i : r) cout << i << " "; cout << endl;
        TreeNode *root = NULL;
        TreeNode* tree[n];
        for(int i = 0;i < n;i++) {
            TreeNode *p = new TreeNode(nums[i]);
            tree[i] = p;
            if(l[i] == i && r[i] == i) root = p;
        }
        for(int i = 0;i < n;i++) if(root != tree[i]) {
            int pt = i;
            if(r[i] == i || l[i]!=i&&nums[l[i]] < nums[r[i]]) {
                pt = l[i];
                // printf("%d -> %d\n", nums[i], nums[pt]);
                tree[pt]->right = tree[i];
            } else {
                pt = r[i];
                // printf("%d -> %d\n", nums[i], nums[pt]);
                tree[pt]->left = tree[i];
            }
        }
        return root;
    }
};