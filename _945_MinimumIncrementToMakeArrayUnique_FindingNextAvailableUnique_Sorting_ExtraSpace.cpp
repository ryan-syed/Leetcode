class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 1)
            return 0;
        
        sort(A.begin(), A.end());

        vector<bool> unique(2 * 40000 + 1, false);

        for(auto nums : A)
            unique[nums] = true;

        int i = 1;
        int j = A[i];
        int moves = 0;

        while(i < A.size() && j < unique.size()) {
            if(A[i] == A[i - 1])
            {   
                j = max(j, A[i]);
                while(j < unique.size() && unique[j])
                    j++;
                unique[j] = true;
                moves += j - A[i];
            }
            i++;
        }

        return moves;
    }
};