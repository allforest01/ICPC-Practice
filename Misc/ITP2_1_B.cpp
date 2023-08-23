#include <bits/stdc++.h>
using namespace std;

vector<pair<char,int>> BubbleSort(vector<pair<char,int>> a) {
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = (int) a.size() - 1; j > i; j--) {
      if (a[j].second < a[j - 1].second) {
        swap(a[j], a[j - 1]);
      }
    }
  }
  return a;
}

vector<pair<char,int>> SelectionSort(vector<pair<char,int>> a) {
  for (int i = 0; i < (int) a.size(); i++) {
    int mini = i;
    for (int j = i; j < (int) a.size(); j++) {
      if (a[j].second < a[mini].second) mini = j;
    }
    if (i != mini) {
      swap(a[i], a[mini]);
    }
  }
  return a;
}

bool check(vector<pair<char,int>> &a, vector<pair<char,int>> &b) {
  vector<vector<int>> spla(10), splb(10);
  for (auto &i : a) {
    spla[i.second].push_back(i.first);
  }
  for (auto &i : b) {
    splb[i.second].push_back(i.first);
  }
  return spla == splb;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pair<char,int>> a(n);
  for (auto &i : a) {
    char c; int x;
    cin >> c >> x;
    i = make_pair(c, x);
  }
  auto bs = BubbleSort(a);
  auto ss = SelectionSort(a);
  for (int i = 0; i < n; i++) {
    cout << bs[i].first << bs[i].second << " \n"[i + 1 == n];
  }
  cout << (check(bs, a) ? "Stable" : "Not stable") << '\n';
  for (int i = 0; i < n; i++) {
    cout << ss[i].first << ss[i].second << " \n"[i + 1 == n];
  }
  cout << (check(ss, a) ? "Stable" : "Not stable") << '\n';
}
