class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comparestring);
        // reverse(nums.begin(),nums.end());
        int n=nums.size();
      
        
        return nums[k-1];
        
    }
//     string quickSelect(vector<string> &arr,int l,int r, int k)
//     {
//         if(k>0 && k<=r-l+1)
//         {
//             int idx=partition(arr,l,r);
//             if(idx-l==k-1) return arr[idx];
//             else if(idx-l>k-1) return quickSelect(arr,l,idx-1,k);
//             else return quickSelect(arr,idx+1,r,k-idx+l-1);
            
//         }
//         return arr[l];
        
//     }
//     int partition(vector<string> &arr,int l ,int r)
//     {
//         string x=arr[r];
//         int i=l;
//         for(int j=l;j<r;j++)
//         {
//             if(comparestring(arr[j],x))
//             {
//                 swap(arr[j],arr[i]);
//                 i++;
//             }
//         }
//         swap(arr[i],arr[r]);
//         return i;
//     }
    static bool comparestring(string s,string t)
    {
        if(s.length()>t.length()) return true;
        if(t.length()>s.length()) return false;
        return (s>t);
    }
};