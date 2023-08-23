#include <bits/stdc++.h>
using namespace std;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  map<int,int> mem;
  for (int i = 1; i < n; i++)
  for (int j = 0; j < i; j++) {
    chmax(mem[a[i] + a[j]], max(mem[a[i]], mem[a[j]]) + 1);
  }
  int ans = 0;
  for (auto &i : mem) {
    ans = max(ans, i.second);
  }
  cout << ans << '\n';
}