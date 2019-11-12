#ifndef GOODS_H
#define GOODS_H
#include <string>
class Goods
{
    public:
        /* ����������� ������ -����������� ������ */
        static float AllObjCost(Goods* arr, int arrSize);
        static void PrintArr(Goods* arr, int arrSize);
        static void WriteFile(Goods* arr, int arrSize);
        /* /����������� ������ -����������� ������ */

        /* ������������ � ���������� */
        Goods();
        Goods(std::string name, std::string category, float cost, int amount);
        virtual ~Goods();
        /* /������������ � ���������� */

        /* ������� */
        void setName(std::string);
        void setCategory(std::string );
        void setCost(float);
        void setAmount(int);
        /* /������� */

        /* ������� */
        std::string getName();
        std::string getCategory();
        float getCost();
        int getAmount();
        /* /������� */

        /* ������ �������*/
        void selfPrint();
        void selfEdit(std::string name, std::string cat, float cst, int amnt);
        void selfEdit();
        /* /������ �������*/

    private:
        /*���� �������*/
        std::string name;
        std::string category;
        float cost;
        int amount;
};

#endif // GOODS_H
