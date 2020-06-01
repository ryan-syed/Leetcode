class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> hash(maxVal + 1, 0);
        
        int length = arr.size();
        
        for(int i = 0; i < length; i++)
            hash[arr[i]]++;
        
        int lucky = -1;
        for(int i = 1; i <= maxVal; i++)
            if(hash[i] == i)
                lucky = i;
        
        return lucky;
    }
};