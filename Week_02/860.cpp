class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int s = bills.size();
       int m5 = 0, m10 = 0;
       for(int i = 0; i < s; ++i)
       {
          if(bills[i] == 5)
             ++m5;
          else if(bills[i] == 10)
          {
              if(m5 < 1) return false;
              {
                  --m5;
                  ++m10;
              }
          }
          else if(bills[i] == 20)
          {
              if(m5 >= 1 && m10 >= 1)
              {
                  --m5;
                  --m10;
              }
              else if(m5 >= 3)
                  m5 -= 3;
              else
                  return false;
          }
       }
       return true;
    }
};