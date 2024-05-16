#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum =0;
        priority_queue<int, vector<int>, greater<int>> tail, head;
        int i = 0, j = costs.size()-1;
        while(i<=j){
            if(i == candidates)
                break;
            head.push(costs[i++]);
            if(i>j)
                break;
            tail.push(costs[j--]);
        }
        while(k--){
            if(tail.empty()){
                sum+=head.top();
                head.pop();
                if(i<=j)
                    head.push(costs[i++]);
            }else if(head.empty()){
                sum+=tail.top();
                tail.pop();
                if(i<=j)
                    tail.push(costs[j--]);
            }else if(head.top()<=tail.top()){
                sum+=head.top();
                head.pop();
                if(i<=j)
                    head.push(costs[i++]);
            }else if(head.top()>tail.top()){
                sum+=tail.top();
                tail.pop();
                if(i<=j)
                    tail.push(costs[j--]);
            }
        }
        return sum;
        
    }
};