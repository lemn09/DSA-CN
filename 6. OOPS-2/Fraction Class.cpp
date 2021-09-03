#include<iostream>
using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator){    //Parameterized Constructor
            this->numerator= numerator;
            this->denominator= denominator;
        }

        void display(){
            cout<<numerator<<'/'<<denominator<<endl;
        }

        void simplify(){
            int n= min(numerator,denominator);
            int gcd;
            for(int i=n; i>=1; i--){
                if(numerator%i == 0 && denominator %i == 0){
                    gcd=i;
                    break;
                }
            }
            numerator/=gcd;
            denominator/=gcd;
        }

        void add(const Fraction &f2){
            int lcm= f2.denominator * this->denominator;
            this->numerator= this->numerator*(lcm/this->denominator) + f2.numerator*(lcm/f2.denominator);
            this->denominator= lcm;
            simplify();
        }

        void multiply(const Fraction &f2){
            this->numerator*=f2.numerator;
            this->denominator*=f2.denominator;
            simplify();
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    f1.add(f2);
    cout<<"Addition: ";
    f1.display();
    cout<<"\tFraction-2: ";
    f2.display();
    f1.multiply(f2);
    cout<<"Multiplication: ";
    f1.display();
    return 0;
}
