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
    int n, x;
    set<int> vis;
    vector<int> xi;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x;
        xi.push_back(x);
    }
    int i = 0;
    while(i>=0 && i<n){
        vis.insert(i);
        if(xi[i]==0)
            break;
        int dir;
        if(xi[i]%2==0)
            dir = -1;
        else
            dir = 1;
        xi[i]--;

        i+=dir;

    }
    ll sum = 0;
    for(auto a:xi)
        sum+=a;

    cout<<vis.size()<<" "<<sum<<endl;


    return 0;
}

