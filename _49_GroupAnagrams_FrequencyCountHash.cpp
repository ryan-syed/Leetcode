class Solution {
public:
    string getCountString(string s) {
        int freq[26] = {0};
        for(auto ch : s)
            freq[ch - 'a']++;
        
        stringstream ss;
        for(int i = 0; i < 26; i++)
            ss << "#" << static_cast<char>(freq[i]) << "#";
        
        return ss.str();
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for(auto s : strs)
            anagrams[getCountString(s)].push_back(s);
            
        vector< vector<string> > result;
        for(auto it : anagrams)
            result.push_back(it.second);
        
        return result;
    }
};