#include <stdio.h> //proporciona funciones para entrada/salida estándar
#include <stdlib.h> //proporciona funciones para convertir cadenas de caracteres a números
#include <string.h>


//administrar los resultados de los partidos de un campeonatod e futbol
//de 2 a 10 equipos
//cada equipo tiene 1 nombre y 1 codigo
//1 tabla de goles de todos los equipos , cuantos goles ha hecho cada equipo a los otros equipos
//y 1 tabla de posiciones, el numero de puntos, los partidos jugadosm ganados, empatados, perdidos y goles a favor y en contra para cada equipo

//opciones
//1. Cargar equipos
// 2. resgistrar un resultado
// 3. corregir un resultado
// 4. mostrar table de goles
// 5. mostrar tabla de posiciones
// 6. finalizar

//validar la entrada de datos con funciones

int salir = 1;
int tamanoCadena =75;

char cadena[75];
int opcion;

char equipos[12][75];

struct mixto {
    int codigo;
    char nombreEquipo[75];
};



void cargarEquipos();//inicializando las funcciones

void registrarResultado();
int identificadorUnicoPartidos();//declarar las funciones
void ingresoDatosDelPartido();

void corregirResultado();
void mostrarTablaGoles();
void mostrarTablaPosiciones();
void opcionsalir();
void ingreseCorrectamente();
void minimoDeEquipos();
void crearEquipo();
void menuPrincipal();
void codigoEquipos();

int numeroDeEquipos;
// int numeroMaximoEquipos=12;
struct mixto vector[12];


int opcionNuevoEquipo;

int registroResultadoEquipo;
int partidoNumero=0;
int registroResultadoEquipoA;
int registroResultadoEquipoB;
    

    
int main() {
    printf("Hola Mundo!\n");

    while (salir <=1)
    {
        printf("\nEl super programa de Rogger\n");
        printf("1. Cargar Equipos\n") ;
        printf("2. Registrar un resultado\n");
        printf("3. corregir un resultado\n");
        printf("4. Mostrar tabla de goles\n");
        printf("5. Mostar tabla de posiciones\n");
        printf("6. Finalizar\n");
        printf("Digita el numero de tu opcion ");
        
        scanf("%d", &opcion);
        printf("Ha escogido la opcion %d \n", opcion);

        switch (opcion)
        {
        case 1:
            cargarEquipos(); //llama a la funcion cargar equipos
            break;
        case 2:
            registrarResultado();
            break;
        case 3:
            corregirResultado();
            break;
        case 4:
            mostrarTablaGoles();
            break;
        case 5:
            mostrarTablaPosiciones();
            break;
        case 6:
            opcionsalir();
            salir =2;
            break;

        
        default:
            ingreseCorrectamente();
            break;
        }
    }
    return 0;
}

void cargarEquipos(){//funcion que carga los equipos    
    if (numeroDeEquipos <2 ){
        minimoDeEquipos();
        codigoEquipos();
        //asignar valores por default
    }
    
    opcionNuevoEquipo =1;
    while (opcionNuevoEquipo >0)
    {
        printf("Desea agregar un nuevo equipo? Digite el numero\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf("3. Regresar al menu principal\n");
        scanf("%d", &opcionNuevoEquipo);
        printf("Ha escogido la opcion %d \n", opcionNuevoEquipo);

        switch (opcionNuevoEquipo)
        {
        case 1:
            crearEquipo();
            break;
        case 2:
            opcionNuevoEquipo = 0;
            break;
        case 3:
            opcionNuevoEquipo = 0;
            menuPrincipal();
            break;
        default:
            printf("Por favor ingrese una opcion valida \n");
            
        }
        
        
        
    }
    return;    
}
void minimoDeEquipos(){//esta funcion se ejecuta siempre que el numero de equipos sea menor a 2
    // printf("Ingrese el nombre del equipo #1: ");
    // scanf("%s", cadena);
    // printf("El equipo ingresado es: %s \n", cadena);
    // strcpy(equipos[0],cadena);
    // printf(equipos[0]);
    // printf("\n");
    // printf("Ingrese el nombre del equipo #2: ");
    // scanf("%s", cadena);
    // printf("El equipo ingresado es: %s \n", cadena);
    // strcpy(equipos[1],cadena);
    // printf(equipos[1]);
    // printf("\n");
    crearEquipo();
    crearEquipo();
    //numeroDeEquipos = 2;
    return;
}
void crearEquipo(){ //funcion para crear equipo
    
    printf("Ingrese el nombre del equipo #%d: ", numeroDeEquipos+1);
    scanf("%s", cadena);
    printf("La cadena ingresada es: %s \n", cadena);
    strcpy(equipos[numeroDeEquipos],cadena);
    printf(equipos[numeroDeEquipos]);
    printf("\n");
    numeroDeEquipos += 1;
    codigoEquipos();
    return ;
}
void codigoEquipos(){ //funcion para asignarle un codigo al equipo

    printf("Equipos \n");
    
    for (int  i = 0; i < numeroDeEquipos; i++)
    {
        vector[i].codigo = i+1;
        strcpy(vector[i].nombreEquipo,equipos[i]);//copiamos la informacion dentro del vector
        printf("%d %s \n", vector[i].codigo, vector[i].nombreEquipo);
    }
    return ;
    // struct mixto vector[numeroMaximoEquipos] = {{1, equipos[0]}, {2, equipos[1]}, {3, equipos[2]}, {4, equipos[3]}, {5, equipos[4]}};
}

void registrarResultado(){

    identificadorUnicoPartidos();//declarar las funciones
    ingresoDatosDelPartido(partidoNumero);
    
    
}

int identificadorUnicoPartidos(){
    partidoNumero += 1;
    return partidoNumero;
}
void ingresoDatosDelPartido(int partidoNumeroVar){
    int golesEquipoA =0;
    int golesEquipoB =0;
    printf("El numero de partido ingresado es el N %d \n", partidoNumeroVar);
    printf("Ingrese codigo del primer equipo\n");
    scanf("%d", &registroResultadoEquipoA);
    printf("Ha escogido al equipo %d %s\n", vector[registroResultadoEquipoA - 1 ].codigo, vector[registroResultadoEquipoA - 1 ].nombreEquipo);
    printf("Ingrese codigo del segundo equipo\n");
    scanf("%d", &registroResultadoEquipoB);
    printf("Ha escogido al equipo %d %s\n", vector[registroResultadoEquipoB-1].codigo, vector[registroResultadoEquipoB-1].nombreEquipo);

    printf("Ingrese el numero de goles del  %s\n", vector[registroResultadoEquipoA - 1 ].nombreEquipo);
    scanf("%d", &golesEquipoA);
    printf("Ingrese el numero de goles del  %s\n", vector[registroResultadoEquipoB-1].nombreEquipo);
    scanf("%d", &golesEquipoB);

    printf("El partido N%d ha sido registrado: %s %d vs %d %s\n", partidoNumeroVar, vector[registroResultadoEquipoA - 1 ].nombreEquipo, golesEquipoA, golesEquipoB,  vector[registroResultadoEquipoB-1].nombreEquipo);

    if ((golesEquipoA == 5 && golesEquipoB == 0) || (golesEquipoB == 5 && golesEquipoA == 0)){
        printf("5 a 0 koketa te acuerdas y te duele\n");
    }

    //llamar a una funcion para  crear tablas

}


void corregirResultado(){}
void mostrarTablaGoles(){}

void mostrarTablaPosiciones(){ //mostrar la tabla de posiciones

    for (int i = 0; i < numeroDeEquipos; i++) {
        printf("%s ", equipos[i]);
        printf("\n");
        // for( int j=0; j<numeroDeEquipos ;j++){
        //     printf("%s ", equipos[j]);
        //     printf("\t");
        // }
        // printf("\n");
    }
    
    
}

void opcionsalir(){}
void ingreseCorrectamente(){}

void menuPrincipal(){};

