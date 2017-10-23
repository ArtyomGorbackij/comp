#include <iostream>
using namespace std;
struct complex_t {
    float real;
    float imag;
};
istream & read( std::istream & stream, complex_t & complex ){
    char i=' ';
    int a;


    while((stream>>i)&&(i!=')')){
        if(!(stream>>a)){
            cout<<endl <<"An error has occured while reading input data";
        }
        if (i==','){complex.imag=a;}
        else if(i=='('){complex.real=a;}
        else{ cout<<endl <<"An error has occured while reading input data";
        }
    }
return stream;
}
std::ostream & write( std::ostream & stream, complex_t complex ){
    stream<<"("<<complex.real<<","<<complex.imag<<")";
    return stream;
}

complex_t add( complex_t x, complex_t y ){
    complex_t c;
 c.real=x.real+y.real;
    c.imag=x.imag+y.imag;
    return c;
}
complex_t sub( complex_t x, complex_t y ){
    complex_t c;
    c.real=x.real-y.real;
    c.imag=x.imag-y.imag;
    return c;
}
complex_t mul( complex_t x, complex_t y ){
    complex_t c;
    c.real=x.real*y.real-x.imag*y.imag;
    c.imag=x.imag*y.real+x.real*y.imag;
    return c;
}
complex_t dev( complex_t x, complex_t y ){
    complex_t c;
    c.real=(x.real*y.real+x.imag*y.imag)/(y.real*y.real+y.imag*y.imag);
    c.imag=(x.imag*y.real-x.real*y.imag)/(y.real*y.real+y.imag*y.imag);
    return c;
}
int main() {
    complex_t a, b;
    char op;
    if (read(cin, a)) {
        cin >> op;
        if (read(cin, b)) {
            switch (op) {
                case '+':
                    write(cout, add(a, b));
                    break;
                case '-':
                    write(cout, sub(a, b));
                    break;
                case '*':
                    write(cout, mul(a, b));
                    break;
                case '/':
                    write(cout, dev(a, b));
                    break;
            }
        }
    }
    cin.get();
    cin.get();
    return 0;
}
