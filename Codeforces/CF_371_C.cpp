
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
    ll nb, ns, nc, pb, ps, pc;
    ll rubbles;
    // record ocurrences
    map<char, ll> stock;
    map<char, ll> cost;
    map<char, ll> inRecipe;
    string recipe;

    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> rubbles;

    stock['B'] = nb;
    stock['S'] = ns;
    stock['C'] = nc;

    cost['B'] = pb;
    cost['S'] = ps;
    cost['C'] = pc;

    ll hamburguerPrice = 0;

    for (auto x : recipe)
    {
        inRecipe[x]++;
        hamburguerPrice += cost[x];
    }

    int i = 0;
    ll count = 0;
    ll bought = 0;
    while (true)
    {
        char ingredient = recipe[i];
        if (stock[ingredient])
        {
            stock[ingredient]--;
            bought = 0;
        }
        else
        {
            if (rubbles - cost[ingredient] >= 0)
            {
                rubbles -= cost[ingredient];
                bought++;
            }
            else
                break;
        }

        i++;
        if (i == recipe.size())
        {
            i = 0;
            count++;
            if (bought > recipe.size())
            {
                // cout<<rubbles<<endl;
                count += rubbles / hamburguerPrice;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}
