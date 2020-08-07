#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define v(n) vector<int> v(n)
#define ifor(i, a, b) for(int i=a; i<b; i++)
#define dfor(i, a, b) for(int i=a; i>=b; i--)

typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int>> VV;
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Student {
    int x;
    int y;
    vector<int> z;

    public:

    Student()
    {

    }

    Student(int x1, int y1, vector<int> z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Student(Student &s_old)
    {
        x = s_old.x;
        y = s_old.y;
        z = s_old.z;
    }

    void display()
    {
        for(int i=0; i<z.size(); i++)
        {
            cout << z[i] << " ";
        }

        z[0] = -5;

        cout << endl;
    }
};

int main()
{
    Student s1(5, 6, vector<int>{1,2,3});
    Student s2;
    s2 = s1;
    s1.display();
    s2.display();
    s1.display();
}