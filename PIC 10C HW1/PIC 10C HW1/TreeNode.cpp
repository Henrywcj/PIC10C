//
//  TreeNode.cpp
//  PIC 10C HW1
//
//  Created by Henry Wang on 1/21/18.
//  Copyright © 2018 Henry Wang. All rights reserved.
//

#include "TreeNode.h"
#include <iostream>


TreeNode::TreeNode():data(""), left(nullptr), right(nullptr){}

TreeNode::TreeNode(const std::string& input_data):data(input_data), left(nullptr), right(nullptr){}

void TreeNode::insert_node(TreeNode*& new_node)
{
    if (new_node->data < data){ // if the inserted data is smaller than the root data
        if (left == nullptr) { // if the left child is empty
            left = new_node;
        }
        else { // if not empty, recursively apply insert_node function the put the data in the left subtree
            left->insert_node(new_node);
        }
    }
    else // if the inserted data is bigger or equal to the root data
    {
        if (right == nullptr) { // if the right child is empty
            right = new_node;
        }
        else { // if not empty, recursively apply insert_node function the put the data in the right subtree
            right->insert_node(new_node);
        }
    }
}


TreeNode::~TreeNode()
{
    left = nullptr;
    right = nullptr;
    data = "";
}



BinarySearchTree::BinarySearchTree():root(nullptr){}

void BinarySearchTree::insert(const std::string& data)
{
    TreeNode* node = new TreeNode(data);
    if (root == nullptr) { //if the root is empty then just put the data on root
        root = node;
    }
    else { // if the root is not empty, call TreeNode's member function to put the data into a correct position
        root->insert_node(node);
    }
}

TreeNode* BinarySearchTree::get_root() const
{
    return root;
}

BinarySearchTree::~BinarySearchTree()
{
    kill_tree(root);
}

void BinarySearchTree::print(TreeNode* node)
{
    // first print the root data
    std::cout << node->data << std::endl;
    if (node->left != nullptr) // if left child tree is not empty, print the left child tree
    {
        print(node->left);
    }
    if (node->right != nullptr) // if right child tree is not empyt, ptin the right child tree
    {
        print(node->right);
    }
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& obj)
{
    root = copy(obj.root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &obj)
{
    if (&obj != this)
    {
        kill_tree(root); // first clean up
        root = copy(obj.root); // then copy
    }
    return *this;
}

TreeNode* BinarySearchTree::copy(TreeNode* node_ptr)
{
    TreeNode* rt = new TreeNode();
    rt->data = node_ptr->data;
    if (node_ptr->left != nullptr){ // if the left tree is not empty, copy the left tree
        rt->left = copy(node_ptr->left);
    }
    if (node_ptr->right != nullptr){ // if the right tree is not empty, copy the right tree
        rt->right = copy(node_ptr->right);
    }
    return rt;
}

void BinarySearchTree::kill_tree(TreeNode* node_ptr)
{
    if (node_ptr == nullptr) return; // if it's already cleaned up, just return
    if (node_ptr->left != nullptr){ // if the left tree is not empty, kill the left tree
        kill_tree(node_ptr->left);
        node_ptr->left = nullptr;
    }
    if (node_ptr->right != nullptr){ // if the right tree is not empty, kill the right tree
        kill_tree(node_ptr->right);
        node_ptr->right = nullptr;
    }
    delete node_ptr;
}
