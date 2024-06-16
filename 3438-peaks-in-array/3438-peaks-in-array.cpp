
#define ll long long
class SegTree{
public:
	int len;
	vector<ll> t;
	
	SegTree(){}
	SegTree(ll l){
		len = l;
		t.resize(4 * len);
	}
	
	// Build Segment Tree -- build(a, 1, 0, len-1); 
	void build1(vector<ll>& a, ll v, ll tl, ll tr){
		if(tl == tr){
			t[v] = a[tl];
			return;
		}
		ll tm = (tl + tr)/2;
		build1(a, 2*v, tl, tm);
		build1(a, 2*v+1, tm+1, tr);
		t[v] = t[2*v] + t[2*v+1];
	}
	
	// Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
	ll query1(int v, int tl, int tr, int l, int r){
		if(tl > r || tr < l) return 0; // no overlap
		if(l <= tl && tr <= r) return t[v]; //Full overlap
		
		// Partial Overlap
		ll tm = (tl + tr)/2;
		ll leftAns = query1(2*v, tl, tm, l, r);
		ll rightAns = query1(2*v+1, tm+1, tr, l, r);
		return leftAns + rightAns;
	}
	
	// Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, id, val) 
	void update1(int v, int tl, int tr, int id, int val){
		// reached leaf node
		if(tl == id && tr == id){
			t[v] = val;
			return;
		}
		if(id > tr || id < tl) return;
		
		ll tm = (tl + tr)/2;
		update1(2*v, tl, tm, id, val);
		update1(2*v+1, tm+1, tr, id, val);
		t[v] = t[2*v] + t[2*v+1];
	}
	
	//over-ridden functions
	void build(vector<ll>& a){
		build1(a, 1, 0, len-1);
	}
	
	int query(int l, int r){
		return query1(1, 0, len-1, l, r);
	}
	
	void update(int id, int val){
		update1(1, 0, len-1, id, val);
	}
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& q) {

        ll n = nums.size();
        vector<ll> peak(n, 0);
        
        for(int i=1; i<n-1; ++i)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                peak[i] = 1;
        }
            
        vector<int> ans;
        
       SegTree st(n);
       st.build(peak);
            
        for(int i=0; i<q.size(); ++i)
        {
            int type = q[i][0];
             
            if(type == 1)
            {
                int l = q[i][1];
                int r = q[i][2];
                
                if(l == r)
                {
                    ans.push_back(0);
                    continue;
                }
                
                ll red = 0;
                
                if(peak[l] == 1)
                    ++red;
                
                if(peak[r] == 1)
                    ++red;
            
                int res = st.query(l, r);
                ans.push_back(res-red);
            }
        
        
            else if(type == 2)
            {
                int p = q[i][1];
                int x = q[i][2];
            
                nums[p] = x;
                
                if(p-1>=0 && p+1<n) // checking index p
                {
                    if(nums[p]>nums[p-1] && nums[p]>nums[p+1])
                    {
                        st.update(p, 1);
                        peak[p] = 1;
                    }
                    
                    else
                    {
                        st.update(p, 0);
                        peak[p] = 0;
                    }
                    
                }
                
                if(p-2>=0 && p<n) // checking index p-1
                {
                    if(nums[p-1]>nums[p-2] && nums[p-1]>nums[p])
                    {
                        st.update( p-1, 1); 
                        peak[p-1] = 1;
                    }
                    
                    else
                    {
                        st.update( p-1, 0);
                        peak[p-1] = 0;
                    }
                }
                
                if(p>=0 && p+2<n) // checking index p+1
                {
                    if(nums[p+1]>nums[p] && nums[p+1]>nums[p+2])
                    {
                        st.update( p+1, 1); 
                        peak[p+1] = 1;
                    }
                    
                    else
                    {
                        st.update( p+1, 0);
                        peak[p+1] = 0;
                    }
                }
            }
        }
        
        return ans;
    }
};