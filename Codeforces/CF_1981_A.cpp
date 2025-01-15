
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, l, r;
    cin>>n;
    for(int i= 0; i<n; i++){
        cin>>l>>r;
        ll x = r;
        ll p2 = 2;
        ll count=0;
        while(p2<=r){
            p2 = p2*2;
            count++;
        }
        cout<<count<<endl;
    }

    return 0;
}