class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        priority_queue<pair<int,string>> pq;
        map<string,int> ump;
        for(int i = 0;i<word.length();i+=k)
        {
            string s= "";
            for(int j = i;j<i+k;j++) s+=word[j];
            ump[s]++;
        }
        for(auto x:ump)
        {
            pq.push({x.second,x.first});
        }
        pq.pop();
        int count = 0;
        while(!pq.empty())
        {
            int x = pq.top().first;
            count+=x;
            pq.pop();
        }
        return count;
        
    }
};