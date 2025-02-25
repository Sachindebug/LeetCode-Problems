class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        int oddCount = 0;
        int evenCount = 0;
        int subarrayCount = 0;
        int mod = 1000000007;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            sum%=2;
            if(sum){
                oddCount++;
                subarrayCount += evenCount;
                subarrayCount+=1;
            }
            else{
                evenCount++;
                subarrayCount += oddCount;
            }
            subarrayCount%=mod;
        }
        return subarrayCount;
    }
};