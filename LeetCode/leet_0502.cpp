#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // holds capital then profit
        vector<pair<int, int>> cp;
        int n = profits.size();
        // holds profit then capital
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            cp.push_back({capital[i], profits[i]});
        }
        int count = 0;
        int j = 0;
        sort(cp.begin(), cp.end());

        while (count < k)
        {
            while (j < n && cp[j].first <= w)
            {
                pq.push({cp[j].second, cp[j].first});
                j++;
            }
            if (pq.empty())
                break;
            pair<int, int> t = pq.top();
            w += t.first;
            count++;
            pq.pop();
        }
        return w;
    }
};