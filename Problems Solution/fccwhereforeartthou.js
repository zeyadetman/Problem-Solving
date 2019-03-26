//https://learn.freecodecamp.org/javascript-algorithms-and-data-structures/intermediate-algorithm-scripting/wherefore-art-thou/

function whatIsInAName(collection, source) {
  // What's in a name?
  var arr = [];
  // Only change code below this line
  
  collection.map(obj => {
    let i = 0;
    Object.keys(source).map(key=>
      obj.hasOwnProperty(key) ? obj[key] === source[key] ? i++ : i = 0 : 0
    )
    i === Object.keys(source).length ? arr.push(obj) : 0;
  })
  
  // Only change code above this line
  return arr;
}

whatIsInAName([{ first: "Romeo", last: "Montague" }, { first: "Mercutio", last: null }, { first: "Tybalt", last: "Capulet" }], { last: "Capulet" });
