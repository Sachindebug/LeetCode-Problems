class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        if(num<=9) return num;
                int ans=num;

        while(num)
        {
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(),arr.end());
        vector<int> temp;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                temp=arr;
                swap(temp[i],temp[j]);
                int res=0;
                for(int i=0;i<arr.size();i++)
                {
                    res=res*10+temp[i];
                }
                ans=max(res,ans);
            }
           
        }
        return ans;
       
        

        
    }
};