#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];

template<typename T>
bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  map<int,int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = -1, mi = INT_MAX;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] == 1 && chmin(mi, a[i])) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
