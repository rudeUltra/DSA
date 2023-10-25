class Solution {
public:
    
    int dfs(int n,int k,int rootval){
        if(n==1){
            return rootval;
        }
        
        //For this current sbutree i have 2n-1 leaf nodes
        
        //now decide where is k left or right Kind of like BST hm
        int total=pow(2,n-1);
        
        if(k>total/2){
            //hm its on the right side
            rootval=rootval==0?1:0;
            return dfs(n-1,k-total/2,rootval);
            
        }
        
        //siu left side
        rootval=rootval==1?1:0;
        return dfs(n-1,k,rootval);
    }
    int kthGrammar(int n, int k) {
        //Queue it is Siuu
        
        queue<int>pq;
        if(n==1 && k==1){
            return 0;
        }
//         pq.push(0);
        
//         int level=1;
//         while(!pq.empty()){
//             int m=pq.size();
            
//             if(level==n){
//                 //hm
//                 for(int i=0;i<k;++i){
//                     int x=pq.front();
//                     pq.pop();
//                     if(i==k-1){
//                         return x;
//                     }
//                 }
//             }
            
//             for(int i=0;i<m;++i){
//                 auto it=pq.front();
//                 pq.pop();
                
//                 if(it==0){
//                     pq.push(0);
//                     pq.push(1);
//                 }
//                 else{
//                     pq.push(1);
//                     pq.push(0);
//                 }
//             }
//             level++;
            
//         }
        //Observation based ? Hm
        //Woah Tree visualization kind problem very nice ngl
        
        //The point is no need to build the tree but visualize it soi
        
        return dfs(n,k,0);
        
        
        
        
    }
};