#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  if (sum % n == 0) {
    cout << 0 << '\n';
    return;
  }
  long long m = sum % n;
  cout << m * (n - m) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
