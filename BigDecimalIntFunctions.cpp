#include "BigDecimalIntHeader.h"

// Defining functions, class methods

// 'a'
BigDecimalInt::BigDecimalInt(string decStr) {
    regex filter("^[+-]?[0-9]+");
    if(regex_match(decStr,filter)){
    }
    else{
        cout<<"invalid";
    }
    return;
}

// 'b'
BigDecimalInt::BigDecimalInt(int decInt) {

    decimalInt = decInt;
    decimalStr = to_string(decInt);

}

// 'c'
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    int sign1=this->sign();
    int sign2=anotherDec.sign();
    int rmndr=0,num1,num2,result;
    string numCh;
    string StrNum1=this->decimalStr;
    string sol="",resultstr;
    int size;
    if(anotherDec.decimalStr[0]=='+' or anotherDec.decimalStr[0]=='-' ){
        anotherDec.decimalStr[0]='0';
    }
    
    if(StrNum1[0]=='+' or StrNum1[0]=='-' ){
        StrNum1[0]='0';
    }
    if(sign1>0&&sign2>0){
        if(StrNum1.size()>anotherDec.size()){
            size=StrNum1.size();
            for(int i=0;i<StrNum1.size()-anotherDec.size();i++){
                anotherDec="0"+anotherDec.decimalStr;
            }
        }
        else if (StrNum1.size()<anotherDec.size()){
            size=anotherDec.size();
            for(int i=0;i<anotherDec.size()-StrNum1.size();i++){
             StrNum1="0"+StrNum1;
            }
        }

        for(int i=size;i>-1;i--){

            numCh=StrNum1[i];
            num1=stoi(numCh);
            numCh=anotherDec.decimalStr[i];
            num2=stoi(numCh);
            num1+=rmndr;
            rmndr--;

            if(num1+num2>10&&i!=0){
                rmndr++;
                result=num1+num2-10;
            }
            else{
                result=num1+num2;
            }
            resultstr=to_string(result);
            sol=resultstr+sol;
        }
    }
    anotherDec.decimalStr=sol;
    return anotherDec;
}

// 'd'
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    int sign1=this->sign();
    int sign2=anotherDec.sign();
    int rmndr=0,num1,num2,result;
    string numCh;
    string StrNum1=this->decimalStr;
    string sol="",resultstr;
    int size;
    if(anotherDec.decimalStr[0]=='+' or anotherDec.decimalStr[0]=='-' ){
        anotherDec.decimalStr[0]='0';
    }
    
    if(StrNum1[0]=='+' or StrNum1[0]=='-' ){
        StrNum1[0]='0';
    }
    if(sign1>0&&sign2>0){
        if(StrNum1.size()>anotherDec.size()){
            size=StrNum1.size();
            for(int i=0;i<StrNum1.size()-anotherDec.size();i++){
                anotherDec="0"+anotherDec.decimalStr;
            }
        }
        else if (StrNum1.size()<anotherDec.size()){
            size=anotherDec.size();
            for(int i=0;i<anotherDec.size()-StrNum1.size();i++){
             StrNum1="0"+StrNum1;
            }
        }

        for(int i=size;i>-1;i--){

            numCh=StrNum1[i];
            num1=stoi(numCh);
            numCh=anotherDec.decimalStr[i];
            num2=stoi(numCh);
            num1+=rmndr;
            rmndr++;

            if(num1<num2){
                rmndr--;
                result=(num1+10)-num2;
            }
            else{
                result=num1-num2;
            }
            resultstr=to_string(result);
            sol=resultstr+sol;
        }
    }
    anotherDec.decimalStr=sol;
    return anotherDec;

return anotherDec;
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
return anotherDec;
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
