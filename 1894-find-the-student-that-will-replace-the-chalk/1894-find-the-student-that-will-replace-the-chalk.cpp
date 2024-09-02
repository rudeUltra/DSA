class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        int total=0;
        int initial=k;
        for(int i=0;i<n;++i){
            if(chalk[i]>k){
                return i;
            }
            total+=chalk[i];
            k=k-chalk[i];
        }
        int remainder=initial%total;
        
        for(int i=0;i<n;++i){
            if(chalk[i]>remainder){
                cout<<remainder<<" ";
                return i;
            }
            remainder=remainder-chalk[i];
        }
        
        return 0;
    }
};