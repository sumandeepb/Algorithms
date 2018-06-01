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
 * Tree.hpp: Generic MinHeap Class
 */

#include <cstdlib>
#include <vector>
#include <algorithm>

#include "BinaryTree.hpp"

void findLastNodeSequence(unsigned int c, std::vector<int>& v) {
    v.clear();

    if (0 == c || 1 == c) return;

    while (c != 1) {
        int nodeIdx = c - ((c >> 1) << 1);
        v.push_back(nodeIdx);
        c = c >> 1;
    }
}

template <class T>
class MinHeap : public BinaryTree<T> {
protected:
    unsigned int nodeCount = 0;

    void heapify_up(TreeNode<T, 2>* node) { //used for insert
        while (NULL != node->parent && node->data < node->parent->data) {
            std::swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    void heapify_down() { // used for extract

    }

public:

    void insert(T& data) {
        if (NULL == BinaryTree<T>::root) {
            BinaryTree<T>::root = new TreeNode<T, 2>;
            BinaryTree<T>::root->data = data;
            nodeCount = 1;
        } else {
            std::vector<int> lastNodeSeq;
            findLastNodeSequence(nodeCount + 1, lastNodeSeq); // nodeCount + 1 gives location of insert node

            TreeNode<T, 2>* node = BinaryTree<T>::root;
            while (lastNodeSeq.size() > 1) { // reach to the parent of insert node
                int nodeIdx = lastNodeSeq.back();
                node = node->child[nodeIdx];
                lastNodeSeq.pop_back();
            }

            TreeNode<T, 2>* nodeNew = new TreeNode<T, 2>;

            // check if left or right available
            if (NULL == node->child[0]) {
                node->child[0] = nodeNew;
            } else if (NULL == node->child[1]) {
                node->child[1] = nodeNew;
            }

            // set parent link
            nodeNew->parent = node;
            // set data
            nodeNew->data = data;

            // maintain heap order
            heapify_up(nodeNew);

            // update count
            nodeCount++;
        }
    }

    /*T extract() {

    }*/
};
