/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    var temp=[];
    var ans=[];
    var size1=0;
    arr.forEach((val,idx)=>{
        temp.push(val);
        size1++;
        if(size1==size){
            ans.push(temp);
            temp=[];
            size1=0;
        }
        else if(idx==arr.length-1){
            ans.push(temp);
        }
    })
    
    return ans
};
