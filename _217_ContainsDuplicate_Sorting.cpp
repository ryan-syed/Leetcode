// Here in place of directly sorting the input, it may be better to make a copy
// to avoid modifying the original input
class Solution {
public:
    bool containsDuplicate(vector<int>& A) {
        vector<int> nums;
        copy(A.begin(), A.end(), back_inserter(nums));
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] == nums[i - 1])
                return true;
        return false;
    }
};