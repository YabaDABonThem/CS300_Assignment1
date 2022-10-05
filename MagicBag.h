#include "Bag.h"
#include <iostream>

using namespace std;

template<class T>
class MagicBag : public PlainBag {
    private:
        bool removed = false;
    public:
        void print() const {
            cout << "[]";
        }

        void size() const {
            if(!removed) {
                return bagSize;
            }
            return 0;
        }

        bool remove(const T& item) {
            // just return false if we don't even have the item
            if (!contains(item)) return false;
            removed = true;
            // We need to find the item in the array and remove it
            // basically what we can do is to assign the value of the last item
            // to the value of the item being replaced and decrease the size
            contents[indexOf(item)] = contents[bagSize-1];
            --bagSize; // decrease size of bag if we do remove an item
            return true;
        }

        int count(const T& item) const {
            if (!removed) return 0;
            // query the bag and find the count of the amount of items there are
            int num = 0;
            for (int i = 0; i < bagSize; ++i) {
                if (contents[i] == item) { // is this the right comparator?
                    ++num;
                }
            }
            return num;
        }
};