class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        
        if(length == 1 || nums[0] < nums[length - 1])
            return nums[0];
        
        int lo = 0;
        int hi = length - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid + 1] < nums[mid])
                return nums[mid + 1];
            
            if(nums[mid] < nums[mid - 1])
                return nums[mid];
            
            if(nums[lo] < nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return -1;
    }
};