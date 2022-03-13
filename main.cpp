#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Term {
    int coefficient = 0;
    int degree{};
    Term *next = nullptr;
};

Term *polynomialConstructor(int n);

void polynomialInput(Term *Polynomial);

Term *polynomialAddition(Term *A, Term *B);

void displayPolynomial(Term *Polynomial);

void deletePolynomial(Term *A);

int main() {
    int m, n;
    cout << "Please enter the degree of your polynomial 1 : " << endl;
    cin >> m;
    Term *A = polynomialConstructor(m);
    polynomialInput(A);
    cout << "Please enter the degree of your polynomial 2 : " << endl;
    cin >> n;
    Term *B = polynomialConstructor(n);
    polynomialInput(B);

    Term *C = polynomialAddition(A, B);
    displayPolynomial(C);

    deletePolynomial(A);
    deletePolynomial(B);
    deletePolynomial(C);

}

Term *polynomialConstructor(int n) {
    Term *Polynomial = new Term;
    Term *ptr = Polynomial;
    int n_temp = n;

    while (n_temp--) {
        cout << "OK" << endl;
        Term *term = new Term;
        ptr->next = term;
    }
    return Polynomial;
}

void polynomialInput(Term *Polynomial) {
    Term *ptr = Polynomial;
    int num;
    char ch;
    do {
        cout << "Please enter a degree of a term: " << endl;
        if (cin >> num && cin.get() == '\n') {
            if (0 <= num && num <= Polynomial->degree) {
                ptr = ptr + num;
                cout << "Please enter the matching coefficient of this term: " << endl;
                cin >> ptr->coefficient;
            } else {
                cout << "Your input can NOT exceed the degree of your polynomial, try again!" << endl;
                cin.clear();
                cin.ignore(INT8_MAX, '\n');
                continue;
            }
        }
        cout << "Do you want to continue inputting?(Y/N)" << endl;
        if (cin >> ch && cin.get() == '\n') {
            if (ch == 'n' || ch == 'N')
                break;
        }
    } while (true);
    displayPolynomial(Polynomial);
}

Term *polynomialAddition(Term *A, Term *B) {
    int i = 0;
    int lower_degree = (A->degree >= B->degree) ? B->degree : A->degree;
    Term *result_polynomial = polynomialConstructor(lower_degree);
    Term *ptr = result_polynomial->next;
    while (i <= lower_degree) {
        (ptr + i)->coefficient = (A + i)->coefficient + (B + i)->coefficient;
        i++;
    }
    if (A + i)
        (ptr + i)->next = A + i;
    else
        (ptr + i)->next = B + i;

}

void displayPolynomial(Term *Polynomial) {
    Term *ptr = Polynomial->next;
    cout << "This is a polynomial with the Highest degree = " << Polynomial->degree << " :" << endl;
    while (ptr->next) {
        if (ptr->coefficient != 0)
            cout << " + " << ptr->coefficient << "x^" << ptr->degree;
        ptr = ptr->next;
    }
}

void deletePolynomial(Term *A) {
    if (A == nullptr)
        return;
    else {
        Term *ptr1 = A->next;
        Term *ptr2;
        delete A;
        while (ptr1) {
            ptr2 = ptr1->next;
            delete ptr1;
            ptr1 = ptr2;
        }
    }

}