#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

    string palavra1 = "E string!";
    cout << "1st: " << palavra1[0] << endl;
    cout << "last: " << palavra1[palavra1.size() - 1] << endl;

    palavra1.append("AAA");
    cout << palavra1;


    return 0;
}