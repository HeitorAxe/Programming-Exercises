#include<bits/stdc++.h>
#define ll long long
using namespace std;

//resolvi esse problema da forma fácil
//o enunciado pede uma solução O(log(n))
//tem uma forma mais interessante de fzr isso com Busca Binária

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int p = 0;
        if(nums.size()==1){
            return 0;
        }
        for(int i = 0; i<nums.size(); i++){
            if(i==nums.size()-1){
                if(nums[i]>nums[p]){
                    return i;
                }
            }
            if(i==0){
                if(nums[i]>nums[i+1]){
                    return i;
                }
            }
            if(nums[i]>nums[i+1] && nums[i]>nums[p])
                return i;
            
            p=i;
        }
        return -1;
    }
};