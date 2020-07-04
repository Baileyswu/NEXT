#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define LL long long
LL p[N], h[N], x[N], y[N];
const int INF = 2e9;
void show(vector< pair<int, int> > v) {
    for(int i = 0;i < v.size();i++)
        cout << v[i].first << " " << v[i].second << endl;
    cout << "===========\n";
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        LL A[4], B[4], C[4], M[4];
        cin >> p[0] >> p[1] >> A[0] >> B[0] >> C[0] >> M[0];
        cin >> h[0] >> h[1] >> A[1] >> B[1] >> C[1] >> M[1];
        cin >> x[0] >> x[1] >> A[2] >> B[2] >> C[2] >> M[2];
        cin >> y[0] >> y[1] >> A[3] >> B[3] >> C[3] >> M[3];
        for(int i = 2;i < n;i++) {
            p[i] = (A[0] * p[i-1] + B[0] * p[i-2] + C[0]) % M[0] + 1;
            h[i] = (A[1] * h[i-1] + B[1] * h[i-2] + C[1]) % M[1] + 1;
        }
        for(int i = 2;i < k;i++) {
            x[i] = (A[2] * x[i-1] + B[2] * x[i-2] + C[2]) % M[2] + 1;
            y[i] = (A[3] * y[i-1] + B[3] * y[i-2] + C[3]) % M[3] + 1;
        }
        vector< pair<int, int> > vec1, vec2;
        for(int i = 0;i < n;i++) 
            vec1.push_back(make_pair(p[i]+h[i], -p[i]+h[i]));
        for(int i = 0;i < k;i++) 
            vec2.push_back(make_pair(x[i]+y[i], -x[i]+y[i]));
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        reverse(vec1.begin(), vec1.end());
        reverse(vec2.begin(), vec2.end());
        // show(vec1);
        // show(vec2);
        int ans = 0, i = 0, maxY = -INF;
        for(int j = 0;j < k;j++) {
            while(i < n && vec1[i].first >= vec2[j].first) {
                maxY = max(maxY, vec1[i].second);
                i++;
            }
            if(vec2[j].second <= maxY)
                ans++;
        }
            
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}