// 034 - There are few types of elements（★4）https ://atcoder.jp/contests/typical90/tasks/typical90_ah
// 解説 https://github.com/E869120/kyopro_educational_90/blob/main/editorial/034.jpg

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) cin >> A[i];

    ll cnt = 0;
    ll right = 0;
    map<ll, ll> m;
    ll ans = 0;
    for (ll left = 0; left < N; ++left)
    {
        while (right < N)
        {
            if (m[A[right]] == 0 && cnt == K) break;
            if (m[A[right]] == 0) ++cnt;
            ++m[A[right]];
            ++right;
        }
        
        ans = max(ans, right - left);
        if (m[A[left]] == 1) --cnt;
        --m[A[left]];
    }
    cout << ans << endl;
    return 0;
}