class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //Aha Greedy 
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int score=0;
        int left=0;
        int right=n-1;
        
        while(left<=right){
            if(power>=tokens[left]){
                score++;
                power=power-tokens[left];
                left++;
            }
            else{
                if(score==0){
                    //Can't play anyomore sed
                    return 0;
                }
                if(left==right){
                    //no pOINT TAKing anymore sed
                    return score;
                }
                score--;
                power=power+tokens[right];
                right--;
            }
        }
        return score;
    }
};