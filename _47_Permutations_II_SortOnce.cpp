// why does this result in lexicographically sorted
// [1 2 3]
// [1 2 3]  --- first swap, zero pos
// [2 1 3]  --- second swap, zero pos
// [3 1 2]  --- third swap, zero pos
// As we are always swapping with the just smaller element,
// and therefore, the rest of the array will be sorted.

class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &result, int pos) {
        if(nums.size() == pos)
            result.push_back(nums);
        
        int i = pos;
        while(i < nums.size()){
            if((i == pos) || (i != pos && nums[i] != nums[pos])) { // skipping duplicates
                swap(nums[i], nums[pos]); // not undoing ensures that the order of the remaining elements are maintained
                helper(nums, result, pos + 1);
            }
            i++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // only need to sort initially to be able to track the duplicates easily
        helper(nums, result, 0);
        
        return result;
    }
};