// https://atcoder.jp/contests/typical90/tasks/typical90_be
// https://twitter.com/e869120/status/1400584377902399490/photo/1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

ll f(vector<vector<ll>>& _A)
{
    ll pos = 0;
    ll N = _A.size();
    ll M = _A[0].size();
    for (ll bit = 0; bit < M; ++bit)
    {
        bool found = false;
        for (ll i = pos; i < N; ++i)
        {
            if (_A[i][bit] == 1)
            {
                if (i != pos) swap(_A[i], _A[pos]);
                found = true;
                break;
            }
        }

        if (found)
        {
            for (ll i = pos + 1; i < N; ++i)
            {
                if (_A[i][bit] == 1)
                {
                    for (ll j = bit; j < M; ++j)
                    {
                        _A[i][j] ^= _A[pos][j];
                    }
                }
            }
            ++pos;
        }
    }
    return pos;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M, 0));
    for (ll i = 0; i < N; ++i)
    {
        ll t;
        cin >> t;
        for (ll j = 0; j < t; ++j)
        {
            ll a;
            cin >> a; --a;
            A[i][a] = 1;
        }
    }

    auto _A = A;

    vector<ll> S(M);
    for (auto& s : S) cin >> s;

    ll _pos = f(_A);

    ll row = 0;
    for (ll bit = 0; bit < M; ++bit)
    {
        if (row >= _pos) break;
        if (_A[row][bit] == 1)
        {
            if (S[bit] == 1)
            {
                for (ll j = bit; j < M; ++j)
                {
                    S[j] ^= _A[row][j];
                }
            }
            ++row;
        }
    }

    if (S == vector<ll>(M, 0))
    {
        ll ans = 1;
        for (ll i = _pos; i < N; ++i)
        {
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}