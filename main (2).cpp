#include <iostream>

using namespace std;

class A {
    private:
        int talaA;
        int talaB;
    public:
        A(): talaA(0),  talaB(0) {}
        A(int a, int b) : talaA(a), talaB(b) {}
        int getA() { return talaA; }
        int getB() { return talaB; }
        virtual void prentaTolur() {}
};

class B : public A {
    public:
        B(): A() {}
        B(int a, int b) : A(a, b) {}
        void prentaTolur() {
            cout << "B klasi, a: " << this->getA() <<  " b: " << this->getB() << endl;
        }
};

class C : public A {
    private:
        int talaC;
    public:
        C(): A() {
            talaC = 0;
        }
        C(int a, int b, int c) : A(a, b) {
            talaC = c;
        }
        void prentaTolur() {
            cout << "C klasi, a: " << this->getA() <<  " b: " << this->getB() << " c: " << talaC << endl;
        }
};

class AListi {
    private:
        A **listi; // ATH. verður pointer á pointera
        int staerd;
        int naesta_lausa;
    public:
        AListi() {
            staerd = 2;
            listi = new A*[staerd]; //ATH. fylki af pointerum
            naesta_lausa = 0;
        }
        void setjaIlista(A *stak) {
            if(naesta_lausa < staerd) {
                listi[naesta_lausa++] = stak;
            } else {
                A** tempListi = new A*[staerd * 2];
                for(int i = 0; i < staerd; i++) {
                    tempListi[i] = listi[i];
                }

                delete [] listi;
                listi = tempListi;
                staerd *= 2;
                listi[naesta_lausa++] = stak;
            }
        }
        void synaLista() {
            for(int i = 0; i < staerd; i++) {
                listi[i]->prentaTolur();
            }
        }
};

int main() {
    AListi l;
    l.setjaIlista(new B(1, 2));
    l.setjaIlista(new C(1, 2, 3));
    l.setjaIlista(new B(3, 4));
    l.setjaIlista(new C(4, 5, 6));

    l.synaLista();

    /* 
    Skrifar út:
    B klasi, a: 1 b: 2
    C klasi, a: 1 b: 2 c: 3
    B klasi, a: 3 b: 4
    C klasi, a: 4 b: 5 c: 6
    */

    return 0;
}
