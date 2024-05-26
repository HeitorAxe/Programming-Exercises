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
    int n;
    string aux;
    vector<string> nomes;
    set<pair<int, string>> idades;
    map<string, int> help;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>aux;
        nomes.push_back(aux);
    }
    for(int i = 0; i<n; i++){
        cin>>aux;
        idades.insert({i, aux});
        help[aux] = i;
    }
    for(int i = 0; i<n; i++){
        pair<int, string> c= *idades.begin();
        cout<<c.second;
        if(i==n-1)
            cout<<endl;
        else
            cout<<" ";
        idades.erase({help[nomes[i]], nomes[i]});
    }

    return 0;
}

