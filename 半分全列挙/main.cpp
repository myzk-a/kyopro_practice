// 051 - Typical Shop（★5） https://atcoder.jp/contests/typical90/tasks/typical90_ay
// 解説 https://github.com/E869120/kyopro_educational_90/blob/main/editorial/051.jpg

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> func(const vector<ll>& v, ll k, ll p)
{
    vector<vector<ll>> res(k + 1);
    ll N = (ll)v.size();
    for (ll mask = 0; mask < (1LL << N); mask++)
    {
        ll w = 0;
        ll c = 0;
        for (ll i = 0; i < N; i++)
        {
            if (mask & (1LL << i))
            {
                w += v[i];
                c++;
            }
        }
        if (c <= k && w <= p) res[c].push_back(w);
    }
    for (ll i = 0; i < (ll)res.size(); i++) sort(res[i].begin(), res[i].end());
    return res;
}

int main()
{
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A;
    vector<ll> B;
    for (ll i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0) A.push_back(a);
        else B.push_back(a);
    }

    vector<vector<ll>> Ca = func(A, K, P);
    vector<vector<ll>> Cb = func(B, K, P);

    ll ans = 0;
    for (ll k = 0; k <= K; k++)
    {
        for (ll i = 0; i < (ll)Ca[k].size(); i++) ans += upper_bound(Cb[K - k].begin(), Cb[K - k].end(), P - Ca[k][i]) - Cb[K - k].begin();
    }
    cout << ans << endl;

    return 0;
}