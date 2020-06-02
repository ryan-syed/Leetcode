class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector< pair<int, int> > numIndexZip;
        
        for(int i = 0; i < nums.size(); i++)
            numIndexZip.push_back({nums[i], i});
        
        sort(numIndexZip.begin(), numIndexZip.end());
        for(int i = 1; i < numIndexZip.size(); i++) {
            if(numIndexZip[i - 1].first == numIndexZip[i].first && 
              numIndexZip[i].second - numIndexZip[i - 1].second <= k)
                return true;
        }
        return false;
    }
};