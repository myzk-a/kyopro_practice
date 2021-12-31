#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;
ll num = 0;
vector<pair<ll, ll>> p;
vector<bool> seen;

void dfs1(Graph& g, ll v)
{
    seen[v] = true;
    for (auto nv : g[v])
    {
        if (seen[nv]) continue;
        dfs1(g, nv);
    }
    p.push_back(make_pair(num, v));
    ++num;
    return;
}

ll dfs2(Graph& g, ll v)
{
    seen[v] = true;
    ll res = 1;
    for (auto nv : g[v])
    {
        if (seen[nv]) continue;
        res += dfs2(g, nv);
    }
    return res;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    Graph g1(N), g2(N);
    for (ll i = 0; i < M; ++i)
    {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        g1[u].push_back(v);
        g2[v].push_back(u);
    }

    seen.assign(N, false);
    for (ll v = 0; v < N; ++v)
    {
        if (seen[v]) continue;
        dfs1(g1, v);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    ll ans = 0;
    seen.assign(N, false);
    for (ll i = 0; i < N; ++i)
    {
        ll v = p[i].second;
        if (seen[v]) continue;
        ll tmp = dfs2(g2, v);
        ans += tmp * (tmp - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}