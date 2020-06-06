class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        for(auto elem : nums2) {
            while(!st.empty() && st.top() < elem) {
                nextGreater[st.top()] = elem;
                st.pop();
            }
            
            st.push(elem);
        }
        
        for(int i = 0; i < nums1.size(); i++)
            nums1[i] = nextGreater.find(nums1[i]) != nextGreater.end() ? nextGreater[nums1[i]] : -1;
        
        return nums1;
    }
};