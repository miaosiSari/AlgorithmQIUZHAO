class Solution {
private:
    unordered_map<char, vector<char> > m;
    vector<string> res;
    int size;
    string dig;
    void initialize(){
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
    }

    void recursive(string& cur, int i){
        //printf("i=%d\n", i);
        if(i == size){
            res.push_back(cur);
            return;
        }
        else{
            //printf("%c", dig[i]);
            if(dig[i] == '0' || dig[i] == '1')
                recursive(dig, i+1);
            else if(dig[i] >= '2' && dig[i] <= '9')
            {
                for(vector<char>::iterator it = m[dig[i]].begin(); it!=m[dig[i]].end(); ++it)
                {
                     //printf("*it = %c", *it);
                     string cur2 = cur + *it;
                     recursive(cur2, i+1);  
                }
            }
        }
    }


public:
    vector<string> letterCombinations(string digits) {
       size = digits.size();
       if(size == 0) return res;
       initialize();
       string cur = "";
       dig = digits;
       recursive(cur, 0);
       return res;
    }
};