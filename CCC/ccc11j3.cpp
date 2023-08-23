#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<int> sumac(3);
  cin >> sumac[1] >> sumac[2];
  for (int i = 3; ; i++) {
    sumac.push_back(0);
    sumac[i] = sumac[i - 2] - sumac[i - 1];
    if (sumac[i - 1] < sumac[i]) {
      cout << i << '\n';
      return 0;
    }
  }
}
