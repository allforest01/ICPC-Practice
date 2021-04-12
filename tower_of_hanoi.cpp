#include <bits/stdc++.h>
using namespace std;

void left(int, int, int);

void right(int l, int r, int n){
    int k = 6 - l - r;
    if(n==1){
        printf("%d -> %d\n", l, r);
    }
    else{
        left(l, k, n-1);
        right(l, r, 1);
        left(k, r, n-1);
    }
}

void left(int l, int r, int n){
    int k = 6 - l - r;
    if(n==1){
        right(l, k, 1);
        right(k, r, 1);
    }
    else {
        left(l, r, n-1);
        right(l, k, 1);
        right(r, l, n-1);
        right(k, r, 1);
        left(l, r, n-1);
    }
}

long long dp(int n){
    vector<long long> f(n+1);
    f[0] = 0; f[1] = 1;
    for(int i=2; i<=n; i++)
        f[i] = (f[i-1] + f[i-2]) * 2 + 3;
    return f[n];
}

int main(){
    int n; cin >> n;
    printf("Minimum Moves: %d\n", dp(n));
    right(1, 2, n);
}
