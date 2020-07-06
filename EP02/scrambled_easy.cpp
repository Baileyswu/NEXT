#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define LL long long
bool exits(string s, string k) {
    if(s.length() < k.length())
        return false;
    int mp[26], len = k.length(), diff = 0;
    memset(mp, 0, sizeof(mp));
    for(int i = 0;i < k.length();i++) {
        mp[k[i] - 'a']--;
        mp[s[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++)
        if(mp[i])
            diff++;
    int l = 0, r = len-1;
    if(diff == 0 && k[0] == s[l] && k[len-1] == s[r]) {
        // cout << k << " " << l << " " << s.substr(l, len) << endl;
        return true;
    }
    while(r < s.length()-1) {
        l++;
        r++;
        
        if(mp[s[l-1]-'a'] == 0)
            diff++;
        if(mp[s[r]-'a'] == 0)
            diff++;
        mp[s[l-1]-'a']--;
        mp[s[r]-'a']++;
        if(mp[s[l-1]-'a'] == 0)
            diff--;
        if(mp[s[r]-'a'] == 0)
            diff--;

        if(diff == 0 && k[0] == s[l] && k[len-1] == s[r]) {
            // cout << k << " " << l << " " << s.substr(l, len) << endl;
            return true;
        }
    }
    return false;
}
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int dsize;
        cin >> dsize;
        vector<string> dict;
        for(int i = 0;i < dsize;i++){
            string s;
            cin >> s;
            dict.push_back(s);
        }

        string s1, s2, s;
        int n;
        LL A, B, C, D;
        cin >> s1 >> s2 >> n >> A >> B >> C >> D;
        s = s1 + s2;

        vector<int> x;
        x.push_back(s[0]);
        x.push_back(s[1]);
        for(int i = 2;i < n;i++) {
            x.push_back((A*x[i-1] + B*x[i-2] + C) % D);
            s += x[i] % 26 + 'a';
        }
        // cout << s << endl;

        int ans = 0;
        for(int i = 0;i < dsize;i++) {
            if (exits(s, dict[i]))
                ans++;
        }
        printf("Case #%d: %d\n", ++o, ans);
    }

    return 0;
}