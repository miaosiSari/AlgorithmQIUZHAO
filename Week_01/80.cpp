class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int c = 0;
        int slow = 0, fast = 0;
        while(slow < size && fast < size)
        {
           //printf("slow=%d, fast=%d\n", slow, fast);
           nums[slow] = nums[fast];
           if(fast < size - 1 && nums[fast] == nums[fast+1])
              ++c;
           else
              c = 0;
           if(c <= 1)
           {
               ++slow;
               ++fast;
           }
           else 
               ++fast;
        }   
        return slow; 
    }
};
