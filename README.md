# HeapAndBST
Heap &amp; BST basic tasks:

* Make a set of maximums for real numbers (double type) using table. The heap should support the following functions:
    insert: insert an item into the pile,
    deleteMax: delete maximum item,
    max: maximum item return &
    destroy: heap destruction, deletion of all elements of the heap.

* Also implement a BST for real numbers using pointers. The tree should support the following functions:
    insert: enter an item in the tree,
    search: search for an item in the tree,
    deleteMax: delete maximum item,
    max: maximum item return,
    rotate left / right: left / right rotation &
    destroy: tree destruction, deletion of all tree elements.


It first reads from the user a integer N and create a heap of maximum size N and a blank BST. It will then produce random N numbers in the space [0, 100) which it will enter one by one into the heap and BST. It will then perform the maximum deletion function element N / 2 times both in the heap and in the search tree. It will print the current maximum for both structures on the screen. It will then randomly select one of the elements of the heap and search for that element in the search tree and report its number comparisons required to be found. At the location where the item was located in the tree, an attempt will be made to make a right turn first, and if not a left turn. In any case, a message will be printed on whether a rotation has been performed and if so. Finally, the program will destroy the heap and the BST and end it.
