class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        unordered_map<char, int> unique;
        int length = A.size();
        int i = 0, j = 0, longest = 0;

        while(i < length && j < length) {
            if(unique.find(A[j]) != unique.end())
                i = max(i, unique[A[j]]);
            longest = max(longest, j - i + 1);
            unique[A[j]] = j + 1;
            j++;
        }

        return longest;
    }
};