class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res=INT_MAX;
        unordered_map<int,int> ump;
        int n=cards.size();
        for(int i=0;i<n;i++)
        {
            if(ump.find(cards[i])!=ump.end())
            {
                res=min(res,i-ump[cards[i]]+1);
            }
            ump[cards[i]]=i;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};