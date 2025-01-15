
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
// https://codeforces.com/contest/378/problem/B
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, aux;
    map<ll, ll> helper;
    vll a, b;
    vector<pll> ab;
    cin >> n;
    vll auxA(n), auxB(n);
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push_back(aux);
        ab.push_back({aux, i});
        cin >> aux;
        b.push_back(aux);
        ab.push_back({aux, i});
    }
    sort(ab.begin(), ab.end());
    // for(auto x:ab){
    //     cout<<"v: "<<x.first<<" i: "<<x.second<<endl;
    // }
    for (int i = 0; i < n; i++)
    {
        if (a[ab[i].second] == ab[i].first)
        {
            // cout << "v: " << ab[i].first << " i: " << ab[i].second << endl;
            auxA[ab[i].second] = -1;
        }
        else if (b[ab[i].second] == ab[i].first)
        {
            // cout << "v: " << ab[i].first << " i: " << ab[i].second << endl;
            auxB[ab[i].second] = -1;
        }
    }
    ll k = n / 2;
    ll i = 0;
    while (i < k)
    {
        if (a[i] < b[i])
        {
            auxA[i] = -1;
            auxB[i] = -1;
        }
        else
        {
            auxB[i] = -1;
            auxA[i] = -1;
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        if (auxA[i] == -1)
            std::cout << "1";
        else
            std::cout << "0";
    }
    std::cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (auxB[i] == -1)
            std::cout << "1";
        else
            std::cout << "0";
    }
    std::cout << endl;

    return 0;
}
