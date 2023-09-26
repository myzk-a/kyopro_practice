// https://atcoder.jp/contests/typical90/tasks/typical90_bo
// https://twitter.com/e869120/status/1404931743820357633/photo/1

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 8進数->10進数
ll f1(string N)
{
    ll res = 0;
    ll w = 1;
    for (ll i = N.size() - 1; i >= 0; --i)
    {
        ll tmp = N[i] - (ll)'0';
        res += tmp * w;
        w *= 8;
    }
    return res;
}

// 10進数->8進数
string f2(ll N)
{
    ll res = 0;
    ll w = 1;
    while (N > 0)
    {
        ll tmp = N % 9;
        if (tmp == 8) tmp = 5;
        res += tmp * w;
        w *= 10;
        N /= 9;
    }
    return to_string(res);
}

int main()
{
    string N;
    ll K;
    cin >> N >> K;
    ll n;
    for (ll i = 0; i < K; ++i)
    {
        n = f1(N);
        N = f2(n);
    }
    cout << N << endl;
    return 0;
}