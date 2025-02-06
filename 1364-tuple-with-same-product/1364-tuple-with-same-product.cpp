class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> prod;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            for(int j = i+1;j<n;j++){
                int p = nums[i]*nums[j];
                prod[p]++;
            }
        }
        int res = 0;
        for(auto x: prod){
            int count = x.second;
            res += (count*(count-1))/2;
        }
        return res*8;
    }
};