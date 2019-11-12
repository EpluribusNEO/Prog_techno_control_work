#include <iostream>
#include "PairNumb.h"

using namespace std;

int main()
{
    cout << "Simple Class" << endl;

    /* Указатели на Объекты */
    cout << "\n___Poiner:___" << endl;
    PairNumb* ptrDef = new PairNumb(); //конструктор по уполчанию
    PairNumb* ptrNum = new PairNumb("myPoint", 3, 14);
    ptrDef->selfPrint();
    ptrNum->selfPrint();
    /* Принудительно удалим Объекты */
    delete ptrDef;
    delete ptrNum;
    /* /Указатели на Объекты */

    /* Объекты */
    cout << "\n___Objects:___" << endl;
    PairNumb Num2("two", 1000, 2000);
    PairNumb Num3("three", 11, 22);

    PairNumb sum = Num2 + Num3;

    Num2.selfPrint();
    Num3.selfPrint();
    sum.selfPrint();
    /* /Объекты */

    return 0;
}
