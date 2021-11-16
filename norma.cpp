#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500005;
const int block = sqrt(N);

int a[N];
int lmin[N], rmin[N];
int lmax[N], rmax[N];
int lpos = 0, rpos = 0, len = 1, ans = 0;

void addRight() {
  rpos++; len++;
  cout << "> " << rpos - lmax[rpos] << ' ' << len << '\n';
  ans += min(rpos - lmax[rpos], len) * a[rpos];
}

void addLeft() {
  lpos--; len++;
  ans += min(rmax[lpos] - lpos, len) * a[lpos];
}

void remRight() {
  ans -= min(rpos - lmax[rpos], len) * a[rpos];
  rpos--; len--;
}

void remLeft() {
  ans -= min(rmax[lpos] - lpos, len) * a[lpos];
  lpos++; len--;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (j >= 1 && a[j] >= a[i]) j = lmin[j];
    lmin[i] = j;
  }
  for (int i = n; i >= 1; i--) {
    int j = i + 1;
    while (j <= n && a[j] >= a[i]) j = rmin[j];
    rmin[i] = j;
  }
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (j >= 1 && a[j] <= a[i]) j = lmax[j];
    lmax[i] = j;
  }
  for (int i = n; i >= 1; i--) {
    int j = i + 1;
    while (j <= n && a[j] <= a[i]) j = rmax[j];
    rmax[i] = j;
  }
  vector<array<int,3>> query;
  for (int i = 1; i <= n; i++) {
    query.push_back({lmin[i] + 1, rmin[i] - 1, a[i]});
  }
  sort(query.begin(), query.end(),
    [](array<int,3> &a, array<int,3> &b)->bool {
      if (a[0] / block == b[0] / block) {
        return a[1] / block > b[1] / block;
      }
      return a[0] / block < b[0] / block;
    }
  );
  int res = 0;
  for (auto &i : query) {
    while (lpos < i[0]) remLeft();
    cout << lpos << ' ' << rpos << ' ' << len << ' ' << ans << '\n';
    while (lpos > i[0]) addLeft();
    cout << lpos << ' ' << rpos << ' ' << len << ' ' << ans << '\n';
    while (rpos < i[1]) addRight();
    cout << lpos << ' ' << rpos << ' ' << len << ' ' << ans << '\n';
    while (rpos > i[1]) remRight();
    cout << lpos << ' ' << rpos << ' ' << len << ' ' << ans << '\n';
    cout << '\n';
    cout << i[0] << ' ' << i[1] << ' ' << ans << '\n';
    cout << '\n';
    res += i[2] * ans;
  }
  cout << res << '\n';
}
