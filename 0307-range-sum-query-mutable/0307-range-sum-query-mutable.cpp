



class NumArray {
public:
	int len;
	vector<int> t;
    NumArray(vector<int>& nums) {
        int l=nums.size();
		len = l;
		t.resize(4 * len);
        build(nums, 1, 0 , len-1);
    }
	void build(vector<int>& a, int v, int tl, int tr){
		if(tl == tr){
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr)/2;
		build(a, 2*v, tl, tm);
		build(a, 2*v+1, tm+1, tr);
		t[v] = t[2*v] + t[2*v+1];
	}
	void update1(int v, int tl, int tr, int id, int val){
		// reached leaf node
		if(tl == id && tr == id){
			t[v] = val;
			return;
		}
		if(id > tr || id < tl) return;
		
		int tm = (tl + tr)/2;
		update1(2*v, tl, tm, id, val);
		update1(2*v+1, tm+1, tr, id, val);
		t[v] = t[2*v] + t[2*v+1];
	}
	int query(int v, int tl, int tr, int l, int r){
		if(tl > r || tr < l) return 0; // no overlap
		if(l <= tl && tr <= r) return t[v]; //Full overlap
		
		// Partial Overlap
		int tm = (tl + tr)/2;
		int leftAns = query(2*v, tl, tm, l, r);
		int rightAns = query(2*v+1, tm+1, tr, l, r);
		return leftAns + rightAns;
	}
    

	int sumRange(int l, int r){
		return query(1, 0, len-1, l, r);
	}
	
	void update(int id, int val){
		update1(1, 0, len-1, id, val);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */