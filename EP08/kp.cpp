/* ---
title: "2018 Round G - Combining Classes"
author: Bin Kuang
--- */

#include <bits/stdc++.h>
using namespace std;

int X[400010];
int Y[400010];
int Z[400010];
int L[400010];
int R[400010];
int K[400010];
int a[800010];

int f[800010];
// g[i] means how many students have scores >= a[i].
long long g[800010];

int main() {
  int T;
  int iCase = 0;
  scanf("%d", &T);
  while (T--) {
    iCase++;
    int N, Q;
    scanf("%d%d", &N, &Q);
    int A1, B1, C1, M1;
    scanf("%d%d%d%d%d%d", &X[1], &X[2], &A1, &B1, &C1, &M1);
    for (int i = 3; i <= N; i++) {
      X[i] = ((long long)A1*X[i-1] + (long long)B1 * X[i-2] + C1) % M1;
    }
    int A2, B2, C2, M2;
    scanf("%d%d%d%d%d%d", &Y[1], &Y[2], &A2, &B2, &C2, &M2);
    for (int i = 3; i <= N; i++) {
      Y[i] = ((long long)A2*Y[i-1] + (long long)B2 * Y[i-2] + C2) % M2;
    }
    int A3, B3, C3, M3;
    scanf("%d%d%d%d%d%d", &Z[1], &Z[2], &A3, &B3, &C3, &M3);
    for (int i = 3; i <= Q; i++) {
      Z[i] = ((long long)A3*Z[i-1] + (long long)B3 * Z[i-2] + C3) % M3;
    }

    for (int i = 1; i <= N; i++) {
      L[i] = min(X[i], Y[i]) + 1;
      R[i] = max(X[i], Y[i]) + 2;
    }
    for (int i = 1; i <= Q; i++) {
      K[i] = Z[i] + 1;
    }

    int tot = 0;
    for (int i = 1; i <= N; i++) {
      a[tot++] = L[i];
      a[tot++] = R[i];
    }
    sort(a, a + tot);
    tot = unique(a, a+tot) - a;
    for (int i = 1; i <= N; i++) {
      L[i] = lower_bound(a, a+tot, L[i]) - a;
      R[i] = lower_bound(a, a+tot, R[i]) - a;
    }

    memset(f, 0, sizeof(f));
    for (int i = 1; i <= N; i++) {
      f[L[i]]++;
      f[R[i]]--;
    }
    for (int i = 1; i < tot; i++) {
      f[i] += f[i-1];
    }
    for (int i = tot-1; i >= 0; i--) {
      if (i == tot-1) {
        g[i] = f[i];
        continue;
      }
      g[i] = g[i+1] + (long long)f[i] * (a[i+1]-a[i]);
    }

    // for(int i = 0;i < tot;i++)
        // printf("%lld%c", g[i], " \n"[i==tot-1]);

    long long ans = 0;
    for (int i = 1; i <= Q; i++) {
      if (K[i] > g[0]) {
        continue;
      }
      int ret = 0;
      int l = 0, r = tot-1;
      while (l <= r) {
        int mid = (l+r)/2;
        if (g[mid] >= K[i]) {
          ret = mid;
          l = mid+1;
        } else {
          r = mid-1;
        }
      }
      int tmp = a[ret] + (g[ret] - K[i])/f[ret];
      ans += (long long)tmp*i;
    }
    printf("Case #%d: %lld\n", iCase, ans);
  }
  return 0;
}