#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;

class Student {
    public: 
        Student (string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa){
            Validate();
        }

        string getName() const { return name_; }
        int getGrade() const { return grade_; }
        float getGPA() const { return gpa_; }

        // TODO: Define "Student" class

        void setName (string name){
            name_ = name;
            Validate();
        }

        void setGrade (int grade){
            grade_ = grade;
            Validate();
        }

        void setGPA (float gpa){
            gpa_ = gpa;
            Validate();
        }

    private:
        string name_;
        int grade_;
        float gpa_;
        void Validate (){
            if (getGrade() < 0 || getGrade() > 12 || getGPA() < 0.0 || getGPA() > 4.0)
            throw std::invalid_argument("negative dimension");
        }
        
};

int main() {
    Student student ("Joe", 2, 3);
    assert(student.getName() == "Joe");
    assert(student.getGrade() == 2);
    assert(student.getGPA() == 3);

    cout << student.getGPA() << endl;

    bool myexception{false};
    try {
        student.setGrade(-100);
    }
    catch(...) {
        myexception = true;
    }
    assert(myexception);
}