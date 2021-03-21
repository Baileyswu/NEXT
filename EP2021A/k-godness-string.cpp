#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1;
int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int samepair = 0;
        for(int i = 0;i < n/2;i++)
            if(s[i] == s[n-1-i]) samepair++;
        int dff = n/2 - samepair;
        int ans = dff > k ? dff-k : k-dff;
        printf("Case #%d: %d\n", ++o, ans);
    }
    return 0;
}
