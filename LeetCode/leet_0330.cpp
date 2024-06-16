#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int count = 0;
        long long sum = 0;
        long long j = 1;

        for (int i = 0; i < nums.size() && sum < n; i++)
        {
            if (sum + nums[i] > sum + sum + 1)
            {
                count++;
                sum = sum + sum + 1;
                i--;
            }
            else
            {
                sum += nums[i];
            }
            cout << sum << endl;
        }

        if (sum < n)
        {
            while (sum < n)
            {
                sum = sum + sum + 1;
                count++;
            }
        }
        return count;
    }
};