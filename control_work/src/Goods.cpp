#include "Goods.h"
#include <string>
#include <sstream>
#include <iomanip> /* setw */
#include <iostream>
#include <fstream> /* работа с файлом */

/* (Конструктор) поумолчанию */
Goods::Goods():name("Noname"), category("None"), cost(0.0f), amount(0) {}

/* (Конструктор) с параметрами */
Goods::Goods(std::string name, std::string category, float cost, int amount){
    this->name = name;
    this->category = category;
    this->cost = cost;
    this->amount = amount;
}

/* (Деструктор) Вызывается при удаление объекта
 *  (Деструктор) Вызывается при удаление объекта...*/
Goods::~Goods(){
    std::cout<<"Объект Удалён!"<<std::endl;
}

 /* СТАТИЧЕСКИЕ методы (Принадлежат классу)
  * (Статический) подсчитать общую стоимость объектов в массиве
  * Принимает указатель на начало массива и размерность */
 float Goods::AllObjCost(Goods* arr, int arrSize){
     float allObjCost = 0.0f;
     for(int i=0; i<arrSize; i++){
        allObjCost += (float)((arr+i)->getAmount() * (arr +i)->getCost());
     }
     return allObjCost;
}

/* (Статический) Печатае массив объектов.
 * Принимает указатель на начало массива и размерность */
void Goods::PrintArr(Goods* arr, int arrSize){
    std::cout << "\nÂûâîä:" << std::endl;
    std::cout << std::setw(12) << "Имя"
        <<std::setw(12) << "Категория"
        <<std::setw(12) << "Цена"
        <<std::setw(10) << "Кол-во"
        <<std::setw(10) << "Всего"
        <<std::endl;
    for(int i=0; i<arrSize; i++){
        (arr +i)->selfPrint();
    }
}

/* (Статический) запись в файл.
 * Принимает указатель на начало массива и размерность*/
void Goods::WriteFile(Goods* arr, int arrSize){
    char fileName[] = "myFile.txt";
    std::ofstream FOUT;
    FOUT.open(fileName);
    float totalCost = 0.0f;

    /* записываем заголовки */
    FOUT << std::setw(12) << "Имя"
        <<std::setw(12) << "Категория"
        <<std::setw(12) << "Цена"
        <<std::setw(10) << "Кол-во"
        <<std::setw(10) << "Всего"
        <<std::endl;
    /* /записываем заголовки */

    /* записываем заголовки */
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
    std::cout << "Массив записан в файл!" << std::endl;
}
/* /СТАТИЧЕСКИЕ методы */

/* Методы Объекта */
/* вывод данных на экран (в отформатированном виде) */
void Goods::selfPrint(){
    float totalCost = (float)((float)this->amount * this->cost);
    std::cout << std::setw(12) << this->name
        <<std::setw(12) << this->category
        <<std::setw(12) << this->cost
        <<std::setw(10) << this->amount
        <<std::setw(10) << totalCost
        <<std::endl;
}

/* редактирование объекта -Заменяет поля на новые (принимает параметры)*/
void Goods::selfEdit(std::string name, std::string cat, float cost, int amount){
    this->name = name;
    this->category = cat;
    this->cost = cost;
    this->amount = amount;
}

/* Редактирование объекта */
void Goods::selfEdit(){
    std::string name, category;
    int amount;
    float cost;

    std::cout << "Наименование:>";
    std::cin >> name;
    this->setName(name);

    std::cout << "Категория:>";
    std::cin >> category;
    this->setCategory(category);

    std::cout << "Стоимость:>";
    std::cin >> cost;
    this->setCost(cost);

    std::cout << "Количество:>";
    std::cin >> amount;
    this->setAmount(amount);
}
/* /Методы Объекта */

/* Сеттеры */
void Goods::setName(std::string name){ this->name = name; }
void Goods::setCategory(std::string cat){ this->category = cat; }
void Goods::setCost(float cost){ this->cost = cost; }
void Goods::setAmount(int amount){ this->amount = amount; }
/* /Сеттеры */

/* Геттеры */
std::string Goods::getName(){ return this->name; }
std::string Goods::getCategory(){ return this->category; }
float Goods::getCost(){ return this->cost; }
int Goods::getAmount(){ return this->amount; }
/* /Геттеры */
