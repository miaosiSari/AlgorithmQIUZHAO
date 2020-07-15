class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         vector<int> res;
         if(digits.size() == 0) return res;
         res.resize(digits.size());
         int c_in = 0;
         for(int cnt = digits.size() - 1; cnt >= 0; --cnt)
         {
             if(cnt == digits.size() - 1){
                res[cnt] = (digits[cnt] + 1)%10;
                c_in =   (digits[cnt] + 1)/10;
             }
             else
             {
                 res[cnt] = (digits[cnt] + c_in)%10;
                 c_in = (digits[cnt] + c_in)/10;
             }
         }
         if(c_in == 1)
            res.insert(res.begin(), 1);
         return res;
    }
};