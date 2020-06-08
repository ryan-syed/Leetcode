class Solution {
public:
    string reverseWords(string s) {
        int r = 0;
        int length = s.size();
        while(r < length) {
            int l = r;
            while(r < length && s[r] != ' ') r++;
            
            reverse(s.begin() + l, s.begin() + r);
            r++;
        }
        
        return s;
    }
};