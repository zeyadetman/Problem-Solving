//https://projecteuler.net/problem=1

const sum = (n) => {
  var result=0;
  [...Array(n).keys()].forEach(
    num => (num%3==0||num%5==0) ? result+=num : 0
  );
  return result;
}

sum(1000);
