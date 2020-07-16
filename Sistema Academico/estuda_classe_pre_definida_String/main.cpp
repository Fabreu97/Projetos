#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("Bom Dia"), s2, s3;

    s2 = s1;
    s3.assign(s1);

    cout << "S1 = " << s1 << endl;
    cout << "S2 = " << s2 << endl;
    cout << "S3 = " << s3 << endl << endl;

    //modificar S2 e S3
    s2[0] = s3[2] = 'r';

    cout << "S1 = " << s1 << endl;
    cout << "S2 = " << s2 << endl;
    cout << "S3 = " << s3 << endl << endl;

    return 0;
}
