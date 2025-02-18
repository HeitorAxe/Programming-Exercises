/*
 * @lc app=leetcode id=2375 lang=cpp
 *
 * [2375] Construct Smallest Number From DI String
 */

// @lc code=start
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    string smallestNumber(string pattern) {
        vector<string> valid;
        findNum(pattern, "", valid);

        return *min_element(valid.begin(), valid.end());
    }

    void findNum(string pattern, string current, vector<string>& valid){
        bool isValid = false;
        if(pattern.size()+1==current.size()){
            isValid = true;
            for(int i=0; i<pattern.size(); i++){
                if(pattern[i]=='D' && current[i]<current[i+1]){
                    isValid=false;
                }else if(pattern[i]=='I' && current[i]>current[i+1]){
                    isValid = false;
                }
            }
        }
        if(isValid){
            valid.push_back(current);
            return;
        }
        for(int i = 1; i<=9; i++){
            if(current.find(to_string(i))==string::npos){
                current+=to_string(i);
                if(current.size()>=2){
                    if(pattern[current.size()-2]=='D'&& current[current.size()-2]>current[current.size()-1]){
                        findNum(pattern, current, valid);
                    }
                    else if(pattern[current.size()-2]=='I'&& current[current.size()-2]<current[current.size()-1]){
                        findNum(pattern, current, valid);
                    }
                }else{
                    findNum(pattern, current, valid);
                }
                current.erase(current.size()-1);
            }
        }
    }

};
// @lc code=end

