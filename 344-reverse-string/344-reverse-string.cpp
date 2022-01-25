class Solution {
public:
    void reverseString(vector<char>& s) {
        //h e l l o
        int n=s.size();
        cout<<n<<endl;
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        
    }
};