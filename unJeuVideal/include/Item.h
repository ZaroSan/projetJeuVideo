#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        virtual int getStrength()=0;
        virtual int getPower()=0;
        virtual int getLifePoint()=0;
    protected:

    private:
};

#endif // ITEM_H
