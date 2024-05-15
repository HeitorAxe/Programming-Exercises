#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ord;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long m = 0;
        long long sum = 0;
        for(int i = 0; i<nums1.size(); i++){
            ord.push_back({nums2[i], nums1[i]});
        }
        sort(ord.rbegin(), ord.rend());
        for(int i = 0; i<nums1.size(); i++){
            sum+=ord[i].second;
            pq.push(ord[i].second);
            if(pq.size()==k)
                m = max(m, sum*ord[i].first);
            if(pq.size()>k-1){
                sum-=pq.top();
                pq.pop();
            }
        }
        return m;
    }
};