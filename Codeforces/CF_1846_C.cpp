#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

bool comparator(const pair<pair<ll, ll>, ll>& a,
                const pair<pair<ll, ll>, ll>& b) {
    if (a.f.f > b.f.f) {
        return true;
    } else if (a.f.f == b.f.f && a.f.s < b.f.s) {
        return true;
    } else if (a.f.f == b.f.f && a.f.s == b.f.s && a.s < b.s) {
        return true;
    } else {
        return false;
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m, h, aux;
        vector<vector<ll>> t;
        //points, penalty, index
        vector<pair<pair<ll, ll>, ll>> p;
        cin>>n>>m>>h;
        for(int i = 0; i<n; i++){
            ll pen = 0;
            vector<ll> helper;
            for(int j = 0; j<m; j++){
                cin>>aux;
                helper.push_back(aux);
            }
            sort(helper.begin(), helper.end());
            t.push_back(helper);
            ll points = 0;
            ll j =0;
            ll time= 0;
            while(time+helper[j]<=h && j<m){
                pen+=time+helper[j];
                time+=helper[j];
                points++;
                j++;
            }
            p.push_back({{points, pen}, i});
            
        }
        sort(p.begin(), p.end(), comparator);
        for(int i = 0; i<n; i++){
            if(p[i].second==0){
                cout<<i+1<<endl;
            }
        }


        
    }
}