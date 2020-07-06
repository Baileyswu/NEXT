#include <bits/stdc++.h>
using namespace std;
#define S 10000
#define N 10000
int x[S];
int walk() {
    int s = 1, t = 0;
    while (s != 0 && t < S) {
        int dir = rand()%2 ? 1 : -1;
        t++;
        s += dir;
    }
    if (t > 10000)
        return -1;
    return t;
}
int main() {
    srand((unsigned)time(NULL));
    int n = N;
    double E = 0;
    memset(x, 0, sizeof(x));
    for(int i = 0;i < n;i++) {
        int s = walk();
        if (s > 0 && s < S)
            x[s]++;
    }
    for(int i = 0;i < S;i++)
        E += 1.0 * x[i] / n * i;
    printf("Expectation: %.f\n", E);
    return 0;
}