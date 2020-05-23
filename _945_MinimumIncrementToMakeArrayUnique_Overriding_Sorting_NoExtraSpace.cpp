class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int i = 0;
        int uniqueValue = 0;
        int length = A.size();
        int moves = 0;
        
        while(i < length) {
            uniqueValue = max(uniqueValue, A[i]); // can only consider greater values
            moves += uniqueValue++ - A[i++];
        }
        
        return moves;
    }
};