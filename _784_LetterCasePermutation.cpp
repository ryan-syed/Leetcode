class Solution {
public:
    void helper(vector<string> &result, string S, int pos) {
        if(S.size() == pos)
        {
            result.push_back(S);
            return;
        }
        
        if(S[pos] >= '0' && S[pos] <= '9')
            helper(result, S, pos + 1);
        else if(S[pos] >= 'a' && S[pos] <= 'z')
        {
            helper(result, S, pos + 1);
            S[pos] -= 32;
            helper(result, S, pos + 1);
        }
        else if(S[pos] >= 'A' && S[pos] <= 'Z')
        {
            S[pos] += 32;
            helper(result, S, pos + 1);
            S[pos] -= 32;
            helper(result, S, pos + 1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        helper(result, S, 0);
        return result;
    }
};