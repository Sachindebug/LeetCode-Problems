class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0, n = nums.size();
        int prev = nums[n-1];
        for(int i = n-2;i>=0;i--){
            int num = nums[i];
            while(num>prev){
                int x = greatestDivisor(num);
                if(x==1) return -1;
                num/=x;
                count++;
            }
            prev = num;
        }
        return count;
    }
    int greatestDivisor(int n){
        int div = 1;
        if(n%2==0) return n/2;
        for(int i = 2; i*i<=n; i++){
            if(n%i==0) {
                div = max(div,i);
                div = max(div,n/i);
            }
        }
        return div;
    }
};