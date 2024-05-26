#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void search(int i, string& digits, string current){
        if(i==digits.size()){
            ans.push_back(current);
            return;
        }else{
            for(int j = 0; j<digitToLetters[digits[i]].size(); j++){
                string temp = current;
                temp.append(1, digitToLetters[digits[i]][j]);
                search(i+1, digits, temp);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return ans;
        search(0, digits, "");
        return ans;
    }
};