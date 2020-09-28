#include<bits/stdc++.h>
using namespace std;

char _x_(int a,...)
{
    static int i =-1;
    // cout << i+++a;
    return i+++a;
}

class x{

};

int main(int argc, char *argv[])
{
    // char (*p)(int,...) = &_x_;
    // cout << "1: - " + (*p)(0,1,2,3,4) << endl;
    // // for(;(*p)(0,1,2,3,4);)
    // //     printf("%d", 1+2);
    // return 0;
    // cout << argc << endl;
    // cout << argv[0] << endl;
    // cout << argv[1] << endl;
    // cout << argv[2] << endl;

    x X;
    cout << sizeof(X);
}