class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> temp;
        bool neg=false;
        int count=0;
        if(num==0) return 0;
        if(num<0){
            neg=true;
            num*=-1;
        } 
        while(num>0)
        {
            int rem=num%10;
            if(rem==0) count++;
            else temp.push_back(rem);
            num/=10;
        }
        sort(temp.begin(),temp.end());
        long long res=0;
        long long int p=1;
        if(neg)
        {
            
            for(int i=temp.size()-1;i>=0;i--)
            {
                res=(res*10)+temp[i];
                
            }
            for(int i=0;i<count;i++)
            {
                res=(res*10);
                
            }
            return -(res);
        }
        else
        {
            res=temp[0];
            p*=10;
            for(int i=0;i<count;i++)
            {
                res=(res*10);
                
            }
            for(int i=1;i<temp.size();i++)
            {
                res=(res*10)+temp[i];
                
            }
            
            
            
        }
        return res;
        
    }
};