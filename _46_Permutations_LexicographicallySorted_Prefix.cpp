class Solution {
public: 
    void helper(vector<int>& nums, vector<int> &prefix, vector<vector<int>> &result, int pos, int n) {
        if(n == pos) {
            result.push_back(prefix);
            return;   
        }
        
        for(int i = 0; i < nums.size(); i++) {
            prefix.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            helper(nums, prefix, result, pos + 1, n);
            nums.insert(nums.begin() + i, prefix.back());
            prefix.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> prefix;
        helper(nums, prefix, result, 0, nums.size());
        
        return result;
    }
};