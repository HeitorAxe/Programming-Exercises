#include<bits/stdc++.h>
#define ll long long
using namespace std;

class SmallestInfiniteSet {
public:
    set<int> s;
    
    SmallestInfiniteSet() {
        for(int i = 1; i<1001; i++)
            s.insert(i);
    }
    
    int popSmallest() {
        int n = *s.begin();
        s.erase(s.begin());
        return n;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */