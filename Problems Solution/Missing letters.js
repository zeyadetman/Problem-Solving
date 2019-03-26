// https://learn.freecodecamp.org/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/missing-letters

function fearNotLetter(str) {
  const alpha = 'abcdefghijklmnopqrstuvwxyz';
  const subAlpha = alpha.slice(alpha.indexOf(str[0]), alpha.indexOf(str[str.length-1])+1);
  let res;
  for(let i=0; i<subAlpha.length; i++){
    res = str.indexOf(subAlpha[i]) === -1 ? subAlpha[i] : res;
  }

  return res;
}

fearNotLetter("abce");
