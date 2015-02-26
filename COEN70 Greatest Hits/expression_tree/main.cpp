/*By Max Werner and Parker Newton
*
*Main file for expressiontree.cpp
*/

#include "expressionTree.cpp"

using namespace std;

int main()
{
    int flag = 1;
    
    while(flag == 1)
    {
        string str;
        eTree a;
        cout << endl << "Please enter your equation in postfix form: ";
        cin >> str;
        a.buildTree(str);
    
        cout << "Prefix: ";
        a.pre();
        cout << endl << "Postfix: ";
        a.post();
        cout << endl << "Infix: ";
        a.in();
        cout << endl << endl <<"Answer : "<< a.evaluate() << endl;
        a.clear();
        cout << "Enter 1 to do another or 0 to quit" << endl;
        cin >>flag;
    }

    return 0;
}
