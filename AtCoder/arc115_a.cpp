#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[2];
int mem[2000000];

void dfs(int i, int b) {
  if (mem[i] != -1) return;
  mem[i] = b;
  for (int j = 0; j < m; j++) {
    dfs(i ^ (1 << j), b ^ 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(mem, -1, sizeof(mem));
  cin >> n >> m;
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int num = 0;
    for (int j = 0; j < m; j++) {
      num += (s[j] - '0') << (m - j - 1);
    }
    ans += cnt[mem[num] ^ 1];
    cnt[mem[num]]++;
  }
  cout << ans << '\n';
}
