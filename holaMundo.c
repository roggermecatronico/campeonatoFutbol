#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void cargarEquipos();
void registrarResultado();
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
int numeroMaximoEquipos=12;

int opcionNuevoEquipo;

int registroResultadoEquipo;
    

    
int main() {
    printf("Hola Mundo!\n");

    while (salir <=1)
    {
        printf("El super programa de Rogger\n");
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
            cargarEquipos();
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


// printf("Ingrese una cadena de caracteres: ");
//     fgets(cadena, 100, stdin);
//     printf("La cadena ingresada es: %s\n", cadena);

void cargarEquipos(){

    
    
    if (numeroDeEquipos <2 ){
        minimoDeEquipos();
        codigoEquipos();
    }
    
    opcionNuevoEquipo =1;
    while (opcionNuevoEquipo >0)
    {
        printf("Desea agregar un nuevo equipo? Digite el numero\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf("3. Regresar al menú principal\n");
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
    
    
}

void minimoDeEquipos(){
    printf("Ingrese el nombre del equipo #1: ");
    scanf("%s", cadena);
    printf("El equipo ingresado es: %s \n", cadena);
    // if (strlen(cadena) == 0)
    // {
    //     strcpy(cadena, "Barcelona");
    // }
    strcpy(equipos[0],cadena);
    printf(equipos[0]);
    printf("\n");

    printf("Ingrese el nombre del equipo #2: ");
    scanf("%s", cadena);
    printf("El equipo ingresado es: %s \n", cadena);
    strcpy(equipos[1],cadena);
    printf(equipos[1]);
    printf("\n");

    numeroDeEquipos = 2;
}

void crearEquipo(){
    
    printf("Ingrese el nombre del equipo #%d: ", numeroDeEquipos+1);
    scanf("%s", cadena);
    printf("La cadena ingresada es: %s \n", cadena);
    strcpy(equipos[numeroDeEquipos],cadena);
    printf(equipos[numeroDeEquipos]);
    printf("\n");
    numeroDeEquipos += 1;
    codigoEquipos();
    
    
}

void codigoEquipos(){

    struct mixto vector[numeroMaximoEquipos];
    printf("Equipos \n");
    for (int  i = 0; i < numeroDeEquipos; i++)
    {
        vector[i].codigo = i+1;
        strcpy(vector[i].nombreEquipo,equipos[i]);
        printf("%d %s \n", vector[i].codigo, vector[i].nombreEquipo);
    }
    
    // struct mixto vector[numeroMaximoEquipos] = {{1, equipos[0]}, {2, equipos[1]}, {3, equipos[2]}, {4, equipos[3]}, {5, equipos[4]}};
}

void registrarResultado(){
    printf("Ingrese codigo del primer equipo\n");
    scanf("%d", &registroResultadoEquipo);
    // printf("Ha escogido la opcion %d \n", registroResultadoEquipo);
    //tenemos que ingresar un identificador unico de partidos, tenemos que almacenar en una matriz numero de partido, local, goles, visitante, goles
}
void corregirResultado(){}
void mostrarTablaGoles(){}

void mostrarTablaPosiciones(){

    for (int i = 0; i < numeroDeEquipos; i++) {
        printf("%s ", equipos[i]);
        printf("\t");
        for( int j=0; j<numeroDeEquipos ;j++){
            printf("%s ", equipos[j]);
            printf("\t");
        }
        printf("\n");
    }
    
}

void opcionsalir(){}
void ingreseCorrectamente(){}

void menuPrincipal(){};

