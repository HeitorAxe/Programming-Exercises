#include <bits/stdc++.h>
using namespace std;
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(0) << (x)
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
    ll e, v;
    cin>>e>>v;

    ll t1 = (e*60) / v;
    ll t2 = 19 * 60;
    ll t = t1+t2;
    int h = (t/60)%24;
    int mi = t%60;


    if(h>=10){
        if(mi>=10)
            cout << h <<":"<<mi<<endl;
        else
            cout << h <<":"<<"0"<<mi<<endl;
    }
    else{
        if(mi>=10)
            cout <<"0"<<h <<":"<<mi<<endl;
        else
            cout <<"0"<<h<<":"<<"0"<<mi<<endl;
    }


    return 0;
}

