class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>ump;
        vector<int>res;
        for(int i=0; i<nums.size(); i++){
            ump[nums[i]]++;
        }
        
        vector<pair<int,int>>A;

        for (auto& it : ump)
            A.push_back(it);

        sort(A.begin(), A.end(), [](auto a, auto b)
                { return a.second > b.second;});

       
        for(auto x: A){
            res.push_back(x.first);
            if(res.size()==k)
                return res;
        }
        return res;
    }
};