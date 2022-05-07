class Solution {
private:
    vector<int> suf,org;
    int n;
public:
    Solution(vector<int>& nums) {
        suf=org=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        int x=rand()%n;
        int y=rand()%n;
        swap(suf[x],suf[y]);
        return suf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */