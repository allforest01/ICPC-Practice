#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define X first
#define Y second

const int N = 100005;

struct FW {
  int n; vector<int> bit;
  FW(int n): n(n), bit(n + 1) {}
  void update(int i, int v) {
    for (; i <= n; i += i & -i) {
      bit[i] += v;
    }
  }
  int get(int i) {
    int v = 0;
    for (; i; i -= i & -i) {
      v += bit[i];
    }
    return v;
  }
};

int n, q, maxVal = 0;
int a[N]; pii qr[N];

template<typename T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}

namespace sub1 {
  void Main() {
    a[qr[1].X] = qr[1].Y;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      vector<int> lastPos(25);
      int cnt = 0;
      for (int j = i; j <= n; j++) {
        if (!lastPos[a[j]]) cnt++;
        lastPos[a[j]] = j;
        ans += cnt;
      }
    }
    cout << ans << '\n';
  }
}

namespace sub2 {
  void Main() {
    a[qr[1].X] = qr[1].Y;
    ll ans = 0, cnt = 0;
    vector<int> lastPos(25);
    for (int i = 1; i <= n; i++) {
      cnt += i - lastPos[a[i]];
      lastPos[a[i]] = i;
      ans += cnt;
    }
    cout << ans << '\n';
  }
}

namespace sub3 {
  void Main() {
    a[qr[1].X] = qr[1].Y;
    ll ans = 0;
    vector<set<int>> pos(maxVal + 1);
    for (int i = 1; i <= n; i++) {
      if (!pos[a[i]].size()) pos[a[i]].insert(0);
      ll d = i - *pos[a[i]].rbegin();
      ans += d * (n - i + 1);
      pos[a[i]].insert(i);
    }
    cout << ans << '\n';
    for (int i = 2; i <= q; i++) {
      int curPos = qr[i].X;
      int updVal = qr[i].Y;
      int curVal = a[curPos];
      // remove
      auto it = pos[curVal].lower_bound(curPos);
      ll d = curPos - *prev(it);
      ans -= d * (n - curPos + 1);
      if (next(it) != pos[curVal].end()) {
        ans += d * (n - *next(it) + 1);
      }
      pos[curVal].erase(curPos);
      // update
      pos[updVal].insert(curPos);
      it = pos[updVal].lower_bound(curPos);
      d = curPos - *prev(it);
      ans += d * (n - curPos + 1);
      if (next(it) != pos[updVal].end()) {
        ans -= d * (n - *next(it) + 1);
      }
      // ------
      a[curPos] = updVal;
      cout << ans << '\n';
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    chmax(maxVal, a[i]);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> qr[i].X >> qr[i].Y;
    chmax(maxVal, qr[i].Y);
  }
  if (n <= 1000 && maxVal <= 20 && q == 1) sub1::Main();
  else if (n <= 1e5 && maxVal <= 20 && q == 1) sub2::Main();
  else sub3::Main();
}
