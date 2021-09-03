#include<iostream>
using namespace std;

class Fraction{
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator){           //Parameterized Constructor
        this->numerator= numerator;
        this->denominator= denominator;
    }

    void simplify(){
        int gcd,n=min(numerator,denominator);
        for(int i=n; i>=1; i--){
            if(numerator%i==0 && denominator%i ==0){
                gcd= i;
                break;
            }
        }
        numerator/= gcd;
        denominator/=gcd;
    }

    Fraction operator+(Fraction const &f2)  const{             // Operator Overloading for: +
        int lcm= this->denominator*f2.denominator;

        int numerator= (this->numerator*(lcm/this->denominator)) + (f2.numerator*(lcm/f2.denominator));
        int denominator= lcm;
        Fraction fnew(numerator,denominator);
        fnew.simplify();
        return fnew;
    }

    Fraction operator*(Fraction const &f2)   const{         //Operator Overloading for: *
        int n= numerator*f2.numerator;
        int d= denominator*f2.denominator;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }

    Fraction& operator++(){                 // Pre-increment operator overloading
        numerator+=denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int){                           //Post Increment Operator, Note: Post Increment Operator can't be nested therefore we don't have reference return type
        Fraction fnew(numerator,denominator);
        numerator+= denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction& operator+=(Fraction const &f2){
        int lcm= denominator*f2.denominator;
        numerator= (numerator*(lcm/denominator)) + (f2.numerator*(lcm/f2.denominator));
        denominator= lcm;
        simplify();
        return *this;
    }

    void print(){
        cout<<numerator<<'/'<<denominator<<endl;
    }

};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,2);
    Fraction f3= f1 + f2;
    Fraction f4= f1*f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    cout<<endl;
    Fraction f5= ++f1;
    Fraction f6= ++(++f2);
    f5.print();
    f6.print();

    ++f1;
    cout<<endl;
    f1.print();
    f2.print();

    f1++;
    cout<<endl;
    f1.print();

    f1+=f2;
    cout<<endl;
    f1.print();
}
