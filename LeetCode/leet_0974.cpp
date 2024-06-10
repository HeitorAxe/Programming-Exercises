#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        map<int, int> modMap;
        int sum = 0, totalSum = 0;
        int count = 0;
        modMap[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
            sum = totalSum % k;
            if (sum < 0)
            {
                sum += k;
            }
            if (modMap.find(sum) != modMap.end())
            {
                count += modMap[sum];
                modMap[sum]++;
            }
            else
            {
                modMap[sum] = 1;
            }
        }
        return count;
    }
};