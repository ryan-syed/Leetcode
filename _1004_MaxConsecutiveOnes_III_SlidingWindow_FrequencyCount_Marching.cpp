class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int length = A.size();
        vector<int> freq(2, 0);
        int maxCount = 0;
        
        for(int l = 0, r = 0; r < length; r++)
        {
            if(A[r] == 1)
                maxCount = max(maxCount, ++freq[A[r]]);
            if(r - l + 1 > K + maxCount)
                freq[A[l++]]--;
        }        
        return min(length, maxCount + K);
    }
};