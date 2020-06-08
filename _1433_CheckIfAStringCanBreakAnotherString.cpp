class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(auto ch: s1)
            freq1[ch - 'a']++;
        for(auto ch: s2)
            freq2[ch - 'a']++;
        
        bool first = true;
        int countFirst = 0;
        
        bool second = true;
        int countSecond = 0;
        for(int i = 0; i < 26; i++) {
            if(!first && !second)
                break;
            if(first) {
                countFirst += freq1[i] - freq2[i];
                first = countFirst >= 0;
            }
            if(second) {
                countSecond += freq2[i] - freq1[i];
                second = countSecond >= 0;
            }
        }
        
        return first || second;
    }
};