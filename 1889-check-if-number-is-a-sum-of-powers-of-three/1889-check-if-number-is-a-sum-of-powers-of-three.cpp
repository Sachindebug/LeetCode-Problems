class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n >= 3){
            if(n % 3 == 2) return false;
            n /= 3;
        }
        return n!= 2;
    }
};