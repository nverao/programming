#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Student
{
    string name;
    string surname;
    int age;
    int grade;
    int mark_count;
    int *marks;
};

Student read_student(){
    Student X;
    cin >> X.name >> X.surname >> X.age >> X.grade >> X.mark_count;
    X.marks = new int[X.mark_count];
    for (int i = 0; i < X.mark_count; i++){
        cin >> X.marks[i];
    }
    return X;
}

void print_student(Student person){
    cout << person.name << " " << person.surname << " " << person.age << " " << person.grade << " " << person.mark_count;
    cout << endl;
    for (int i = 0; i < person.mark_count; i++){
        cout << person.marks[i] << " ";
    }
    cout << endl;
}

double get_student_avg_mark(Student person){
    double avg = 0;
    for (int i = 0; i < person.mark_count; i++){
        avg += person.marks[i];
    }
    avg = avg / person.mark_count;
    return avg;
}

bool will_graduate(Student person, int after_years){
    return person.grade + after_years > 11;
}

int age_entrance(Student person){
    return person.age - person.grade + 1; 
}

void add_mark(Student &person, int mark){
    double avr1;
    int i;
    avr1 = get_student_avg_mark(person);
    while (avr1 >= 4.5){
        i=person.mark_count;
        person.marks[i] = 5;
        avr1 = get_student_avg_mark(person);
        person.mark_count += 1;
    }
}

struct StudentJournal {
    int count;
    Student* data;
};

StudentJournal read_journal(){
    StudentJournal x;
    cin >> x.count;
    x.data = new Student[x.count]; //создали динамический массив студентов
    for (int i = 0; i < x.count; i++){
        x.data[i] = read_student();
    }
    return x;
}

void print_journal(StudentJournal x){
    for (int i = 0; i < x.count; i++){
        print_student(x.data[i]);
    }
}

void add_total_marks(StudentJournal &journal){
    for (int i = 0; i < journal.count; i++){
        journal.data[i].marks[journal.data[i].mark_count++] = round(get_student_avg_mark(journal.data[i]));
    }
}

void delete_student(StudentJournal &journal, int x){
    delete[] journal.data[x].marks;
    for ( int j = x; j < journal.count; j++){
        journal.data[j] = journal.data[j+1];
    }
    journal.count--;
}

void filter_avg_above(StudentJournal &journal, double x = 4.5){
    for (int i = 0; i <  journal.count; i++){
        if (get_student_avg_mark(journal.data[i]) < x){
            //cout << get_student_avg_mark(journal.data[i]);
            delete_student(journal, i);
        }
    }
}

bool equal_students(Student s1, Student s2){
    if ((s1.name == s2.name) && (s1.surname ==  s2.surname) && (s1.age == s2.age) && 
    (s1.grade == s2.grade) && (s1.mark_count == s2.mark_count)){
        for (int i = 0; i < s1.mark_count; i++){
            if (s1.marks[i] != s2.marks[i]){
                return false; 
            }
        }
        return true;
    }
    return false;
}

void remove_duplicates(StudentJournal &journal){
    for (int i = 0; i < journal.count; i++){
        for ( int j = i + 1; j < journal.count; j++){
            if (equal_students(journal.data[i], journal.data[j])){
                delete_student(journal, j);
                j--;
            }
        }
    }
}

/*int main(){
    Student X;
    int after_years;
    int mark;
    //cin >> after_years;
    X = read_student();
    add_mark(X, mark);
    print_student(X);
    //cout << get_student_avg_mark(X);
    //cout << will_graduate(X, after_years);
    //cout << age_entrance(X);
    delete[] X.marks;
}*/

int main(){
    StudentJournal sj;
    Student s1, s2;
    sj = read_journal();
    //add_total_marks(sj);
    //print_journal(sj);
    //filter_avg_above(sj, 3.75);
    remove_duplicates(sj);
    cout << sj.count << endl; 
    print_journal(sj);
    for (int i = 0; i < sj.count; i++){
        delete[] sj.data[i].marks;
    }
    delete[] sj.data;
}