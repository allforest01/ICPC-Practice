#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  deque<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      cout << a.front();
      a.pop_front();
    }
    else {
      cout << a.back();
      a.pop_back();
    }
    cout << " \n"[i + 1 == n];
  }
  for (int i = 0; i < n - n % 2; i++) {
    cout << (i % 2 ? 'S' : 'B');
  }
  if (n % 2) cout << 'E';
  cout << '\n';
}
