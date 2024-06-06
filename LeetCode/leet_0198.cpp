#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        long long dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = -1;
        }
        dp[0] = nums[0];
        if (n == 1)
            return nums[0];
        dp[1] = max((long long)nums[1], dp[0]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};