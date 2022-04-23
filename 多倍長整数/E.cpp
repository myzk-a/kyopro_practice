// https://atcoder.jp/contests/abc180/tasks/abc180_d
// https://atcoder.jp/contests/abc180/editorial/1172

#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
using ll = long long;

int main()
{
    cpp_int X, Y, A, B;
    cin >> X >> Y >> A >> B;

    cpp_int e = 0;
    cpp_int s = X;
    while (1)
    {
        if (s >= Y)
        {
            cout << e - 1 << endl;
            return 0;
        }

        if ( A * s <= s + B)
        {
            if (A * s < Y)
            {
                s *= A;
                ++e;
            }
            else
            {
                cout << e << endl;
                return 0;
            }
        }
        else
        {
            cpp_int tmp = Y - 1 - s;
            tmp /= B;
            cout << e + tmp << endl;
            return 0;
        }
    }

    return 0;
}