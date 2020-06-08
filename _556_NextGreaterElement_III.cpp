class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int length = s.size();
        
        int r = length - 2;
        while(r >= 0 && s[r] >= s[r + 1])
            r--;
        
        if(r < 0)
            return -1;
        
        int i = length - 1;
        for(;i > r; i--)
            if(s[i] > s[r])
                break;
        
        swap(s[i], s[r]);
        reverse(s.begin() + r + 1, s.end());
        
        long greaterNum = stol(s);
        if(greaterNum > INT_MAX)
            return -1;
        return greaterNum;
    }
};