class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto x:nums)
        {
            if(x>0) pos.push_back(x);
            if(x<0) neg.push_back(x);
        }
        nums.clear();
        int p=0;
        int q=0;
        while(p<pos.size())
        {
            nums.push_back(pos[p]);
            nums.push_back(neg[p]);
            p++;
        }
        return nums;

        
    }
};