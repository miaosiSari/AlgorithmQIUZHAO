class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        while(size <= 1) return true;
        int maxreach = 0;
        int cnt = 0;
        while(maxreach < size-1 && cnt <= maxreach){
            if(nums[cnt] + cnt > maxreach) maxreach = nums[cnt] + cnt;
            ++cnt;
        }
        if(maxreach >= size-1) return true;
        return false;
    }
};
