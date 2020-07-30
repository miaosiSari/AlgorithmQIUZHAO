class Solution {
private:
    int m, n, c;
    vector<vector<bool> > isvisit;
    queue<pair<int, int> > q;
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        m = grid.size();
        n = grid[0].size();
        c = 0;
        for(int i = 0; i < m; ++i){
           vector<bool> temp;
           for(int j = 0; j < n; ++j)
              temp.push_back(false);
           isvisit.push_back(temp);
        }
        for(int i = 0; i < m; ++i)
           for(int j = 0; j < n; ++j)
           {
               if(!isvisit[i][j] && grid[i][j] == '1')
               {
                   c++;
                   isvisit[i][j] = true;
                   q.push(make_pair(i, j));
                   while(!q.empty())
                   {
                       pair<int, int> p = q.front();
                       int a = p.first;
                       int b = p.second;
                       q.pop();
                       if(a + 1 < m && !isvisit[a+1][b] && grid[a+1][b] == '1'){
                           q.push(make_pair(a+1, b));
                           isvisit[a+1][b] = true;
                       }
                       if(a - 1 >= 0 && !isvisit[a-1][b] && grid[a-1][b] == '1'){
                           q.push(make_pair(a-1, b));
                           isvisit[a-1][b] = true;
                       }
                       if(b + 1 < n && !isvisit[a][b+1] && grid[a][b+1] == '1'){
                           q.push(make_pair(a, b+1));
                           isvisit[a][b+1] = true;
                       }
                       if(b - 1 >= 0 && !isvisit[a][b-1] && grid[a][b-1] == '1'){
                           q.push(make_pair(a, b-1));
                           isvisit[a][b-1] = true;
                       }
                   }
               }
           }
        return c;
    }
};