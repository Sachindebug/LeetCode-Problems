class Solution {
public:
    int minSteps(int n) {
       if(n==1) return 0;
        for(int i = n-1;i>=1;i--){
            if(n%i == 0)
                return n/i + minSteps(i);
        }
        return 0;   
    }   
};