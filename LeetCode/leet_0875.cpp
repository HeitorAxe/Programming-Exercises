#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& piles, int k, int h){
        long long ans = 0;
        for(auto x:piles){
            ans+= (x+k-1)/k;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int r = 1;
       int l = 0;
       int k = 0;
       for(auto x:piles){
            r = max(r, x);
       }
       while(l<=r){
            int m = l + (r-l)/2;
            if(m!=0&&isValid(piles, m, h)){
                r=m-1;
                k=m;
            }else{
                l = m+1;
            }
       }
       return k;
        
    }
};

