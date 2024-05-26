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
    int aux;
    set<int> s;
    for(int i = 0; i<3; i++){
        cin>>aux;
        s.insert(aux);
    }
    for(int i = 1; i<4; i++){
        if(s.find(i)==s.end())
            cout<<i<<endl;
    }
    return 0;
}

