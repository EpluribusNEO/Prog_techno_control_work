#include <iostream> //библиотека ввода-вывода
#include <locale>   //Библиотека Локализации
#include <cstdlib>
#include "Goods.h" //Пользовательский Класс
//#include <Windows.h>


using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian"); //Подключение Русской локали
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    const int SIZE = 4;
    void fillArrGoods(Goods* arr, int sizeArr);

    cout << "Пирогов Денис Сергеевич.\nИБ-76с № 1710393." << endl;

    /*создание объекта с помощью конструктора по умолчанию*/
    cout << "Cоздание объекта с помощью конструктора по умолчанию:"<<endl;
    Goods gds1;// = new Goods();
    gds1.selfPrint();
    /* /создание объекта с помощью конструктора по умолчанию*/

    /*создание объекта с помощью конструктора с параметрами*/
    cout << "\nCоздание объекта  с помощью конструктора с параметрами:"<<endl
         << "Введите параметры:"<<endl;
    std::string name, category;
    int amount;
    float cost;
    cout << "Название:>";   cin>>name;
    cout << "Каиегория:>";  cin>>category;
    cout << "Цена:>";       cin>>cost;
    cout << "Количество:>"; cin>>amount;
    Goods* gds2 = new Goods(name, category, cost, amount);
    gds2->selfPrint();
    /* /создание объекта с помощью конструктора с параметрами*/

    cout<<"\n\nСоздание массива объектов: " <<endl;
    Goods* arrGoods = new Goods[SIZE];
    fillArrGoods(arrGoods, SIZE);
    Goods::PrintArr(arrGoods, SIZE);

    float cst = Goods::AllObjCost(arrGoods, SIZE);
    cout << "\n\nОбщая стоимость<:" << cst <<endl;

    Goods::WriteFile(arrGoods, SIZE);

    system("pause");
    return 0;
}

void fillArrGoods(Goods* arr, int sizeArr){
    cout << "\nРедактирование:" << endl;
     for(int i=0; i<sizeArr; i++){
        cout << "\nОбъект № " << i << endl;
        (arr+i)->selfEdit();
    }
}

