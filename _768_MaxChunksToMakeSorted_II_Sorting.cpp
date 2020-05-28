#define ll long long
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int length = arr.size();
        int chunks = 0;
        
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        ll sumArr = 0;
        ll sumSorted = 0;
        
        for(int i = 0; i < length; i++) {
            sumArr += arr[i];
            sumSorted += sorted[i];
            if(sumArr == sumSorted)
                chunks++;
        }
        
        return chunks;
    }
};