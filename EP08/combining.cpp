#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 4e5 + 10;
const int Q = 1e5 + 10;

unordered_map<int, int> mp;
vector<pair<int, int>> qs;
LL query[2 * N];
int x[N], y[N], z[Q], l[N], r[N], k[Q];
int sc[2 * N], cnt[2 * N];

void display(int len, int a[])
{
    for (int i = 0; i < len; i++)
        printf("%2d%c", a[i], " \n"[i == len - 1]);
}
void display(int len, LL a[])
{
    for (int i = 0; i < len; i++)
        printf("%2lld%c", a[i], " \n"[i == len - 1]);
}
int main()
{
    int T, o = 0;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        LL A1, B1, C1, M1;
        LL A2, B2, C2, M2;
        LL A3, B3, C3, M3;
        cin >> x[0] >> x[1] >> A1 >> B1 >> C1 >> M1;
        cin >> y[0] >> y[1] >> A2 >> B2 >> C2 >> M2;
        cin >> z[0] >> z[1] >> A3 >> B3 >> C3 >> M3;
        for (int i = 2; i < n; i++)
        {
            x[i] = (A1 * x[i - 1] + B1 * x[i - 2] + C1) % M1;
            y[i] = (A2 * y[i - 1] + B2 * y[i - 2] + C2) % M2;
        }
        for (int i = 0; i < n; i++)
        {
            l[i] = min(x[i], y[i]) + 1;
            r[i] = max(x[i], y[i]) + 2;
        }
        for (int i = 2; i < q; i++)
            z[i] = (A3 * z[i - 1] + B3 * z[i - 2] + C3) % M3;
        for (int i = 0; i < q; i++)
            k[i] = z[i] + 1;

        // display(n, l);
        // display(n, r);
        // display(q, k);
        // cout << "------\n" ;

        int sz = 2 * n;
        LL all = 0;
        memset(sc, 0, sizeof(sc));
        memset(cnt, 0, sizeof(cnt));
        mp.clear();
        for (int i = 0; i < n; i++)
        {
            sc[i << 1] = l[i];
            sc[i << 1 | 1] = r[i];
            all += 1LL * (r[i] - l[i]);
        }
        sort(sc, sc + sz);
        sz = unique(sc, sc + sz) - sc;
        for (int i = 0; i < sz; i++)
        {
            mp[sc[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cnt[mp[l[i]]]++;
            cnt[mp[r[i]]]--;
        }
        for (int i = 1; i < sz; i++)
            cnt[i] += cnt[i - 1];

        memset(query, 0, sizeof(query));
        query[sz - 1] = cnt[sz - 1];
        for (int i = sz - 2; i >= 0; i--)
            query[i] = query[i + 1] + 1LL * (sc[i + 1] - sc[i]) * cnt[i];

        // cout << all << "->" << sz << endl;
        // display(sz, sc);
        // display(sz, cnt);
        // display(sz, query);

        LL ans = 0, mover = sz-1, kp = 0;
        qs.erase(qs.begin(), qs.end());
        for(int i = 0;i < q;i++)
            qs.push_back(make_pair(k[i], i+1));
        sort(qs.begin(), qs.end());
        while(mover >= 0 && kp < qs.size()) {
            if (query[mover] >= qs[kp].first) {
                ans += (sc[mover] + (query[mover] - qs[kp].first) / cnt[mover]) * 1LL * qs[kp].second;
                kp++;
            } else {
                mover--;
            }
        }

        printf("Case #%d: %lld\n", ++o, ans);
    }
    return 0;
}