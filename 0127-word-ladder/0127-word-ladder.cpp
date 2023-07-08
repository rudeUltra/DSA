class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<wordList.size();++i){
            mp[wordList[i]]++;
        }
        
        if(mp[endWord]==0){
            return 0; //sed can't make string salam ALeekUM
        }
        queue<string>pq;
        pq.push(beginWord);
        int steps=0;
        while(!pq.empty()){
            int n=pq.size();
            for(int k=0;k<n;++k){
                //check out all possibilities SIU
                auto it=pq.front();
                pq.pop();
                if(it==endWord){
                    return steps+1;
                }
                int m=it.size();
                for(int i=0;i<m;++i){
                    //check each char siu
                    string temp=it;
                    for(char ch='a';ch<='z';++ch){
                        temp[i]=ch;
                        if(mp.find(temp)!=mp.end()){
                            //exists salam alekumm
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