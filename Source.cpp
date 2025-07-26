#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include <iomanip>
#include <algorithm>

using namespace std;

enum class StudentType { Uni, College };
// Struct used to store numbers of each part of a course that students must take
struct including {
    int assignments;
    int tests;
    int exams;
};

class Student {
public:
    string name;
    float score;
    string day_of_birth;
    string school_name;
    string course_name;
    StudentType studentType;

    Student(string name, string day_of_birth, string school_name, string course_name, StudentType studentType)
        : name(name), score(0), day_of_birth(day_of_birth), school_name(school_name), course_name(course_name), studentType(studentType) {}

    virtual void DoAssignment(float&) {}
    virtual void TakeTest(float&) {}
    virtual void TakeExam(float&) {}
};

class UniStudent : public Student {
private:
    int semesters;
    int courses_num;
    struct including includ { 3, 2, 1 };

public:
    UniStudent(string name, string day_of_birth, string school_name, string course_name)
        : Student(name, day_of_birth, school_name, course_name, StudentType::Uni), semesters(8), courses_num(4) {}

    void DoAssignment(float& sum) {
        float score = 0, sum_each_semester, sum_each_course;
        cout << "\nPlease enter score for the assignments of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            sum_each_semester = 0;
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                sum_each_course = 0;
                cout << "\nCourse " << j << endl;
                for (int k = 1; k <= (int)includ.assignments; ++k) {
                    cout << "Please enter score for the assignment " << k << ": ";
                    cin >> score;
                    sum_each_course += score;
                }
                sum_each_semester += (sum_each_course / includ.assignments);
                cout << "This course has: " << fixed << setprecision(2) << (sum_each_course / includ.assignments) << endl;
            }
            sum += (sum_each_semester / courses_num);
            cout << "\nThis semester has: " << fixed << setprecision(2) << (sum_each_semester / courses_num) << endl;
        }
        sum /= semesters;
    }
    void TakeTest(float& sum) {
        float score = 0, sum_each_semester, sum_each_course;
        cout << "\nPlease enter score for the tests of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            sum_each_semester = 0;
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                sum_each_course = 0;
                cout << "\nCourse " << j << endl;
                for (int k = 1; k <= (int)includ.tests; ++k) {
                    cout << "Please enter score for the test " << k << ": ";
                    cin >> score;
                    sum_each_course += score;
                }
                sum_each_semester += (sum_each_course / includ.tests);
                cout << "This course has: " << fixed << setprecision(2) << (sum_each_course / includ.tests) << endl;
            }
            sum += (sum_each_semester / courses_num);
            cout << "\nThis semester has: " << fixed << setprecision(2) << (sum_each_semester / courses_num) << endl;
        }
        sum /= semesters;
    }
    void TakeExam(float& sum) {
        float score = 0, sum_each_semester;
        cout << "\nPlease enter score for the exams of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            sum_each_semester = 0;
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                cout << "Course " << j << endl;
                cout << "Please enter score for the exam: ";
                cin >> score;
                sum_each_semester += score;
            }
            sum += (sum_each_semester / courses_num);
            cout << "\nThis semester has: " << fixed << setprecision(2) << (sum_each_semester / courses_num) << endl;
        }
        sum /= semesters;
    }
};

class CollegeStudent : public Student {
private:
    int semesters;
    int courses_num;
    struct including includ { 1, 1, 1 };

public:
    CollegeStudent(string name, string day_of_birth, string school_name, string course_name)
        : Student(name, day_of_birth, school_name, course_name, StudentType::College), semesters(4), courses_num(3) {}

    void DoAssignment(float& sum) {
        float score = 0;
        cout << "\nPlease enter score for the assignments of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                cout << "Course " << j << endl;
                cout << "Please enter score for the assignment: ";
                cin >> score;
                sum += score;
            }
        }
        sum /= (semesters * courses_num);
    }
    void TakeTest(float& sum) {
        float score = 0;
        cout << "\nPlease enter score for the tests of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                cout << "Course " << j << endl;
                cout << "Please enter score for the test: ";
                cin >> score;
                sum += score;
            }
        }
        sum /= (semesters * courses_num);
    }
    void TakeExam(float& sum) {
        float score = 0;
        cout << "\nPlease enter score for the exams of " + to_string(semesters) + " semesters\n";
        for (int i = 1; i <= (int)semesters; ++i) {
            cout << "\nSemester " << i << endl;
            for (int j = 1; j <= (int)courses_num; ++j) {
                cout << "Course " << j << endl;
                cout << "Please enter score for the exam: ";
                cin >> score;
                sum += score;
            }
        }
        sum /= (semesters * courses_num);
    }
};

class University {
private:
    string name;
    vector<unique_ptr<Student>> students; // Vector of unique pointers for managing students in a university
    int capacity;
    int count = 0;

    // Private constructor to prevent direct instantiation
    University(string name, int size) : name(name), capacity(size) {
        students.reserve(size);
    }

    // Static instance of the University class
    static University* instance;
public:
    // Static method to get the singleton instance
    static University* getInstance(string name, int size) {
        if (!instance) {
            instance = new University(name, size);
        }
        return instance;
    }

    // Disable copy constructor and assignment operator
    University(const University&) = delete;
    University& operator=(const University&) = delete;

    // Destructor to clean up the instance
    ~University() {
        delete instance;
    }

    void add(const string& new_name, const string& day_of_birth, const string& school_name, const string& course_name, StudentType stuType) {
        if (count >= capacity) {
            cout << "The list is full!!\n";
            return;
        }

        if (stuType == StudentType::Uni) {
            students.push_back(make_unique<UniStudent>(new_name, day_of_birth, school_name, course_name));
        }
        else if (stuType == StudentType::College) {
            students.push_back(make_unique<CollegeStudent>(new_name, day_of_birth, school_name, course_name));
        }
        ++count;
    }

    void display() const {
        if (count == 0) {
            cout << "Empty list!!\n";
            return;
        }

        cout << endl << name << " currently has " << count << " students\n";
        cout << "NAME - BIRTH - COURSE - STU_TYPE - FINAL SCORE\n";

        // Range for loop is implemented to print all student's details in students vector
        for (const auto& student : students) {
            cout << student->name << " - " << student->day_of_birth << " - " << student->course_name << " - " <<
                ((student->studentType == StudentType::Uni) ? "Uni" : "College") << " - " << student->score << endl;
        }
        cout << endl;
    }

    void remove(const string& name) {
        // The use of auto helps to probably initiate suitable data type for variable it
        // Lamda function to check for each student's name if it is matched or not
        auto it = find_if(students.begin(), students.end(), [&](const unique_ptr<Student>& student) {return (student->name == name);});

        if (it != students.end()) {
            students.erase(it);
            --count;
        }
        else {
            cout << "Cannot find a student with that name!!\n";
        }
    }

    void bestScore() const {
        if (count == 0) {
            cout << "Empty list!!\n";
            return;
        }

        float max = 0;
        for (const auto& student : students) {
            if (student->score > max) {
                max = student->score;
            }
        }

        int BScount = 0;
        cout << "\nNAME - BIRTH - COURSE - STU_TYPE - FINAL SCORE\n";
        for (const auto& student : students) {
            if (student->score == max) {
                cout << student->name << " - " << student->day_of_birth << " - " << student->course_name << " - " <<
                    ((student->studentType == StudentType::Uni) ? "Uni" : "College") << " - " << student->score << endl;
                ++BScount;
            }
        }
        cout << endl << name << " currently has " << BScount << " best students\n";
    }
};

// Initialize static instance to nullptr
University* University::instance = nullptr;

int main() {
    int capa;
    string school_name;
    cout << "Enter name of university (no space between words): ";
    getline(cin, school_name);
    cout << "Enter capacity of list of students: ";
    cin >> capa;
    University* uni = University::getInstance(school_name, capa);
    cout << endl;

    int num;
    while (true) {
        cout << "\nEnter choice (1: add new student, 2: display list, 3: remove student, 4: display best students 0: exit): ";
        cin >> num;

        switch (num) {
        case 1: {
            string new_name, birthday, course_name;
            cout << "\nPlease enter details of the new student to be added:\n";
            cout << "Name: ";
            cin.ignore(); // Ignore newline character left in the input buffer
            getline(cin, new_name);
            cout << "Day of birth: ";
            getline(cin, birthday);
            cout << "Course: ";
            getline(cin, course_name);

            int type_of_stu;
            cout << "Is he/she a university or college student? (1: Uni, 2: College): ";
            cin >> type_of_stu;
            if (type_of_stu == 1)
                uni->add(new_name, birthday, school_name, course_name, StudentType::Uni);
            else if (type_of_stu == 2)
                uni->add(new_name, birthday, school_name, course_name, StudentType::College);
            else
                cout << "Invalid type of student\n";
            cout << endl;
            continue;
        }
        case 2:
            uni->display();
            continue;
        case 3: {
            string name;
            cout << "\nEnter name of student to be removed: ";
            cin.ignore(); // Ignore newline character left in the input buffer
            getline(cin, name);
            uni->remove(name);
            cout << endl;
            continue;
        }
        case 4: {
            uni->bestScore();
            continue;
        }
        case 0:
            return 0;
        default:
            cout << "Invalid number!!!!!" << endl;
        }
    }
}
