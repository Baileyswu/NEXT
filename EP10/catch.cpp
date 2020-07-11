#include <bits/stdc++.h>
using namespace std;
#define N 1010
const int INF = 2e9;
int n, K;
int pos[N], color[N], dp[N][N][2];
vector<int> dogs[N];
int solve() {
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			dp[i][j][0] = dp[i][j][1] = INF;

	for(int i = 0;i < N;i++)
		dp[i][0][0] = dp[i][0][1] = 0;
	for(int j = 0;j < dogs[0].size();j++) {
		dp[0][j+1][0] = 2 * dogs[0][j];
		dp[0][j+1][1] = dogs[0][j];
	}

	for(int i = 1;i < N;i++)
		for(int k = 0;k <= K;k++) {
			dp[i][k][0] = min(dp[i][k][0], dp[i-1][k][0]);
			dp[i][k][1] = min(dp[i][k][1], dp[i-1][k][1]);
			for(int j = 0;j < dogs[i].size();j++) if(k-(j+1) >= 0) {
				int dis = dogs[i][j];
				dp[i][k][0] = min(dp[i][k][0], dp[i-1][k-(j+1)][0] + 2 * dis);
				dp[i][k][1] = min(dp[i][k][1], dp[i-1][k-(j+1)][1] + 2 * dis);
				dp[i][k][1] = min(dp[i][k][1], dp[i-1][k-(j+1)][0] + dis);
			}
		}
	return dp[N-1][K][1];
}
int main()
{
	int T;
	cin >> T;
	for(int o = 1;o <= T;o++) {
		cin >> n >> K;
		for(int i = 0;i < n;i++)
			cin >> pos[i];
		for(int i = 0;i < n;i++)
			cin >> color[i];
		for(int i = 0;i < N;i++)
			dogs[i].clear();
		for(int i = 0;i < n;i++)
			dogs[color[i]].push_back(pos[i]);
		for(int i = 0;i < N;i++)
			sort(dogs[i].begin(), dogs[i].end());
		int ans = solve();
		printf("Case #%d: %d\n", o, ans);
	}
	return 0;
}