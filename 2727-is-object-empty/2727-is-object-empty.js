/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let stringObj = JSON.stringify(obj);
    return ((stringObj[0]=='{'  && stringObj[1]=='}') || (stringObj[0]=='['  && stringObj[1]==']'))
};