#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/**
 * Fiz uma relação entre as duas arrays
*/
class Student {
private:
    string name;
    string disciplines[9] = { "Matematica", "Portugues", "Ingles", "Quimica", "Biologia", "Fisica", "Historia", "Geografia", "Sociologia" };
    double values[9];
public:
    Student(string name) : name(name) {
        for (int i = 0; i < 9; i++) {
            values[i] = rand() % 20;
        }
    }

    /**
     * Metodo para verificar se o aluno passou
     * 
     * @author simaodiazz
    */
    void getPassed() {
        for (int i = 0; i < 9; i++) {
            if (values[i] >= 10) {
                cout << "O aluno " << name << " passou na disciplina "<< disciplines[i] << " " << endl;
            }
        }
    }

    /**
     * Metodo para retornar a media
     * 
     * @author simaodiazz
    */
    void getAvarage() {
        double sum = 0;
        for (int i = 0; i < 9; i++) {
            sum += values[i];
        }
        cout << "A media do aluno " << name << " foi de " << sum / 9 << endl;
    }

    /**
     * Metodo para retornar a maior nota
     * 
     * @author simaodiazz
    */
    void getBetter() {
        int index;
        double max = 0;
        for (int i = 0; i < 9; i++) {
            if (values[i] > max) {
                max = values[i];
                index = i;
            }
        }
        cout << "A maior nota do aluno " << name << " foi de " << max << " na disciplina " << disciplines[index] << endl;
    }
};