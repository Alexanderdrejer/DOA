# Summer 2024

# Har kun svaret på spørgsmål 2 per 23/2 2026.

## Question 1
Consider the following data structure and algorithm:
```cpp 
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* search(Node* root, int key) {
    while (root != nullptr) {
        if (root->val == key) {
            return root;
        }
        else if (key < root->val) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return nullptr;
}
```

Nodes are connected to other nodes as either left or right node.

Provide an answer to each the following:

### 1. Is search a recursive or an iterative function? Explain why.
An iterative function since there is no recursive calls AKA no self-calls. The function does not call itself at any point.


### 2. Argue what the worst-case time complexity (Big-O) of search is?
The worst case is O(n). 
// BEDRE BEGRUNDELSE HER. Har ikke fået undervisning i BST endnu (4/3).

### 3. Describe the worse case scenarios for the complexity proposed above


## Question 2

Consider the following hashing function:

```cpp 
unsigned long hash(const std::string& str) {
unsigned long hash = 5381;

    for (char c : str) {
        hash = (hash * 33) + c;
        }
    return hash;
}
```

The value of the variable c of type char is the ascii value of the letter.

This function is used in the insertion of values into an hash table with linear probing of size N = 7:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **State** | E | O | E | E | D | O | E |

The state of each index is indicated by the letters:

    E: Empty

    O: Occupied (already filled)

    D: Deleted (previously used)

### 1. Show the steps to insert the string "go" into the hash map using the hashing function hash. Do not resize the table.

Hash får ny værdi for hver kan algoritmen har haft en char igennem. Derfor:

    g = 103
    o = 111

hash = ((5381*33) + 103) = 177676

Hash har fået ny værdi, så:

((177676*33) + 111) = 5863419 % 7 = [2].

'go' ligger altså på indeks 2 og tabellen bliver nu:

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **State** | E | O | O | E | D | O | E |

###  2. Show the steps to insert the string "ben" into the hash map using the hashing function hash. Do not resize the table.

Jeg gør tilsvarende procedure som i forrige spørgsmål:

b = 98

e = 101

n = 110

((5381*33) + 98) = 177671
((177617*33) + 101) = 5861462
((5861462*33) + 110) = 193428356
193428356 % 7 = 2.

ben skal altså indsættes på [2]. Den er optaget, så med linear probing går jeg frem i indekset indtil der findes en tom plads. Det gør der først på [4]. Da jeg indsætter, ses pladsen som tom og jeg kan indsætte ben her. Ved søgning ville jeg have været nødt til at lægge ben på indeks 6, da pladsen ville være anset som værende optaget.

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **State** | E | O | O | E | D | O | O |

### 3. Is it possible that the string "adam" is stored in the hash table? Explain why or why not and which steps are needed to provide an exact answer.

Først alle ascii-værdier.

    a = 97

    d = 100

    a = 97

    m = 109

Så igennem hashfunktionen.

((5381*33) + 97) = 177670

((177670*33)+ 100 ) = 5863210

((5863210*33) + 97) = 193486027

((193486027*33) + 109) = 6385039000

6385039000 % 7 = [4]

Vi antager et scenarie hvor indeks 4 først har været tomt. I så fald kunne adam have ligget der og så være blevet slettet. 

I et andet scenarie, lå der noget på indeks 4, da adam skulle indsættes. I så fald opstod der kollision, så adam blev rykket frem i listen og ligger på indeks 5 som har været optaget helt fra start. adam kan altså være til stede på listen. Skulle vi med sikkerhed vide om adam lå der, skulle vi sammenligne værdien på indeks 5 med 'adam'. Er det ikke adam på indeks 5, stoppede søgningen her, da indeks 6 er tom. 