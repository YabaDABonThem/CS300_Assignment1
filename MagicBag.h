#include "Bag.h"
#include <iostream>

using namespace std;

template<class T>
class MagicBag : public PlainBag<T> {
    public:
        MagicBag()
        {

        }
        void print() const {
            cout << "\n[]";
        }

};