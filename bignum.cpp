#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> bigNum;

const ll BASE = 1e9;

bigNum stobn(string s) {
  bigNum c;
  reverse(s.begin(), s.end());
  while ((int) s.size() % 9) s += '0';
  reverse(s.begin(), s.end());
  for (int i = (int) s.size() - 9; i >= 0; i -= 9) {
    c.push_back(stoll(s.substr(i, 9)));
  }
  return c;
}

bigNum normalize(bigNum a) {
  while (a.size() > 1 && a.back() == 0) a.pop_back();
  return a;
}

bigNum operator+(bigNum a, bigNum b) {
  while (a.size() < b.size()) a.push_back(0);
  while (b.size() < a.size()) b.push_back(0);
  bigNum c; c.resize(a.size());
  ll d = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    c[i] = (a[i] + b[i] + d) % BASE;
    d = (a[i] + b[i] + d) / BASE;
  }
  if (d) c.push_back(d);
  return normalize(c);
}

bigNum operator-(bigNum a, bigNum b) {
  while (b.size() < a.size()) b.push_back(0);
  bigNum c; c.resize(a.size());
  ll d = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    c[i] = a[i] - (b[i] + d);
    if (c[i] < 0) c[i] += BASE, d = 1; else d = 0;
  }
  return normalize(c);
}

bigNum operator*(bigNum a, ll b) {
  bigNum c; c.resize(a.size());
  ll d = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    c[i] = (a[i] * b + d) % BASE;
    d = (a[i] * b + d) / BASE;
  }
  if (d) c.push_back(d);
  return normalize(c);
}

bigNum shift(bigNum a, int b) {
  reverse(a.begin(), a.end());
  for (int i = 0; i < b; i++) {
    a.push_back(0);
  }
  reverse(a.begin(), a.end());
  return a;
}

bigNum operator*(bigNum a, bigNum b) {
  bigNum c; c.resize(1, 0);
  for (int i = 0; i < (int) b.size(); i++) {
    c = c + shift(a * b[i], i);
  }
  return normalize(c);
}

bool operator>=(bigNum a, bigNum b) {
  if (a.size() > b.size()) return true;
  if (a.size() < b.size()) return false;
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
  }
  return true;
}

ostream& operator<<(ostream &os, bigNum a) {
  int n = a.size();
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) os << a[i];
    else os << setw(9) << setfill('0') << a[i];
  }
  return os;
}

istream& operator>>(istream &is, bigNum &a) {
  string s; is >> s;
  a = stobn(s);
  return is;
}

signed main() {
  bigNum a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  if (a >= b) cout << a - b << '\n';
  else cout << '-' << b - a << '\n';
  cout << a * b << '\n';
}
