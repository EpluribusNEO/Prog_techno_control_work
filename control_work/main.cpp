#include <iostream> //���������� �����-������
#include <locale>   //���������� �����������
#include <cstdlib>
#include "Goods.h" //���������������� �����
//#include <Windows.h>


using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian"); //����������� ������� ������
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    const int SIZE = 4;
    void fillArrGoods(Goods* arr, int sizeArr);

    cout << "������� ����� ���������.\n��-76� � 1710393." << endl;

    /*�������� ������� � ������� ������������ �� ���������*/
    cout << "C������� ������� � ������� ������������ �� ���������:"<<endl;
    Goods gds1;// = new Goods();
    gds1.selfPrint();
    /* /�������� ������� � ������� ������������ �� ���������*/

    /*�������� ������� � ������� ������������ � �����������*/
    cout << "\nC������� �������  � ������� ������������ � �����������:"<<endl
         << "������� ���������:"<<endl;
    std::string name, category;
    int amount;
    float cost;
    cout << "��������:>";   cin>>name;
    cout << "���������:>";  cin>>category;
    cout << "����:>";       cin>>cost;
    cout << "����������:>"; cin>>amount;
    Goods* gds2 = new Goods(name, category, cost, amount);
    gds2->selfPrint();
    /* /�������� ������� � ������� ������������ � �����������*/

    cout<<"\n\n�������� ������� ��������: " <<endl;
    Goods* arrGoods = new Goods[SIZE];
    fillArrGoods(arrGoods, SIZE);
    Goods::PrintArr(arrGoods, SIZE);

    float cst = Goods::AllObjCost(arrGoods, SIZE);
    cout << "\n\n����� ���������<:" << cst <<endl;

    Goods::WriteFile(arrGoods, SIZE);

    system("pause");
    return 0;
}

void fillArrGoods(Goods* arr, int sizeArr){
    cout << "\n��������������:" << endl;
     for(int i=0; i<sizeArr; i++){
        cout << "\n������ � " << i << endl;
        (arr+i)->selfEdit();
    }
}

