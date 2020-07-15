class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int slow = 0, fast = 0, size = nums.size();
       if(size == 0) return;
       while(slow < size && fast < size)
       {
           while(fast < size && nums[fast] == 0) ++fast;
           if(fast < size){
               nums[slow] = nums[fast];
               ++slow, ++fast;
           }
       }
       cout << slow << endl;
       while(slow < size)
       {
           nums[slow] = 0;
           ++slow;
       }
    }
};