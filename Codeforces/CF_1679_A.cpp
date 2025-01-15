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
    string s;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>n;
        cin>>s;
        char prev = s[0];
        bool ta = true;
        for(int j=1; j<s.size(); j++){
            if(prev>s[j]){
                ta =false;
            }
            prev = s[j];
        }
        if(ta)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }

    return 0;
}