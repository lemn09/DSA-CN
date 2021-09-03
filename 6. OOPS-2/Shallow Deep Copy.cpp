#include<iostream>
using namespace std;
#include<cstring>

class Stud{
    int age;

public:
    char *name;
    Stud(Stud const &s){                            // Copy Constructor
        this->age= s.age;
        // this->name = s.name;                       // Shallow Copy
        this->name= new char[strlen(s.name) + 1];   //Deep Copy
        strcpy(this->name,s.name);
    }

    Stud(char *name, int age){                      // Parameterized Constructor
        this->name= new char[strlen(name) + 1];
        strcpy(this->name,name);
        this->age= age;
    }

    void display(){
        cout<<name<<' '<<age<<endl;
    }
};

int main(){
    char name[]="drid";
    Stud s1(name,10);
    s1.display();
    Stud s2(s1);
    s2.name[0]= 'k';
    s2.display();
    s1.display();
    return 0;
}
