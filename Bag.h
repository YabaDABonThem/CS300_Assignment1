#ifndef BAG_INTERFACE
#define BAG_INTERFACE


template<class T>
class Bag
{
	public:
		virtual void insert(const T&) = 0;
		virtual bool remove(const T&) = 0;
		virtual int size() const = 0;
		virtual void clear() = 0;
		virtual bool contains(const T&) const = 0;
		virtual int count(const T&) const = 0;
		virtual bool isEmpty() const = 0;
		virtual bool isFull() const = 0;
		virtual void print() const = 0;
};

#endif
