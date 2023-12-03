//Maps it is wut is isss



var TimeLimitedCache = function() {
    this.cache=new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let found=this.cache.has(key);
    if(found){
        clearTimeout(this.cache.get(key).ref); //delete this fonction
    }
    
    //not found time to add
    
    this.cache.set(key,{
           val:value,
            ref:setTimeout(()=>this.cache.delete(key),duration)
        });
    
    // this.cache.set(key, {
    //     value,  // Equivalent to `value: value`
    //     ref: setTimeout(() => this.cache.delete(key), duration)
    // });
    return found;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if(this.cache.has(key)){
        return this.cache.get(key).val;
    }
    return -1;
    
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */


//Bhai ye kya hai ...Aiyoo

