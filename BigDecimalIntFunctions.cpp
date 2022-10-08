#include "BigDecimalIntHeader.h"

// Defining functions, class methods

// 'a'
BigDecimalInt::BigDecimalInt(string decStr) {

    decimalStr = decStr;

}

// 'b'
BigDecimalInt::BigDecimalInt(int decInt) {

    decimalInt = decInt;
//    decimalStr = to_string(decInt);

}

// 'c'
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
//    return ;
}

// 'd'
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
//    return ;
}

// 'e'
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    string str1 = "";
    string str2 = "";

    if(this->sign() == -1 && anotherDec.sign() != -1) {
        return true;
    }

    if(this->sign() != -1 && anotherDec.sign() == -1) {
        return false;
    }

    if(this->sign() == 1 || this->sign() == -1) {
        for(int i = 1; i < this->decimalStr.length(); i++) {
            str1 +=  this->decimalStr[i];
        }
    }

    if(anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for(int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 +=  anotherDec.decimalStr[i];
        }
    }



    if(anotherDec.sign() != -1) {
        if(str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()){
            return true;
        } else {
            string num1;
            string num2;
            for(int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if(stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
        }
    } else if(anotherDec.sign() == -1) {
        if(str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()){
            return false;
        } else {
            string num1;
            string num2;
            for(int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if(stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
        }
    }
}

// 'f'
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {

    string str1 = "";
    string str2 = "";

    if(this->sign() == -1 && anotherDec.sign() != -1) {
        return false;
    }

    if(this->sign() != -1 && anotherDec.sign() == -1) {
        return true;
    }

    if(this->sign() == 1 || this->sign() == -1) {
        for(int i = 1; i < this->decimalStr.length(); i++) {
            str1 +=  this->decimalStr[i];
        }
    } else {
        str1 = this->decimalStr;
    }
    

    if(anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for(int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 +=  anotherDec.decimalStr[i];
        }
    } else {
        str2 = anotherDec.decimalStr;
    }


    if(anotherDec.sign() != -1) {
        if(str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()){
            return false;
        } else {
            string num1;
            string num2;
            for(int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if(stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
        }
    } else if(anotherDec.sign() == -1) {
        if(str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()){
            return true;
        } else {
            string num1;
            string num2;
            for(int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if(stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
        }
    }
}

// 'g'
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    return false;
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

    } else{

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
string BigDecimalInt::getDecimalStr(){

    return decimalStr;

}
