class Solution{
public:

    vector<int>res;
    void merge(vector<pair<int,int>>&nums,int low,int high,int mid){
        int l=mid-low+1,r=high-mid;
        vector<pair<int,int>>left,right;
        for(int i=low;i<=mid;i++)   left.push_back(nums[i]);
        for(int j=mid+1;j<=high;j++) right.push_back(nums[j]);
        int k=low,i=0,j=0;
        while(i<l and j<r){
            if(left[i].first>right[j].first){
                nums[k]=right[j];
                j++;
            }
            else{
                nums[k]=left[i];
                res[left[i].second]+=j;
                i++;
            }
            k++;
        }
        while(i<l){
            nums[k++]=left[i];
            res[left[i++].second]+=j;
        }
        while(j<r) nums[k++]=right[j++];
        return;
    }

    void mergeSort(vector<pair<int,int>>&nums,int low,int high){
        if(low>=high)
            return;
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,high,mid);
    }

    vector<int>countSmaller(vector<int>&nums){
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],i});
        cout<<vec.size()<<endl;
        res.resize(nums.size(),0);
        mergeSort(vec,0,vec.size()-1);
        return res;      
    }
};