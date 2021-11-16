#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k, pow2[N];
string s; char mem[N][N];

int mod(int x) {
  return (x % n + n) % n;
}

char win(char a, char b) {
  if (a == b) return a;
  if ((a == 'R' && b == 'S') || (a == 'S' && b == 'R')) return 'R';
  if ((a == 'P' && b == 'R') || (a == 'R' && b == 'P')) return 'P';
  if ((a == 'S' && b == 'P') || (a == 'P' && b == 'S')) return 'S';
}

char dp(int p, int k) {
  if (k == 0) return s[p];
  if (mem[p][k] != '?') return mem[p][k];
  mem[p][k] = win(dp(p, k - 1), dp(mod(p + pow2[k - 1]), k - 1));
  return mem[p][k];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> s;
  pow2[0] = 1;
  for (int i = 1; i < N; i++) {
    pow2[i] = (pow2[i - 1] * 2) % n;
  }
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++) {
    mem[i][j] = '?';
  }
  cout << dp(0, k) << '\n';
}
