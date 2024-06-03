
#include <bits/stdc++.h>
using namespace std;
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define DBG_VEC(v)                   \
    do                               \
    {                                \
        cout << "[" << #v << "]: ";  \
        for (const auto &elem : (v)) \
        {                            \
            cout << elem << " ";     \
        }                            \
        cout << endl;                \
    } while (0)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t, n, f, k, aux;
    string bank;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        vector<ll> cubes;
        ll fvalue;
        cin >> n >> f >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            cubes.push_back(aux);
            if (i + 1 == f)
                fvalue = aux;
        }
        sort(cubes.rbegin(), cubes.rend());
        // DBG(fvalue);
        bool left = false;
        bool right = false;
        for (int i = 0; i < n; i++)
        {
            ll value = cubes[i];
            if (i < k)
            {
                if (value == fvalue)
                {
                    left = true;
                }
            }
            else
            {
                if (value == fvalue)
                {
                    right = true;
                }
            }
        }

        if (right && left)
            cout << "MAYBE" << endl;
        else if (left)
            cout << "YES" << endl;
        else if (right)
            cout << "NO" << endl;
    }

    return 0;
}
