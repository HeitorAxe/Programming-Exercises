
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

    ll t, m, n;
    string bank;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        map<char, ll> record;
        record['A'] = 0;
        record['B'] = 0;
        record['C'] = 0;
        record['D'] = 0;
        record['E'] = 0;
        record['F'] = 0;
        record['G'] = 0;
        cin >> n >> m;
        cin >> bank;
        ll ma = 0;
        for (auto c : bank)
        {
            record[c]++;
            ma = max(record[c], ma);
        }
        ll ans = 0;
        for (auto p : record)
        {
            if (p.second < m)
                ans += (m - p.second);
        }

        cout << ans << endl;
    }

    return 0;
}
