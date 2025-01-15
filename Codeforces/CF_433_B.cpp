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
//https://codeforces.com/contest/433/problem/B



 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //type = 1, sum from l to r
    //type = 2, ith cheapest in l to r
    ll n, aux, m, type, l, r, sum=0;
    vector<ll> v, prefixSum, prefixSum2; 
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>aux;
        v.push_back(aux);
        prefixSum.push_back(sum);
        sum+=aux;
    }
    prefixSum.push_back(sum);
    sort(v.begin(), v.end());
    sum = 0;
    for(int i = 0; i<n; i++){
        prefixSum2.push_back(sum);
        sum+=v[i];
    }
    prefixSum2.push_back(sum);
    cin>>m;
    for(int i = 0; i< m; i++){
        cin>>type>>l>>r;
        ll ans=-1;
        if(type==1){
            ans = prefixSum[r]-prefixSum[l-1];
        }else{
             ans = prefixSum2[r]-prefixSum2[l-1];
        }
        cout<<ans<<endl;
    }

    return 0;
}

