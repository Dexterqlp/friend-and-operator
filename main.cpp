#include <iostream>


//#define DEBUG
using namespace std;

class Grade{
    int math;
    int bio;
    int mus;

public:
    void setMath(int a){
        math=a;
    }

    void setBio(int b){
        bio=b;
    }

    void setMus(int c){
        mus=c;
    }

#ifdef DEBUG
    Grade operator+(const Grade& d){
        Grade grade;
        grade.math=this->math+d.math;
        grade.bio=this->bio+d.bio;
        grade.mus=this->mus+d.mus;
        return grade;
    }

#endif
#ifndef DEBUG
    Grade operator+(const Grade& d){
        Grade grade;
        grade.math=this->math+d.math-1;
        grade.bio=this->bio+d.bio-1;
        grade.mus=this->mus+d.mus-1;
        return grade;
    }
#endif

    friend Grade operator-(const Grade&a, const Grade& b);
    void showGrade(){
        cout<<"the math grade is:"<<math<<endl;
        cout<<"the bio grade is:"<<bio<<endl;
        cout<<"the mus grade is:"<<mus<<endl;
    }
};

Grade operator-(const Grade&a,const Grade& b){
    Grade c;
    c.mus=a.mus-b.mus;
    c.bio=a.bio-b.bio;
    c.math=a.math-b.math;
    return c;
}

int main() {
    Grade grade1;
    Grade grade2;
    Grade grade3;
    Grade grade4;
    grade1.setMath(95);
    grade1.setBio(90);
    grade1.setMus(91);

    grade2.setMath(80);
    grade2.setMus(81);
    grade2.setBio(85);

    grade3=grade1+grade2;
    grade4=grade1-grade2;
    cout<<"the grade of grade3 is:"<<endl;
    grade3.showGrade();
    grade4.showGrade();

    return 0;
}