// 鉄則 B56 - Palindrome Queries
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ec

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const long long MOD = 1000000007LL;

vector<ll> get_mod_pow_B(ll B, ll N, ll mod)
{
    vector<ll> res(N + 1, 0);
    res[0] = 1;
    for (ll i = 1; i <= N; ++i)
    {
        res[i] = (res[i - 1] * B) % mod;
        res[i] %= mod;
    }
    return res;
}

// 1-index
vector<ll> get_hash_array(ll B, ll N, ll mod, const vector<ll> T)
{
    vector<ll> H(N + 1, 0);
    for (ll i = 1; i <= N; ++i) H[i] = (H[i - 1] * B + T[i]) % mod;
    return H;
}

// 1-index
ll hash_value(ll l, ll r, vector<ll>& H, vector<ll>& mod_pow_100, ll mod)
{
    ll val = H[r] - (H[l - 1] * mod_pow_100[r - l + 1] % mod);
    if (val < 0) val += MOD;
    return val % MOD;
}


int main()
{
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<ll> Tl(N + 1, 0);
    for (ll i = 1; i <= N; ++i) Tl[i] = S[i - 1] - 'a';

    vector<ll> Tr(N + 1, 0);
    for (ll i = 1; i <= N; ++i) Tr[i] = S[N - i] - 'a';

    ll B = 100;
    vector<ll> mod_pow_100 = get_mod_pow_B(100, N, MOD);

    vector<ll> Hl = get_hash_array(B, N, MOD, Tl);

    vector<ll> Hr = get_hash_array(B, N, MOD, Tr);

    for (ll i = 0; i < Q; ++i)
    {
        ll L, R;
        cin >> L >> R;
        ll hash_value_l = hash_value(L, R, Hl, mod_pow_100, MOD);
        ll hash_value_r = hash_value(N - R + 1, N - L + 1, Hr, mod_pow_100, MOD);

        if (hash_value_l == hash_value_r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}