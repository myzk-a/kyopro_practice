// 028 - Cluttered Paper（★4）https://atcoder.jp/contests/typical90/tasks/typical90_ab
// 解説 https://github.com/E869120/kyopro_educational_90/blob/main/editorial/028.jpg

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> m(1001, vector<ll>(1001, 0));
    for (ll i = 0; i < N; ++i)
    {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        ++m[lx][ly];
        ++m[rx][ry];
        --m[lx][ry];
        --m[rx][ly];
    }

    for (ll y = 0; y <= 1000; ++y)
    {
        for (ll x = 0; x < 1000; ++x) m[x + 1][y] += m[x][y];
    }
    for (ll x = 0; x <= 1000; ++x)
    {
        for (ll y = 0; y < 1000; ++y) m[x][y + 1] += m[x][y];
    }

    vector<ll> ans(N + 1, 0);
    for (ll x = 0; x <= 1000; ++x)
    {
        for (ll y = 0; y <= 1000; ++y) ans[m[x][y]]++;
    }

    for (ll i = 1; i <= N; ++i) cout << ans[i] << endl;

    return 0;
}