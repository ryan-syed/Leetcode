class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        unordered_set<char> unique;
        int length = A.size();
        int i = 0, j = 0, longest = 0;

        while(i < length && j < length) {
            if(unique.find(A[j]) == unique.end()) {
                unique.insert(A[j++]);
                longest = max(j - i, longest);
            }
            else
                unique.erase(A[i++]);
        }

        return longest;
    }
};