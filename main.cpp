#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

class Student
{
private:
    string name;
    string surname;
    vector<float> grades;
    int album_number;
public:
    Student(string m, string n)
    {
        name = m;
        surname = n;
        cout << "an object was created" << endl;
        enter_grades();
        enter_album_number();
    }
    bool add_album_number(int album_number)
    {
        if(validate_albumNumber(album_number))
        {
            this->album_number = album_number;
            return true;
        }
        else
        {
            cout << "Invalid album number. It must have 5 or 6 digits." << endl;
            return false;
        }
    }
    bool add_grade(float grade)
    {
        if(grade >= 2.0 && grade <= 5.0)
        {
            grades.push_back(grade);
            return true;
        }
        else
        {
            cout << "Invalid grade. Grade must be between 2.0 and 5.0." << endl;
            return false;
        }
    }
    float calculate_grade() const
    {
        float sum = accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }
    void print() const
    {
        cout << setw(10) << left << name << setw(10) << left << surname << "Grades: ";
        for (const auto &grade : grades)
        {
            cout << grade << " ";
        }
        cout << "Final Grade: " << calculate_grade() << " Result: " << (passed() ? "PASSED" : "FAILED") << endl;
    }
private:
    void enter_grades()
    {
        while(true)
        {
            cout << "Enter grade between 2.0 and 5.0, 0 to stop: ";
            float grade;
            cin >> grade;
            if (grade == 0)
            {
                break;
            }
            add_grade(grade);
        }
    }
    void enter_album_number()
    {
        while(true)
        {
            cout << "Enter album number (5 or 6 digits): ";
            int album;
            cin >> album;
            if (add_album_number(album))
            {
                break;
            }
            else
            {
                cout << "Invalid input. Try again." << endl;
            }
        }
    }
    bool validate_albumNumber(int album_number) const
    {
        int num_digits = 0;
        int temp = album_number;
        while(temp != 0)
        {
            temp /= 10;
            ++num_digits;
        }
        return num_digits == 5 || num_digits == 6;
    }
    bool passed() const
    {
        int counter = 0;
        for(const auto& grade : grades)
        {
            if(grade <= 2)
            {
                counter++;
            }
        }
        if(counter > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
void final_assignment_1()
{
    vector<Student> students;
    while(true)
    {
        cout << "Enter 1 to add student, 2 to print info, 0 to stop: ";
        int choice;
        cin >> choice;
        if(choice == 1)
        {
            string name, surname;
            cout << "Enter name and surname: ";
            cin >> name >> surname;
            students.emplace_back(name, surname);
            cin.ignore();
        }
        else if(choice == 2)
        {
            cout << "-----------------------------------------------------------------------------\n";
            cout << setw(10) << left << "Name" << setw(10) << left << "Surname" << "Info" << endl;
            cout << "-----------------------------------------------------------------------------\n";
            for (const auto &student : students)
            {
                student.print();
            }
        }
        else if(choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
class Complex
{
private:
    double real, imag;
public:
    Complex(double real_val, double imag_val = 0.0)
    {
        real = real_val;
        imag = imag_val;
    }
    void set_real(double real_val)
    {
        real = real_val;
    }
    void set_imag(double imag_val)
    {
        imag = imag_val;
    }
    void print() const
    {
        if(imag > 0)
        {
            cout << real << "+" << imag << "i" << endl;
        }
        else if(imag == 0)
        {
            cout << real << endl;
        }
        else
        {
            cout << real << imag << "i" << endl;
        }
    }
    Complex add(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }
};
void final_assignment_2()
{
    Complex a(1.0, -3.0);
    Complex b(3.14);

    b.set_imag(-5);

    Complex c = a.add(b);

    c.print();
}
int main()
{
    int choice;
    cout << "enter 1 for task 1, 2 for task 2, 0 to terminate: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        final_assignment_1();
        break;
    case 2:
        final_assignment_2();
        break;
    case 0:
        cout << "terminating program..";
        return 0;
    default:
        cout << "invalid choice enter again" << endl;
    }
    return 0;
}
