
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
#define DBG_VEC(v) \
    do { \
        cout << "[" << #v << "]: "; \
        for (const auto& elem : (v)) { \
            cout << elem << " "; \
        } \
        cout << endl; \
    } while (0)

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, aux;
    vll l;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>aux;
        l.push_back(aux);
    }
    sort(l.begin(), l.end());
    int i =0, j=1, k=2;
    bool flag = false;
    while(k<n){
        //cout<<i<<" "<<j<<" "<<k<<endl;
        if(l[k]>=l[i]+l[j]){
            if(i<j-1){
                i++;
            }else if(j<k-1){
                j++;
            }else{
                k++;
            }
        }
        else if(l[i]+l[j]>l[k]){
            flag = true;
            break;
        }

    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}