#include "BigDecimalIntFunctions.cpp"

int main() {

    BigDecimalInt bI1("999");
    BigDecimalInt bI2(-88);
    BigDecimalInt bI3("-254");
    BigDecimalInt bI4("+254");
    BigDecimalInt bI5("254");

    BigDecimalInt bI6;
    bI6.setDecimalStr("538");

//    bI2 = bI1;

    cout << bI1 << endl;
    cout << bI2 << endl;
    cout << bI3 << endl;
    cout << bI4 << endl;
    cout << bI5 << endl;
    cout << bI6 << endl;
    cout << bI2.sign() << endl;

    if (bI5 > bI4) {
        cout << "Yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
