#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  if (n <= 0) return 0;
  return n * (n + 1) / 2;
}

int main() {
  int n; cin >> n;
  vector<int> len(n + 1);
  len[0] = 0;
  len[1] = 1;
  for (int i = 2; i <= n; i++) {
    len[i] = 2 * len[i - 1] - len[i - 2] + i;
  }
  vector<int> duoi(n + 1);
  duoi[0] = 0;
  duoi[1] = 0;
  duoi[2] = 1;
  duoi[3] = 3;
  for (int i = 4; i <= n; i++) {
    duoi[i] = 2 * duoi[i - 2] - duoi[i - 4] + i * 2 - 3;
  }
  for (int i = 1; i <= n; i++) {
    cout << len[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << duoi[i] << ' ';
  }
  cout << '\n';
}