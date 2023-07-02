class Solution {
public:
    int maxArea(vector<int>& height) {
        //2 pointer tum jao nahi tum jao.. xD
        int n=height.size();
        int husband=0;
        int wife=n-1; //cuz the wife is always right what am i doing ... nvm
        int ans=INT_MIN;
        
        while(husband<wife){
            //not equal bcus we need 2!!!! andrew tate F
            ans=max(ans,(wife-husband)*min(height[husband],height[wife]));
            
            //look for next best thing sed
            if(height[husband]<height[wife]){
                husband++; //bruh
            }
            else{
                wife--;
            }
        }
        return ans;
    }
};