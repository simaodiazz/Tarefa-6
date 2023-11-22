#include <iostream>

#include "../include/list.h"
#include "../include/student.h"

using namespace std;

int main() {
    List<Student> students(
        10,
        Student("John"),
        Student("Jane"),
        Student("Peter"),
        Student("Mary"),
        Student("Mark"),
        Student("Sarah"),
        Student("Alex"),
        Student("Alexa"),
        Student("Sara"),
        Student("Sofia")
    );

    students.forEach([](Node<Student>* node) {
        node->data.getPassed();
        node->data.getAvarage();
        node->data.getBetter(); 
        cout << endl << endl;
    });
}