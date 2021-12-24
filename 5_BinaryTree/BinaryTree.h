#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BinaryTree
{
private:

    struct node
    {
        string data;
        node* left;
        node* right;
        node(string val)
        {
            left = nullptr;
            right = nullptr;
            data = val;
        }
    };

    node* root;
    int tree_size;
    void print_tree(node* t)
    {
        if (t)
        {
            print_tree(t->left);
            cout << t->data << " ";
            print_tree(t->right);
        }
    }
    void delete_tree(node* t)
    {
        if (t)
        {
            delete_tree(t->left);
            delete_tree(t->right);
            delete t;
        }
    };

public:
    int treeCompare = 0;
    BinaryTree()
    {
        root = nullptr;
        tree_size = 0;
    }

    BinaryTree(string x)
    {
        root = new node(x);
        tree_size = 1;
    }
    ~BinaryTree()
    {
        delete_tree(root);
    }
    void print() {
        print_tree(root);
        cout << endl;
    }
    bool find(string x)
    {
        node* t = root;
        while (t && t->data != x)
        {
            if (t->data > x)
                t = t->left;
            else
                t = t->right;
        }
        return t != nullptr;
    }
    void insert(string x)
    {
        if(!root)
        {
            root = new node(x);
            ++treeCompare;
            ++tree_size;
            return;
        }
        node* t = root;
        while (t && t->data != x)
        {
            treeCompare+=2;
            if (t->data > x && t->left == nullptr)
            {
                t->left = new node(x);
                treeCompare+=2;
                ++tree_size;
                return;
            }
            if (t->data < x && t->right == nullptr)
            {
                t->right = new node(x);
                ++tree_size;
                treeCompare+=2;
                return;
            }
            if (t->data > x) {
                t = t->left;
                treeCompare++;
            }

            else {
                t = t->right;
                treeCompare++;
            }

        }
    }
    void remove(string x)
    {
        node* t = root;
        node* parent = nullptr;
        while (t && t->data != x)
        {
            parent = t;
            if (t->data > x)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        if (!t)
            return;
        if (t->left == nullptr)
        {
            if (parent && parent->left == t)
                parent->left = t->right;
            if (parent && parent->right == t)
                parent->right = t->right;
            --tree_size;
            delete t;
            return;
        }
        if (t->right == nullptr)
        {
            if (parent && parent->left == t)
                parent->left = t->left;
            if (parent && parent->right == t)
                parent->right = t->left;
            --tree_size;
            delete t;
            return;
        }
        node* replace = t->right;
        while (replace->left)
            replace = replace->left;
        string replace_value = replace->data;
        remove(replace_value);
        t->data = replace_value;
    }
    int size() {
        return tree_size;
    }
};