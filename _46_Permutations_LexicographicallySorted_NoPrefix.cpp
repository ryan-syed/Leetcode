// why does this result in lexicographically sorted
// [1 2 3]
// [1 2 3]  --- first swap, zero pos
// [2 1 3]  --- second swap, zero pos
// [3 1 2]  --- third swap, zero pos
// As we are always swapping with the just smaller element,
// and therefore, the rest of the array will be sorted.
class Solution {
public: 
    void helper(vector<int> nums, vector<vector<int>> &result, int pos) {
        if(nums.size() == pos) {
            result.push_back(nums);
            return;   
        }
        
        for(int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            helper(nums, result, pos + 1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, result, 0);
        
        return result;
    }
};