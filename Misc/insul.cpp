#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  deque<int> a(n);
  int sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  sort(a.begin(), a.end());
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      b.push_back(a.front());
      a.pop_front();
    }
    else {
      b.push_back(a.back());
      a.pop_back();
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += max(0, b[i] - b[i - 1]);
  }
  cout << sum + ans << '\n';
}