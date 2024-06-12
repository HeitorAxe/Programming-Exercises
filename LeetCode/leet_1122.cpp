#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> m;
        map<int, int> t;
        set<int> helper;
        vector<int> ans;
        vector<int> rest;
        for (int i = 0; i < arr2.size(); i++)
        {
            m[i] = arr2[i];
            helper.insert(arr2[i]);
        }
        for (int i = 0; i < arr1.size(); i++)
        {
            t[arr1[i]]++;
            if (!helper.count(arr1[i]))
            {
                rest.push_back(arr1[i]);
            }
        }
        sort(rest.begin(), rest.end());
        for (auto x : m)
        {
            int n = t[x.second];
            for (int i = 0; i < n; i++)
            {
                ans.push_back(x.second);
            }
        }
        for (auto x : rest)
            ans.push_back(x);
        return ans;
    }
};