var evalRPN = function(tokens) {
  const stack = []; // ["2", "1", "+", "3", "*"]
  let i = 0;
  if(tokens.length === 1) return Number(tokens[0]);
  stack.push(tokens[i++]);
  stack.push(tokens[i++]);
  while(stack.length && tokens[i]) {
    if(!isNaN(tokens[i])) {
      stack.push(tokens[i]);
    } else {
      const num2 = Number(stack.pop());
      const num1 = Number(stack.pop());
      if(tokens[i] === '+') stack.push(num1 + num2);
      if(tokens[i] === '*') stack.push(num1 * num2);
      if(tokens[i] === '-') stack.push(num1 - num2);
      if(tokens[i] === '/') stack.push(
        Math.trunc(num1 / num2)
      );
    }
    i++;
  };

  return stack.pop();
};

//test cases
[["2", "1", "+", "3", "*"], ["18"], ["4", "13", "5", "/", "+"], ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]].map(v => {
  console.log(evalRPN(v));
});
