class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<bills.size();++i){
            //try to give higher bills as many as possible so we can give lesser bills to others maximise the chances siu
            if(bills[i]==5){
                mp[5]++;
            }
            else if(bills[i]==10){
                if(mp[5]==0){
                    return false;
                }
                mp[5]--;
                mp[10]++;
            }
            else{
                if(mp[5]==0){
                    return false;
                }
                if(mp[10]!=0){
                    mp[10]--; //try to give the 10 dollar bill 
                    mp[5]--;
                }
                else if(mp[5]<3){
                    return false;
                }
                else{
                    mp[5]=mp[5]-3;
                }
                //20 dollars is useless lmao
                
            }
        }
        
        return true;
    }
};