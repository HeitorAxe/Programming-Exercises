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
//https://codeforces.com/contest/6/problem/B
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    char p, aux;
    set<char> adj;
    vector<vector<char>> office;
    cin>>n>>m>>p;
    for(int i =0; i<n; i++){
        vector<char>auxV;
        for(int j = 0; j<m; j++){
            cin>>aux;
            auxV.push_back(aux);
        }
        office.push_back(auxV);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(office[i][j]==p){
                if(i-1>=0){
                    if(office[i-1][j]!='.' && office[i-1][j]!=office[i][j]){
                        adj.insert(office[i-1][j]);
                    }
                }
                if(i+1<n){
                    if(office[i+1][j]!='.' && office[i+1][j]!=office[i][j]){
                        adj.insert(office[i+1][j]);
                    }

                }
                if(j-1>=0){
                    if(office[i][j-1]!='.'&& office[i][j-1]!=office[i][j]){
                        adj.insert(office[i][j-1]);
                    }
                }
                if(j+1<m){
                    if(office[i][j+1]!='.'&& office[i][j+1]!=office[i][j]){
                        adj.insert(office[i][j+1]);
                    }

                }
            }
        }
    }
    cout<<adj.size()<<endl;

    

    return 0;
}

