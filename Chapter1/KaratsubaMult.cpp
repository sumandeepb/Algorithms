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

#include <cstdlib>
#include <iostream>
#include <string>

#define _DEBUG 0

using namespace std;

string AddLargeNumbers(const string &strFirstNumber, const string &strSecondNumber) {
    int nFirstNumber = strFirstNumber.length();
    int nSecondNumber = strSecondNumber.length();
    int length = max(nFirstNumber, nSecondNumber);

    string x;
    string y;
    if (nFirstNumber > nSecondNumber) {
        x = strFirstNumber;
        // pad second number with preceeding zeros
        y = string(nFirstNumber - nSecondNumber, '0').append(strSecondNumber);
    } else {
        // pad first number with preceeding zeros
        x = string(nSecondNumber - nFirstNumber, '0').append(strFirstNumber);
        y = strSecondNumber;
    }

    int carry = 0;
    int sum = 0;
    string strResult;
    for (int k = length - 1; k >= 0; k--) {
        int xk = x[k] - '0'; // convert digit to number
        int yk = y[k] - '0';
        sum = carry + xk + yk;
        (sum > 9) ? carry = 1 : carry = 0;
        sum %= 10;
        strResult.insert(0, 1, to_string(sum)[0]);
#if _DEBUG
        cout << xk << "+" << yk << "=" << carry << " " << sum << " | " << strResult << endl;
#endif
    }

    if (carry) {
        strResult.insert(0, 1, to_string(carry)[0]);
    }

    // remove leading zeroes
    return strResult.erase(0, min(strResult.find_first_not_of('0'), strResult.size() - 1));
}

string SubtractLargeNumbers(const string &strFirstNumber, const string &strSecondNumber) {
    int nFirstNumber = strFirstNumber.length();
    int nSecondNumber = strSecondNumber.length();
    int length = max(nFirstNumber, nSecondNumber);

    string x;
    string y;
    if (nFirstNumber > nSecondNumber) {
        x = strFirstNumber;
        // pad second number with preceeding zeros
        y = string(nFirstNumber - nSecondNumber, '0').append(strSecondNumber);
    } else {
        // pad first number with preceeding zeros
        x = string(nSecondNumber - nFirstNumber, '0').append(strFirstNumber);
        y = strSecondNumber;
    }

    int diff = 0;
    string strResult;
    for (int k = length - 1; k >= 0; k--) {
        int xk = x[k] - '0'; // convert digit to number
        int yk = y[k] - '0';
        diff = xk - yk;
        if (diff >= 0) {
            strResult.insert(0, 1, to_string(diff)[0]);
        } else {
            // borrow
            int i = k - 1;
            while (i >= 0) {
                x[i] = ((x[i] - '0') - 1) % 10 + '0';
                if (x[i] != '9') {
                    break;
                } else {
                    i--;
                }
            }
            strResult.insert(0, 1, to_string(diff + 10)[0]);
        }
#if _DEBUG
        cout << xk << "-" << yk << "=" << diff << " | " << strResult << endl;
#endif
    }

    // remove leading zeroes
    return strResult.erase(0, min(strResult.find_first_not_of('0'), strResult.size() - 1));
}

// Karatsuba Multiplication Algorithm
string MultiplyLargeNumbers(const string &strFirstNumber, const string &strSecondNumber) {
    int nFirstNumber = strFirstNumber.length();
    int nSecondNumber = strSecondNumber.length();
    int length = max(nFirstNumber, nSecondNumber);

    string x;
    string y;
    if (nFirstNumber > nSecondNumber) {
        x = strFirstNumber;
        // pad second number with preceeding zeros
        y = string(nFirstNumber - nSecondNumber, '0').append(strSecondNumber);
    } else {
        // pad first number with preceeding zeros
        x = string(nSecondNumber - nFirstNumber, '0').append(strFirstNumber);
        y = strSecondNumber;
    }

    string strResult;
    if (1 == length) { // base case
        strResult = string(to_string(stoi(strFirstNumber) * stoi(strSecondNumber)));
#if _DEBUG
        if (nFirstNumber != nSecondNumber) {
            cout << nFirstNumber << "<>" << nSecondNumber << endl;
            cout << x << "*" << y << "=" << strResult << endl;
        }
#endif
        return strResult;
    } else {
        // a & b are first and second halves of x respectively
        string a = x.substr(0, length / 2);
        string b = x.substr(length / 2);
        // c & d are first and second halves of y respectively
        string c = y.substr(0, length / 2);
        string d = y.substr(length / 2);

        string p = AddLargeNumbers(a, b);
        string q = AddLargeNumbers(c, d);

        string ac = MultiplyLargeNumbers(a, c);
        string bd = MultiplyLargeNumbers(b, d);
        string pq = MultiplyLargeNumbers(p, q);
        string adbc = SubtractLargeNumbers(pq, AddLargeNumbers(ac, bd));

        // round up length to nearest multiple of 2
        strResult = AddLargeNumbers(ac.append(2 * ((length + 1) / 2), '0'), AddLargeNumbers(adbc.append((length + 1) / 2, '0'), bd));
#if _DEBUG
        if (nFirstNumber != nSecondNumber) {
            cout << nFirstNumber << "<>" << nSecondNumber << endl;
            cout << x << "*" << y << "=" << strResult << endl;
        }
#endif
        return strResult;
    }
}

int main(int argc, char *argv[]) {
#if _DEBUG
    string strX("2000");
    string strY("4000");
#else
    string strX("3141592653589793238462643383279502884197169399375105820974944592");
    string strY("2718281828459045235360287471352662497757247093699959574966967627");
#endif

    cout << " x: " << strX << endl;
    cout << " y: " << strY << endl;
#if _DEBUG
    cout << AddLargeNumbers(strX, strY) << endl;
    cout << SubtractLargeNumbers(strX, strY) << endl;
#endif

    cout << "xy: " << MultiplyLargeNumbers(strX, strY) << endl;

    return 0;
}
