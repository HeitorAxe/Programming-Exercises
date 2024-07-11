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
        ll n;
        ll count = 0;
        ll aux;
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>aux;
            if(aux%2!=0)
                count++;
        }
        if(count%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}