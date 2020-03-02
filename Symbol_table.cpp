#include<bits/stdc++.h>
using namespace std;
// It has been seen if chain length is < 50 then some space is underutilized,
// Theoretically seen if > 50, prime number is taken then chain takes moderate space.
// So thats why 25 is used.
#define CHAIN_LENGTH 25
#define M 128
// Two columns of the symbol table with name and class type.
struct symbol_info{
    char *name;
    char *classtype;
    struct symbol_info *next;
} *block[CHAIN_LENGTH];
// Hashing position is calculated using sum of all character ascii values
// Then performing Modulo operation to go to any bucket from 0 to CHAIN_LENGTH
int cHash(char* name){
    int idx = 0;
    for(int i = 0; name[i]; ++i){
        idx = idx + name[i];
    }
    return (idx % CHAIN_LENGTH);
}
// If there is no element in the chain then new element is added in front,
// otherwise through hashing if we reach a chain or, bucket that contains an
// element then we insert the new element at the beginning of the chain and
// the rest of the elements is lniked to the end of new node.
void cInsert(char* name, char* classtype){
    int pos = cHash(name);

    if( block[pos] == NULL ){
        block[pos] = new symbol_info();
        block[pos]->name = name;
        block[pos]->classtype = classtype;
        block[pos]->next = NULL;
    }
    else{
        symbol_info* newNode = new symbol_info();
        newNode->name = name;
        newNode->classtype = classtype;

        // pointer swap
        symbol_info* nextNode = block[pos];
        block[pos] = newNode;
        newNode->next = nextNode;
    }
}
// Print the symbol table chain wise.
void showSymbolTable(){
    // Implement
    for(int i = 0; i < CHAIN_LENGTH; ++i){
        printf("%d:", i);

        // Do not modify the head
        symbol_info* temp = block[i];

        while( temp != NULL ){
            printf("->[%s|%s]", temp->name, temp->classtype);
            temp = temp->next;
        }

        printf("\n");
    }
}


int showMenu(){
    cout << "Menu:\n";
    cout << "=====\n";

    string message = "Enter 1 to insert(name, class type)\n"
                     "Enter 2 to show the symbol table\n";

    cout << message << "\n";


    cout << "User Choice: ";
    int choice;
    scanf("%d", &choice);


    return choice;
}


int main(){
    int choice = showMenu();
    while( 1 ){

        char *name = new char[M];
        char *classtype = new char[M];

        switch(choice){
        case 1:
            {
                cout << "Insert Selected:\n";
                scanf("%s%s", name, classtype);

                // Omit the comma character
                int pos = strlen(name) - 1;
                if( name[ pos ] == ',' ){
                    name[ pos ] = '\0';
                }

                printf("%s %s\n", name, classtype);
                printf("%d\n", cHash(name) );
                cInsert(name, classtype);
            }
            break;
        case 2:
            cout << "Show Selected\n";
            showSymbolTable();
            break;
        default:
            return 0;
        };

        choice = showMenu();
    }



    return 0;
}
