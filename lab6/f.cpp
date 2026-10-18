#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

unordered_map<string, double> gpaTable = {
    {"A+", 4.00},
    {"A", 3.75},
    {"B+", 3.50},
    {"B", 3.00},
    {"C+", 2.50},
    {"C", 2.00},
    {"D+", 1.50},
    {"D", 1.00},
    {"F", 0.00}
};

struct Student
{
    string ln, fn;
    double gpa;

    Student(string& s1, string& s2, double gpa) : ln(s1), fn(s2), gpa(gpa) {}
};

int main()
{
    int n;
    cin >> n;

    vector<Student> students;

    for (int i = 0; i < n; i++)
    {
        string ln, fn;
        int cnt;

        cin >> ln >> fn >> cnt;

        double gpa = 0.0;

        int sum = 0;
        for (int j = 0; j < cnt; j++)
        {
            string grade;
            int credits;
            cin >> grade >> credits;

            sum += credits;
            gpa += gpaTable[grade] * credits;
        }

        if (sum)
            gpa /= sum;
        else
            gpa = 0;
        students.emplace_back(ln, fn, gpa);
    }

    sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
        if (s1.gpa != s2.gpa)
            return s1.gpa < s2.gpa;
        if (s1.ln != s2.ln)
            return s1.ln < s2.ln;
        return s1.fn < s2.fn;
    });

    for (Student& st : students)
    {
        cout << st.ln << " " << st.fn << " " << fixed << setprecision(3) << st.gpa << endl;
    }
}