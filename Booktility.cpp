#include <iostream>
#include <cstring>

using namespace std;

class carte {
    char *denumire, *autorPrincipal, *autorSecundar;
    unsigned int pagini;
    float pret, rating;
public:
    carte();

    carte(carte &c);

    ~carte();

    void operator<<(carte &c);

    void operator>>(carte &c);

    carte operator=(carte &c);

    bool operator>(carte &c);

    bool operator>=(carte &c);

    bool operator<(carte &c);

    bool operator<=(carte &c);

    void setDenumire(char *denumire);

    char *getDenumire();

    void setAutorPrincipal(char *autorPrincipal);

    char *getAutorPrincipal();

    void setAutorSecundar(char *autorSecundar);

    char *getAutorSecundar();

    void setPagini(unsigned int pagini);

    unsigned int getPagini();

    void setPret(float pret);

    float getPret();

    void setRating(float rating);

    float getRating();
};

carte::carte() {
    denumire = new char[100];
    autorPrincipal = new char[50];
    autorSecundar = new char[50];
    pret = 0;
    pagini = 0;
    rating = 0;
}

carte::carte(carte &c) {
    strcpy(denumire, c.denumire);
    strcpy(autorPrincipal, c.autorPrincipal);
    strcpy(autorSecundar, c.autorSecundar);
    pagini = c.pagini;
    pret = c.pret;
    rating = c.rating;
}

carte::~carte() {
    delete[]denumire;
    delete[]autorPrincipal;
    delete[]autorSecundar;
}

//void carte::operator>>(istream &in, const carte &c) {
//    cin.getline(denumire, 100);
//    cin.getline(autorPrincipal, 50);
//    cin.getline(autorSecundar, 50);
//    cin>>pagini>>pret>>rating;
//}

carte carte::operator=(carte& c){
    strcpy(denumire, c.denumire);
    strcpy(autorPrincipal, c.autorPrincipal);
    strcpy(autorSecundar, c.autorSecundar);
    pagini = c.pagini;
    pret = c.pret;
    rating = c.rating;
}

void carte::setDenumire(char *denumire) {
    strcpy(this->denumire, denumire);
}

char *carte::getDenumire() { return denumire;}

void carte::setAutorPrincipal(char *autorPrincipal) {
    strcpy(this->autorPrincipal, autorPrincipal);
}

char*carte::getAutorPrincipal() {return autorPrincipal;}

void carte::setAutorSecundar(char *autorSecundar) {
    strcpy(this->autorSecundar, autorSecundar);
}

char*carte::getAutorSecundar() {return autorSecundar;}

void carte::setPagini(unsigned int pagini) {this->pagini=pagini;}

unsigned int carte::getPagini() {return pagini;}

void carte::setPret(float pret) {
    if (pret<0) {
        cout << "Value error: Price cannot be a negative number.";
        return;
    }
    this->pret=pret;
}

float carte::getPret(){return pret;}

void carte::setRating(float rating){
    if (rating>10 or rating<0){
        cout<<"Value error: Rating must be between 0.00 and 10.00";
        return;
    }

    this->rating=rating;
}

float carte::getRating() {return rating;}


int main() {
    carte books[100];
    int n;

//    array reading and welcome message
    cout<<"Welcome to Booktility v1.0 !\n..........LOADING...........\n\n";
    cout<<"Enter the number of books you wish to input: "; cin>>n;
    cout<<"\nEnter a list of books in the following format: \n";
    cout<<"BookName       MainAuthor      SecondAuthor      NumberOfPages       Price       GoodReadsRating\n\n";

    for (int i=0; i<n; i++) {
        cout<<"Enter book number "<<i<<":\n";
        cin>>books[i];
    }
//abort and  quit
    cout<<"\nBooktility employs the following functions:\n";
    cout<<"1) compare two books\n";
    cout<<"2) modify book\n";
    cout<<"3) print all stored books\n\n";
    cout<<"Instruction manual:\n";
    cout<<"- menus can be accessed by their number ID, given as plain numbers to the keyboard, following the appropriate message\n";
    cout<<"- to abort current function-menu, type \"abort\"\n";
    cout<<"- to quit the program, type \"quit\"\n";
    cout<<"- books can only be identified by their order number in the list\n\n";

//    TEST AREA
//    char test[] = "test";
//    c2.setDenumire("test"); c2.setAutorPrincipal("test"); c2.setAutorSecundar("test"); c2.setPagini(10); c2.setPret(10); c2.setRating(4.7);
//    c1=c2;
//    cout << c1.getDenumire()<<" "<<c1.getAutorPrincipal()<< " "<<c1.getAutorSecundar()<<" "<<c1.getPagini()<<" "<<c1.getPret()<<" "<<c1.getRating();

    return 0;
}