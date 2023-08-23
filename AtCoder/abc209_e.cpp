#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

const int N = 400005;

vector<int> adj[N], radj[N];
int state[N], out[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<string> s(n);
  map<string,int> id; int cid = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    string s1 = s[i].substr(0, 3);
    string s2 = s[i].substr(sz(s[i]) - 3, 3);
    if (!id.count(s1)) id[s1] = ++cid;
    if (!id.count(s2)) id[s2] = ++cid;
    adj[id[s1]].push_back(id[s2]);
    radj[id[s2]].push_back(id[s1]);
    out[id[s1]]++;
  }
  // 1 - win | 2 - lose | 0 - draw
  queue<int> q;
  for (int i = 1; i <= cid; i++) {
    if (!out[i]) {
      state[i] = 2;
      q.push(i);
    }
  }
  while (q.size()) {
    int i = q.front(); q.pop();
    for (auto &j : radj[i]) if (state[j] == 0) {
      out[j]--;
      if (state[i] == 2) {
        state[j] = 1;
        q.push(j);
      }
      else if (out[j] == 0) {
        state[j] = 2;
        q.push(j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    string s2 = s[i].substr(sz(s[i]) - 3, 3);
    int t = state[id[s2]];
    if (t == 1) cout << "Aoki" << '\n';
    else if (t == 2) cout << "Takahashi" << '\n';
    else cout << "Draw" << '\n';
  }
}
