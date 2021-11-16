#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  vector<int> usb, ps2;
  for (int i = 0; i < n; i++) {
    int p; string s;
    cin >> p >> s;
    if (s == "USB") usb.push_back(p);
    else ps2.push_back(p);
  }
  sort(usb.begin(), usb.end(), greater<int>());
  sort(ps2.begin(), ps2.end(), greater<int>());
  long long ans = 0, cnt = 0;
  while (a && usb.size()) {
    ans += usb.back();
    usb.pop_back();
    a--;
    cnt++;
  }
  while (b && ps2.size()) {
    ans += ps2.back();
    ps2.pop_back();
    b--;
    cnt++;
  }
  while (c && (usb.size() || ps2.size())) {
    if (usb.size() && ps2.size()) {
      if (usb.back() < ps2.back()) {
        ans += usb.back();
        usb.pop_back();
        c--;
        cnt++;
      }
      else {
        ans += ps2.back();
        ps2.pop_back();
        c--;
        cnt++;
      }
    }
    else if (usb.size()) {
      ans += usb.back();
      usb.pop_back();
      c--;
      cnt++;
    }
    else {
      ans += ps2.back();
      ps2.pop_back();
      c--;
      cnt++;
    }
  }
  cout << cnt << ' ' << ans << '\n';
}
