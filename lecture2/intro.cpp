#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student {
    string m_first = "First";
    string m_last = "Last";
    int m_id = 0;
    float m_average = 0;

public:
    Student() {}

    Student(string first, string last, int id, float avg)
        : m_first(first), m_last(last), m_id(id), m_average(avg) {}

    float getAvg() {
        return m_average;
    }
   
    int getId() {
        return m_id;
    }

    string getName() {
        return m_first + " " + m_last;
    }

    void print() const {
        cout << m_first << " " << m_last << " " << m_id << " " << m_average << endl;
    }
};

class Course {
    string m_name = "Course";
    vector<Student> m_students;

public:
    Course() {}

    Course(string name) 
        : m_name(name) {}

    void add_student(const Student& student) {
        m_students.push_back(student);
    }

    const vector<Student>& get_students() const {
        return m_students;
    }

    void load_from_file(const string file_name) {
        ifstream fin(file_name);
        string first, last;
        int id;
        float avg;

        while(fin >> first) {
            fin >> last >> id >> avg;

            add_student(Student(first, last, id, avg));
        }
    }

    void print() {
        for(const auto& s: m_students) {
            s.print();
        }
    }
};

int main(int argc, char * argsv[]) {

    vector<int> vec;
    vec.push_back(32);
    vec.push_back(63);
    vec.push_back(94);

/*
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
*/

/*
*    for(int a : vec) {
*        cout << a << endl;
*    }
*/

/*
    Student s1;
    Student s2("dave", "mark", 1, 3.14);
    Student s3("mary", "doe", 2002200001, 99.9);

    Course course4300("COMP 4300");

    course4300.add_student(s1);
    course4300.add_student(s2);
    course4300.add_student(s3);

    course4300.print();
*/
    
    Course c("COMP4300");

    c.load_from_file("students.txt");

    c.print();

    return 0;
}
