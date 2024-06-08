#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        set<int> modSum;
        int sum = 0, prevSum;
        for (int i = 0; i < nums.size(); i++)
        {
            prevSum = sum;
            sum = (sum + nums[i]) % k;

            // obs: Caso um elemento se repita nesse set
            // sabemos que existe uma subarray divisivel por K
            if (modSum.count(sum))
            {
                return true;
            }
            // devemos inserir aqui a anterior para
            // garantir que a subarray seja de tamanho 2
            modSum.insert(prevSum);
        }
        return false;
    }
};