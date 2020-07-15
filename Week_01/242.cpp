class Solution {
public:
    bool isAnagram(string s, string t) {
       int hash[26];
       memset(hash, 0, sizeof(hash));
       int size_s = size(s), size_t = size(t);
       if(size_s != size_t) return false;
       if(size_s == 0 && size_t == 0) return true;
       for(int cnt = 0; cnt < size_s; ++cnt)
            ++hash[s[cnt] - 'a'];
       for(int cnt = 0; cnt < size_t; ++cnt)
            --hash[t[cnt] - 'a'];
       for(int cnt = 0; cnt < 26; ++cnt)
            if(hash[cnt] != 0) 
                 return false;
       return true;
    }
};