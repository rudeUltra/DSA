class Solution {
public:
    	bool isValid(vector<int>& bloomDay, int m, int k, int mid) {

		int count = 0, size = 0;
		for (int i = 0; i < bloomDay.size(); i++) {
			size = (bloomDay[i] <= mid) ? size+1 : 0;
			if (size == k) size = 0, count++;
			if (count == m)
				return true;
		}

		return false;
	}
    int minDays(vector<int>& bloomDay, int m, int k) {
        //search over a possible set of answers and choose the min ! (valid or not also check)
        	if(bloomDay.size() == 0 || m == 0 || k == 0) return 0;
		if ((1LL)*m * (1LL)*k > bloomDay.size()) return -1;
        int n=bloomDay.size();
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<n;++i){
            l=min(l,bloomDay[i]);
            h=max(h,bloomDay[i]);
        }
        //l-h possible set of answers siu
        int ans=-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isValid(bloomDay,m,k,mid)){
                ans=mid;
                h=mid-1; //search for a better ans
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};