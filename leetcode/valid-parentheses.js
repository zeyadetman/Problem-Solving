// https://leetcode.com/problems/valid-parentheses

/**
 * @param {string} s
 * @return {boolean}
 */
 
const parenthesesMap = {
  '(': ')',
  '{': '}',
  '[': ']'
};

var isValid = function(s) {
        var stack = [];
    s.split('').forEach((char) => {
      
      if(stack.length === 0) stack.push(char);
      else {
        var lastCharAdded = stack[stack.length-1];
        if(parenthesesMap[lastCharAdded] === char) {
          stack.pop();
        } else {
          stack.push(char);
        }
      }
    });
    
    return stack.length ? false : true;
};
