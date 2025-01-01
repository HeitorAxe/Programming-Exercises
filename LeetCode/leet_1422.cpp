#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n0 = 0;
        int n1 = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='1')
                n1++;
            else
                n0++;
        }
        int r = n1;
        int l = 0;
        int m=0;
        for(int i = 0; i<s.size()-1; i++){
            if(s[i]=='1')
                r--;
            else
                l++;
            m=max(m, l+r);
        }

        return m;
    }
};