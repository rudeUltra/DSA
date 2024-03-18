class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //I will need u in the next group but if u become 0 then gg return false siu.
        int n=hand.size();
        //I need a min queue hm.
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        
        if(n%groupSize!=0){
            //Maa Chuda not divisble hm.
            return false;
        }
        
        
        for(int i=0;i<n;++i){
            mp[hand[i]]++;
            if(mp[hand[i]]==1){
                pq.push(hand[i]); //only push once cuz no need to repeat 
            }
        }
        
        while(!pq.empty()){
            int first=pq.top();
            
            for(int i=first;i<first+groupSize;++i){
                if(mp[i]==0){
                    //Wow.
                    return false;
                }
                
                mp[i]--;
                
                if(mp[i]==0){
                    //eK sec
                    if(pq.top()!=i){
                        //i need u but u left me sed
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        
        return true;
        
        
        
    }
};