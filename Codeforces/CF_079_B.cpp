
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
    //k = waste cells
    //t = queries
    int n, m, k, t, x, y;
    cin>>n>>m>>k>>t;
    vector<int> w;
    for(int i = 0; i<k; i++){
        cin>>x>>y;
        w.push_back(((x-1)*m)+y-1);
    }
    sort(w.begin(), w.end());
    vector<string> crops = {"Carrots", "Kiwis", "Grapes"};
    for(int i = 0; i<t; i++){
        cin>>x>>y;
        if(find(w.begin(), w.end(),  (((x-1)*m)+y-1))!=w.end())
            cout<<"Waste"<<endl;    
        else{
            int a = (((x-1)*m)+y-1);
            int count = std::count_if(w.begin(), w.end(), [a](int x) {
                return x < a;
            });
            a-=count;
            a%=3;
            //int a = ((y*m)+x);
            cout<<crops[a]<<endl;

        }
    }

    

    return 0;
}