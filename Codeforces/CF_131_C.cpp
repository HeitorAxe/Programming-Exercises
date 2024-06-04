
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

long long combination(long long n, long long k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (k > n - k)
        k = n - k;

    long long result = 1;
    for (long long i = 1; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

// Dificil, tive que consultar a solução
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, t, ans = 0;

    cin >> n >> m >> t;

    for (int i = 4; i <= min(n, t); i++)
    {
        if (t - i >= 1)
            ans += combination(n, i) * combination(m, t - i);
    }

    cout << ans << endl;

    return 0;
}

/* Isso aqui não vai funcionar pq eu tentei deixar o grupo inicial de 4
meninos e 1 uma menina como fixo. AAo fazer isso eu assumo que exatamente
o grupo inicial é escolhido e isso vai me impedir de considerar todas as
possibilidades.
*/

/* int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, t, ans=1;

    cin>>n>>m>>t;

    ans *= binomialCoefficient(n, 4);
    ans *= binomialCoefficient(m, 1);

    n-=4;
    m-=1;
    t-=5;
    ans *= binomialCoefficient(m+n, t);

    cout<<ans<<endl;


    return 0;
}
*/