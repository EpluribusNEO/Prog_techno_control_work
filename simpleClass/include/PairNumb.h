#include <string>
#ifndef PAIRNUMB_H
#define PAIRNUMB_H

class PairNumb
{
    public:
        PairNumb();
        PairNumb(std::string name, int first, int second);
        virtual ~PairNumb();

        void selfPrint();
        std::string getName();
        int getFirst();
        int getSecond();

        void setName(std::string name);
        void setFirst(int first);
        void setSecond(int second);

        PairNumb operator + (const PairNumb& right);

    private:
        std::string name;
        int first;
        int second;
};

#endif // PAIRNUMB_H
