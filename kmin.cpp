#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

int n, m, k;
int a[N], b[N];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
  for (int i = 1; i <= m; i++) {
    q.push({a[1] + b[i], 1, i});
  }
  while (q.size() && k) {
    auto i = q.top(); q.pop();
    k--;
    cout << i[0] << '\n';
    if (i[1] + 1 <= n) q.push({a[i[1] + 1] + b[i[2]], i[1] + 1, i[2]});
  }
}
