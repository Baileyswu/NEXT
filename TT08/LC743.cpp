class Solution {
public:
    typedef pair<int, int> pr;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N, -1);
        vector<pr> mp[N];
        K--;
        for(auto edge: times) {
            int u = edge[0], v = edge[1], w = edge[2];
            u--; v--;
            mp[u].push_back({v, w});
        }
        priority_queue<pr, vector<pr>, less<pr>> Q;
        Q.push({K, 0});
        dist[K] = 0;
        while(!Q.empty()) {
            auto ft = Q.top(); Q.pop();
            int u = ft.first;
            // cout << ft.first+1 << " " << ft.second << endl;
            if(dist[u] < ft.second) continue;
            for(auto p : mp[u]) {
                int v = p.first;
                int w = p.second;
                int dis = dist[u] + w;
                if(dist[v] == -1 || dist[v] > dis) { 
                    Q.push({v, dist[u]+w});
                    dist[v] = dis;
                }
            }
        }
        // for(auto d : dist) cout << d << " "; cout << endl;
        for(auto d : dist) if(d == -1) return -1;
        int maxn = 0;
        for(auto d : dist) maxn = max(maxn, d);
        return maxn;
    }
};