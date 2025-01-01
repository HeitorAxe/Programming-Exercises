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

set<int> inBag;
set<int> outBag;
map<pll, int> lookup;

//first = value
//second = weight
//pairs
void knapsackBruteForce(int& w, int& ma, vector<pair<int, int>>& pairs, int cValue, int cWeight){
    if(lookup.find({cValue, cWeight})!=lookup.end()){
        ma = max(ma, lookup[{cValue, cWeight}]);
        return;
    }
    if(cWeight>w){
        return;
    }
    else{
        ma = max(ma, cValue);
        lookup[{cValue, cWeight}] = ma;
        for(auto x:outBag){
            inBag.insert(x);
            outBag.erase(x);
            knapsackBruteForce(w, ma, pairs, cValue+pairs[x].first, cWeight+pairs[x].second);
            outBag.insert(x);
            inBag.erase(x);
        }
    }
    
}

int knapsackDp(vector<pair<int, int>>& pairs, int w){

    vector<int> dp;
    for(int i = 0; i<w+1; i++){
        dp.push_back(0);
    }
    dp[0] = 0;

    for(int i=0; i<pairs.size(); i++){
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, a1, a2;
    vector<pair<int, int>> pairs;
    cin>>n>>w;
    for(int i =0; i<n; i++){
        cin>>a1>>a2;
        pairs.push_back({a1, a2});
        outBag.insert(i);
    }
    int ma = 0;
    knapsackBruteForce(w, ma, pairs, 0, 0);
    cout<<ma<<endl;


    return 0;
}