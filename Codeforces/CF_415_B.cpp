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
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, f, k, l;
    vll kv, lv;
    ll sum = 0;
    vector<pll> dv;
    cin>>n>>f;

    for(int i = 0; i<n; i++){
        cin>>k>>l;
        lv.push_back(l);
        kv.push_back(k);
        ll soldD;
        ll sold;
        if(2*k>=l)
            soldD = l;
        else
            soldD = 2*k;
        if(k>=l)
            sold = l;
        else
            sold = k;
        //storing the profit gained by doubling
        dv.push_back({soldD-sold, i});
    }
    sort(dv.rbegin(), dv.rend());
    for(int i = 0; i<n; i++){
        if(f>0){
            ll ind = dv[i].second;
            ll sold;
            if(2*kv[ind]>=lv[ind])
                sold = lv[ind];
            else
                sold = 2*kv[ind];
            sum+=max(dv[i].first, sold);
            f--;
        }else{
            ll ind = dv[i].second;
            ll sold;
            if(kv[ind]>=lv[ind])
                sold = lv[ind];
            else
                sold = kv[ind];

            sum+=sold;
            
        }
    }
    cout<<sum<<endl;

    

    return 0;
}