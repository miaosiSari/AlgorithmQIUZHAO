class Solution {
public:
    int majorityElement(vector<int>& nums) {
         if(nums.size() == 0)
             return -1;
         int count = 1;
         int candidate = nums[0];  
         for(int i = 1; i < nums.size(); ++i){
             if(candidate == nums[i] || count == 0)
             {
                 ++count;
                 candidate = nums[i];
             }
             else
                 --count;
         }
         return candidate;
    }
};