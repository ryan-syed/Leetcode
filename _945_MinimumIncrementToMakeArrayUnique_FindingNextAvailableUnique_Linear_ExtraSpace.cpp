// TC: O(maxVal + range) //SC: O(2 * range)
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int length = A.size();
        if(length <= 1)
            return 0;
        
        int maxVal = 0;
        vector<int> rangeFreq(80000, 0);
        for(auto &num: A) {
            rangeFreq[num]++;
            maxVal = max(maxVal, num);
        }
        
        
        int moves = 0;
        int dupsToUnique = 0;
        
        for(uint i = 0; i < maxVal + length; i++) {
            if(rangeFreq[i] > 1) {
                dupsToUnique += rangeFreq[i] - 1; // for count greater than one, there will be duplicate
                moves -= (rangeFreq[i] - 1) * i; // moves = valueWhereItCanBeSeated - currentValue. Here we are subtracting the currentValue
            }
            else if(rangeFreq[i] == 0 && dupsToUnique > 0)
            {
                dupsToUnique--; // one seat to make duplicate value unique
                moves += i; // now the valueWhereItCanBeSeated is being added and a move is being made 
            }
        }
        
        return moves;
    }
};