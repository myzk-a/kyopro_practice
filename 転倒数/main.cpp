// https://atcoder.jp/contests/chokudai_s001/tasks/chokudai_S001_j
// https://ikatakos.com/pot/programming_algorithm/dynamic_programming/inversion
#include<bits/stdc++.h>
#include<atcoder/segtree.hpp>
using namespace atcoder;
using namespace std;
using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) cin >> a;
    ll max_e = *max_element(A.begin(), A.end());

    vector<ll> v(max_e+1, 0);

    segtree<ll, op, e> seg(v);

    ll ans = 0;
    for (ll i = 0; i < N; ++i)
    {
        ll tmp = seg.get(A[i]);
        seg.set(A[i], tmp + 1);
        ans += i + 1 - seg.prod(0, A[i] + 1);
    }
    cout << ans << endl;
    return 0;
}