class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> rem(k,0);
        for(int i=0;i<arr.size();i++)
        {
            rem[(arr[i]%k+k)%k]++;
        }
        int count=0;
        if(rem[0]%2) return false;
        count+=(rem[0]/2);
        for(int i=1;i<=k/2;i++)
        {
            if(k-i!=i)
            {
                if(rem[i]!=rem[k-i]) return false;
                count+=rem[i];
            }
        }
        if(k%2==0)
        {
            if(rem[k/2]%2) return false;
            count+=(rem[k/2]/2);
            
        }
        return count==(n/2);
    }
};