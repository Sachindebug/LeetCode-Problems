class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> ump;
        for(auto x:nums) ump[x]++;
        for(auto x:ump) if(x.second==1) return -1;
        int count = 0;
        for(auto x:ump)
        {
            count += (x.second/3);
            if(x.second%3!=0)
            {
                count++;
            }
        }
        return count;
    }
};