#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int succ[N], in[N];
int res[N], ins[N];

int vst(int i) {
  ins[i] = 1;
  int t = succ[i];
  if (!ins[t]) t = vst(succ[i]);
  if (ins[t]) res[i] = i; else res[i] = t;
  ins[i] = 0;
  return t;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> succ[i];
    in[succ[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!in[i] ) vst(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!res[i]) vst(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}
