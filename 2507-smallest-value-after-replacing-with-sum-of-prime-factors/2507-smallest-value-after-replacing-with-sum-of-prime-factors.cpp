class Solution {
    bool isPrime(int n){
        for(int i = 2;i * i <= n;i++){
            if(n % i == 0)return false;
        }
        return true;
    }
public:
    int smallestValue(int n) {

        if(isPrime(n))return n;

        int x = n;
        int sum = 0;
        //Sum all the prime factors of n
        for(int i = 2;i * i <= n;i++){
            while(x % i == 0){
                sum += i;
                x /= i;
            }
        }
        if(x > 1)sum += x;

        if(sum == n)return n;

        return smallestValue(sum);
    }
};