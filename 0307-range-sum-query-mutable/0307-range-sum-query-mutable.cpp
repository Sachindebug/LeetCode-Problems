class NumArray {
private:
    vector<int> seg;
    vector<int> arr;
    int n;
    void build(int l, int r, int idx, vector<int> &arr){
        if(l==r){
            seg[idx] = arr[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(l,mid,2*idx+1,arr);
        build(mid+1,r,2*idx+2,arr);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    int query(int s, int e, int idx, int l, int r){
        if(r<s || l>e) return 0;
        if(l<=s && r>=e) return seg[idx];
        int mid = s+(e-s)/2;
        int lres = query(s,mid,2*idx+1,l,r);
        int rres = query(mid+1,e,2*idx+2,l,r);
        return lres+rres;        
    }
    void updateSeg(int l, int r, int idx, int index, int val){
        if(l==r){
            seg[idx] = val;
            return;
        }
        int mid = l+(r-l)/2;
        if(index<=mid) updateSeg(l,mid,2*idx+1,index,val);
        else updateSeg(mid+1,r,2*idx+2,index,val);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        seg.resize(4*n+1);
        build(0,n-1,0,arr);
    }
    void update(int index, int val) {
        return updateSeg(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */