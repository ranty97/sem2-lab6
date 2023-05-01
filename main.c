#include "list.h"
#include "input.h"
#include "numbers.h"

int main() {
    int c;
    int num;
    list *first = initList(malloc(sizeof(list)));

    do {
        system("cls");
        c = inputNaturalRange(0, 2, "Fill list?\n"
                                    "[1] Yes\n"
                                    "[2] No\n"
                                    "[0] Exit\n");
        switch (c) {
            case 1:
                system("cls");
                num = inputNatural("Number: ");
                push(first, num);
                break;
            case 2:
                break;
            case 0:
                rewind(stdin);
                getchar();
                exit(666);
            default:
                printf("Something wrong");
                break;
        }
    } while (c != 2);

    printf("Resulting list: ");
    visitList(first, printVisitor, NULL);

    list *prime = initList(malloc(sizeof(list)));
    list *even = initList(malloc(sizeof(list)));
    list *odd = initList(malloc(sizeof(list)));

//    visitList(first, visitSimple, &simpleNumbers);
    eraseFromToPrime1(first, prime, even, odd);

    if(empty(prime)){
        printf("There are no such audiences.\n");
        rewind(stdin);
        getchar();
        exit(0);
    }

    printf("\nFirst list: ");
    if(!empty(first)){visitList(first, printVisitor, NULL);}
    printf("\nList of primes: ");
    visitList(prime, printVisitor, NULL);
    printf("\nList of even:   ");
    visitList(even, printVisitor, NULL);
    printf("\nList of odd:    ");
    visitList(odd, printVisitor, NULL);
    rewind(stdin);
    getchar();
}
