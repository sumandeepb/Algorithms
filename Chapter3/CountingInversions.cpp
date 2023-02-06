/*
    Copyright (C) 2020 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

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
 * File:   CountingInversions.cpp
 * Author: sumandeepb
 *
 * Created on 12 April, 2020, 6:41 PM
 */

#include <fstream>
#include <iostream>
#include <vector>

#define _DEBUG 0

using namespace std;

unsigned int MergeAndCountSplitInv(vector<int> &data, int low, int high) {
    vector<int>::const_iterator first = data.begin() + low;
    vector<int>::const_iterator last = data.begin() + high + 1;
    vector<int> buffer(first, last);
    int mid = (buffer.size() - 1) / 2;

#if _DEBUG
    cout << "M> low " << low << ", mid " << mid << ", high " << high << endl;
    for (int i = 0; i < buffer.size(); i++) {
        cout << buffer[i] << ", ";
    }
    cout << endl;
#endif

    int i = 0;       // goes from 0 to mid
    int j = mid + 1; // goes from mid + 1 to buffer.size() - 1
    unsigned int splitInv = 0;
    for (int k = low; k <= high; k++) {
#if _DEBUG
        cout << "k = " << k << ", ";
#endif
        if ((j > (buffer.size() - 1) || buffer[i] < buffer[j]) && i <= mid) {
            data[k] = buffer[i];
#if _DEBUG
            cout << "pick from i " << i << ":" << buffer[i];
#endif
            i++;
        } else if ((i > mid || buffer[i] >= buffer[j]) && j <= (buffer.size() - 1)) {
            data[k] = buffer[j];
#if _DEBUG
            cout << "pick from j " << j << ":" << buffer[j];
#endif
            j++;
            splitInv += (unsigned int)(mid - i + 1);
        }
#if _DEBUG
        cout << endl;
#endif
    }

    return splitInv;
}

unsigned int SortAndCountInv(vector<int> &data, int low, int high) {
    int n = high - low + 1;
    int mid = (low + high) / 2;
#if _DEBUG
    cout << "S> low " << low << ", mid " << mid << ", high " << high << endl;
#endif

    if (n <= 1) {
        return 0;
    }

    unsigned int leftInv = SortAndCountInv(data, low, mid);
    unsigned int rightInv = SortAndCountInv(data, mid + 1, high);
    unsigned int splitInv = MergeAndCountSplitInv(data, low, high);

    return leftInv + rightInv + splitInv;
}

void loadData(const string strFileName, vector<int> &data) {
    ifstream file(strFileName);

    if (!file.is_open()) {
        throw std::runtime_error("couldn't open file");
    }

    while (!file.eof()) {
        int input;
        file >> input;
        data.push_back(input);
    }
    cout << "Loaded: " << data.size() << endl;
    file.close();
}

int main(int argc, char *argv[]) {
#if _DEBUG
    // vector<int> a{1, 3, 5, 2, 4, 6};
    // vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> a{8, 7, 6, 5, 4, 3, 2, 1};
#else
    if (argc < 2) {
        throw std::invalid_argument("missing input filename");
    }
    vector<int> a;
    loadData(argv[1], a);
#endif

    unsigned int nInversions = SortAndCountInv(a, 0, a.size() - 1);
    cout << "Number of inversions: " << nInversions << endl;
#if _DEBUG
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ", ";
    }
    cout << endl;
#endif

    return 0;
}
