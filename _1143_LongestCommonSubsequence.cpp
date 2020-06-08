
class Solution {
public:
    vector< vector<int> > memo;
    int helper(string &text1, string &text2, int m, int n) {
        if(m < 0 || n < 0)
            return 0;
        if(memo[m][n] >= 0)
            return memo[m][n];
            
        if(text1[m] == text2[n])
            return memo[m][n] = 1 + helper(text1, text2, m - 1, n - 1);
        else
            return memo[m][n] = max(helper(text1, text2, m - 1, n), helper(text1, text2, m, n - 1));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        memo.assign(m, vector<int>(n, -1));
        return helper(text1, text2, m - 1, n - 1);
    }
};