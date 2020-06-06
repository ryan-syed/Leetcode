class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> indexMap;
        
        for(int i = 0; i < nums1.size(); i++)
            indexMap[nums1[i]] = i;
        
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        
        for(auto elem : nums2) {
            while(!st.empty() && st.top() < elem) {
                int top = st.top();
                st.pop();
                if(indexMap.count(top))
                    result[indexMap[top]] = elem;
            }
            st.push(elem);
        }
        
        return result;
    }
};