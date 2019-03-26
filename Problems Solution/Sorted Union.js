// https://learn.freecodecamp.org/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/sorted-union

function uniteUnique(arr) {
  return ([...new Set([...arguments].flat())]);
}

uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]);
