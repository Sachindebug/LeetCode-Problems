class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                mx=max(mx,height[i]*(j-i));
                i++;
            }
            else
            {
                mx=max(mx,height[j]*(j-i));
                j--;
                
            }
            
        }
        return mx;
    }
};