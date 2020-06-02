class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int i = 1;
        
        while(i < length && nums[i] >= nums[i - 1])
            i++;
        
        if(i == length)
            return nums[0];
        return nums[i];
    }
};