class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i=0;
        int j=0;
        vector<vector<int>> res;
        while(i<nums1.size() || j<nums2.size())
        {
            if(i<nums1.size() && j<nums2.size())
            {
                int a=nums1[i][0];
                int b=nums1[i][1];
                int c=nums2[j][0];
                int d=nums2[j][1];
                if(a==c)
                {
                    res.push_back({a,b+d});
                    i++;
                    j++;
                }
                else if(a>c)
                {
                    res.push_back(nums2[j]);
                    j++;
                }
                else
                {
                    res.push_back(nums1[i]);
                    i++;
                }
            }
            else if(i<nums1.size())
            {
                res.push_back(nums1[i]);
                i++;
            }
            else if(j<nums2.size())
            {
               res.push_back(nums2[j]);
                j++; 
            }
        }
        return res;
    }
};