#include "maxheap.h"

class implementation : public MaxHeap {
    public: 

    bool isEmpty() const override;

    int size() override;

    void insert(const int x) override;

    const int findMax() const override;

    int deleteMax() override;

};