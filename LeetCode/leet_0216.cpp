#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int sum;
    int num;
    vector<int> aux;
    set<set<int>> mySets;
    set<int> curr;
    void search(int s, int qtd)
    {
        if(num==qtd){
            if(sum==s && mySets.count(curr)==0){
                mySets.insert(curr);
                ans.push_back(aux);
            }
        }else{
            for(int i = 1; i<=9; i++){
                if(find(aux.begin(), aux.end(), i)==aux.end()){
                    curr.insert(i);
                    aux.push_back(i);
                    search(s+i, qtd+1);
                    curr.erase(i);
                    aux.pop_back();
                }
            }
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        num = k;
        sum = n;
        search(0, 0);
        return ans;
    }
};