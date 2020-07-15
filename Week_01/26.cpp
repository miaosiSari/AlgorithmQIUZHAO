class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int len = nums.size();
         if(len == 0)
             return 0;
         int res = 1;
         int curplace = 0;
         int current = nums[0];
         for(int i = 0; i < len; ++i)
             if(nums[i] != current){
                 ++curplace;
                 nums[curplace] = nums[i];
                 current = nums[curplace];
                 ++res;
             }
         return res;
    }
};