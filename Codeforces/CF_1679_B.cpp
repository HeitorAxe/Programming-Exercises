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
    int t, n;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        ll aux;
        ll last;
        vector<ll> a, b;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>aux;
            a.push_back(aux);
        }
        for(int j=0; j<n+1; j++){
            cin>>aux;
            b.push_back(aux);
        }
        if(a.size()==b.size()){
            cout<<0<<endl;
            continue;
        }
        last = b[b.size()-1];
        ll mi = INT_MAX;
        ll sum =0;
        for(int j = 0; j<n; j++){
            ll au = abs(max(b[j], a[j])-min(b[j], a[j]));
            sum+=au;
            if(last >= min(b[j], a[j]) && last <= max(b[j], a[j])){
                mi = 0;
                //cout<<"AQUI"<<endl;
            }else{
                //DBG(max(b[j], a[j]));
                //DBG(min(b[j], a[j]));
                if(last>max(b[j], a[j])){
                    mi = min(mi, abs(last-max(b[j], a[j])));
                    //DBG(mi);
                }
                if(last<min(b[j], a[j])){
                    mi = min(mi, abs(min(b[j], a[j])-last));
                }
                
                //DBG(last);
            }

        }
        cout<<sum+(mi+1)<<endl;
        
    }

    return 0;
}