var createCounter = function(n) {
  return function() {
    return n++;      
  };
};
//SO basically n is a global variable who will tell all that Da