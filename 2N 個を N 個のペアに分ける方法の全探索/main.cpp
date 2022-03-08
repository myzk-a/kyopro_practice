// ABC236-D https://atcoder.jp/contests/abc236/tasks/abc236_d
// 解説 https://atcoder.jp/contests/abc236/editorial/3285

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> used;
vector<pair<ll, ll>> P;
ll N;

ll dfs(vector<vector<ll>>& A)
{
    if (P.size() == N)
    {
        ll res = 0;
        for (auto p : P) res ^= A[p.first][p.second];
        return res;
    }

    ll l = -1;
    for (ll i = 0; i < used.size(); ++i)
    {
        if (!used[i])
        {
            l = i;
            used[l] = true;
            break;
        }
    }

    ll res = 0;
    for (ll i = 0; i < used.size(); ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            P.push_back(make_pair(l, i));
            ll tmp = dfs(A);
            res = max(res, tmp);
            P.pop_back();
            used[i] = false;
        }
    }

    used[l] = false;
    return res;
}

int main()
{
    cin >> N;
    vector<vector<ll>> A(2 * N-1, vector<ll>(2*N, 0));
    for (ll i = 0; i < A.size(); ++i)
    {
        for (ll j = i + 1; j <= 2 * N - 1; ++j)
        {
            cin >> A[i][j];
        }
    }

    used.assign(2*N, false);
    ll ans = dfs(A);
    cout << ans << endl;
    return 0;
}