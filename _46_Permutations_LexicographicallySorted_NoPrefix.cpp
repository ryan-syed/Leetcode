#define what_is_array(x) for(auto elem : x) cout << elem << " "; cout << endl
#define what_is(x) cout << #x << " is " << x << endl
#define what_is_fn(fn, x) cout << #fn << "(" << #x << ")" << " is " << fn(x) << endl

class Solution {
public: 
    void helper(vector<int> nums, vector<vector<int>> &result, int pos) {
        if(nums.size() == pos) {
            result.push_back(nums);
            return;   
        }
        
        for(int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            helper(nums, result, pos + 1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, result, 0);
        
        return result;
    }
};