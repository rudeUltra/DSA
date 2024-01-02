class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int n1=flowerbed.size();
        
        if(n1==1 && flowerbed[0]==0 && n==1){
            return true;
        }
        if(n1==1 && n==0){
            return true;
        }
        
        if(n1==1){
            return false;
        }
        
        for(int i=2;i<n1;++i){
            if(flowerbed[i]==0 && i>0 && i<n1-1){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        if(n!=0){
            if(flowerbed[0]==0 && flowerbed[1]==0){
                n--;
            }
            if(flowerbed[n1-1]==0 && flowerbed[n1-2]==0 && n1!=2){
                n--;
            }
        } //Edge cases
        cout<<n;
        return n<=0;
    }
};