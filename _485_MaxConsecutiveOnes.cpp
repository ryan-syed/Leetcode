class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            if(nums[i] == 1)
                count++;
            else {
                maxCount = max(count, maxCount);
                count = 0;
            }
        }
        
        return max(maxCount, count);
    }
};
