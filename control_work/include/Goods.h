#ifndef GOODS_H
#define GOODS_H
#include <string>
class Goods
{
    public:
        /* СТАТИЧЕСКИЕ методы -принадлежат классу */
        static float AllObjCost(Goods* arr, int arrSize);
        static void PrintArr(Goods* arr, int arrSize);
        static void WriteFile(Goods* arr, int arrSize);
        /* /СТАТИЧЕСКИЕ методы -принадлежат классу */

        /* Конструкторы и деструкнор */
        Goods();
        Goods(std::string name, std::string category, float cost, int amount);
        virtual ~Goods();
        /* /Конструкторы и деструкнор */

        /* сеттеры */
        void setName(std::string);
        void setCategory(std::string );
        void setCost(float);
        void setAmount(int);
        /* /сеттеры */

        /* геттеры */
        std::string getName();
        std::string getCategory();
        float getCost();
        int getAmount();
        /* /геттеры */

        /* Методы объекта*/
        void selfPrint();
        void selfEdit(std::string name, std::string cat, float cst, int amnt);
        void selfEdit();
        /* /Методы объекта*/

    private:
        /*Поля объекта*/
        std::string name;
        std::string category;
        float cost;
        int amount;
};

#endif // GOODS_H
