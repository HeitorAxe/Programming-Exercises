#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<int> dp;
    int tribonacciAux(int n) {
        if(n==0){
            dp[n] = 0;
            return 0;
        }
        if(n<3){
            dp[n] = 1;
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];

        }

        int a1 = tribonacciAux(n-1);
        int a2 = tribonacciAux(n-2);
        int a3 = tribonacciAux(n-3);
        int ans = a1+a2+a3;

        dp[n] = ans;
        return ans;       
    }
    int tribonacci(int n){
        for(int i = 0; i<38; i++){
            dp.push_back(-1);
        }
        int ans = tribonacciAux(n);
        return ans;
    }
};

