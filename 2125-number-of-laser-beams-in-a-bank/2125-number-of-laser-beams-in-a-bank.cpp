class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        
        vector<int>rows(n,0);
        
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<m;++j){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            rows[i]=count;
            cout<<rows[i]<<" ";
        }
        
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(bank[i][j]=='1'){
                    
                    int count=0;
                    int k=i+1;
                    
                     if(k==n){
                        break;
                    }
                    
                    //go down the rows hm
                    while(k<n && rows[k]==0){
                        k++;
                    }
                    
                     if(k==n){
                        break;
                    }
                    
                    count+=rows[k];
                    ans+=count;
                }
            }
        }
        
        return ans;
    }
};