class Solution {
private:
    unordered_set<string> visit;
    int size;

    //一定要加引用, 否则超时
    bool distance(string& i, string& j)
    {
        int isize = i.size();
        int count = 0;
        for(int x = 0; x < isize; ++x){
           if(i[x] != j[x])
              ++count;
           if(count > 1) return false;
        }
        return count == 1;
    }


    int find_exists(string beginWord, string endWord, vector<string>& wordList, int& begin, unordered_map<string, vector<string> >& neighbor){
        int res = -1;
        for(int i = 0; i < size; ++i){
            if(endWord == wordList[i])
                res = i;
        }

        if(begin == -1)
        {
            wordList.push_back(beginWord);
            ++size;
            begin = size - 1;
        }

        for(int i = 0; i < size; ++i){
           for(int j = 0; j < i; ++j)
           {
              if(distance(wordList[i], wordList[j])){
                 neighbor[wordList[i]].push_back(wordList[j]);
                 neighbor[wordList[j]].push_back(wordList[i]);
              }
           }
        }
        return res;
    }
    
    /*
    void printvis(){
        for(int i = 0; i < size; ++i)
           printf("visit[%d] = %d\n", i, visit[i]);
    }

    void printneighbor(){
        for(int i = 0; i < size; ++i){
           printf("neighbor[%d].size()=%lu\n", i, neighbor[i].size());
           for(int j = 0; j < neighbor[i].size(); ++j)
              printf("<%d %d>\n", i, neighbor[i][j]);
        }
    }
    */

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string> > neighbor;
        size = wordList.size();
        if(size == 0) return 0;
        int begin = -1;
        int find = find_exists(beginWord, endWord, wordList, begin, neighbor);
        if(find == -1) return 0;
        queue<string> q;
        q.push(beginWord);
        visit.insert(beginWord);
        int step = 1;
        while(!q.empty())
        {
           int qsizenow = q.size();
           for(int qpointer = 0; qpointer < qsizenow; ++qpointer)
           {
                string cur = q.front();
                //printf("cur=%d, step=%d\n", cur, step);
                q.pop();
                //printf("cur = %d, neighbor[%d] = %lu\n", cur, cur, neighbor[cur].size());
                vector<string> neigh= neighbor[cur];
                int neighsize = neigh.size();
                for(int i = 0; i < neighsize; ++i)
                {
                    string here =  neigh[i];
                    if(visit.find(here) == visit.end()){
                        //printf("here=%d\n", here);
                        visit.insert(here);
                        if(endWord == here){
                            //printvis();
                            //printf("here=%d\n", here);
                            return step+1;
                        }
                        q.push(here);
                    }
                }
           }//qsize
           ++step;
        }//while
        return 0;
    }
};