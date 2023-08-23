#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll sum = 0;
  for (auto &i : a) {
    if (i > sum + 1) break;
    sum += i;
  }
  cout << sum + 1 << '\n';
}
