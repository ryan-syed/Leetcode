class Solution {
public:
    bool isSame(vector<int> hash1, vector<int> hash2) {
        for(int i = 0; i < hash1.size(); i++)
            if(hash1[i] != hash2[i])
                return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(p.size() == 0 || p.size() > s.size())
            return {};
        vector<int> hashP(26, 0);
        vector<int> hashS(26, 0);
        for(int i = 0; i < p.size(); i++) {
            hashP[p[i] - 'a']++;
            hashS[s[i] - 'a']++;   
        }
        vector<int> result;
        for(int i = 0; i <= s.size() - p.size(); i++)
        {
            if(isSame(hashP, hashS))
                result.push_back(i);
            
            if(i != s.size() - p.size()) {
                hashS[s[i] - 'a']--;
                hashS[s[i + p.size()] - 'a']++;
            }
        }
        
        return result;
    }
};