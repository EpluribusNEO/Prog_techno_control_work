#include "Goods.h"
#include <string>
#include <sstream>
#include <iomanip> /* setw */
#include <iostream>
#include <fstream> /* ������ � ������ */

/* (�����������) ����������� */
Goods::Goods():name("Noname"), category("None"), cost(0.0f), amount(0) {}

/* (�����������) � ����������� */
Goods::Goods(std::string name, std::string category, float cost, int amount){
    this->name = name;
    this->category = category;
    this->cost = cost;
    this->amount = amount;
}

/* (����������) ���������� ��� �������� �������
 *  ������� ��������� �� ����� ��� ��������...*/
Goods::~Goods(){
    std::cout<<"������ �����!"<<std::endl;
}

 /* ����������� ������ (����������� ������)
  * (�����������) ���������� ����� ��������� �������� � �������
  * ��������� ��������� �� ������ ������� � ����������� */
 float Goods::AllObjCost(Goods* arr, int arrSize){
     float allObjCost = 0.0f;
     for(int i=0; i<arrSize; i++){
        allObjCost += (float)((arr+i)->getAmount() * (arr +i)->getCost());
     }
     return allObjCost;
}

/* (�����������) ������� ������ ��������.
 * ��������� ��������� �� ������ ������� � ����������� */
void Goods::PrintArr(Goods* arr, int arrSize){
    std::cout << "\n�����:" << std::endl;
    std::cout << std::setw(12) << "���"
        <<std::setw(12) << "���������"
        <<std::setw(12) << "����"
        <<std::setw(10) << "���-��"
        <<std::setw(10) << "�����"
        <<std::endl;
    for(int i=0; i<arrSize; i++){
        (arr +i)->selfPrint();
    }
}

/* (�����������) ������ � ����.
 * ��������� ��������� �� ������ ������� � �����������*/
void Goods::WriteFile(Goods* arr, int arrSize){
    char fileName[] = "myFile.txt";
    std::ofstream FOUT;
    FOUT.open(fileName);
    float totalCost = 0.0f;

    /* ���������� ��������� */
    FOUT << std::setw(12) << "���"
        <<std::setw(12) << "���������"
        <<std::setw(12) << "����"
        <<std::setw(10) << "���-��"
        <<std::setw(10) << "�����"
        <<std::endl;
    /* /���������� ��������� */

    /* ���������� ������ �������� */
    for(int i=0; i<arrSize; i++){
         totalCost = (float)((float)(arr +i)->getAmount() * (arr +i)->getCost());
         FOUT << std::setw(12) << (arr +i)->getName()
        <<std::setw(12) << (arr +i)->getCategory()
        <<std::setw(12) << (arr +i)->getCost()
        <<std::setw(10) << (arr +i)->getAmount()
        <<std::setw(10) << totalCost
        <<std::endl;
        totalCost = 0.0f;
    }
    FOUT.close();
    std::cout << "������ ������� � ����!" << std::endl;
}
/* /����������� ������ */

/* ������ ������� */
/* ����� ������ �� ����� (� ����������������� ����) */
void Goods::selfPrint(){
    float totalCost = (float)((float)this->amount * this->cost);
    std::cout << std::setw(12) << this->name
        <<std::setw(12) << this->category
        <<std::setw(12) << this->cost
        <<std::setw(10) << this->amount
        <<std::setw(10) << totalCost
        <<std::endl;
}

/* �������������� ������� -�������� ���� �� ����� (��������� ���������)*/
void Goods::selfEdit(std::string name, std::string cat, float cost, int amount){
    this->name = name;
    this->category = cat;
    this->cost = cost;
    this->amount = amount;
}

/* �������������� ������� */
void Goods::selfEdit(){
    std::string name, category;
    int amount;
    float cost;

    std::cout << "������������:>";
    std::cin >> name;
    this->setName(name);

    std::cout << "���������:>";
    std::cin >> category;
    this->setCategory(category);

    std::cout << "���������:>";
    std::cin >> cost;
    this->setCost(cost);

    std::cout << "����������:>";
    std::cin >> amount;
    this->setAmount(amount);
}
/* /������ ������� */

/* ������� */
void Goods::setName(std::string name){ this->name = name; }
void Goods::setCategory(std::string cat){ this->category = cat; }
void Goods::setCost(float cost){ this->cost = cost; }
void Goods::setAmount(int amount){ this->amount = amount; }
/* /������� */

/* ������� */
std::string Goods::getName(){ return this->name; }
std::string Goods::getCategory(){ return this->category; }
float Goods::getCost(){ return this->cost; }
int Goods::getAmount(){ return this->amount; }
/* /������� */
