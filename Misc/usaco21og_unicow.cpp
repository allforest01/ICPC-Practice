#include <bits/stdc++.h>
using namespace std;

struct FT {
  int n; vector<int> bit;
  FT(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] += v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v += bit[i];
    }
    return v;
  }
  void update(int i, int j, int v) {
    update(i, v);
    update(j + 1, -v);
  }
};

int main() {
  int n; cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<long long,int> last;
  vector<int> left(n + 1);
  for (int i = 1; i <= n; i++) {
    left[i] = last[a[i]];
    last[a[i]] = i;
  }
  last.clear();
  vector<int> right(n + 1);
  for (int i = n; i >= 1; i--) {
    if (last.count(a[i])) {
      right[i] = last[a[i]];
    }
    else right[i] = n + 1;
    last[a[i]] = i;
  }
  long long ans = 0;
  FT ft(n);
  for (int i = 1; i <= n; i++) {
    if (left[i]) {
      ft.update(left[i], i - 1, -1);
    }
    ans += ft.get(i) - ft.get(left[i]);
    ft.update(i, right[i] - 1, 1);
  }
  cout << ans << '\n';
}