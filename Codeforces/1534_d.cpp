#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int v[N][N];
vector<int> bi[2];

signed main() {
  int n; cin >> n;
  cout << "? 1" << endl;
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    cin >> v[1][i];
    v[i][1] = v[1][i];
    bi[v[1][i] % 2].push_back(i);
  }
  int target = 0;
  if (bi[0].size() > bi[1].size()) target = 1;
  for (auto &i : bi[target]) {
    if (i == 1) continue;
    cout << "? " << i << endl;
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      cin >> v[i][j];
      v[j][i] = v[i][j];
    }
  }
  cout << '!' << endl;
  fflush(stdout);
  for (int i = 1; i <= n; i++)
  for (int j = i + 1; j <= n; j++) {
    if (v[i][j] == 1) {
      cout << i << ' ' << j << endl;
      fflush(stdout);
    }
  }
  fflush(stdout);
}
