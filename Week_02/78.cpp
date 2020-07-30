class Solution {
private:
    vector<vector<int> > res;
    vector<int> nums2;
    int size;
    void recursive(vector<int>& t, int n){
        vector<int> t1 = t;
        vector<int> t2 = t;
        if(n != size - 1)
            recursive(t1, n+1);
        t2.push_back(nums2[n]);
        if(n != size - 1)
            recursive(t2, n+1);
        if(n == size - 1)
        {
            res.push_back(t1);
            res.push_back(t2);
        }
        return;
    }

public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> t;
        nums2 = nums;
        size = nums.size();
        recursive(t, 0);
        return res;
    }
};