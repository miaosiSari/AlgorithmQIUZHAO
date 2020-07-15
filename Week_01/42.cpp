class Solution {
public:
    int trap(vector<int> height) {
        int col = 0;
        int all = 0;
        int maxh = 0;
        for(int i=0;i<height.size();i++){
            col += height[i];
            maxh = max(maxh,height[i]);
        }
        for(int i=1;i<=maxh;i++){
            int l=0;
            int r = height.size()-1;
            while(l<r && height[l]<i)
                l++;
            while(l<r && height[r]<i)
                r--;
            all += r-l+1;
        }
        return all-col;
    }
};