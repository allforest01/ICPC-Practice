#include <bits/stdc++.h>
using namespace std;

#define ar array

void Main() {
  int n; cin >> n;
  vector<ar<int,2>> segs(n);
  for (auto &i : segs) {
    cin >> i[0] >> i[1];
  }
  sort(segs.begin(), segs.end());
  {
    multiset<int> candi;
    int i = 0, p = 0;
    while (i < n || candi.size()) {
      if (!candi.size()) {
        p = max(p, segs[i][0]);
      }
      while (i < n && segs[i][0] <= p) {
        candi.insert(segs[i][1]);
        i++;
      }
      if (*candi.begin() < p) {
        cout << "No" << '\n';
        return;
      }
      p++;
      candi.erase(candi.begin());
    }
  }
  cout << "Yes" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) Main();
}
