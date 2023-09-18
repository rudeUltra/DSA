class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<wordList.size();++i){
            mp[wordList[i]]++;
        }
        
        if(mp[endWord]==0){
            return 0; //Bruh
        }
        
        //bc bfs and timers are really annoying xD but it is what it is
        
        int steps=0;
        queue<string>pq;
        
        pq.push(beginWord);
        
        while(!pq.empty()){
            int n=pq.size();
            while(n--){
                auto it=pq.front();
                pq.pop();
                if(it==endWord){
                    return steps+1;
                }
                
                for(int i=0;i<it.size();++i){
                    //Try to replace each character siu
                    string temp=it;
                    for(char c='a';c<='z';++c){
                        temp[i]=c;
                        if(mp.find(temp)!=mp.end()){
                            //SIUU
                            pq.push(temp);
                            mp.erase(temp);
                        }
                        
                    }
                }
            }
            steps++;
        }
        
        return 0;
    }
};