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
        ll n, k, aux;
        vector<ll> lastOc;
        vector<ll> firstOc;
        vector<ll> colors;
        cin>>n>>k;
        for(int i = 0; i<n; i++){
            cin>>aux;
            colors.push_back(aux);
        }
        for(int i=0; i<n; i++){
            if(colors[i] == colors[0])
                firstOc.push_back(i);
            if(colors[i] == colors[n-1])
                lastOc.push_back(i);
        }
        reverse(lastOc.begin(), lastOc.end());
        bool flag = true;  

        if(!(lastOc.size()>=k && firstOc.size()>=k))
            flag = false;
        
        if(flag){
            int i =0;
            while(i<k){
                if(firstOc[i]>lastOc[i]){
                    flag = false;
                    break;
                }
                i++;
            }
        }

        if(colors[0]==colors[n-1] && firstOc.size()>=k)
            flag = true;
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;





        
    }
}