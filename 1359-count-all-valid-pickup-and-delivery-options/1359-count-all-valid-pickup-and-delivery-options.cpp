class Solution {
public:
    int countOrders(int n) {
        //Generate all permutation then check if they are valid or not
        //Bhai this was big brain meths how tf will i do this in coding Interview lol
        
        long ans=1;
        int mod=1e9+7;
        
        int slots=2*n;
        
        while(slots){
            int choices=(slots)*(slots-1);
            choices=choices/2;
            ans=((ans%(mod))*(choices%(mod)))%mod;
            slots=slots-2;
        }
        return ans%mod;
    }
};