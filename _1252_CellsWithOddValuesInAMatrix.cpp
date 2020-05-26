class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices, int res = 0) {
        vector<bool> rows(n), cols(m);
        int r = 0, c = 0;
        for (auto& idx : indices) {
            rows[idx[0]] = !rows[idx[0]];
            r += rows[idx[0]] ? 1 : -1;
            
            cols[idx[1]] = !cols[idx[1]];
            c += cols[idx[1]] ? 1 : -1;
        }
        
        return r * (m - c) + c * (n - r);
    }
};