class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> prefix;
        vector<int> sufix(nums.size());
        int mi = INT_MAX;
        int ma = 0;
        for(int i =0; i<nums.size(); i++){
            mi = min(nums[i], mi);
            prefix.push_back(mi);
        }
        for(int i =nums.size()-1; i>=0; i--){
            ma = max(nums[i], ma);
            sufix[i] = ma;
        }
        for(int i = 0; i<nums.size(); i++){
            if(prefix[i]<nums[i] && nums[i]<sufix[i])
                return true;
        }

        return false;
    }
};