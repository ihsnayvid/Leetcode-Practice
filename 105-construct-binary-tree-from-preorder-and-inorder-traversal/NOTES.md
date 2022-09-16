In preorder root is always the first elt so start from there
Now one by one take elts from preorder, search them in inorder ( returns idx of the elt)
​
now tree->right = preorder -> start to idx -1
tree->left   = preorder -> idx +1 to end
​