class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
         
         int n = nums1.size() , m = nums2.size(); 
         vector<int> a = nums1 , b = nums2; 
        
         int max1 = nums1[n-1] , max2 = nums2[m-1];  
         int ans1 = 0 , ans2 = 1; 
         for(int i = 0 ; i < n-1 ; i++){
              if(nums1[i] > max1 and nums2[i] > max1)return -1;
              if(nums1[i] > max2 and nums2[i] > max2)return -1; 
              if(nums1[i] <= max1 and nums2[i] <= max2 )continue; 
              swap(nums1[i] , nums2[i]); ans1++; 
              if(nums1[i]>max1 || nums2[i] > max2)return -1; 
          } 
         for(int i = 0 ; i < n-1 ; i++){
              if(a[i] <= max2 and b[i] <= max1 )continue; 
              swap(a[i] , b[i]); ans2++;
              if(a[i]>max2 || b[i] > max1) return ans1; 
         }
         
         return min(ans1 , ans2); 
    }
};