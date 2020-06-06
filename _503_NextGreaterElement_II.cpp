class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size();
        
        for(int i = 0; i < length; i++)
            nums.push_back(nums[i]);
        
        unordered_map<int, int> nextGreater;
        length = nums.size();
        stack<int> st;
        for(int i = 0; i < length; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                int topIndex = st.top();
                st.pop();
                nextGreater[topIndex] = nums[i];
            }
            if(i < length/2)
                st.push(i);
        }
        
        vector<int> result(length/2, -1);
        for(int i = 0; i < length/2; i++){
            if(nextGreater.count(i))
                result[i] = nextGreater[i];
        }
        
        return result;
    }
};