class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
        if(commands.size() == 0) return 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        int d = 3;
        int d1 = 0, d2 = 0;
        int maxeuclid = 0;
        set<pair<int, int> > obs;
        for(int i = 0; i < obstacles.size(); ++i)
            obs.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        for(int i = 0; i < commands.size(); ++i)
        {
             if(commands[i] == -1)
                d = (d + 1)%4;
             else if (commands[i] == -2)
             {
                d = (d - 1)%4;
                if(d < 0) d += 4;
             }
             else{
                 for(int j = 0; j < commands[i]; ++j)
                 {
                       pair<int, int> p = make_pair(d1 + dx[d], d2 + dy[d]);
                       if(obs.count(p) == 1)
                           break;
                       else
                       {
                            d1 += dx[d];
                            d2 += dy[d];
                            int dis = d1 * d1 + d2 * d2; 
                            if(dis > maxeuclid) maxeuclid = dis;
                       }
                 }
             }
        }
        return maxeuclid;   
    }
};