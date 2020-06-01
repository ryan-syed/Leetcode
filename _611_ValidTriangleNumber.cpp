class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int length = nums.size(); 
        for(int i = length - 1; i >= 2; i--) {
            int lo = 0;
            int hi = i - 1;
            
            while(lo < hi) {
                int sum = nums[lo] + nums[hi];
                if(sum <= nums[i])
                    lo++;
                else {
                    count += hi - lo;
                    hi--;
                }
            }
        }
        
        return count;
    }
};