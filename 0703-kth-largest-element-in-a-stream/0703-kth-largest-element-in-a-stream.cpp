class KthLargest {
public:
    int l;
    priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(int n : nums) pq.push(n);
        l=k;
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>l) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */