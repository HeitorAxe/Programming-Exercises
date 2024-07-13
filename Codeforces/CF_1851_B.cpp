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
        ll n, aux;
        vector<ll> nums;
        vector<bool> isPair;
        cin>>n;
        for(int i =0; i<n; i++){
            cin>>aux;
            nums.push_back(aux);
            if(aux%2==0)
                isPair.push_back(true);
            else
                isPair.push_back(false);
        }
        sort(nums.begin(), nums.end());
        bool flag = false;
        for(int i = 0; i<n; i++){
            if((nums[i]%2==0)!=isPair[i]){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;


        
    }
}