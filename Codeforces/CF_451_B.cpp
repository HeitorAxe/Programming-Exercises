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
    int n, aux;
    vi v, vs;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>aux;
        v.push_back(aux);
        vs.push_back(aux);
    }
    sort(vs.begin(), vs.end());
    int i = 0;
    //if p = 0, previous position was sorted
    //if p = 1, previous position was reversed
    int p=0;
    int l, r;
    int prev;
    while(i<n){
        //cout<<v[i]<<endl;
        if(p==0){
            if(v[i]!=vs[i]){
                p = 1;
                prev = v[i];
                l = i;
                r =i;
            }
        }
        if(p==1){
            if(v[i]<=prev){
                r = i;
                prev = v[i];
            }
            else{
                break;
            }
        }
        i++;
    }
    if(p==0){
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    reverse(v.begin()+l, v.begin()+r+1);
    for(int i = 0; i<n; i++){
        if(v[i]!=vs[i]){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    cout<<l+1<<" "<<r+1<<endl;

    return 0;
}