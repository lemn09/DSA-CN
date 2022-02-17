
/*************
 Driver program to test below functions

int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}
****************/

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;


    	Polynomial(){
            degCoeff= new int[10]();
            capacity =10;
        }

    	Polynomial(int cap){
            capacity= cap;
            degCoeff= new int[cap]();
        }

    	Polynomial(Polynomial const &p){
            degCoeff= new int[p.capacity]();
            for(int i=0; i<p.capacity; i++){
                degCoeff[i]= p.degCoeff[i];
            }
            capacity= p.capacity;
        }

    	void operator=(Polynomial const &p){
            degCoeff= new int[p.capacity]();
            for(int i=0; i<p.capacity; i++){
                degCoeff[i]= p.degCoeff[i];
            }
            capacity= p.capacity;
        }

    	void setCoefficient(int deg, int value){
    		while(capacity <= deg){
                int *newArr= new int[capacity*2]();
                for(int i=0; i<capacity; i++){
                    newArr[i]= degCoeff[i];
                }
                delete []degCoeff;
                degCoeff= newArr;
                capacity*=2;
            }
            degCoeff[deg]= value;

        }

		Polynomial operator+(Polynomial const &p){
            Polynomial pNew;
            int cap= (this->capacity > p.capacity) ? this->capacity : p.capacity;
            while(pNew.capacity < cap){
                int *temp= new int[2*pNew.capacity]();
                delete []pNew.degCoeff;
                pNew.degCoeff= temp;
                pNew.capacity*=2;
            }
            int i=0,j=0,pos=0;
            while(i<this->capacity && j<p.capacity){
                pNew.degCoeff[pos++]= this->degCoeff[i++] + p.degCoeff[j++];
            }
            while(i<this->capacity){
                pNew.degCoeff[pos++]= this->degCoeff[i++];
            }
            while(j<p.capacity){
                pNew.degCoeff[pos++]= p.degCoeff[j++];
            }
            return pNew;
        }

    	Polynomial operator-(Polynomial const &p){
            Polynomial pNew;
            int cap= (this->capacity > p.capacity) ? this->capacity : p.capacity;
            while(pNew.capacity < cap){
                int *temp= new int[2*pNew.capacity]();
                delete []pNew.degCoeff;
                pNew.degCoeff= temp;
                pNew.capacity*=2;
            }
            int i=0,j=0,pos=0;
            while(i<this->capacity && j<p.capacity){
                pNew.degCoeff[pos++]= this->degCoeff[i++] - p.degCoeff[j++];
            }
            while(i<this->capacity){
                pNew.degCoeff[pos++]= this->degCoeff[i++];
            }
            while(j<p.capacity){
                pNew.degCoeff[pos++]= (-1)*p.degCoeff[j++];
            }
            return pNew;
        }

//     	Polynomial operator*(Polynomial const &p){
//             int cap= capacity + p.capacity;
// 			Polynomial pNew(cap);

// 			int i=0,j=0;
//            	while(i <=this->capacity){
//                 if(degCoeff[i] != 0){
//                     while(j <=p.capacity){
//                         if(degCoeff[j]!=0){
//                             pNew.degCoeff[i+j]+= (this->degCoeff[i])*(p.degCoeff[j]);
//                             j++;
//                         }else{
//                             j++;
//                         }
//                     }
//                     i++;
//                 }else{
//                     i++;
//                 }
//             }
//             return pNew;
//         }
    	Polynomial operator*(Polynomial const &P2){
        int newcap=this->capacity+P2.capacity;
        Polynomial P3(newcap);
        for(int i=0;i<this->capacity;i++){
            for(int j=0;j<P2.capacity;j++){
                P3.degCoeff[i+j]+=this->degCoeff[i]*P2.degCoeff[j];
            }
        }
        return P3;
    }

    	void print(){
            for(int i=0; i<capacity; i++){
                if(degCoeff[i] !=0){
                    cout<<degCoeff[i]<<'x'<<i<< ' ';                }
            }
        }
    // Complete the class

};
