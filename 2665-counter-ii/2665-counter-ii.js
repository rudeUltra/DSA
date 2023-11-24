/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let curr=init;
    return {
        increment:function(){
            return ++curr;
        },
        
        reset:function(){
            curr=init;
            return curr;
        },
        
        decrement:function(){
            return --curr;
        }
        
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */