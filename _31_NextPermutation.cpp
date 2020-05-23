class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int i = length - 2;
        
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j;
        for(j = length - 1; j > i; j--)
            if(nums[j] > nums[i])
                break;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};