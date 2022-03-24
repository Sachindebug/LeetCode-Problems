class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
                
            }
            else
            {
                j--;
            }
            count++;
        }
        if(i==j) count++;
        return count;
    }
};