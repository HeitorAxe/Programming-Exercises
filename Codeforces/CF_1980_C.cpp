
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

    ll t, n, m, aux;
    string bank;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        vll original;
        vll found;
        map<ll, ll> preserved;
        vll preservedOrder;
        set<ll> used;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            original.push_back(aux);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            found.push_back(aux);
        }
        ll last = 0;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> aux;
            preserved[aux]++;
            if (i == m - 1)
                last = aux;
        }
        bool flag = false;
        ll qtd = 0;
        for (int i = 0; i < n; i++)
        {
            if (found[i] != original[i])
            {
                if (preserved.find(found[i]) == preserved.end())
                {
                    flag = true;
                    break;
                }
                else
                {
                    if (preserved[found[i]] > 0)
                    {
                        preserved[found[i]]--;
                        qtd++;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }

        if (!flag && qtd < m)
        {
            flag = true;
            for (int i = 0; i < n; i++)
            {
                if (found[i] == last)
                {
                    flag = false;
                }
            }
        }

        if (flag)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}
