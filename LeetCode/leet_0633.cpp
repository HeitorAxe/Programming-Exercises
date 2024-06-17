#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long i = 0, j = sqrt(c);
        while (j >= i)
        {
            if ((i * i) + (j * j) == c)
            {
                return true;
            }
            else if ((i * i) + (j * j) > c)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};