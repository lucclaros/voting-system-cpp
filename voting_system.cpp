#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
class ALUMNO
{
    public:
            ALUMNO (char*);
            ~ALUMNO();
            char NOM[20];
            ALUMNO * SIG;

};
ALUMNO::ALUMNO(char * S)
{
    strcpy(NOM, S);
    SIG = NULL;


}
ALUMNO::~ALUMNO()
{

    cout << "MATANDO A ... " << NOM;
    getchar();
}
class PARTIDO
{
    public :
            PARTIDO (char * , ALUMNO *);
            ~PARTIDO();
            char NOM[20];
            ALUMNO * PALUM; // Puntero a alumno q va al inicio de alumno
            PARTIDO * SIG;
};

PARTIDO::PARTIDO(char * S, ALUMNO * PRESI)
{

    strcpy(NOM, S);
    PALUM = PRESI;

}

PARTIDO::~PARTIDO()
{

    cout << "MATANDO A ... TODOS LOS ALUMNOS ";
    // DEBE DESTRUIR TODOS LOS ALUMNOS Q DEPENDAN DE ESE PARTIDO
    // HACER EL DESTRUCTOR
    getchar();
}

class GUIRNALDA
{
    private:
            PARTIDO * INICIO;
            PARTIDO * BUSCAR(char *);
    public :
        GUIRNALDA();
        ~GUIRNALDA();
        void ARREGLATE(char * );
        void MIRAR();
        int TRUCHO(char *);
};

GUIRNALDA::GUIRNALDA(){
    INICIO = NULL;
}

GUIRNALDA::~GUIRNALDA(){

    cout << "MATANDO A TODOS LOS PARTIDOS";
    getchar();
}
void GUIRNALDA::ARREGLATE(char * S)
{   char * GENERARPARTIDO(); // PROTOTIPO LOCAL

    char BUF[20]; // para guardar el nombre del partido
    ALUMNO * PAL, *P;
    PARTIDO * PPAR;

    PAL = new ALUMNO(S); // llama al constructor de alumno y le manda el char S
    strcpy(BUF, GENERARPARTIDO());
    PPAR = BUSCAR(BUF);

    if(PPAR == NULL/*o if !PPAR*/){
        //PARTIDO NUEVO
        PPAR = new PARTIDO(BUF, PAL); // llama la constructor del partido y lo guarda como en un maloc creo q era
        //lo engancho a la lista de partidos de la guirnalda
        PPAR->SIG = INICIO;
        INICIO = PPAR;
        return;
    }

    //SI ESTA ACA ABAJO ES PORQ NO VOLVIO ARRIBA, OSEA PARTIDO NO ES NUEVO OSEA EXISTENTE.!!
    P = PPAR->PALUM; // P PAUNTA AL PRESIDENTE

    while(P->SIG){
        P = P->SIG; // va al ultimo alumno
    }
    P->SIG = PAL; // y añado el alumno al partido
}
int GUIRNALDA::TRUCHO(char * S)
{
    PARTIDO * PPAR;
    PPAR = INICIO;
    ALUMNO * PAL;
    while(PPAR){
        PAL = PPAR->PALUM;
        while(PAL){
            if((strcmpi(S, PAL->NOM)) == 0){
                return 0;
            }
            PAL = PAL->SIG;
        }
        PPAR = PPAR->SIG;
    }

    return 1;
}



PARTIDO * GUIRNALDA::BUSCAR(char * S)
{
    PARTIDO * PPAR;
    PPAR = INICIO;
    while(PPAR){
        if(strcmpi(PPAR->NOM, S) == 0){ // si encontramos lo qb uscmaos(el partido)
           return PPAR;
        }
        PPAR = PPAR->SIG;
    }
    return NULL;
}

void GUIRNALDA::MIRAR(){
    PARTIDO * PPAR;
    ALUMNO * PAL;

    cout << "\n\n\nCONTENIDO DE LA GURINALDA\n\n\n";
    PPAR = INICIO;

    while(PPAR){
        cout << "\n\n\t\tPARTIDO : " ;
        cout << PPAR->NOM << "\n\n";
        PAL = PPAR->PALUM;
        while(PAL){
            cout << "\n\n\t\t";
            cout << PAL->NOM;
            PAL = PAL->SIG;
        }
        getchar();
        PPAR = PPAR->SIG;
    }

    return;

}


char * GENERARPARTIDO();
char * GENERARNOM();

int main(){
    GUIRNALDA G;
    char BUF[20];

    srand(65);

    strcpy(BUF, GENERARNOM());
    while(strcmp(BUF, "FIN")){
       if(! G.TRUCHO(BUF)){//osea si retorna 1 creo, si se repite el nombre
            cout << "\n\n" << BUF << " VOTO MAS DE DOS VECES, SOLO CUENTA EL PRIMER VOTO...\n";
       }
        //podria hacer como un while mientras no llegue a buf, y ir comparando todos y si lo encuentro es la 2da vez q vota o algo asi
        // retorna 1 si ya votó
        else{
            G.ARREGLATE(BUF);
        }
        strcpy(BUF, GENERARNOM());
    }
    G.MIRAR();


    // tengo qhacer essto G.GANADOR();
    printf("\n\n\n");
    return 0;

}


char * GENERARNOM(){

    static int I = 0;
    static char NOM[][20] = {"DARIO", "CAROLINA", "PEPE", "LOLA",
                            "PACO", "LUIS", "MARIA", "ANSELMO",
                            "ANA", "LAURA","PEDRO","ANIBAL",
                            "PABLO","ROMUALDO","ALICIA","MARTA",
                            "MARTIN","TOBIAS","SAUL","LORENA", "LUIS",
                            "ANDRES","KEVIN","LUCRECIA","RAUL",
                            "ENZO","BETO","HERMINDO","FELIPE",
                            "GUILLERMO","TATO","KARINA","AQUILES",
                            "MINERVA","OLGA","LALO","TATIANA",
                            "LILO","STITCH","EMA","THELMA", "ALICIA",
                            "LOUISE","BONNIE","CLYDE","ROMEO",
                            "JULIETA","VERONICA","JORGE","ALEJANDRO",
                            "ROCIO","FIN"};
    return NOM[I++];
}


char * GENERARPARTIDO(){

    static char NOM[][20] = {"ARRIBA", "ABAJO", "ATRAS", "ADELANTE",
                            "IZQUIERDA", "DERECHA", "CENTRO"};
    return NOM[rand()%7];
}
