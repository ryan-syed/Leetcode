class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = s.size();
        vector<int> freq(26, 0);
        int maxCount = 0;
        
        for(int l = 0, r = 0; r < length; r++)
        {
            maxCount = max(maxCount, ++freq[s[r] - 'A']);
            if(r - l + 1 > k + maxCount)
                freq[s[l++] - 'A']--;
        }        
        return min(length, maxCount + k);
    }
};