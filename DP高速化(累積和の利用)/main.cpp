// https://atcoder.jp/contests/abc179/tasks/abc179_d
// âê‡ https://drken1215.hatenablog.com/entry/2020/09/20/081800

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> v(K);
    for (ll i = 0; i < K; ++i) cin >> v[i].first >> v[i].second;

    vector<ll> dp(N, 0), sdp(N + 1, 0);
    dp[0] = 1;
    sdp[1] = 1;
    for (ll n = 1; n < N; ++n)
    {
        for (auto p : v)
        {
            ll left = max(0LL, n - p.second);
            ll right = max(0LL, n - p.first + 1);
            ll add = sdp[right] - sdp[left];
            if (add < 0) add += MOD;
            dp[n] += add;
            dp[n] %= MOD;
        }
        sdp[n + 1] = sdp[n] + dp[n];
        sdp[n + 1] %= MOD;
    }
    cout << dp[N - 1] << endl;
    return 0;
}