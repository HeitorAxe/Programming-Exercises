#include <bits/stdc++.h>
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define ll int int
#define pii pair<int, int>
#define pll pair<int int, int int>
#define vi vector<int>
#define vll vector<int int>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define MAX 112345
using namespace std;

vector<pair<double, pair<int, int>>> vet;

int knapSack(int b)
{
    double res=0;
    for(int i = 0; i<vet.size(); i++){
        if(b>=vet[i].second.second){
            b-=vet[i].second.second;
            res+=vet[i].second.first;
        }else{
            res += b/vet[i].first;
            break;
        }
    }
    return res;
}

int main() {

    int  n, b, aux;
    vector<int> vol;
    vector<int> price;

    cin>>n>>b;

    for(int  i = 0; i<n; i++){
        cin>>aux;
        vol.push_back(aux);
    }

    for(int  i = 0; i<n; i++){
        cin>>aux;
        price.push_back(aux);
    }
    for(int  i = 0; i<n; i++){
        double aux2 = ((double) price[i]) / vol[i];
        vet.push_back({aux2, {vol[i], price[i]}});
    }
    sort(vet.begin(), vet.end());

    double  totalVolume = knapSack(b);
    
    int count = 0;
    while(totalVolume>count){
        count++;
        totalVolume -= count;
    }

    if (b == 0)
    {
        cout << 0 << '\n';
    }else
        cout << count<<endl;

    return 0;
}