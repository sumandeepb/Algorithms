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
 * File:   KaratsubaMult.cpp
 * Author: sumandeep
 *
 * Created on 12 April, 2020, 23:39 PM
 */

#include <iostream>
#include <string>

using namespace std;

void AddLargeNumbers(const string &x, const string &y) {
}

void KaratsubaMult(const string &x, const string &y, string &xy) {
    int n = max(x.length(), y.length());

    if (1 == n) {
        xy = string(to_string(stoi(x) * stoi(y)));
    } else {
        // a & b are first and second halves of x respectively
        string a = x.substr(0, n / 2);
        string b = x.substr(n / 2);
        // c & d are first and second halves of y respectively
        string c = y.substr(0, n / 2);
        string d = y.substr(n / 2);
    }
}

int main(int argc, char *argv[]) {
    string x("3141592653589793238462643383279502884197169399375105820974944592");
    string y("2718281828459045235360287471352662497757247093699959574966967627");
    string xy;

    KaratsubaMult(x, y, xy);

    cout << " x: " << x << endl;
    cout << " y: " << y << endl;
    cout << "xy: " << xy << endl;

    return 0;
}
