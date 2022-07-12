class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       vector<long long int> freq(60,0);
       for(auto x:time) freq[x%60]++;
       long long int count=0;
       for(int i=0;i<60;i++)
       {
           if(i==0 || i==30)
           {
               count+=(freq[i]*(freq[i]-1));
           }
           else
           {
               count+=(freq[i]*freq[60-i]);
           }
       }
       return count/2;
    }
};