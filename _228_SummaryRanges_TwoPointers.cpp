class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        int length = nums.size();
        int i = 0;
        int j = 0;
        
        while(j < length) {
            while(j < length && (i == j || nums[j - 1] + 1 == nums[j]))
                j++;
            
            stringstream ss;
            if(i == j - 1)
                ss << nums[i];
            else
                ss << nums[i] << "->" << nums[j - 1];
            
            result.push_back(ss.str());
            i = j;
        }
        
        return result;
    }
};