class Solution {
public:

bool isValid(vector<int> &v,int mid){
    int count  = 0;
    for(auto x:v){
        if(x>=mid) count++;
    }

return count>=mid;
}

int hIndex(vector<int>& v) {

    int high = *max_element(v.begin(),v.end());
    int low = 1;
    int ans = 0;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(isValid(v,mid)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }   
    return ans; 
    
}
};