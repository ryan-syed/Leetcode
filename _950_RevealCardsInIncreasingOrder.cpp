class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int count = deck.size();
        queue<int> cardSim;
        for(int i = 0; i < count; i++)
            cardSim.push(i);
    
        vector<int> order;
        
        while(!cardSim.empty()) {
            order.push_back(cardSim.front());
            cardSim.pop();
            if(!cardSim.empty()) {
                cardSim.push(cardSim.front());
                cardSim.pop();
            }
        }
        
        sort(deck.begin(), deck.end());
        vector<int> result(count, 0);
        
        for(int i = 0; i < count; i++)
            result[order[i]] = deck[i];
        
        return result;
    }
};