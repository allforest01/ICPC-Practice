#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  multiset<int> ms;
  for (int i = 0; i < k; i++) {
    ms.insert(a[i]);
  }
  cout << *ms.begin() << ' ';
  for (int i = k; i < n; i++) {
    ms.erase(ms.find(a[i - k]));
    ms.insert(a[i]);
    cout << *ms.begin() << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
