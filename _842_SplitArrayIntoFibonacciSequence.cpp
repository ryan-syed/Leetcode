class Solution {
public:
    bool helper(string S, vector<int> &result, vector<int> partial, int pos)
    {
        if(pos == S.size() && partial.size() >= 3)
        {
            result = partial;
            return true;
        }
        
        long long num = 0;
        for(int i = pos; i < S.size(); i++) {
            num = num * 10 + (S[i] - '0');
            if((i > pos && S[pos] == '0') || num > INT_MAX)
                return false;
            
            int partialLength = partial.size();
            if(partialLength < 2 || (num == (long long)partial[partialLength - 1] + partial[partialLength - 2]))
            {
                partial.push_back(num);
                if(helper(S, result, partial, i + 1))
                    return true;
                partial.pop_back();
            }
        }
        return false;
    }
        
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        helper(S, result, {}, 0);
        
        return result;
    }
};