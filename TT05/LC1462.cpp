class Solution {
public:
    void dfs(vector<set<int>> &pt, vector<bool> &vis, int x) {
        // printf("dfs %d\n", x);
        vis[x] = true;
        for(auto i : pt[x]) if(pt[i].size()) {
            if(!vis[i]) dfs(pt, vis, i);
            for(auto j : pt[i]) pt[x].insert(j);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> pt(n);
        vector<bool> vis(n, false);
        for(auto p : prerequisites) {
            pt[p[1]].insert(p[0]);
        }
        for(int i = 0;i < n;i++) if(!vis[i] && pt[i].size()) {
            dfs(pt, vis, i);
        }
        // for(int i = 0;i < n;i++) if(pt[i].size()) {
        //     cout << i << ": ";
        //     for(auto x : pt[i]) cout << x << " "; cout << endl;
        // }

        vector<bool> ans;
        for(auto q : queries) {
            if(pt[q[1]].count(q[0]))
                ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};