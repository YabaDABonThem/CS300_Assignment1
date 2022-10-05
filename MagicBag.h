#ifndef MAGICBAG_H
#define MAGICBAG_H
#include "Bag.h"
#include "PlainBag.h"
#include <iostream>

using namespace std;

template<class T>
class MagicBag : public PlainBag<T> {
    public:
        MagicBag()
        {
            // create constructor
        }
        void print() const {
            cout << "[]"; //override print and print empty list
        }

};

#endif