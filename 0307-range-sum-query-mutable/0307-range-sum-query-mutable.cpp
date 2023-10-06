class NumArray {
public:
    //Bhai jaan ye to direct hogaya lmao xD
    vector<int>segment;
    int k=0;
    void buildTree(vector<int>&nums,int low,int high,int index){
        if(low==high){
            segment[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        
        buildTree(nums,low,mid,index*2+1);
        buildTree(nums,mid+1,high,index*2+2);
        
        segment[index]=segment[index*2+1]+segment[index*2+2]; //siu
    }
    
    void pointUpdate(int index,int point,int newVal,int low,int high){
        if(low==high && point==low){
            segment[index]=newVal;
            return;
        }
        
        int mid=(low+high)/2;
        
        if(point<=mid && point>=low){
            //SUS
            pointUpdate(index*2+1,point,newVal,low,mid);
        }
        else{
            pointUpdate(index*2+2,point,newVal,mid+1,high);
        }
        
        segment[index]=segment[index*2+1]+segment[index*2+2]; //Update the parent hm
        return;
    }
    
    int getSum(int low,int high,int index,int l,int r){
        if(high<l || low>r){
            return 0;
        }
        if(low>=l && high<=r){
            //Complete inside hm
            return segment[index];
        }
        
        //split
        int mid=(low+high)/2;
        
        return getSum(low,mid,index*2+1,l,r)+getSum(mid+1,high,index*2+2,l,r); //siu
    }
    
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        k=n;
        segment.resize(n*4,0);
        buildTree(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        pointUpdate(0,index,val,0,k-1);
    }
    
    int sumRange(int left, int right) {
        return getSum(0,k-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */