/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while(true){
            int mid = left + (right - left) / 2;
            if(guess(mid)>0){
                left = mid+1;
            }
            if(guess(mid)<0){
                right = mid-1;
            }
            if(guess(mid)==0)
                return mid;
        }
    }
};