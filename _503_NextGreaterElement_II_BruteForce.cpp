class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        int length = nums.size();
        
        for(int i = 0; i < length; i++)
        {
            int nextGreater = -1;
            for(int j = 1; j < length; j++)
                if(nums[(i + j) % length] > nums[i]) {
                    nextGreater = nums[(i + j) % length];
                    break;   
                }
            result.push_back(nextGreater);
        }
        
        return result;
    }
};