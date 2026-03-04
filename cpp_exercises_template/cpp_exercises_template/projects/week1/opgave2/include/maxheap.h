
#include <vector>

class MaxHeap {
    public:
    
    std::vector<int> vector;

    virtual bool isEmpty() const = 0;

    virtual int size() = 0;

    virtual void insert(const int x) = 0;

    virtual const int findMax() const = 0;

    virtual int deleteMax() = 0;

};