/**********

Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.


int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }

}

 ************/


class ComplexNumbers {
    // Complete this class
    private:
    	int real;
    	int img;
    public:
    	ComplexNumbers(int real, int img){
            this->real= real;
            this->img= img;
        }

    	void plus(const ComplexNumbers c2){
            this->real+=c2.real;
            this->img+=c2.img;
        }

    	void multiply(ComplexNumbers const c2){
            ComplexNumbers temp(0,0);
            temp.real= (this->real*c2.real) - (this->img*c2.img);
            temp.img= (this->real*c2.img) + (this->img*c2.real);
            this->real= temp.real;
            this->img= temp.img;
        }

    	void print(){
            cout<<real<<" + i"<<img;
        }

};
