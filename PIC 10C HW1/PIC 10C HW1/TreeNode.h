//
//  TreeNode.h
//  PIC 10C HW1
//
//  Created by Henry Wang on 1/21/18.
//  Copyright © 2018 Henry Wang. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

#include <string>

class TreeNode
{
public:
    
    /*
    Default constructor for TreeNode class
    */
    TreeNode();
    
    /*
    Constructor for TreeNode class
     @param input_data: the data to store in the TreeNode
    */
    TreeNode(const std::string& input_data);
    
    /*
     Destructor for TreeNode class
     */
    ~TreeNode();
    
    /*
     connect the new_node with other TreeNode object
     @param new_node: node that need to be connected to other TreeNode object
     */
    void insert_node(TreeNode*& new_node);

   
private:
    std::string data;
    TreeNode* left;
    TreeNode* right;
    friend class BinarySearchTree;
};




class BinarySearchTree
{
public:
    /*
     Default constructor for BinarySearchTree class
     */
    BinarySearchTree();
    
    /*
     insert data into the binary search tree
     @param data: string data that need to be inserted to binary search tree
     */
    void insert(const std::string& data);
    
    /*
     Accessor function that get the root of the binary search tree
     @return rt: pointer to TreeNode object that is the root of the binary search tree
     */
    TreeNode* get_root() const;
    
    /*
     Destructor for BinarySearchTree class
     */
    ~BinarySearchTree();
    
    /*
     Copy Constructor for BinarySearchTree class
     @param right: the BinarySearchTree object which we copy the data from
     */
    BinarySearchTree(const BinarySearchTree& right);
    
    /*
     Assignment Operator
     @param right: the BinarySearchTree object on the right of the operator =
     */
    BinarySearchTree& operator=(const BinarySearchTree& right);
    
    /*
     checking function that print the BinarySearchTree object by the order: left, root, right
     */
    void print(TreeNode* node);
private:
    /*
     helper function that clean up the dynamically allocated memory
     @param node_ptr: root node of the tree we need to kill
     */
    void kill_tree(TreeNode* node_ptr);
    
    /*
     helper function that helps to copy another BinarySearchTree object
     @param node_ptr: the root pointer of another BinarySearchTree object to copy from
     */
    TreeNode* copy(TreeNode* node_ptr);
    TreeNode* root;
};


#endif /* TreeNode_h */
