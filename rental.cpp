#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  freopen("rental.in" , "r", stdin );
  freopen("rental.out", "w", stdout);
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> milk(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> milk[i];
  }
  sort(milk.begin() + 1, milk.end(), greater<int>());
  for (int i = 1; i <= n; i++) {
    milk[i] += milk[i - 1];
  }
  vector<pair<int,int>> store(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> store[i].first >> store[i].second;
  }
  sort(store.begin() + 1, store.end(), [](pair<int,int> &a, pair<int,int> &b) -> bool {
    return a.second > b.second;
  });
  auto sum_store = store;
  for (int i = 1; i <= m; i++) {
    sum_store[i].first += sum_store[i - 1].first;
    sum_store[i].second = sum_store[i - 1].second + store[i].second * store[i].first;
  }
  vector<int> farmer(r + 1);
  for (int i = 1; i <= r; i++) {
    cin >> farmer[i];
  }
  sort(farmer.begin() + 1, farmer.end(), greater<int>());
  for (int i = 1; i <= r; i++) {
    farmer[i] += farmer[i - 1];
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int cal = farmer[min(i, r)];
    int sum_milk = milk[n - i];
    int p = lower_bound(sum_store.begin(), sum_store.end(), make_pair(sum_milk, 0LL)) - sum_store.begin();
    if (p == m + 1) {
      cal += sum_store.back().second;
    }
    else {
      cal += sum_store[p].second - (store[p].second * (sum_store[p].first - sum_milk));
    }
    ans = max(ans, cal);
  }
  cout << ans << '\n';
}
