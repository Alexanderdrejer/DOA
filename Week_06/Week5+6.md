# (1) Week 5.
## Implement a recursive algorithms that given an array A of N elements will: 
    a. search for a given element x in A and if x is found, return true, otherwise false.

    b. find the maximum and minimum of elements in A.


```cpp
bool search(int a[], int size, int tal) {


    if (size == 0) {
        return false;
    } 
    
    else if (a[size - 1] == tal) { 
        return true;
    }

    else {
        return search(a, size - 1, tal); 
    }
}
```

### Redegørelse for opgavebesvarelse:

Worst case time complexity er O(n) da hele listen løbes igennem hver gang. Er base-casen ikke nået, tjek fra [size - 1] om tallet er der.

Hvis hverken base-case eller tallet er fundet, kald igen.
Antag funktionen er kaldt én gang: Anden gang kommer der en ny stackframe på, som kigger fra size - 1, altså 9. Næste gang size - 1 igen, så 8 osv.