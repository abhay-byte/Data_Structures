#include <stdio.h>
//#include <conio.h>
struct Term {
    int coefficient;
    int exponent;
};
void inputPolynomial(struct Term poly[]) {
    printf("Enter the number of terms: ");
    int num;
    scanf("%d", &num);
    printf("Enter the coefficients and exponents:\n");
    for (int i = 0; i < num; i++) {
        printf("Term %d: Coefficient = ", i + 1);
        scanf("%d", &poly[i].coefficient);
        printf("Term %d: Exponent = ", i + 1);
        scanf("%d", &poly[i].exponent);
    }
    poly[num].exponent = -1;
}
void addPolynomials(struct Term p1[], struct Term p2[], struct Term res[]) {
    int i = 0, j = 0, k = 0;
    while (p1[i].exponent != -1 && p2[j].exponent != -1) {
        if (p1[i].exponent > p2[j].exponent)
            res[k++] = p1[i++];
        else if (p1[i].exponent < p2[j].exponent)
            res[k++] = p2[j++];
        else {
            res[k].exponent = p1[i].exponent;
            res[k++].coefficient = p1[i++].coefficient + p2[j++].coefficient;
        }
    }
    while (p1[i].exponent != -1)
        res[k++] = p1[i++];
    while (p2[j].exponent != -1)
        res[k++] = p2[j++];

    res[k].exponent = -1;
}
void displayPolynomial(struct Term poly[]) {
    for (int i = 0; poly[i].exponent != -1; i++) {
        printf("%dx^%d%s", poly[i].coefficient, poly[i].exponent, poly[i + 1].exponent != -1 ? " + " : "");
    }
    printf("\n");
}
void main() {
    struct Term poly1[30], poly2[30], result[60];

    printf("Enter the first polynomial:\n");
    inputPolynomial(poly1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(poly2);

    addPolynomials(poly1, poly2, result);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);
    //getch();
}
