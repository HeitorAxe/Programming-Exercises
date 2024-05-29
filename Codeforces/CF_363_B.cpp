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
//https://codeforces.com/contest/363/problem/B

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, aux, sum=0;
    vector<int> fences;
    vector<int> prefixSum;
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>aux;
        fences.push_back(aux);
        prefixSum.push_back(sum);
        sum+=aux;
    }
    prefixSum.push_back(sum);
    int mi = INT_MAX;
    int j = 0;
    for(int i = 0; i<=n-k; i++){
        if(prefixSum[i+k]-prefixSum[i]<mi){
            mi = prefixSum[i+k]-prefixSum[i];
            j = i;
        }
/*         DBG(i);
        DBG(mi); */
    }
    cout<<j+1<<endl;
    

    return 0;
}

