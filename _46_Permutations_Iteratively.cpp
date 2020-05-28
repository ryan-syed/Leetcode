// This is the fastest solution with time complexity of O(n! * n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        
        do {
            permutations.push_back(nums);
        } while(nextPermutation(nums));
        
        return permutations;
    }
    
    bool nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int i = length - 2;
        
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return false;
        }
        
        int j;
        for(j = length - 1; j > i; j--)
            if(nums[j] > nums[i])
                break;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
};