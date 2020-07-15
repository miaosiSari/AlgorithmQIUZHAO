class Solution {
private:
    void reverse(vector<int>& nums, int start, int end)
    {
        int l = start, r = end;
        while(l < r)
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            ++l;
            --r;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
         if(nums.size() == 0 || k <= 0) return;
         if(k >= nums.size()) k %= nums.size();
         reverse(nums, 0, nums.size() - 1);
         reverse(nums, 0, k-1);
         reverse(nums, k, nums.size() - 1);
    }
};