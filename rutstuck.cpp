#include <bits/stdc++.h>
using namespace std;

const int N = 55;

char dir[N];
int x[N], y[N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dir[i] >> x[i] >> y[i];
  }
  vector<tuple<int,int,int,int>> inter;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
    if (i == j) continue;
    if (dir[i] == 'N' && dir[j] == 'E' && y[i] < y[j] && x[i] > x[j]) {
      if (y[j] - y[i] > x[i] - x[j]) {
        inter.push_back(make_tuple(y[j] - y[i], i, j, x[i] - x[j]));
      }
      else if (y[j] - y[i] < x[i] - x[j]) {
        inter.push_back(make_tuple(x[i] - x[j], j, i, y[j] - y[i]));
      }
    }
    if (dir[i] == 'N' && dir[j] == 'W' && y[i] < y[j] && x[i] < x[j]) {
      if (y[j] - y[i] > x[j] - x[i]) {
        inter.push_back(make_tuple(y[j] - y[i], i, j, x[j] - x[i]));
      }
      else if (y[j] - y[i] < x[j] - x[i]) {
        inter.push_back(make_tuple(x[j] - x[i], j, i, y[j] - y[i]));
      }
    }
    if (dir[i] == 'S' && dir[j] == 'E' && y[i] > y[j] && x[i] > x[j]) {
      if (y[i] - y[j] > x[i] - x[j]) {
        inter.push_back(make_tuple(y[i] - y[j], i, j, x[i] - x[j]));
      }
      else if (y[i] - y[j] < x[i] - x[j]) {
        inter.push_back(make_tuple(x[i] - x[j], j, i, y[i] - y[j]));
      }
    }
    if (dir[i] == 'S' && dir[j] == 'W' && y[i] > y[j] && x[i] < x[j]) {
      if (y[i] - y[j] > x[j] - x[i]) {
        inter.push_back(make_tuple(y[i] - y[j], i, j, x[j] - x[i]));
      }
      else if (y[i] - y[j] < x[j] - x[i]) {
        inter.push_back(make_tuple(x[j] - x[i], j, i, y[i] - y[j]));
      }
    }
  }
  sort(inter.begin(), inter.end());
  vector<int> res(n, INT_MAX);
  for (auto &i : inter) {
    if (res[get<2>(i)] > get<3>(i)) {
      chmin(res[get<1>(i)], get<0>(i));
    }
  }
  for (auto &i : res) {
    if (i == INT_MAX) cout << "Infinity" << '\n';
    else cout << i << '\n';
  }
}
