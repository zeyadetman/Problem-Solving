# Building BST using Javascript

This file is a playground with BST.

## Without Pivot

The input array is sorted, so the binary search tree will looks like in just one direction (right). So we'll lose all BST features,
and to solve this we have to choose a pivot to be the root.
```js
const l = [-1, 0, 3, 5, 9, 12]
let binaryTree = null;

const add = (root, item, index) => {
  console.log(root, item)
  let node = root.get(Array.from(root.keys())[0]);
  console.log({nodeValue: node.value, item})
  if (item > node.value) {
    if (node.right) {
      add(node.right, item, index)
    } else {
      node.right = new Map();
      node.right.set(
        item,
        { left: null, right: null, value: item, index }
      );
    }
  }

  if (item < node.value) {
    if (node.left) {
      add(node.left, item, index)
    } else {
      node.left = new Map();
      node.left.set(
        item,
        { left: null, right: null, value: item, index }
      );
    }
  }
}

l.forEach((item, index) => {
  if (binaryTree === null) {
    binaryTree = new Map()
    binaryTree.set(
      item,
      { left: null, right: null, value: item, index }
    );
  } else {
    const root = Array.from(binaryTree.keys())[0];
    add(binaryTree, item, index);
  }
})
```