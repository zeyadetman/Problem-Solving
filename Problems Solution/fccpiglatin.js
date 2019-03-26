//https://learn.freecodecamp.org/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/pig-latin

function translatePigLatin(str) {
 if(!str[0].match(/(a|i|e|o|u)/g)){
  let consonants = '', i=0;
  while(i<str.length && !str[i].match(/(a|i|e|o|u)/g)) {consonants+= str[i]; i++;}
  return `${str.slice(consonants.length, str.length)+consonants}ay`;
  }
  else{
    return `${str}way`;
  }
}

translatePigLatin("consonant");
