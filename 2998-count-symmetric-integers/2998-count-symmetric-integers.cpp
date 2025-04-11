class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            int x = i;
            vector<int> temp;
            while(x>0)
            {
                temp.push_back(x%10);
                x/=10;
            }
            if(temp.size()%2==0)
            {
                int l = 0;
                int r = temp.size()-1;
                int sum1=0,sum2=0;
                while(l<r)
                {
                    sum1+=temp[l];
                    sum2+=temp[r];
                    l++;
                    r--;
                }
                count+=(sum1==sum2);
            }
        }
        return count;
        
    }
};