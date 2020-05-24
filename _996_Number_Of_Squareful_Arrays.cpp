class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int count = 0;
        helper(A, 0, count);
        
        return count;
    }
    
     void helper(vector<int> A, int pos, int &count) {
        if (pos == A.size()) {
            count++;
            return;
        }
         
        for(int i = pos; i < A.size(); i++){
            if(i == pos || (i != pos && A[i] != A[pos]))
            {
                if (pos > 0) {
                    int sqrtN = sqrt(A[i] + A[pos-1]);
                    if(sqrtN * sqrtN  != (A[i] + A[pos-1]))
                        continue;
                }
                swap(A[i], A[pos]);
                helper(A, pos + 1, count);
            }
        }
    }
};