#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (prev == nums[i])
            {
                nums[i]++;
                count++;
            }
            else if (prev > nums[i])
            {
                int aux = nums[i];
                nums[i] = prev + 1;
                count += nums[i] - aux;
            }

            prev = nums[i];
        }
        return count;
    }
};