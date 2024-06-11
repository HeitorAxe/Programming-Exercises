#include <bits/stdc++.h>
#define ll long long
using namespace std;

// comparator to sort based on length
bool compareLength(string &a, const string &b)
{
    return a.length() < b.length();
}

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        vector<string> result;
        istringstream iss(sentence);
        string word;
        while (iss >> word)
        {
            result.push_back(word);
        }
        sort(dictionary.begin(), dictionary.end(), compareLength);
        string res = "";

        for (auto x : result)
        {
            bool flag = true;
            for (auto y : dictionary)
            {
                if (x.compare(0, y.length(), y) == 0)
                {
                    res += y;
                    flag = false;
                    break;
                }
            }
            if (flag)
                res += x;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};