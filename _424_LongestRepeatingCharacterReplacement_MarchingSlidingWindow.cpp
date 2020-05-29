class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = s.size();
        int l = 0, r = 0;
        
        vector<int> freq(26, 0);
        
        while(r < length) {
            freq[s[r] - 'A']++;
            
            auto it = max_element(freq.begin(), freq.end());
            int maxIndex = it - freq.begin();
            int countOther = 0;
            for(int i = 0; i < 26; i++)
                if(i != maxIndex)
                    countOther += freq[i];
            
            if(countOther > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        
        return r - l;
    }
};