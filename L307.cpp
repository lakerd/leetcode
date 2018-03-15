class NumArray {
public:
    vector<int> tree;
    vector<int> A;
    int len;
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = A[start];
            return;
        }
        
        int mid = (start + end) / 2;
        int lc = 2 * node;
        int rc = 2 * node + 1;
        build(lc, start, mid);
        build(rc, mid + 1, end);
        tree[node] = tree[lc] + tree[rc];
    }
    
    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            A[idx] = val;
            tree[node] = val;
            return;
        }
        
        int lc = 2 * node;
        int rc = 2 * node + 1;
        
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update_tree(lc, start, mid, idx, val);
        } else {
            update_tree(rc, mid + 1, end, idx, val);
        }
        tree[node] = tree[lc] + tree[rc];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        if (start >= l && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
    
    NumArray(vector<int> nums) {
        A = nums;
        len = A.size();
        if (len > 0) {
            tree.reserve(len * 4);
            build(1, 0, len - 1);
        }
    }
    
    void update(int i, int val) {
        update_tree(1, 0, len - 1, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(1, 0, len - 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
