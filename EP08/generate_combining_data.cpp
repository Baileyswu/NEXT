#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;
const int Q = 1e5;
const int M = 1e9;

int main() {
    int T = 100;
    cout << T << endl;
    srand((unsigned)time(NULL));
    while(T--) {
        int n = rand() % N + 1;
        int q = rand() % Q + 1;
        cout << n << " " << q << endl;
        int a[3], b[3], c[3], m[3], x[2], y[2], z[2];
        for(int i = 0;i < 3;i++) {
            m[i] = rand() % M + 1;
            a[i] = rand() % m[i];
            b[i] = rand() % m[i];
            c[i] = rand() % m[i];
        }
        x[0] = rand() % m[0];
        x[1] = rand() % m[0];
        y[0] = rand() % m[1];
        y[1] = rand() % m[1];
        z[0] = rand() % m[2];
        z[1] = rand() % m[2];
        cout << x[0] << " " << x[1] << " " << a[0] << " " << b[0] << " " << c[0] << " " << m[0] << endl;
        cout << y[0] << " " << y[1] << " " << a[1] << " " << b[1] << " " << c[1] << " " << m[1] << endl;
        cout << z[0] << " " << z[1] << " " << a[2] << " " << b[2] << " " << c[2] << " " << m[2] << endl;
    }
    return 0;
}