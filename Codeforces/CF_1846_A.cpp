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
        ll n, a, b;
        vector<ll> h, l;
        cin>>n;
        for(int i =0; i<n; i++){
            cin>>a>>b;
            h.push_back(a);
            l.push_back(b);
        }
        ll count =0;
        for(int i =0; i<n; i++){
            if(h[i] - l[i] >0)
                count++;
        }
        cout<<count<<endl;

        
    }
}