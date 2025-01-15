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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m, k, h, aux, count=0;
        vector<ll> people;
        cin>>n>>m>>k>>h;
        m--;
        for(int i = 0.; i<n; i++){
            cin>>aux;
            people.push_back(aux);
            if((max(h, aux)-min(h, aux))%k==0 && 
            (max(h, aux)-min(h, aux))<=m*k &&  
            (max(h, aux)-min(h, aux))>=k &&
            (max(h, aux)-min(h, aux))!=0)
        
            {
                count++;
            }
        }
        cout<<count<<endl;

        
    }
}