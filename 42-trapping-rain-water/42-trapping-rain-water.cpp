class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int res=0;
        if(n<=2)
        {
            return res;
        }
        vector<int> left(n),right(n);
        int leftmax=0;
        int rightmax=0;
        left[0]=0;
        right[n-1]=0;
        for(int i=0;i<n;i++)
        {
            left[i]=leftmax;
            if(height[i]>leftmax)
            {
                leftmax=height[i];
            }
            
        }
        for(int i=n-1;i>=0;i--)
        {
            right[i]=rightmax;
            if(height[i]>rightmax)
            {
                rightmax=height[i];
            }
            
        }
        for(int i=0;i<n;i++)
        {
            int p=min(left[i],right[i]);
            if(height[i]>=p)
            {
                continue;
            }
            else
            {
                res+=(p-height[i]);
            }
        }
        return res;

        
    }
};