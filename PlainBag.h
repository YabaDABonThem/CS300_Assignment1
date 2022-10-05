#include "Bag.h"
#include <iostream>

using namespace std;

template<class T> // makes it generic
class PlainBag : public Bag<T> {
     // private helper method :trol:
    private:
        // Instantiate fields
        // The bag's capacity is 20, so we have that as the length and store the size
        T contents[20];
        // When we loop, we ALWAYS need to loop through indexes with a max of size
        // because remove is coded so that items outside the size aren't removed.
        int bagSize = 0;

        // helper method
        int indexOf(const T& item) {
            for (int i = 0; i < bagSize; ++i) {
                if (item == contents[i]) {
                    return i;
                }
            }
            return -1; // if the item isn't even in the array
        }

    public: 
        void insert(const T& item) override {
            if (isFull()) return; // don't add if the bad is full
            contents[bagSize] = item; // are those the same T?
            ++bagSize; // increase size of bag if we do add an item
        }

        bool remove(const T& item) {
            // just return false if we don't even have the item
            if (!contains(item)) return false;
            
            // We need to find the item in the array and remove it
            // basically what we can do is to assign the value of the last item
            // to the value of the item being replaced and decrease the size
            contents[indexOf(item)] = contents[bagSize-1];
            --bagSize; // decrease size of bag if we do remove an item
            return true;
        }

        int size() const {
            return bagSize; // returns the size
        }

        void clear() {
            bagSize = 0; // having size = 0 is the same as having an empty array
            // you disregard any existing information, and new info will replace the old. 
        }

        bool contains(const T& item) const {
            // Loop through the array
            // use ampersand for reference
            for (int i = 0; i < bagSize; ++i) {
                if (contents[i] == item) {
                    return true;
                }
            }
            return false;
        }

        int count(const T& item) const {
            // query the bag and find the count of the amount of items there are
            int num = 0;
            for (int i = 0; i < bagSize; ++i) {
                if (contents[i] == item) { // is this the right comparator?
                    ++num;
                }
            }
            return num;
        }

        bool isEmpty() const {
            if (bagSize <= 0) return true;
            return false;
        }

        bool isFull() const {
            if (bagSize >= 20) return true; 
            return false;
        }

        void print() const {
            // iterate thru array and cout everything
            cout << "\n[";
            for (int i = 0; i < bagSize-1; ++i) {
                cout << contents[i] << ", ";
            }
            cout << contents[bagSize-1] << "]"; // make this method repeatable
        }


};