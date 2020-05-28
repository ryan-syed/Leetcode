// for some reason accumulate is taking longer than 
class Solution {
public:
    string largestNumber(vector<int>& A) {
        vector<string> nums;
        transform(A.begin(), A.end(), back_inserter(nums), [](int number) {
            return to_string(number);
        });
    
        sort(nums.begin(), nums.end(), [](string a, string b) -> bool {
           return a + b > b + a;
        });
    
        if(nums[0] == "0")
            return "0";
    
        string result = "";
        for(auto elem : nums)
            result += elem;
        return result;
    }
};  