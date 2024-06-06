
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
#define INF 1000000000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, aux;
        vll v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.push_back(aux);
        }
        ll mi = INT_MAX;
        ll ma = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ma = max(v[i], v[i + 1]);
            mi = min(ma - 1, mi);
        }
        cout << mi << endl;
    }

    return 0;
}
