//https://learn.freecodecamp.org/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/spinal-tap-case

function spinalCase(str) {
  // "It's such a fine line between stupid, and clever."
  // --David St. Hubbins
  return str.split(/(?=[A-Z])/g).map(w=>w.replace(/(-|_)/g, ' ').trim()).map(w=>w.split(' ')).flat().map(w=>w.toLowerCase()).join('-');
}

spinalCase('This Is Spinal Tap');
