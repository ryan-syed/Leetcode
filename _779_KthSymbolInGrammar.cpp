class Solution {
public:
    int lookup[2][2] = {{0, 1},{1, 0}};
    int getValue(int n) {
        if(n == 1)
            return 0;
        
        int parent = (n + 1)/2;
        return lookup[getValue(parent)][n % 2 == 0];
    }
    
    int kthGrammar(int N, int K) {
        return getValue(K);
    }
};