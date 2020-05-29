class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int length = A.size();
        int l = 0;
        int r = 0;
        
        while(r < length) {
            if(A[r] == 0)
                K--;
            
            if(K < 0) {
                if(A[l] == 0)
                    K++;
                l++;
            }
            r++;
        }
        
        return r - l;
    }
};