#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 7, INF = 99999;
int n;
int mp[N][N<<1];
typedef pair<int, int> pr;
int dp[2][3][2] = {
    {0, -1, 0, 1, -1, -1},
    {0, -1, 0, 1, 1, 1}
};
bool not_ok(int &tx, int &ty) {
    return tx < 1 || tx > n || ty < 1 || ty >= 2*tx || mp[tx][ty];
}
int score(int x) {
    printf("score =========\n");
    int a = 0, b = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= (n-i)*2;j++)
            printf(" ");   
        for(int j = 1;j < 2*i;j++) {
            printf("%d%c", mp[i][j], " \n"[j==2*i-1]);
            if(mp[i][j] == 1) a++;
            else if(mp[i][j] == 2) b++;
        }
    }
    int s = x == 1 ? a-b : b-a;
    printf("score=%d\n", s);
    printf("==============\n");
    return s;
}
bool move(pr &a) {
    int id = a.second & 1;
    for(int i = 0;i < 3;i++) {
        int ix = a.first + dp[id][i][0];
        int iy = a.second + dp[id][i][1];
        if(!not_ok(ix, iy)) return true;
    }
    return false;
}
bool play(pr &a, pr &b, int player, int &amin, int &amax) {
    printf("play %d [%d, %d]\n", player, a.first, a.second);
    int ret = -99999;
    if(!move(a) && !move(b)) {
        printf("can't move!\n");
        amin = amax = score(player);
        return false;
    }

    for(int i = 0;i < 3;i++) {
        int id = a.second & 1;
        int ix = a.first + dp[id][i][0];
        int iy = a.second + dp[id][i][1];
        if(not_ok(ix, iy)) continue;
        mp[ix][iy] = player;

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= (n-i)*2;j++)
                printf(" ");
            for(int j = 1;j < 2*i;j++) {
                printf("%d%c", mp[i][j], " \n"[j==2*i-1]);
            }
        }

        int tmin = INF, tmax = -INF;
        pr c = make_pair(ix, iy);
        if(play(b, c, player^1^2, tmin, tmax)) {
            amin = min(amin, -tmax);
            amax = max(amax, -tmax);
        } else {
            play(c, b, player, tmin, tmax);
            amin = min(amin, tmax);
            amax = max(amax, tmax);
        }
        mp[ix][iy] = 0;
    }
    printf("%d in [%d, %d] min = %d, max = %d\n", player, a.first, a.second, amin, amax);
    return true;
}
int work(pr &a, pr &b, vector<pr> &c) {
    memset(mp, 0, sizeof(mp));
    mp[a.first][a.second] = 1;
    mp[b.first][b.second] = 2;
    for(auto x : c) mp[x.first][x.second] = 3;
    int mmin = INF, mmax = -INF;
    if(play(a, b, 1, mmin, mmax))
        return mmax;
    return 0;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        pr A, B;
        A = {a, b};
        B = {c, d};
        vector<pr> printed;
        printed.clear();
        for(int i = 0;i < e;i++) {
            cin >> a >> b;
            printed.push_back({a, b});
        }
        int ans = work(A, B, printed);
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
