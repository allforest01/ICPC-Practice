#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N   =     105;
const int MOD = 1e9 + 7;

int n;
map<string, int> mem[N];

string concat(char a, char b, char c) {
  string ret;
  ret += a; ret += b; ret += c;
  return ret;
}

bool check(string str, char chr) {
  str += chr;
  for (int i = 0; i < 2; i++) {
    string t = str.substr(i, 3);
    if (t == "AGC" || t == "GAC" || t == "ACG") {
      return 0;
    }
  }
  for (int i = 0; i < 4; i++)
  for (int j = i + 1; j < 4; j++)
  for (int k = j + 1; k < 4; k++) {
    if (concat(str[i], str[j], str[k]) == "AGC") {
      return 0;
    }
  }
  return 1;
}

int dfs(int cur, string str) {
  if (cur == n) return 1;
  if (mem[cur].count(str)) return mem[cur][str];
  int ret = 0;
  string nxt = str.substr(1, 2);
  for (auto chr : {'A', 'C', 'G', 'T'}) {
    if (check(str, chr)) {
      (ret += dfs(cur + 1, nxt + chr)) %= MOD;
    }
  }
  return mem[cur][str] = ret;
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << dfs(0, "---") << '\n';
}
