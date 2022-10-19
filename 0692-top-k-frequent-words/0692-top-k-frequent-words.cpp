class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for(auto i : words) ++counts[i];
        
        vector<vector<string>> buckets(words.size() + 1);
        for(auto & k : counts) 
            buckets[k.second].push_back(k.first);
        reverse(begin(buckets), end(buckets));
        
        vector<string> res;
        for(auto & bucket: buckets) {
            sort(bucket.begin(),bucket.end());
            for(auto i : bucket) {
                res.push_back(i);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};