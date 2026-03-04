#ifndef _STACK_H_
#define _STACK_H_

template <typename Object>
class Stack {
  private:
    Object *array;
    int capacity;
    int topIndex;

    void doubleCapacity() {
        Object *oldArray = array; // gemmer adressen på mit gamle array, så vi ved hvor det findes på heapen.
        int oldCapacity = capacity; // Laver en variabel der gemmer den nuværende kapacitet.
        capacity *= 2; // fordobler det gamle arrays kapacitet
        array = new Object[capacity]; // Tildeler nu en sammenhængende blok af hukommelse hvor objekterne gemmes som det ville i et array.
        for (int i = 0; i < oldCapacity; i++) { // det gamle arrays kapacitet igennem og tildeler hvert indeks på det nye arary, indholdet på det gmale.
            array[i] = oldArray[i];
        }
        delete[] oldArray; // sletter det gamle. 
    }

  public:
    Stack() {
        capacity = 100;
        array = new Object[capacity];
        topIndex = -1;
    }

    Stack(int size) {
        capacity = size;
        array = new Object[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] array;
    }

    bool empty() const {
        return topIndex == -1;
    }

    Object top() const {
        return array[topIndex];
    }

    Object pop() {
        return array[topIndex--]; // Konstant tid, da jeg går direkte hen til et indeks og dekrementerer.
    }

    void push(const Object x) {
        if (topIndex == capacity - 1) {
            doubleCapacity();
        } // Worst case er O(n), hvis listen er fyldt, da vi så skal løbe hele listen igennem igen.
        array[++topIndex] = x; // Alternativt O(1), da jeg bare lægger det nye objekt direkte ind. Hvis vi lagde ind på første plads
		// blev det bøvlet, da vi så skulle rykke alle elementer. Ain't nobody got time fo' dat.
    }
};

#endif
