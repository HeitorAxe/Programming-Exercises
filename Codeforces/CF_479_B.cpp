
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
#define DBG_VEC(v) \
    do { \
        cout << "[" << #v << "]: "; \
        for (const auto& elem : (v)) { \
            cout << elem << " "; \
        } \
        cout << endl; \
    } while (0)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, aux;
    //height, index
    vector<pll> towers;
    vector<pll> operations;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        towers.push_back({ aux, i });
    }
    sort(towers.begin(), towers.end());
    ll count = 0;
    ll inst = towers[towers.size() - 1].first - towers[0].first;
    ll mi = INT_MAX, miCount = 0;
    while (count < k && inst != 0) {
        //cout << towers[towers.size() - 1].second+1 << " " << towers[0].second+1<< endl;
        //cout << towers[towers.size() - 1].first << " " << towers[0].first << endl << endl;
        towers[0].first++;
        towers[towers.size() - 1].first--;
        operations.push_back({ towers[towers.size() - 1].second, towers[0].second });
        sort(towers.begin(), towers.end());
        inst = towers[towers.size() - 1].first - towers[0].first;
        count++;
        if (inst < mi) {
            mi = inst;
            miCount = count;
        }

    }

    inst = towers[towers.size() - 1].first - towers[0].first;
    if (inst < mi) {
        mi = inst;
        miCount = count;
    }
    cout << mi << " " << miCount << endl;
    for (ll i = 0; i < miCount; i++)
    {
        cout << operations[i].first + 1 << " " << operations[i].second + 1 << endl;
    }



    return 0;
}

