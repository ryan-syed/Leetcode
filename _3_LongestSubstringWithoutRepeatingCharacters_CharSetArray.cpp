class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        vector<int> unique(256, -1);
        int length = A.size();
        int i = 0, j = 0, longest = 0;

        while(i < length && j < length) {
            if(unique[A[j]] != -1)
                i = max(i, unique[A[j]]);
            longest = max(longest, j - i + 1);
            unique[A[j]] = j + 1;
            j++;
        }

        return longest;
    }
};