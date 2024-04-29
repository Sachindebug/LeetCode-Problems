class Solution {
public:
    
    bool check (int mid , vector <int> &arr){
        int n = (int)arr.size() ; 
        int dist = 0 ; 
        unordered_map <int , int > mp ; 
        int head = -1 , tail = 0 ;
        long long ans = 0 ;  
        while(tail < n){
            while(head +1 < n 
                  && ((mp[arr[head+1]] == 0 && dist < mid) || (mp[arr[head+1]] > 0) ))
            {
                head ++ ; 
                if(mp[arr[head]] == 0){
                    dist ++ ; 
                }
                mp[arr[head]] ++ ; 
            }

            ans += 1ll*(head - tail + 1) ; 

            if(head >= tail){
                if(mp[arr[tail]] -1 == 0){
                    dist -- ; 
                }
                mp[arr[tail]] -- ; 
                tail ++ ;
            }
            else{
                tail ++ ; 
                head = tail -1 ; 
            }
            
        }
        long long num = 1ll*n*(n+1) ; 
        num/=2 ; 
        if((num) %2 == 0){
        return ans >= (num/2) ; 

        }
        else{
            return ans >= ((num/2) + 1) ;
        }
        return 0 ; 
    }



    int medianOfUniquenessArray(vector<int>& nums) {
        int n =(int)nums.size() ; 
        unordered_map <int,int> st ; 
        for(int i = 0 ; i< n ; i++){
            st[nums[i]]++;
        }
        int hi = (int)st.size() , lo =1  , mid , ans =1 ;
        while(hi >= lo){
            mid = (hi + lo)/2 ; 
            if(check(mid , nums)){
                ans = mid ; 
                hi = mid -1 ; 
            } 
            else{
                lo = mid +1 ; 
            }
        } 
        return ans ; 
    }
};