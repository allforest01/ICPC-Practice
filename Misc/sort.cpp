#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = b.size();
  int ma = 0;
  vector<int> sav;
  do {
    vector<int> a = b;
    int moo = 0;
    bool sorted = false;
    while (!sorted) {
      sorted = true;
      // cout << "moo" << '\n';
      moo++;
      for (int i = 0; i <= n - 2; i++) {
        if (a[i + 1] < a[i]) {
          swap(a[i], a[i + 1]);
          sorted = false;
        }
      }
    }
    if (moo > ma) {
      ma = moo;
      sav = b;
    }
  } while (next_permutation(b.begin(), b.end()));
  cout << "ma = " << ma << '\n';
  for (auto &i : sav) {
    cout << i << ' ';
  }
  cout << '\n';
}
