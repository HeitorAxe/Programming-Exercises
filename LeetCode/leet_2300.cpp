#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans(spells.size());
        vector<pair<int, int>> aux;
        for(int i = 0; i<spells.size(); i++)
            aux.push_back({spells[i], i});
        sort(aux.begin(), aux.end());
        sort(spells.begin(), spells.end());
        sort(potions.rbegin(), potions.rend());
        int i = 0;
        int j = 0;
        while(j<potions.size() && i<spells.size()){
            long long helper = ((long long)spells[i])*potions[j];
            if(helper>=success){
                j++;

            }
            if(j==potions.size()){
                while(i<spells.size()){
                    ans[aux[i].second] = j;
                    i++;
                }
                break;
            }
            helper = ((long long)spells[i])*potions[j];
            if(helper<success){
                ans[aux[i].second] = j;
                i++;

            }
        }
        return ans;


    }
};