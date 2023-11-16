// https://atcoder.jp/contests/typical90/tasks/typical90_cj

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	ll N, Q;
	cin >> N >> Q;

	vector<ll> A(N + 1);
	for (ll i = 1; i <= N; ++i) cin >> A[i];

	vector<vector<ll>> g(N + 1);
	for (ll i = 0; i < Q; ++i)
	{
		ll X, Y;
		cin >> X >> Y;
		g[X].push_back(Y);
	}

	bool f = false;
	vector<set<vector<ll>>> ans(10000);
	vector<ll> v;
	vector<ll> c(N + 1);

	auto dfs = [&](auto dfs, ll pos) -> void
	{
		if (pos == N + 1) return;
		if (f) return;

		dfs(dfs, pos + 1);

		if (c[pos] == 0)
		{
			v.push_back(pos);
			ll tmp = 0;
			for (auto _v : v) tmp += A[_v];
			ans[tmp].insert(v);
			if (ans[tmp].size() == 2)
			{
				f = true;
			}
			for (auto np : g[pos])
			{
				++c[np];
			}
			dfs(dfs, pos + 1);

			v.pop_back();
			for (auto np : g[pos])
			{
				--c[np];
			}
			return;
		}
	};

	dfs(dfs, 1);

	for (ll i = 1; i <= 8888; ++i)
	{
		if (ans[i].size() >= 2)
		{
			ll cnt = 0;
			for (auto a : ans[i])
			{
				cout << a.size() << endl;
				for (auto _a : a) cout << _a << " ";
				cout << endl;
				++cnt;
				if (cnt == 2) return 0;
			}
		}
	}

	return 0;
}