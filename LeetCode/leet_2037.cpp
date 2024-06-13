#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int count = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            while (students[i] != seats[i])
            {
                if (students[i] < seats[i])
                {
                    students[i]++;
                }
                else
                {
                    students[i]--;
                }
                count++;
            }
        }
        return count;
    }
};