// Improve this solution
// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int length = A.size();
        int l = 0, r = 1;
        
        int maxTurb = 0;
        bool nextCompLess;
        while(r < length) {
            if(r - 1 == l) {
                if(A[r] == A[l])
                    l++;
                else
                    nextCompLess = !(A[r] < A[l]);
                r++;
                maxTurb = max(r - l, maxTurb);
            }
            else {
                if((nextCompLess && A[r] < A[r - 1]) ||
                   (!nextCompLess && A[r] > A[r - 1])) {
                       nextCompLess = !nextCompLess;
                       r++;
                       maxTurb = max(r - l, maxTurb);
                }
                else
                   l = r - 1;
            }
        }
                   
        maxTurb = max(r - l, maxTurb);
        return maxTurb;
    }
};