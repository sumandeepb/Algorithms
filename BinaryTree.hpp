/*
    Copyright (C) 2018 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Tree.hpp: Generic Binary Tree Class
 */

#include <cstdlib>
#include <iostream>

#include "Tree.hpp"

template <class T>
class BinaryTree {
protected:
    TreeNode<T, 2>* root;

public:

    BinaryTree() {
        root = NULL;
    }

    bool isEmpty() {
        return (NULL == root);
    }
    
    void preOrderTraverse() {
        std::cout << "Pre-Order: ";
        preOrderPrint(root);
        std::cout << std::endl;
    }

    void preOrderPrint(TreeNode<T, 2>* node) {
        if (NULL != node) {
            std::cout << node->data << " {";
            preOrderPrint(node->child[0]);
            preOrderPrint(node->child[1]);
            std::cout << "} ";
        }
    }
};
