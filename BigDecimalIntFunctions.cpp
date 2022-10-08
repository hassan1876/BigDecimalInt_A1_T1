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
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {
//    return ;
}

// 'i'
int BigDecimalInt::size() {
    return 0;
}

// 'j'
int BigDecimalInt::sign() {
    return 0;
}

// 'k'
ostream &operator<<(ostream &out, BigDecimalInt b) {

    out << b.decimalStr;

    return out;
}
