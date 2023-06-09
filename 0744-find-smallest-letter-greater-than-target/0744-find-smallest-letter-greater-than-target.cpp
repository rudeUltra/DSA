class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0;
        int high=letters.size()-1;
        char ans=letters[0];
        while(low<=high){
            int mid=(low+high)/2;
            cout<<mid<<" ";
            if(letters[mid]>target){
                //siu
                ans=letters[mid];
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};