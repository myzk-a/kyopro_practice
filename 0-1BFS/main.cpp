// https://atcoder.jp/contests/abc246/tasks/abc246_e
// https://atcoder.jp/contests/abc246/editorial/3702

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60LL;

int main()
{
    ll N, Ax, Ay, Bx, By;
    cin >> N >> Ax >> Ay >> Bx >> By;
    --Ax; --Ay; --Bx; --By;

    vector<string> B(N);
    for (ll i = 0; i < N; ++i) cin >> B[i];

    vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(N, vector<ll>(4, INF)));
    vector<vector<vector<bool>>> checked(N, vector<vector<bool>>(N, vector<bool>(4, false)));

    deque<pair<pair<ll, ll>, ll>> dq;
    ll dx[] = { -1, -1, 1, 1 };
    ll dy[] = { 1, -1, 1, -1 };
    for (ll i = 0; i < 4; ++i)
    {
        ll nx = Ax + dx[i];
        ll ny = Ay + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && B[nx][ny] != '#')
        {
            dist[nx][ny][i] = 1;
            dq.push_back({ {nx, ny}, i });
        }
    }

    while (!dq.empty())
    {
        auto p = dq.front();
        dq.pop_front();
        ll x = p.first.first;
        ll y = p.first.second;
        ll dir = p.second;
        if (checked[x][y][dir]) continue;
        checked[x][y][dir] = true;

        for (ll i = 0; i < 4; ++i)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && B[nx][ny] != '#')
            {
                ll cost = dist[x][y][dir];
                if (i != dir) ++cost;
                if (cost < dist[nx][ny][i])
                {
                    dist[nx][ny][i] = cost;
                    if (i == dir) dq.push_front({ {nx, ny}, i });
                    else dq.push_back({ {nx, ny}, i });
                }
            }
        }
    }

    ll ans = INF;
    for (ll i = 0; i < 4; ++i) ans = min(ans, dist[Bx][By][i]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}