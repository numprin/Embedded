#include <iostream>
using myInt = int32_t;
const myInt maxValue = INT32_MAX;
const myInt minValue = INT32_MIN;
using myLong = int64_t;

using namespace std;

class Int {
    myInt val;
    myLong rVal;
    bool ov;
    bool cz;
    myInt rem;
public:
    Int(myInt x=0) : ov{false} , val{x}  {}
    Int(myLong value) : ov{false} 
    {
        if ((value >= minValue) && (value <=maxValue))
            val = value;
        else {
            val = 0;
            cout << "!!! Initial value is out of range, set to zero\n"; 
        }
                
    }  
    myInt value() {return val;}
    myLong realVal(){return rVal;}
    bool overflow() {return ov;}
    bool checkzero(){return cz;}
    Int operator + (Int const & B) {
        Int res;
        res.val = val + B.val;
        res.rVal = (myLong)val + (myLong)B.val;
        res.ov = ((val>0)&&(B.val>0)&&(res.val<0)) || 
             ((val<0)&&(B.val<0)&&(res.val>0));
        return res;
    }
    Int operator - (Int const & B) {
        Int res;
        res.val = val - B.val;
        res.rVal = (myLong)val - (myLong)B.val;
        res.ov = ((val>0)&&(B.val<0)&&(res.val<0)) || 
             ((val<0)&&(B.val>0)&&(res.val>0));
        return res;
    }
    Int operator * (Int const & B){
        Int res;
        res.val = val * B.val;
        res.rVal = (myLong)val * (myLong)B.val;
        if(val ==0 || B.val ==0){
            res.ov = false;
        }
        else{
            if (val == res.val / B.val ){
            res.ov = false;}
            else{
                res.ov = true;
            }
        }
        return res;
    }
    Int operator / (Int const & B){
        Int res;
        if(B.val == 0){
            res.cz = true;
        }
        else{
            res.val = val / B.val;
            res.rem = val % B.val;
            res.rVal = (myLong)val / (myLong)B.val;
            if(val == res.val * B.val + res.rem){
                res.ov = false;}
            else{
                res.ov = true;}
        }
        return res;
    }
};
int main()
{
    //Int A(init);
    Int A(-0x7FFFFFFF);
    Int B(1);
    Int C = A + B;
    Int D = A - B;
    Int G = A * B;
    Int K = A / B;
    cout<<"Hello World!" << endl;
    cout<<"A = " <<A.value() << endl;
    cout<<"B = " <<B.value() << endl;
    if(C.overflow()){
        cout << "A + B = " << C.value() << endl;
        cout << "This is overflow"<<endl;
        cout << "Real value is : " << C.realVal() << endl;
    }
    else{
        cout << "A + B = " << C.value() << endl;
        cout << "This is not overflow"<<endl;
    }
    if(D.overflow()){
        cout << "A - B = " << D.value() << endl;
        cout << "This is overflow"<<endl;
        cout << "Real value is : " << D.realVal() << endl;
    }
    else{
        cout << "A - B = " << D.value() << endl;
        cout << "This is not overflow"<<endl;
    }
    if(G.overflow()){
        cout << "A * B = " << D.value() << endl;
        cout << "This is overflow"<<endl;
        cout << "Real value is : " << G.realVal() << endl;
        
    }
    else{
       
        cout << "A * B = " << G.value() << endl;
        cout << "This is not overflow"<<endl;
    }
    if(K.checkzero()){
        cout << "A / B = infinity" << endl;
    }
    else{
        if(K.overflow()){
            cout << "A / B = " << K.value() << endl;
            cout << "This is overflow"<<endl;
            cout << "Real value is : " << K.realVal() << endl;
        }
        else{
            cout << "A / B = " << K.value() << endl;
            cout << "This is not overflow"<<endl;
        }
    }
    
      return 0;
}