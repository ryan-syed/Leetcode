class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxVal = arr[0];
        int length = arr.size();
        
        vector<int> minVal(length + 1, INT_MAX);
        for(int j = length - 1; j >= 0; j--)
            minVal[j] = min(minVal[j + 1], arr[j]);
        
        for(int i = 0; i < arr.size(); i++) {
            maxVal = max(arr[i], maxVal);
            if(maxVal <= minVal[i + 1])
                chunks++;
        }
        
        return chunks;
    }
};