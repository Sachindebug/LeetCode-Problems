class RLEIterator {
private:
    int i;
    vector<int> nums;
public:
    RLEIterator(vector<int>& encoding) {
        nums = encoding;
        i = 0;
    }
    
    int next(int n) {
        while(i<nums.size()){
            if(nums[i] < n){
                n-=nums[i];
                i+=2;
            }
            else{
                nums[i]-=n;
                return nums[i+1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */