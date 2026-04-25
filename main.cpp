#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
public:
    Person(string n) {
        name = n;
    }
    virtual void display() = 0; // Polymorphism
};
class Student : public Person {
private:
    string enrolled[10];
    int enrolledCount;
public:
    Student(string n) : Person(n) {
        enrolledCount = 0;
    }
    void enroll(string course) {
        enrolled[enrolledCount++] = course;
    }
    bool hasCompleted(string course) {
        for (int i = 0; i < enrolledCount; i++) {
            if (enrolled[i] == course)
                return true;
        }
        return false;
    }
    void display() override {
        cout << "\nStudent Name: " << name << endl;
        cout << "Enrolled Courses: ";
        if (enrolledCount == 0)
            cout << "None";
        for (int i = 0; i < enrolledCount; i++)
            cout << enrolled[i] << " ";
        cout << endl;
    }
};
class CourseGraph {
private:
    string courses[10];
    // Adjacency Matrix
    int prereq[10][10]; 
    int courseCount;
public:
    CourseGraph() {
        courseCount = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                prereq[i][j] = 0;
    }
    void addCourse(string course) {
        courses[courseCount++] = course;
    }
    int getIndex(string course) {
        for (int i = 0; i < courseCount; i++) {
            if (courses[i] == course)
                return i;
        }
        return -1;
    }
    void addPrerequisite(string course, string prerequisite) {
        int c = getIndex(course);
        int p = getIndex(prerequisite);
        if (c != -1 && p != -1)
            prereq[c][p] = 1;
    }
    bool checkPrerequisites(Student &s, string course) {
        int c = getIndex(course);
        if (c == -1) return false;
        for (int i = 0; i < courseCount; i++) {
            if (prereq[c][i] == 1) {
                if (!s.hasCompleted(courses[i]))
                    return false;
            }
        }
        return true;
    }
    void displayCourses() {
        cout << "\n--- Available Courses & Prerequisites ---\n";
        for (int i = 0; i < courseCount; i++) {
            cout << courses[i] << " <- ";
            bool hasPrereq = false;
            for (int j = 0; j < courseCount; j++) {
                if (prereq[i][j] == 1) {
                    cout << courses[j] << " ";
                    hasPrereq = true;
                }
            }
            if (!hasPrereq)
                cout << "None";
            cout << endl;
        }
    }
};
#include <iostream>
using namespace std;

int main() {
    Student student("Zainab");
    CourseGraph university;
    // Add courses
    university.addCourse("Programming-I");
    university.addCourse("Data Structures");
    university.addCourse("Algorithms");
    university.addCourse("Databases");
    // Add prerequisites
    university.addPrerequisite("Data Structures", "Programming-I");
    university.addPrerequisite("Algorithms", "Data Structures");
    university.addPrerequisite("Databases", "Programming-I");
    int choice;
    string course;
    do {
        cout << "\n===== University Course Registration System =====\n";
        cout << "1. View Courses\n";
        cout << "2. Enroll in Course\n";
        cout << "3. View Student Details\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            university.displayCourses();
            break;
        case 2:
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, course);
            if (university.checkPrerequisites(student, course)) {
                student.enroll(course);
                cout << "Enrollment successful!\n";
            } else {
                cout << "Prerequisites not satisfied.\n";
            }
            break;
        case 3:
            student.display();
            break;
        case 0:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
