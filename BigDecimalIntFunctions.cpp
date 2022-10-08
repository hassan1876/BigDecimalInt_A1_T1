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
    return false;
}

// 'f'
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    return false;
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
