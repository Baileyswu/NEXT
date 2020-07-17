#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int Q = 1e5;
bool v[N+10];
int main() {
    int T = 1;
    cout << T << endl;
    srand((unsigned)time(NULL));
    while(T--) {
        // int n = rand() % N + 2;
        // int q = rand() % Q + 1;
        int n = 20;
        int q = 20;
        cout << n << " " << q << endl;
        memset(v, false, sizeof(v));
        for(int i = 1;i < n;i++) {
            int t = rand() % (N-1) + 1;
            while(v[t]) t = t % (N-1) + 1;
            v[t] = true;
            cout << t << " ";
        }
        cout << endl;
        for(int i = 0;i < q;i++) {
            int s = rand() % n + 1;
            int k = rand() % n + 1;
            cout << s << " " << k << endl;
        }
    }
    return 0;
}