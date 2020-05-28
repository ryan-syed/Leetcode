class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxVal = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxVal = max(arr[i], maxVal);
            if(maxVal == i)
                chunks++;
        }
        
        return chunks;
    }
};