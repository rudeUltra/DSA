class Solution {
public:
    
    bool static cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //Treat empty spaces as Taller people as you know since the array is sorted there will be a taller person hm
        
        int n=people.size();
        sort(people.begin(),people.end(),cmp);
        
        vector<vector<int>>ans(n);
        
       
        
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(people[i][1]==count && ans[j].size()==0){
                    //Not occupied xD
                    ans[j]=people[i];
                    break;
                }
                
                if(ans[j].size()==0){
                    count++; //empty
                }
            }
        }
        
        return ans;
        
    }
};