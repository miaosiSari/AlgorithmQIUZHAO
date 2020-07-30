https://leetcode-cn.com/problems/minesweeper/solution/bfs-dfs-by-powcai-8/

class Solution {
public:
    vector<pair<int,int>>direction{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};//方向数组表示8邻域不同位置
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int x=click[0],y=click[1];
    if(board[x][y]=='M')//case1:点到***，结束
    {
        board[x][y]='X';
        return board;
    }
    int between=neighbor(x,y,board);
    if(between==0){     //case2:周围没有***，以此为源点进行BFS
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty())//标准BFS过程
    {
        int size=q.size();
        for(int i=0;i<size;++i)
        {
            auto temp=q.front();
            q.pop();
            int a=temp.first,b=temp.second;
            if(board[a][b]=='M'){
                continue;
            }
            int count=neighbor(a,b,board);//该源点周围的***个数
            if(count==0){//若为零，进一步探索其8邻域
            board[a][b]='B';
            int  m=board.size(),n=board[0].size();
            for(int j=0;j<direction.size();++j)
            {
            int x1=a+direction[j].first,y1=b+direction[j].second;
            if(x1>=0 && x1<m && y1>=0 && y1<n && board[x1][y1]=='E'){//E状态代表未访问过，省却了单独用set进行判断
                board[x1][y1]='B';//此处只是暂时标记，后续出队时若周围有***则会更新状态，我在第一次提交的时候入队也判断了个数，造成大量重复计算，最后两个例子没能AC
                q.push({x1,y1});//入队
            }
            }
            }
            else//更新为***个数
                board[a][b]='0'+count;
        }
    }
    }
    else //case3:周围有***，更新个数
    board[x][y]=between+'0';
    return board;
    }
    int neighbor(int a,int b,vector<vector<char>>& board)//辅助函数，求解一个单元格周围***个数
    {
        int cnt=0;
        int  m=board.size(),n=board[0].size();
        for(int i=0;i<direction.size();++i)
        {
            int x=a+direction[i].first,y=b+direction[i].second;
            if(x>=0 && x<m && y>=0 && y<n)//防止越界
            {
                if(board[x][y]=='M')
                    ++cnt;
            }
        }
        return cnt;
    }
};