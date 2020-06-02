class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 1 || nums[0] < nums[length - 1])
            return nums[0];
        
        int lo = 0;
        int hi = length - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[lo] <= nums[mid] && nums[mid + 1] <= nums[hi])
                return nums[mid + 1];
            else if(nums[lo] <= nums[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        
        return -1;
    }
};