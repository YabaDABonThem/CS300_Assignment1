#include "Bag.h"
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
            cout << "\n[]"; //override print and print empty list
        }

};