class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for(int i = 0; i<32;i++){
            for(auto x: nums){
                if(x&(1<<i)) bits[i]++;
            }
        }
        int res = 0;
        for(int i = 0;i<32;i++)
            if(bits[i]%3) res = res | (1<<i);
        return res;
    }
};