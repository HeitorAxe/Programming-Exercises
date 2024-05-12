#include <bits/stdc++.h>
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
#include <bits/stdc++.h>
using namespace std;
//1966
long knapSack(long  W, vector<long> wt, vector<long> val, long  n)
{
    long dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (long i = 1; i < n + 1; i++) {
        for (long w = W; w >= 0; w--) {
            if (wt[i - 1] <= w)
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main() {

    long  n, b, aux;
    vector<long> vol;
    vector<long> price;

    cin>>n>>b;

    for(long  i = 0; i<n; i++){
        cin>>aux;
        vol.push_back(aux);
    }

    for(long  i = 0; i<n; i++){
        cin>>aux;
        price.push_back(aux);
    }
    long  totalVolume = knapSack(b, price, vol, n);
    
    long count = 0;
    while(totalVolume>count){
        count++;
        totalVolume -= count;
    }

    cout << count <<endl;

    return 0;
}