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

#include "MinHeap.hpp"

int main(int argv, char *argc[]) {
	/*unsigned int count = (unsigned int) atoi(argc[1]);
	vector<int> lastNodeSeq;

	findLastNodeSequence(count, lastNodeSeq);
	while(!lastNodeSeq.empty()) {
		int nodeIdx = lastNodeSeq.back();
		lastNodeSeq.pop_back();
		cout << nodeIdx << endl;
	}*/

	MinHeap<int> minHeap;

	int values[] = {55, 50, 90, 4, 87, 7, 2, 80};
	for (int i = 0; i < 8; i++) {
		minHeap.insert(values[i]);
	}

	minHeap.preOrderTraverse();

	return 0;
}