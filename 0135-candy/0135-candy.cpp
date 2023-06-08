class Solution {
public:
    int candy(vector<int>& ratings) {
        //imagine kids standing in line xD like class 1 0.o
        
        //first check all kids to  ur left
        //then check all kids to ur right 
        
        int n=ratings.size();
        vector<int>left(n,1);
        vector<int>right(n,1); //Each kid will atleast get 1 candy xD like me Xd rememeber bucket lul
        
        for(int i=1;i<n;++i){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1; //i shall get one candy extra than u siu
            }
        }
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                //i am better chal candy de xD
                right[i]=right[i+1]+1;
            }
        }
        int sum=0;
        
        for(int i=0;i<n;++i){
            sum=sum+max(left[i],right[i]);
        }
        return sum;
    }
};