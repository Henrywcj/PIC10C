//
//  main.cpp
//  PIC 10C HW1
//
//  Created by Henry Wang on 1/21/18.
//  Copyright © 2018 Henry Wang. All rights reserved.
//

#include <iostream>
#include "TreeNode.h"

int main() {
    BinarySearchTree tree;
    tree.insert("c");
    tree.insert("b");
    tree.insert("d");
    tree.print(tree.get_root()); // output c b d
    BinarySearchTree tree2 = tree; // copy constructor
    tree2.print(tree2.get_root()); // output c b d
    tree2.insert("e");
    tree2.print(tree2.get_root()); // output c b d e
    BinarySearchTree tree3;
    tree3 = tree; // assignment operator
    tree3.print(tree3.get_root()); // output c b d
    tree3.insert("f");
    tree3.print(tree3.get_root()); // output c b d f
    return 0;
}
