class Solution {
public: 
    void helper(vector<int>& nums, vector<vector<int>> &result, int pos, int n) {
        if(n == pos) {
            result.push_back(nums);
            return;   
        }
        
        for(int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            helper(nums, result, pos + 1, n);
            swap(nums[i], nums[pos]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, result, 0, nums.size());
        
        return result;
    }
};