class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int p=0;
        for(auto x:piles) p^=x;
        return p>0;
    }
};