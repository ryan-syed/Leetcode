class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int length = A.size();
        int i = 0;
        int j = 0;
        int longestSub = 0;
        
        while(i < length && j < length) {
            if(K >= 0) {
                longestSub = max(j - i, longestSub);
                if(A[j++] == 0)
                    K--;
            }
            else {
                if(A[i++] == 0)
                    K++;
            }
        }
        
        if(K >= 0)
            longestSub = max(j - i, longestSub);
        
        return longestSub;
    }
};