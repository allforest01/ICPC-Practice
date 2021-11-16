#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> cnt(3);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x <= a) cnt[0]++;
    else if (x <= b) cnt[1]++;
    else cnt[2]++;
  }
  cout << *min_element(cnt.begin(), cnt.end()) << '\n';
}
