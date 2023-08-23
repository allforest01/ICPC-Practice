#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; long long k;
  cin >> n >> k;
  vector<pair<long long,long long>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  sort(a.begin(), a.end());
  long long p = 0;
  for (auto &i : a) {
    long long d = i.first - p;
    if (k >= d) {
      k -= d;
      p = i.first;
      k += i.second;
    }
    else break;
  }
  cout << p + k << '\n';
}
