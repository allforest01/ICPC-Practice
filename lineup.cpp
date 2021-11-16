#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lineup.in" , "r", stdin );
  freopen("lineup.out", "w", stdout);
  // cin.tie(0)->sync_with_stdio(0);
  vector<string> name = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  sort(name.begin(), name.end());
  int n; cin >> n;
  vector<pair<string,string>> a(n);
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> a[i].first;
    while (ss >> a[i].second);
  }
  vector<int> b(8);
  for (int i = 0; i < 8; i++) {
    b[i] = i;
  }
  do {
    int cnt = 0;
    for (int i = 0; i + 1 < 8; i++)
    for (int k = 0; k < n; k++) {
      if (name[b[i]] == a[k].first && name[b[i + 1]] == a[k].second) cnt++;
      if (name[b[i + 1]] == a[k].first && name[b[i]] == a[k].second) cnt++;
    }
    if (cnt == n) break;
  } while (next_permutation(b.begin(), b.end()));
  for (int i = 0; i < 8; i++) {
    cout << name[b[i]] << '\n';
  }
}
