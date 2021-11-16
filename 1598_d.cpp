#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n; cin >> n;
  vector<array<int,2>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][0]--;
    a[i][1]--;
  }
  vector<int> cnt0(n), cnt1(n);
  map<array<int,2>,int> cnt2;
  vector<int> res1(n), res2(n);
  for (int i = 0; i < n; i++) {
    cnt0[a[i][0]]++;
    cnt1[a[i][1]]++;
    cnt2[a[i]]++;
  }
  int s2 = 0;
  for (int i = 0; i < n; i++) {
    int s = n - 1;
    int l = cnt0[a[i][0]] - 1;
    int r = cnt1[a[i][1]] - 1;
    int c = cnt2[a[i]] - 1;
    res1[i] = s - l - r + c;
    s2 += res1[i];
  }
  for (int i = 0; i < n; i++) {
    cnt0[i] = cnt1[i] = 0;
  }
  cnt2.clear();
  for (int i = 0; i < n; i++) {
    cnt0[a[i][0]] += res1[i];
    cnt1[a[i][1]] += res1[i];
    cnt2[a[i]] += res1[i];
  }
  for (int i = 0; i < n; i++) {
    int s = s2 - res1[i] * 2;
    int l = cnt0[a[i][0]] - res1[i];
    int r = cnt1[a[i][1]] - res1[i];
    int c = cnt2[a[i]] - res1[i];
    res2[i] = s - l - r + c;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += res2[i];
  }
  cout << ans / 6 << '\n';
  for (int i = 0; i < n; i++) {
    cout << res1[i] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << res2[i] << ' ';
  }
  cout << '\n';
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}