#include <bits/stdc++.h>
using namespace std;
#define N 310
int R, C, K;
int mp[N][N];
int rt[N][N];

int solve(int c) {
	int ans = 0;
	for(int i = 0;i < R;i++) {
		int minH = rt[i][c] - c + 1;
		for (int j = i;j >= 0;j--) {
			minH = min(minH, rt[j][c] - c + 1);
			int t = minH * (i-j+1);
			ans = max(ans, t);
		}
	}
	return ans;
}
int main()
{
	int T, sr, sc;
	cin >> T;
	for(int o = 1;o <= T;o++) {
		cin >> R >> C >> K;
		for(int i = 0;i < R;i++)
			for(int j = 0;j < C;j++) 
				cin >> mp[i][j];
		for(int i = 0;i < R;i++)
			for(int j = 0;j < C;j++) {
				int tmin = mp[i][j], tmax = mp[i][j];
				for(int k = j;k < C;k++) {
					tmin = min(tmin, mp[i][k]);
					tmax = max(tmax, mp[i][k]);
					if (tmax - tmin > K)
						break;
					else
						rt[i][j] = k;
				}
				// printf("%d%c", rt[i][j], " \n"[j == C-1]);
			}
		int ans = 0;
		for(int j = 0;j < C;j++)
			ans = max(ans, solve(j));
		printf("Case #%d: %d\n", o, ans);
	}
	return 0;
}