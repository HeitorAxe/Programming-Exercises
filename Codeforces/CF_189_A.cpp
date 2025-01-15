
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

// PD - Problema da moeda praticamente

ll solve(ll N, ll X, vector<ll> &coins)
{
    vector<ll> dp(X + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= X; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (coins[j] > i || dp[i - coins[j]] == -1)
                continue;
            dp[i] = max(dp[i], dp[i - coins[j]] + 1);
        }
    }
    if (dp[X] != -1)
        return dp[X];

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, n, b, c;
    vll sizes;

    cin >> n >> a >> b >> c;
    sizes.push_back(a);
    sizes.push_back(b);
    sizes.push_back(c);

    cout << solve(3, n, sizes) << endl;

    return 0;
}
