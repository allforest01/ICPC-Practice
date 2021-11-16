#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int isPrime[N], cntMax[N];
vector<int> prime;

void chmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 2; i < N; i++) {
    isPrime[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j < N; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) prime.push_back(i);
  }
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 1 << ' ';
      continue;
    }
    int x = i, ma = 0;
    for (int j = 0; prime[j] * prime[j] <= x; j++) {
      int cnt = 0;
      while (x % prime[j] == 0) {
        cnt++;
        x /= prime[j];
      }
      chmax(cntMax[j], cnt + 1);
      chmax(ma, cntMax[j]);
    }
    if (x > 1) {
      chmax(cntMax[x], 2);
      chmax(ma, cntMax[x]);
    }
    cout << ma << ' ';
  }
  cout << '\n';
}
