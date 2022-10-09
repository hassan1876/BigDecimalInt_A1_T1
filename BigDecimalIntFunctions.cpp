#include "BigDecimalIntHeader.h"

// Defining functions, class methods

// 'a'
// Hassan
BigDecimalInt::BigDecimalInt(string decStr) {

    regex filter("^[+-]?[0-9]+");
    if (regex_match(decStr, filter)) {

        int i = 0;
        if (decStr[0] == '+' || decStr[0] == '-') {

            decimalStr += decStr[0];
            i = 1;

        }

        for (; i < decStr.length(); ++i) {

            if (decStr[i] != '0'){
                break;
            }

        }

        for (; i < decStr.length(); ++i) {

            decimalStr+= decStr[i];

        }


    } else {
        cout << "Invalid Input";
    }


}

// 'b'
// Hassan
BigDecimalInt::BigDecimalInt(int decInt) {

    decimalInt = decInt;
    decimalStr = to_string(decInt);

}

// 'c'
// Hassan
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    int sign1 = this->sign();
    int sign2 = anotherDec.sign();
    int rmndr = 0, num1, num2, result;
    string numCh;
    string StrNum1 = this->decimalStr;
    string sol = "", resultstr;
    int size;
    if (anotherDec.decimalStr[0] == '+' or anotherDec.decimalStr[0] == '-') {
        anotherDec.decimalStr[0] = '0';
    }

    if (StrNum1[0] == '+' or StrNum1[0] == '-') {
        StrNum1[0] = '0';
    }
    if (sign1 > 0 && sign2 > 0) {
        if (StrNum1.size() > anotherDec.size()) {
            size = StrNum1.size();
            for (int i = 0; i < StrNum1.size() - anotherDec.size(); i++) {
                anotherDec = "0" + anotherDec.decimalStr;
            }
        } else if (StrNum1.size() < anotherDec.size()) {
            size = anotherDec.size();
            for (int i = 0; i < anotherDec.size() - StrNum1.size(); i++) {
                StrNum1 = "0" + StrNum1;
            }
        }

        for (int i = size; i > -1; i--) {

            numCh = StrNum1[i];
            num1 = stoi(numCh);
            numCh = anotherDec.decimalStr[i];
            num2 = stoi(numCh);
            num1 += rmndr;
            rmndr--;

            if (num1 + num2 > 10 && i != 0) {
                rmndr++;
                result = num1 + num2 - 10;
            } else {
                result = num1 + num2;
            }
            resultstr = to_string(result);
            sol = resultstr + sol;
        }
    }
    anotherDec.decimalStr = sol;
    return anotherDec;
}

// 'd'
// Hassan
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    int sign1 = this->sign();
    int sign2 = anotherDec.sign();
    int rmndr = 0, num1, num2, result;
    string numCh;
    string StrNum1 = this->decimalStr;
    string sol = "", resultstr;
    int size;
    if (anotherDec.decimalStr[0] == '+' or anotherDec.decimalStr[0] == '-') {
        anotherDec.decimalStr[0] = '0';
    }

    if (StrNum1[0] == '+' or StrNum1[0] == '-') {
        StrNum1[0] = '0';
    }
    if (sign1 > 0 && sign2 > 0) {
        if (StrNum1.size() > anotherDec.size()) {
            size = StrNum1.size();
            for (int i = 0; i < StrNum1.size() - anotherDec.size(); i++) {
                anotherDec = "0" + anotherDec.decimalStr;
            }
        } else if (StrNum1.size() < anotherDec.size()) {
            size = anotherDec.size();
            for (int i = 0; i < anotherDec.size() - StrNum1.size(); i++) {
                StrNum1 = "0" + StrNum1;
            }
        }

        for (int i = size; i > -1; i--) {

            numCh = StrNum1[i];
            num1 = stoi(numCh);
            numCh = anotherDec.decimalStr[i];
            num2 = stoi(numCh);
            num1 += rmndr;
            rmndr++;

            if (num1 < num2) {
                rmndr--;
                result = (num1 + 10) - num2;
            } else {
                result = num1 - num2;
            }
            resultstr = to_string(result);
            sol = resultstr + sol;
        }
    }
    anotherDec.decimalStr = sol;
    return anotherDec;

}

// 'e'
// Seif
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return true;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        return false;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    }

    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    }


    if (anotherDec.sign() != -1) {
        if (str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()) {
            return true;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
            return false;
        }
    } else if (anotherDec.sign() == -1) {
        if (str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()) {
            return false;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
            return false;
        }
    }
}

// 'f'
// Seif
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {

    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return false;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        return true;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    } else {
        str1 = this->decimalStr;
    }


    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    } else {
        str2 = anotherDec.decimalStr;
    }


    if (anotherDec.sign() != -1) {
        if (str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()) {
            return false;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
            return false;
        }
    } else if (anotherDec.sign() == -1) {
        if (str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()) {
            return true;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
            return false;
        }
    }
}

// 'g'
// Seif
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {

    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return false;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        cout << "Str1 = " << str1 << endl;
        cout << "Str2 = " << str2 << endl;
        return false;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    } else {
        str1 = this->decimalStr;
    }


    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    } else {
        str2 = anotherDec.decimalStr;
    }



    if(str1.length() != str1.length()) {
        return false;
    } else {
        for(int i = 0; i < str1.length(); i++) {
            if(str1[i] != str2[i]) {
                return false;
            } else {
                continue;
            }
        }
        return true;
    }
}

// 'h'
// Youssef
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {

    decimalStr = anotherDec.decimalStr;
    decimalInt = anotherDec.decimalInt;
    decimalSign = anotherDec.decimalSign;

    return *this;
}

// 'i'
// Youssef
int BigDecimalInt::size() {

    return this->decimalStr.length();

}

// 'j'
// Youssef
int BigDecimalInt::sign() {

    if (decimalStr[0] == '+') {

        decimalSign = 1;

    } else if (isdigit(decimalStr[0])) {

        decimalSign = 0;

    } else {

        decimalSign = -1;

    }

    return decimalSign;
}

// 'k'
// Youssef
ostream &operator<<(ostream &out, BigDecimalInt b) {

    if (b.sign() == 1) {

        for (int i = 1; i < b.size(); ++i) {

            out << b.decimalStr[i];

        }

    } else {

        out << b.decimalStr;

    }

    return out;
}

// Youssef
string BigDecimalInt::getDecimalStr() {

    return decimalStr;

}

void BigDecimalInt::setDecimalStr(string decStr) {

    decimalStr = decStr;

}

BigDecimalInt::BigDecimalInt() {}