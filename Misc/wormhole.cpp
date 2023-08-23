#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, x[N], y[N];
int hole[N], blocked[N];
int ans = 0;

void check() {
  for (int i = 1; i <= n; i++) {
    cout << hole[i] << ' ';
  }
  cout << '\n';
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (y[i] == y[hole[i]]) cnt++;
  }
  if (cnt) ans++;
}

void brute(int i) {
  if (blocked[i]) {
    if (i == n) check();
    else brute(i + 1);
  }
  else {
    for (int j = i + 1; j <= n; j++) {
      if (!hole[j]) {
        hole[i] = j;
        hole[j] = i;
        blocked[j] = 1;
        if (i == n) check();
        else brute(i + 1);
        hole[i] = 0;
        hole[j] = 0;
        blocked[j] = 0;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  brute(1);
  cout << ans << '\n';
}
