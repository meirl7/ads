#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

unordered_map<string, float> gpaTable = {
    {"A+", 4.00f},
    {"A", 3.75f},
    {"B+", 3.50f},
    {"B", 3.00f},
    {"C+", 2.50f},
    {"C", 2.00f},
    {"D+", 1.50f},
    {"D", 1.0f},
    {"F", 0.f}
};

struct Student
{
    string ln, fn;
    float gpa;

    Student(string& s1, string& s2, float gpa) : ln(s1), fn(s2), gpa(gpa) {}
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

        float gpa = 0.0f;

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
            gpa = 0.0f;
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