// https://atcoder.jp/contests/abc340/tasks/abc340_e

#include <bits/stdc++.h>
// #include <atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;
using ll = long long;

struct LazySegmentTree
{
private:
    long long n;
    vector<long long> node, lazy;

public:
    LazySegmentTree(vector<long long> v)
    {
        long long sz = (long long)v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);

        for (long long i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (long long i = n - 2; i >= 0; i--) node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(long long k, long long l, long long r)
    {
        if (lazy[k] != 0)
        {
            node[k] += lazy[k];
            if (r - l > 1)
            {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(long long a, long long b, long long x, long long k = 0, long long l = 0, long long r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b)
        {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else
        {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    long long getsum(long long a, long long b, long long k = 0, long long l = 0, long long r = -1)
    {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return node[k];
        long long vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        long long vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};


int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + 1);
    for(ll i = 0; i < N; ++i) cin >> A[i];

    LazySegmentTree seg = LazySegmentTree(A);

    for(ll i = 0; i < M; ++i)
    {
        ll b;
        cin >> b;
        ll x = seg.getsum(b, b + 1);
        seg.add(b, b + 1, -x);

        ll c = x / N;
        x %= N;
        seg.add(0, N, c);
        ++b;
        if(b + x < N)
        {
            seg.add(b, b + x, 1);
        }
        else
        {
            seg.add(b, N, 1);
            seg.add(0, b + x - N, 1);
        }
    }

    for(ll i = 0; i < N; ++i)
    {
        cout << seg.getsum(i, i + 1) << " ";
    }
    cout << endl;

    return 0;
}