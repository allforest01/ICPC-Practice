#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  int n; cin >> n;
  vector<int> a(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  int ans = 0;
  unordered_map<int,int> f; f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = s[j] - s[i];
      if (f.count(s[i] - sum)) {
        chmax(ans, j - f[s[i] - sum]);
      }
    }
    if (!f.count(s[i])) f[s[i]] = i;
  }
  cout << ans << '\n';
}
