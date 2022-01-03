// 072 - Loop Railway Plan（★4） https://atcoder.jp/contests/typical90/tasks/typical90_bt
// 解説 https://github.com/E869120/kyopro_educational_90/blob/main/editorial/072.jpg

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> seen;

ll dfs(vector<string>& m, ll sh, ll sw, ll h, ll w, ll k, ll H, ll W)
{
    if (h == sh && w == sw && seen[h][w])
    {
        if (k >= 3) return k;
        else return -1;
    }
    seen[h][w] = true;
    ll dx[4] = {-1, 1, 0, 0};
    ll dy[4] = {0, 0, -1, 1};
    ll res = -1;
    for (ll i = 0; i < 4; ++i)
    {
        ll nh = h + dx[i];
        ll nw = w + dy[i];
        if (0 <= nh && nh < H && 0 <= nw && nw < W)
        {
            if (m[nh][nw] == '.')
            {
                if (!seen[nh][nw] || (nh == sh && nw == sw))
                {
                    res = max(res, dfs(m, sh, sw, nh, nw, k + 1, H, W));
                }
            }
        }
    }
    seen[h][w] = false;
    return res;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> m(H);
    for (ll i = 0; i < H; ++i) cin >> m[i];
    ll ans = -1;
    for (ll h = 0; h < H; ++h)
    {
        for (ll w = 0; w < W; ++w)
        {
            seen.resize(H, vector<ll>(W, false));
            ans = max(ans, dfs(m, h, w, h, w, 0, H, W));
        }
    }
    cout << ans << endl;
    return 0;
}