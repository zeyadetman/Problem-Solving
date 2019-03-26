const palindrome = num =>
  num.toString() === num.toString().split('').reverse().join('') ? true : false;

function pal(a,b){
  let result = new Set([]);
  for(let i=a;i<=b;i++){
    for(let j=i; j<=b; j++){
      result.add(i*j);
    }
  }
  
  let min=0,max=0,ind=100000000000; 
  Array.from(result).filter((val, indx) => {
    if(palindrome(val)) {
      if(indx <= ind){
        min = val;
        ind = indx;
      } else {
        max=val;
      }
    }
  })

  return [min, max];
}

pal(2,100); // 4, 9009
