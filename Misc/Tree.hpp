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
 * Tree.hpp: Generic n-ary Tree Node Class
 */

#include <cstdlib>
#include <cstring>

template <class T, int N>
class TreeNode {
public:
    T data;
    TreeNode<T, N>* parent;
    TreeNode<T, N>* child[N];

    TreeNode() {
        this->parent = NULL;
        memset(child, 0, N * sizeof (TreeNode<T, N>*));
    }

    TreeNode<T, N>* findMinChild() {
        TreeNode<T, N>* minChild = child[0];

        if (NULL != minChild) {
            for (int i = 1; i < N; i++) {
                if (NULL != child[i] && child[i]->data < minChild->data) {
                    minChild = child[i];
                }
            }
        }

        return minChild;
    }
};
