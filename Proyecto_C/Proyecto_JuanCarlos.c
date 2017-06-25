//  |___________________________________________|
//  | AUTOR : Juan Carlos Villegas Mármol       |
//  | PROYECTO C                                |
//  | Mantenimiento de fabrica de textil        |
//  |___________________________________________|
//  |___________________________________________|


//******************    BIBLIOTECAS     ***************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//_________________________________________________________


//*********************     DEFINIR ARCHIVOS        ********************
#define farticulos "articulos.jc"
#define fpedidos "pedidos.jc"
#define fproveedor "proveedor.jc"



//*****************************************************
//------------- ESTRUCTURA DE ARTICULOS ---------------
typedef struct
{
    //char codigo[12];
    char componente[13];         //Componente del articulo
    char modelo[10];
    int talla;                   //Talla del articulo
    int color;                   //color del articulo
    float consumo;               //consumo del articulo

}articulos;


typedef struct
{
    long int nregistros;
    char blancos[32];

}registroArticulos;


//*****************************************************
//------------- ESTRUCTURA DE PEDIDOS ---------------

typedef struct
{
    char codigo[12];
    char componente[13];        //componente del pedido
    float necesitad_total;     //necesidad total
    float pedido_total;        //cantidad_pedido
    float necesidad_actual;    //pedido pendiente por llegar
    float recibido_total;      //numero de pedido que se ha recibido
    float proceso;             // el numero de pedido en proceso gastado


}pedidos;


typedef struct
{
    long int nregistros;
    char blancos[44];

}registroPedidos;

//*****************************************************
//------------- ESTRUCTURA DE PROVEEDORES ---------------

typedef struct
{
    char codigo[12];         //Codigo del pedido
    char nombre[22];         //Nombre del proveedir
    char telefono[12];       //Telefono del proveedor
    char color[32];          // color que tiene el proveedor
    char pais[30];           //Pais del proveedor
    char provincia[30];      //Provincia del proveedor
    char localidad[30];      //Localidad del proveedor
    char direcccion[30];     //Direccion del proveedor
    char correo[30];         //correo del proveedor
    char componente[16];
}proveedor;


typedef struct
{
    long int nregistros; //mide 4
    char blancos[240];

}registroProveedor;





//**************************************************************
//------------------------- PROTOTIPOS DE FUNCIONES ------------

//articulos

void gestionarticulos();
void comprobar_articulos();              //Comprueba si el fichero esta vacio o no
void altas_articulos();                 //realiza altas de articulos
void listados_articulos();              //lista_articulos
void consultas_articulos();             //consulta por componente y por modelo
void bajas_articulos();                 //realiza las bajas
void modificaciones_articulos();        //modifica
void ordenar_articulos();                //ORDENA POR CODIGO DE PROVEEDOR
void ordenar_nombre_articulos();         // ORDENA POR NOMBRE DEL PROVEEDOR
void MintoMay_articulos(char string[]);  // FUNCION PARA CONVERTIR A MAYUSCULAS


//pedidos

void gestionpedidos();
void comprobar_pedidos();
void altas_pedidos();
void listados_pedidos();
void consultas_pedidos();
void bajas_pedidos();
void modificaciones_pedidos();
void ordenar_pedidos();                //ORDENA POR CODIGO DE PROVEEDOR
void ordenar_nombre_pedidos();         // ORDENA POR NOMBRE DEL PROVEEDOR
void MintoMay_pedidosP(char string[]);  // FUNCION PARA CONVERTIR A MAYUSCULAS


//proveedor

void gestionproveedor();
void comprobar_proveedor();              //Comprueba si el fichero esta vacio o no
void altas_proveedor();
void listados_proveedor();
void consultas_proveedor();
void bajas_proveedor();
void modificaciones_proveedor();
void ordenar_proveedor();                //ORDENA POR CODIGO DE PROVEEDOR
void ordenar_nombre_proveedor();         // ORDENA POR NOMBRE DEL PROVEEDOR
void MintoMay_proveedor(char string[]);  // FUNCION PARA CONVERTIR A MAYUSCULAS



//aplicacion

void aplicacion();
void ver_por_componente();
void conocer_total();       //funcion conocer totales de pedidos
void ver_todo();
void ver_todo_codigo();

//******************* VARIABLES GLOBALES ************************

FILE *ptrArticulos;             //puntero a archivo de articulos
FILE *ptrPedidos;               //puntero a archivo de pedidos
FILE *ptrProveedor;              //puntero a archivo de proveedores

long int n;                    //Numero de registros
long int desplazamiento;       //Desplazamiento

articulos artic1;
registroArticulos regArti;

pedidos pedid1;
registroPedidos regPedid;

proveedor proveedor1;
registroProveedor regProv;




int main()
{
    int seleccion;
    int k;

    //*** Comprobar estructuras
    printf(" Tamano de Articulos => %d \n", sizeof(artic1));
    printf(" Tamano de Registro 0 de articulos => %d \n", sizeof(regArti));

    printf(" Tamano de Pedidos => %d \n", sizeof(pedid1));
    printf(" Tamano de Registro 0 de pedidos => %d \n", sizeof(regPedid));

    printf(" Tamano de Proveedores => %d \n", sizeof(proveedor1));
    printf(" Tamano de Registro 0 de Proveedores => %d \n", sizeof(regProv));

    getch();

    //*** Comprobar ficheros
    comprobar_articulos();
    comprobar_pedidos();
    comprobar_proveedor();

    do{
        system("cls");
        printf("---------------------------------\n");
        printf("-------- FABRICA TEXTIL ---------\n");
        printf("---------------------------------\n");
        printf("| - 1) GESTION DE ARTICULOS     |\n");
        printf("| - 2) GESTION DE PEDIDOS       |\n");
        printf("| - 3) GESTION DE PROVEEDORES   |\n");
        printf("| - 4) APLICACION               |\n");
        printf("| - 0) SALIR                    |\n");
        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA ");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    gestionarticulos();
                    break;
                }
            case 2:
                {
                    gestionpedidos();
                    break;
                }
            case 3:
                {
                    gestionproveedor();
                    break;
                }

            case 4:
                {
                    aplicacion();
                    break;
                }

            default:
                {
                    printf("OPCION INCORRECTA\n");
                    getch();
                }
        }


    }while(1);




}


// FUNCIONES DE ARTICULOS DESARROLLADAS

void gestionarticulos(void)
{
//printf("Tamaño de la estructura de articulos %d \n", sizeof(articulos));
    //printf("Tamaño de la estructura de registroArticulos %d \n", sizeof(primer_registro));
    int seleccion;
    int k;
    //comprobar_articulos();

    do{
        system("cls");
        printf("-------------------------------------\n");
        printf("---------- GESTION DE ARTICULOS -----\n");
        printf("-------------------------------------\n");
        printf("| - 1) INSERTAR UN ARTICULO NUEVO   |\n");
        printf("| - 2) VER TODOS LOS ARTICULOS      |\n");
        printf("| - 3) BUSCAR ARTICULOS             |\n");
        printf("| - 4) ELIMINAR ARTICULO            |\n");
        printf("| - 5) MODIFICAR ARTICULO           |\n");
        printf("| - 0) SALIR                        |\n");

        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    altas_articulos();
                    break;
                }
            case 2:
                {
                    ordenar_articulos();      //ORDENO POR COMPONENTE DE ARTICULO
                    listados_articulos();
                    break;
                }
            case 3:
                {
                    consultas_articulos();
                    break;
                }
            case 4:
                {
                    bajas_articulos();
                    break;
                }
            case 5:
                {
                    modificaciones_articulos();
                    break;
                }
            default:
                {
                    printf("Opcion incorrecta\n");
                    getch();
                }
        }


    }while(1);
}






//******** FUNCION DE COMPROBAR FICHERO ********

void comprobar_articulos()
{
    int k;
    ptrArticulos = fopen(farticulos, "rb");
    if(ptrArticulos==NULL)
    {
        printf("NO HAY NINGUN ARCHIVO \n");
        getch();
        system("cls");
        ptrArticulos=fopen(farticulos,"w+b");
        printf("ARCHIVO CREADO DE ARTICULOS\n");
        getch();
        fseek(ptrArticulos, 0L, 0);
        regArti.nregistros = 0L;
        for(k=0;k<=32;k++)
        {
            regArti.blancos[k] =' ';
        }
        fwrite(&regArti, sizeof(regArti), 1, ptrArticulos);
    }
    fclose(ptrArticulos);
}




//******** ALTAS ARTICULOS ********

void altas_articulos()
{
    int k;

    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos, 0L, 0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);

    n= regArti.nregistros;

    do{
        n= n+1;
        system("cls");

        printf("INTRODICE LA COMPONENTE DEL ARTICULO => ");
        fflush(stdin);
        gets(artic1.componente);
        MintoMay_articulos(artic1.componente);

        printf("INTRODUCE EL MODELO DEL ARTICULO => ");
        fflush(stdin);
        gets(artic1.modelo);
        MintoMay_articulos(artic1.modelo);

        printf("INTRODUCE LA TALLA DEL ARTICULO=> ");
        fflush(stdin);
        scanf("%d", &artic1.talla);


        printf("INTRODUCE EL COLOR DEL ARTICULO => ");
        fflush(stdin);
        scanf("%d", &artic1.color);

        printf("INTRODUCE EL CONSUMO DEL ARTICULO => ");
        fflush(stdin);
        scanf("%f", &artic1.consumo);




        desplazamiento =n *sizeof(artic1);
        fseek(ptrArticulos, desplazamiento, 0);
        fwrite(&artic1, sizeof(artic1), 1, ptrArticulos);

        printf("Articulo registrado\n");


        printf("DESEA ANIADIR MAS ARTICULOS?(s/n)=> ");
        fflush(stdin);

    }while(getchar()=='s'||getchar()=='S');

    fseek(ptrArticulos,0L,0);
    regArti.nregistros = n;
    for(k=0;k<32;k++)
    {
        regArti.blancos[k]=' ';
    }
    fwrite(&regArti, sizeof(regArti), 1, ptrArticulos);
    fclose(ptrArticulos);
}


//******** FUNCION LISTADOS DE PROVEEDOR ********
void listados_articulos()
{

    int i;

    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos, 0L, 0);
    fread(&regArti, sizeof(regArti), 1,ptrArticulos);

    n = regArti.nregistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(artic1);
        fseek(ptrArticulos, desplazamiento, 0);
        fread(&artic1, sizeof(artic1), 1, ptrArticulos);
        if(strncmp(artic1.componente,"#####", 5)==0){
            continue;
        }
        else{


            system("cls");


            printf("ARTICULO ======================> %d\n", i);
            printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
            printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
            printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
            printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
            printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);


            getch();
        }
    }

    fclose(ptrArticulos);

}


//******** FUNCION DE CONSULTAS ARTICULOS ********
void consultas_articulos(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    long int inicio, fin;
    char buscar[20];


    articulos artic1;
    registroArticulos regArti;
    FILE *ptrArticulos;
    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) COMPONENTE DEL ARTICULO\n");
        printf("2) MODELO DEL ARTICULO\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar_articulos();
                    do{
                        system("cls");
                        fflush(stdin);

                        printf("INTRODUCE LA COMPONENTE DEL ARTICULO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_articulos(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;   //0
                        der =n; //n-1
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);
                            if(strncmp(buscar,artic1.componente,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,artic1.componente, longitud)==0)
                                {
                                    inicio=cen;

                                    for(i=cen;i>0;i--)   //i>=-1
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            inicio = i+1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==1)
                                        {
                                            inicio = i;
                                        }
                                    }
                                    fin = cen;

                                    //printf("fin %ld\n", fin); // coge valor uno

                                    for(i=cen;i<=n;i++)
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            fin = i-1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==n)
                                        {
                                            fin = i;
                                        }
                                    }
                                    //printf("inicio= %d, fin= %d",inicio, fin);getch();
                                    for(i=inicio;i<=fin;i++)
                                    {
                                            desplazamiento = i*sizeof(artic1);
                                            fseek(ptrArticulos, desplazamiento, 0);  // ERROR IMPORTANTE
                                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);


                                                printf("ARTICULO ======================> %d\n", i);
                                                printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                                printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                                printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                                printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                                printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                                printf("\n");

                                                getch();

                                    }

                                }
                                else
                                {

                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,artic1.componente,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen+1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(buscar != 0);
                    break;

                }

                 case 2:
                    {
                    ordenar_nombre_articulos();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("INTRODUCE EL MODELO  DEL ARTICULO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_articulos(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;   //0
                        der =n; //n-1
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);
                            if(strncmp(buscar,artic1.modelo,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,artic1.modelo, longitud)==0)
                                {
                                    inicio=cen;

                                    for(i=cen;i>0;i--)   //i>=-1
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.modelo, longitud)!=0)
                                        {
                                            inicio = i+1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.modelo, longitud)==0 && i==1)
                                        {
                                            inicio = i;
                                        }
                                    }
                                    fin = cen;

                                    //printf("fin %ld\n", fin); // coge valor uno

                                    for(i=cen;i<=n;i++)
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.modelo, longitud)!=0)
                                        {
                                            fin = i-1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.modelo, longitud)==0 && i==n)
                                        {
                                            fin = i;
                                        }
                                    }
                                    //printf("inicio= %d, fin= %d",inicio, fin);getch();
                                    for(i=inicio;i<=fin;i++)
                                    {
                                            desplazamiento = i*sizeof(artic1);
                                            fseek(ptrArticulos, desplazamiento, 0);  // ERROR IMPORTANTE
                                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                                printf("ARTICULO ======================> %d\n", i);
                                                printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                                printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                                printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                                printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                                printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                                printf("\n");

                                                getch();

                                    }

                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,artic1.modelo,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen+1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(buscar != 0);
                    break;

                }
            default:
                {
                    printf("OPCION INCORRECTA\n");
                    break;
                }
        }
    }

}



//FUNCION BAJAS CORRECTAMENTE

void bajas_articulos(void)
{
    int k;
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    long int inicio, fin;
    char buscar[20];
    char respuesta;

    articulos artic1;
    registroArticulos regArti;
    FILE *ptrArticulos;
    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;

    ordenar_articulos();        //ORDENO POR COMPONENTE PARA QUE FUNCIONE LA BUSQUEDA DICOTOMICA
    do{
                        system("cls");
                        fflush(stdin);

                        printf("INTRODUCE LA COMPONENTE DEL ARTICULO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_articulos(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;   //0
                        der =n; //n-1
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);
                            if(strncmp(buscar,artic1.componente,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,artic1.componente, longitud)==0)
                                {
                                    inicio=cen;

                                    for(i=cen;i>0;i--)   //i>=-1
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            inicio = i+1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==1)
                                        {
                                            inicio = i;
                                        }
                                    }
                                    fin = cen;

                                    //printf("fin %ld\n", fin); // coge valor uno

                                    for(i=cen;i<=n;i++)
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            fin = i-1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==n)
                                        {
                                            fin = i;
                                        }
                                    }
                                    //printf("inicio= %d, fin= %d",inicio, fin);getch();
                                    for(i=inicio;i<=fin;i++)
                                    {
                                            desplazamiento = i*sizeof(artic1);
                                            fseek(ptrArticulos, desplazamiento, 0);  // ERROR IMPORTANTE
                                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);


                                            printf("ARTICULO ======================> %d\n", i);
                                            printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                            printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                            printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                            printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                            printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                            printf("\n");

                                            getch();

                                            printf("DESEAS ELIMINAR ESTE ARTICULO? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {



                                                continue;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                strcpy(artic1.componente,"#####");
                                                desplazamiento = n*sizeof(artic1);
                                                fseek(ptrArticulos, desplazamiento, 0);

                                                fwrite(&artic1, sizeof(artic1), 1, ptrArticulos);

                                                n--;

                                                fseek(ptrArticulos, 0L, 0);
                                                regArti.nregistros= n;
                                                for(k=0;k<32;k++)
                                                {
                                                    regArti.blancos[k]=' ';
                                                }
                                                fwrite(&regArti, sizeof(regArti), 1, ptrArticulos);
                                                printf("ARTICULO ELIMINADO");

                                            }



                                    }

                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,artic1.componente,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen+1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(buscar != 0);
    fclose(ptrArticulos);
    ordenar_articulos();      //ORDENO POR COMPONENTE

}


void modificaciones_articulos(void)
{


    int k;
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    long int inicio, fin;
    char buscar[20];
    char respuesta;

    articulos artic1;
    registroArticulos regArti;
    FILE *ptrArticulos;
    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;

    ordenar_articulos();        //ORDENO POR COMPONENTE PARA QUE FUNCIONE LA BUSQUEDA DICOTOMICA
    do{
                        system("cls");
                        fflush(stdin);
                        printf("INTRODUCE LA COMPONENTE DEL ARTICULO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_articulos(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;   //0
                        der =n; //n-1
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);
                            if(strncmp(buscar,artic1.componente,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,artic1.componente, longitud)==0)
                                {
                                    inicio=cen;

                                    for(i=cen;i>0;i--)   //i>=-1
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            inicio = i+1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==1)
                                        {
                                            inicio = i;
                                        }
                                    }
                                    fin = cen;

                                    //printf("fin %ld\n", fin); // coge valor uno

                                    for(i=cen;i<=n;i++)
                                    {
                                        desplazamiento = i*sizeof(artic1);
                                        fseek(ptrArticulos, desplazamiento, 0);
                                        fread(&artic1, sizeof(artic1), 1, ptrArticulos);

                                        if(strncmp(buscar, artic1.componente, longitud)!=0)
                                        {
                                            fin = i-1;
                                            break;
                                        }
                                        if(strncmp(buscar, artic1.componente, longitud)==0 && i==n)
                                        {
                                            fin = i;
                                        }
                                    }
                                    //printf("inicio= %d, fin= %d",inicio, fin);getch();
                                    for(i=inicio;i<=fin;i++)
                                    {
                                            desplazamiento = i*sizeof(artic1);
                                            fseek(ptrArticulos, desplazamiento, 0);  // ERROR IMPORTANTE
                                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);


                                            printf("ARTICULO ======================> %d\n", i);
                                            printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                            printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                            printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                            printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                            printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                            printf("\n");

                                            getch();

                                            printf("DESEAS MODIFICAR ESTE ARTICULO? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {



                                                continue;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                do{
                                                    system("cls");
                                                    //printf("Registro ===============> %ld\n", cen);
                                                    printf("ARTICULO ======================> %d\n", i);
                                                    printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                                    printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                                    printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                                    printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                                    printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                                    printf("\n");


                                                    printf("1) COMPONENTE DEL ARTICULO\n");
                                                    printf("2) MODELO DEL ARTICULO\n");
                                                    printf("3) TALLA DEL ARTICULO\n");
                                                    printf("4) COLOR DEL ARTICULO\n");
                                                    printf("5) CONSUMO DEL ARTICULO\n");
                                                    printf("0) SALIR\n");
                                                    printf("ELIGE UNA OPCION => ");
                                                    fflush(stdin);
                                                    scanf("%d", &seleccion);
                                                    if(seleccion==0)
                                                    {
                                                        break;
                                                    }
                                                    switch(seleccion)
                                                    {
                                                        case 1:
                                                            {
                                                               printf("INTRODUCE EL NUEVO COMPONENTE DEL ARTICULO => ");
                                                               fflush(stdin);
                                                               gets(artic1.componente);
                                                               MintoMay_articulos(artic1.componente);
                                                               break;
                                                            }
                                                        case 2:
                                                            {

                                                                printf("INTRODUCE EL NUEVO MODELO DEL ARTICULO => ");
                                                                fflush(stdin);
                                                                gets(artic1.modelo);
                                                                MintoMay_articulos(artic1.modelo);
                                                                break;
                                                            }
                                                        case 3:
                                                            {
                                                                printf("INTRODUCE LA NUEVA TALLA DEL ARTICULO => ");
                                                                fflush(stdin);
                                                                scanf("%d", &artic1.talla);
                                                                break;
                                                            }
                                                        case 4:
                                                            {
                                                                printf("INTRODUCE EL NUEVO COLOR DEL ARTICULO => ");
                                                                fflush(stdin);
                                                                scanf("%d", &artic1.color);

                                                                break;
                                                            }
                                                        case 5:
                                                            {
                                                                printf("INTRODUCE EL NUEVO CONSUMO DEL ARTICULO => ");
                                                                fflush(stdin);
                                                                scanf("%f", &artic1.consumo);
                                                                break;
                                                            }

                                                        default:

                                                            printf("OPCION INCORRECTA\n");
                                                            getch();
                                                    }

                                                }while(1);
                                                desplazamiento = i*sizeof(artic1);
                                                fseek(ptrArticulos, desplazamiento, 0);
                                                fwrite(&artic1, sizeof(artic1), 1, ptrArticulos);
                                                printf("ARTICULO HA SIDO MODIFICADO\n");
                                                getch();

                                            }



                                    }

                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,artic1.componente,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen+1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(buscar != 0);
    fclose(ptrArticulos);
    ordenar_articulos();      //ORDENO POR COMPONENTE


}

//******** FUNCION ORDENAR ARTICULOS POR COMPONENTE *********
void ordenar_articulos(void)
{

    articulos registro1, registro2;

    long int i, d;
    int sw;


    ptrArticulos = fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrArticulos, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrArticulos);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrArticulos, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrArticulos);

                if(strcmp(registro1.componente, registro2.componente)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrArticulos, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrArticulos);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrArticulos, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrArticulos);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrArticulos);
}

//********* FUNCION ORDENAR ARTICULOS POR MODELO ********
void ordenar_nombre_articulos()
{

    articulos registro1, registro2;

    long int i, d;
    int sw;
    FILE *ptrArticulos;

    ptrArticulos = fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrArticulos, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrArticulos);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrArticulos, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrArticulos);

                if(strcmp(registro1.modelo, registro2.modelo)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrArticulos, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrArticulos);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrArticulos, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrArticulos);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrArticulos);
}




//******** FUNCION DE CONVERTIR A MAYUSCULAS ********
void MintoMay_articulos(char string[])
{
    int i=0;
    int desp='a'-'A';
    for(i=0;string[i]!='\0';++i)
    {
        if(string[i]>='a'&&string[i]<='z')
        {
            string[i]=string[i]-desp;
        }
    }
}


// FIN DE LAS FUNCIONES DE ARTICULOS

//------------------------------------------
//------------------------------------------


// FUNCIONES DE PEDIDOS DESARROLLADAS


void gestionpedidos(void)
{

    int seleccion;
    int k;
    comprobar_pedidos();

    do{

        system("cls");
        printf("-------------------------------------\n");
        printf("---------- GESTION DE PEDIDOS -------\n");
        printf("-------------------------------------\n");
        printf("| - 1) INSERTAR UN PEDIDO NUEVO   |\n");
        printf("| - 2) VER TODOS LOS PEDIDOS      |\n");
        printf("| - 3) BUSCAR PEDIDOS             |\n");
        printf("| - 4) ELIMINAR PEDIDOS           |\n");
        printf("| - 5) MODIFICAR PEDIDOS          |\n");
        printf("| - 0) SALIR                      |\n");

        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    altas_pedidos();
                    break;
                }
            case 2:
                {
                    ordenar_pedidos();      //ORDENO POR COMPONENTE DE pedido
                    listados_pedidos();
                    break;
                }
            case 3:
                {

                    consultas_pedidos();
                    break;
                }
            case 4:
                {
                    bajas_pedidos();
                    break;
                }
            case 5:
                {
                    modificaciones_pedidos();
                    break;
                }
            default:
                {
                    printf("OPCION INCORRECTA\n");
                    getch();
                }
        }


    }while(1);



}

//******** FUNCION DE COMPROBAR FICHERO ********

void comprobar_pedidos()
{
    int k;
    ptrPedidos = fopen(fpedidos, "rb");
    if(ptrPedidos==NULL)
    {
        printf("NO HAY NINGUN ARCHIVO \n");
        getch();
        system("cls");
        ptrPedidos=fopen(fpedidos,"w+b");
        printf("ARCHIVO CREADO PEDIDOS\n");
        getch();
        fseek(ptrPedidos, 0L, 0);
        regPedid.nregistros = 0L;
        for(k=0;k<=44;k++)
        {
            regPedid.blancos[k] =' ';
        }
        fwrite(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    }
    fclose(ptrPedidos);
}


//******** ALTAS PEDIDOS ********

void altas_pedidos(void)
{
    int k;
    pedidos pedid1;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos, 0L, 0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);

    n= regPedid.nregistros;

    do{
        n= n+1;
        system("cls");
        printf("INTRODUCE EL CODIGO DEL PEDIDO => ");
        fflush(stdin);
        gets(pedid1.codigo);
        MintoMay_pedidosP(pedid1.codigo);

        printf("INTRODUCE LA COMPONENTE  => ");
        fflush(stdin);
        gets(pedid1.componente);
        MintoMay_pedidosP(pedid1.componente);

        printf("INTRODUCE EL PEDIDO TOTAL =>");
        fflush(stdin);
        scanf("%f", &pedid1.pedido_total);
        printf("INTRODUCE EL PEDIDO RECIBIDO TOTAL => ");
        fflush(stdin);
        scanf("%f", &pedid1.recibido_total);

        printf("INTRODUCE LA NECESIDAD TOTAL => ");
        fflush(stdin);
        scanf("%f", &pedid1.necesitad_total);

        printf("INTRODUCE LA CANTIDAD EN PROCESO => ");
        fflush(stdin);
        scanf("%f", &pedid1.proceso);

        printf("INTRODUCE LA NECESIDAD ACTUAL => ");
        fflush(stdin);
        scanf("%f", &pedid1.necesidad_actual);






        desplazamiento =n *sizeof(pedid1);
        fseek(ptrPedidos, desplazamiento, 0);
        fwrite(&pedid1, sizeof(pedid1), 1, ptrPedidos);

        printf("PEDIDO REGISTRADO\n");

        printf("DESEA ANIADIR MAS PEDIDOS?(s/n)=> ");
        fflush(stdin);

    }while(getchar()=='s'||getchar()=='S');

    fseek(ptrPedidos,0L,0);
    regPedid.nregistros = n;
    for(k=0;k<44;k++)
    {
        regPedid.blancos[k]=' ';
    }
    fwrite(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    fclose(ptrPedidos);

}

//******** FUNCION LISTADOS DE PEDIDOS ********
void listados_pedidos(void)
{

    int i;

    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos, 0L, 0);
    fread(&regPedid, sizeof(regPedid), 1,ptrPedidos);

    n = regPedid.nregistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(pedid1);
        fseek(ptrPedidos, desplazamiento, 0);
        fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
        if(strncmp(pedid1.componente,"#####", 5)==0){
            continue;
        }
        else{




            system("cls");
            printf("PEDIDO ======================> %d\n", i);
            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);


            getch();
        }
    }

    fclose(ptrPedidos);

}



//FUNCION CONSULTAS PEDIDOS

void consultas_pedidos(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];

    pedidos pedid1;
    registroPedidos regPedid;
    FILE *ptrPedidos;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    n = regPedid.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) CODIGO DEL PEDIDO\n");
        printf("2) NOMBRE DEL COMPONENTE\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar_pedidos();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("INTRODUCE EL CODIGO DEL PEDIDO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_pedidosP(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(pedid1);
                            fseek(ptrPedidos, desplazamiento, 0);
                            fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                            if(strncmp(buscar,pedid1.codigo,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,pedid1.codigo, longitud)==0)
                                {
                                    //printf("PEDIDO ======================> %d\n", i);
                                    printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                    printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                    printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                    printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                    printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                    printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                    printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                    printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                    printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                    printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);

                                    getch();
                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,pedid1.codigo,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }

                 case 2:
                {
                    ordenar_nombre_pedidos();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("INTRODUCE LA COMPONENTE DEL PEDIDO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_pedidosP(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(pedid1);
                            fseek(ptrPedidos, desplazamiento, 0);
                            fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                            if(strncmp(buscar,pedid1.componente,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,pedid1.componente, longitud)==0)
                                {
                                    //printf("PEDIDO ======================> %d\n", i);
                                    printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                    printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                    printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                    printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                    printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                    printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                    printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                    printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                    printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                    printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);

                                    getch();
                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,pedid1.componente,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }

            default:
                {
                    printf("OPCION INCORRECTA\n");
                }
        }
    }

}


//******** FUNCION DE BAJAS PEDIDOS  2º VERSION ********

void bajas_pedidos(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;
    int k;
    pedidos pedid1;
    registroPedidos regPedid;
    FILE *ptrPedidos;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    n = regPedid.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) ELIMINAR POR CODIGO DEL PEDIDO\n");
        printf("2) ELIMINAR POR NOMBRE DEL COMPONENTE\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                     ordenar_pedidos();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("INTRODUCE EL CODIGO DEL PEDIDO QUE DESEAS ELIMINAR (FIN PARA SALIR) => ");
                            scanf("%s", &buscar);
                            MintoMay_pedidosP(buscar);
                            longitud = strlen(buscar);
                            /*for(i=0;i<longitud;i++)
                            {
                                buscar[i]=toupper(buscar[i]);
                            }*/
                            if(strncmp(buscar, "FIN",1)==0)
                            {
                                break;
                            }
                            sw =0;
                            izq =1;
                            der =n;
                                do{
                                    cen=(izq+der)/2;

                                    desplazamiento = cen*sizeof(pedid1);
                                    fseek(ptrPedidos, desplazamiento, 0);
                                    fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                                    if(strncmp(buscar,pedid1.codigo,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedid1.codigo, longitud)==0)
                                        {
                                            //printf("Pedido => %ld\n", cen);


                                            //printf("PEDIDO ======================> %d\n", cen);
                                            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);
                                            getch();

                                            printf("DESEAS ELIMINAR ESTE PEDIDO? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                desplazamiento = n*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                                                desplazamiento = cen*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fwrite(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                                                n = n -1;

                                                fseek(ptrPedidos, 0L, 0);
                                                regPedid.nregistros= n;
                                                for(k=0;k<44;k++)
                                                {
                                                    regPedid.blancos[k]=' ';
                                                }
                                                fwrite(&regPedid, sizeof(regPedid), 1, ptrPedidos);
                                            }
                                            printf("PEDIDO ELIMINADO\n");
                                            getch();
                                        }
                                        else
                                        {
                                            printf("NO ENCONTRADO\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedid1.codigo,longitud)<0)
                                        {
                                            der = cen-1;
                                        }
                                        else
                                        {
                                            izq = cen +1;
                                        }
                                    }
                                    if(sw==1)
                                    {
                                        break;
                                    }
                                }while(1);
                            }while(1);
                                fclose(ptrPedidos);
                                ordenar_pedidos();
                                    break;

                }

            case 2:
                {
                        ordenar_nombre_pedidos();
                        do{
                            system("cls");
                            fflush(stdin);

                            printf("INTRODUCE LA COMPONENTE DEL PEDIDO QUE DESEAS ELIMINAR (FIN PARA SALIR) => ");
                            scanf("%s", &buscar);
                            MintoMay_pedidosP(buscar);
                            longitud = strlen(buscar);
                            /*for(i=0;i<longitud;i++)
                            {
                                buscar[i]=toupper(buscar[i]);
                            }*/
                            if(strncmp(buscar, "FIN",1)==0)
                            {
                                break;
                            }
                            sw =0;
                            izq =1;
                            der =n;
                                do{
                                    cen=(izq+der)/2;

                                    desplazamiento = cen*sizeof(pedid1);
                                    fseek(ptrPedidos, desplazamiento, 0);
                                    fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                                    if(strncmp(buscar,pedid1.componente,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedid1.componente, longitud)==0)
                                        {


                                            //printf("PEDIDO ======================> %d\n", cen);
                                            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);
                                            getch();

                                            printf("DESEAS ELIMINAR ESTE PEDIDO? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                desplazamiento = n*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                                                desplazamiento = cen*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fwrite(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                                                n = n -1;

                                                fseek(ptrPedidos, 0L, 0);
                                                regPedid.nregistros= n;
                                                for(k=0;k<44;k++)
                                                {
                                                    regPedid.blancos[k]=' ';
                                                }
                                                fwrite(&regPedid, sizeof(regPedid), 1, ptrPedidos);
                                            }
                                            printf("PEDIDO ELIMINADO\n");
                                            getch();
                                        }
                                        else
                                        {
                                            printf("NO ENCONTRADO\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedid1.componente,longitud)<0)
                                        {
                                            der = cen-1;
                                        }
                                        else
                                        {
                                            izq = cen +1;
                                        }
                                    }
                                    if(sw==1)
                                    {
                                        break;
                                    }
                                }while(1);
                            }while(1);
                                fclose(ptrPedidos);
                                ordenar_pedidos();
                                    break;





                }


            default:
                {
                    printf("OPCION INCORRECTA\n");
                }
        }
    }



}


//FUNCION MODIFICACIONES VERSION DE MODIFICAR POR CODIGO Y NOMBRE

void modificaciones_pedidos(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;
    int k;
    pedidos pedid1;
    registroPedidos regPedid;
    FILE *ptrPedidos;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    n = regPedid.nregistros;

    while(seleccion!=0)
    {
        system("cls");

        printf("1) MODIFICAR POR CODIGO DEL PEDIDO\n");
        printf("2) MODIFICAR POR NOMBRE DE LA COMPONENTE\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                        ordenar_pedidos();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("INTRODUCE EL CODIGO DEL PEDIDO QUE DESEAS MODIFICAR (FIN PARA SALIR) => ");
                            scanf("%s", &buscar);
                            MintoMay_pedidosP(buscar);
                            longitud = strlen(buscar);
                            /*for(i=0;i<longitud;i++)
                            {
                                buscar[i]=toupper(buscar[i]);
                            }*/
                            if(strncmp(buscar, "FIN",1)==0)
                            {
                                break;
                            }
                            sw =0;
                            izq =1;
                            der =n;
                                do{
                                    cen=(izq+der)/2;

                                    desplazamiento = cen*sizeof(pedid1);
                                    fseek(ptrPedidos, desplazamiento, 0);
                                    fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                                    if(strncmp(buscar,pedid1.codigo,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedid1.codigo, longitud)==0)
                                        {
                                            //printf("Pedido => %ld\n", cen);

                                            //printf("PEDIDO ======================> %d\n", cen);
                                            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);


                                            getch();

                                            printf("DESEAS MODIFICAR ESTE PEDIDO? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                do{
                                                    system("cls");
                                                    //printf("PEDIDO ======================> %d\n", cen);
                                                    printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                                    printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                                    printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                                    printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                                    printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                                    printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                                    printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                                    printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                                    printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                                    printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);
                                                    printf("\n");


                                                    printf("1) CODIGO PEDIDO\n");
                                                    printf("2) COMPONENTE DEL PEDIDO\n");
                                                    printf("3) PEDIDO REALIZADO\n");
                                                    printf("4) PEDIDO RECIBIDO TOTAL\n");
                                                    printf("5) EN PROCESO\n");
                                                    printf("6) NECESIDAD TOTAL\n");
                                                    printf("7) NECESIDAD ACTUAL\n");
                                                    printf("0) SALIR\n");
                                                    printf("ELIGE UNA OPCION =>");
                                                    fflush(stdin);
                                                    scanf("%d", &seleccion);
                                                    if(seleccion==0)
                                                    {
                                                        break;
                                                    }
                                                    switch(seleccion)
                                                    {
                                                        case 1:
                                                            {
                                                               printf("INTRODUCE EL NUEVO CODIGO DEL PEDIDO => ");
                                                               fflush(stdin);
                                                               gets(pedid1.codigo);
                                                               MintoMay_pedidosP(pedid1.codigo);
                                                               break;
                                                            }
                                                        case 2:
                                                            {
                                                                printf("INTRODUCE LA NUEVA COMPONENTE   => ");
                                                                fflush(stdin);
                                                                gets(pedid1.componente);
                                                                MintoMay_pedidosP(pedid1.componente);
                                                                break;
                                                            }
                                                        case 3:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PEDIDO REALIZADO => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.pedido_total);
                                                                break;
                                                            }
                                                        case 4:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PEDIDO RECIBIDO TOTAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.recibido_total);
                                                                break;
                                                            }
                                                        case 5:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PROCESO => ");
                                                                fflush(stdin);
                                                                 scanf("%f", &pedid1.proceso);
                                                                break;
                                                            }
                                                        case 6:
                                                            {
                                                                printf("INTRODUCE LA NUEVA NECESIDAD TOTAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.necesitad_total);

                                                                break;
                                                            }

                                                        case 7:
                                                            {
                                                                printf("INTRODUCE LA NUEVA NECESIDAD ACTUAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.necesidad_actual);
                                                            }
                                                        default:
                                                            printf("OPCION INCORRECTA\n");
                                                            break;
                                                    }

                                                }while(1);

                                                desplazamiento = cen*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fwrite(&pedid1, sizeof(pedid1), 1, ptrPedidos);


                                                printf("Pedido modificado\n");
                                                getch();
                                        }
                                            }

                                        else
                                        {
                                            printf("No encontrado\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedid1.codigo,longitud)<0)
                                        {
                                            der = cen-1;
                                        }
                                        else
                                        {
                                            izq = cen +1;
                                        }
                                    }
                                    if(sw==1)
                                    {
                                        break;
                                    }
                                }while(1);
                        }while(1);
                        fclose(ptrPedidos);
                        ordenar_pedidos();



                        break;

                }


                case 2:
                {
                        ordenar_nombre_pedidos();
                        do{
                            system("cls");
                            fflush(stdin);

                            printf("INTRODUCE LA COMPONENTE DEL PEDIDO QUE DESEAS MODIFICAR (FIN para salir) => ");
                            scanf("%s", &buscar);
                            MintoMay_pedidosP(buscar);
                            longitud = strlen(buscar);
                            /*for(i=0;i<longitud;i++)
                            {
                                buscar[i]=toupper(buscar[i]);
                            }*/
                            if(strncmp(buscar, "FIN",1)==0)
                            {
                                break;
                            }
                            sw =0;
                            izq =1;
                            der =n;
                                do{
                                    cen=(izq+der)/2;

                                    desplazamiento = cen*sizeof(pedid1);
                                    fseek(ptrPedidos, desplazamiento, 0);
                                    fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
                                    if(strncmp(buscar,pedid1.componente,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedid1.componente, longitud)==0)
                                        {
                                            //printf("Pedido => %ld\n", cen);

                                            //printf("PEDIDO ======================> %d\n", cen);
                                            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);


                                            getch();

                                            printf("Deseas modificar este pedido? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                do{
                                                    system("cls");
                                                    //printf("PEDIDO ======================> %d\n", cen);
                                                    printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                                    printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                                    printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                                    printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                                    printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                                    printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                                    printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                                    printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                                    printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                                    printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);
                                                    printf("\n");


                                                    printf("1) CODIGO PEDIDO\n");
                                                    printf("2) COMPONENTE DEL PEDIDO\n");
                                                    printf("3) PEDIDO REALIZADO\n");
                                                    printf("4) PEDIDO RECIBIDO TOTAL\n");
                                                    printf("5) EN PROCESO\n");
                                                    printf("6) NECESIDAD TOTAL\n");
                                                    printf("7) NECESIDAD ACTUAL\n");
                                                    printf("0) SALIR\n");
                                                    printf("ELIGE UNA OPCION =>");
                                                    fflush(stdin);
                                                    scanf("%d", &seleccion);
                                                    if(seleccion==0)
                                                    {
                                                        break;
                                                    }
                                                    switch(seleccion)
                                                    {
                                                        case 1:
                                                            {
                                                               printf("INTRODUCE EL NUEVO CODIGO DEL PEDIDO => ");
                                                               fflush(stdin);
                                                               gets(pedid1.codigo);
                                                               MintoMay_pedidosP(pedid1.codigo);
                                                               break;
                                                            }
                                                        case 2:
                                                            {
                                                                printf("INTRODUCE LA NUEVA COMPONENTE   => ");
                                                                fflush(stdin);
                                                                gets(pedid1.componente);
                                                                MintoMay_pedidosP(pedid1.componente);
                                                                break;
                                                            }
                                                        case 3:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PEDIDO REALIZADO => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.pedido_total);
                                                                break;
                                                            }
                                                        case 4:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PEDIDO RECIBIDO TOTAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.recibido_total);
                                                                break;
                                                            }
                                                        case 5:
                                                            {
                                                                printf("INTRODUCE EL NUEVO PROCESO => ");
                                                                fflush(stdin);
                                                                 scanf("%f", &pedid1.proceso);
                                                                break;
                                                            }
                                                        case 6:
                                                            {
                                                                printf("INTRODUCE LA NUEVA NECESIDAD TOTAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.necesitad_total);

                                                                break;
                                                            }

                                                        case 7:
                                                            {
                                                                printf("INTRODUCE LA NUEVA NECESIDAD ACTUAL => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedid1.necesidad_actual);
                                                            }
                                                        default:
                                                            printf("OPCION INCORRECTA\n");
                                                            break;
                                                    }

                                                }while(1);

                                                desplazamiento = cen*sizeof(pedid1);
                                                fseek(ptrPedidos, desplazamiento, 0);
                                                fwrite(&pedid1, sizeof(pedid1), 1, ptrPedidos);


                                                printf("PEDIDO MODIFICADO\n");
                                                getch();
                                        }
                                            }

                                        else
                                        {
                                            printf("NO ENCONTRADO\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedid1.componente,longitud)<0)
                                        {
                                            der = cen-1;
                                        }
                                        else
                                        {
                                            izq = cen +1;
                                        }
                                    }
                                    if(sw==1)
                                    {
                                        break;
                                    }
                                }while(1);
                        }while(1);
                        fclose(ptrPedidos);
                        ordenar_pedidos();



                        break;

                }


            default:
                {

                    printf("OPCION INCORRECTA\n");
                }
        }
    }



}


//******** FUNCION ORDENAR pedidos POR codigp *********
void ordenar_pedidos(void)
{

    pedidos registro1, registro2;

    long int i, d;
    int sw;


    ptrPedidos = fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    n = regPedid.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrPedidos, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrPedidos);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrPedidos, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrPedidos);

                if(strcmp(registro1.codigo, registro2.codigo)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrPedidos, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrPedidos);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrPedidos, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrPedidos);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrPedidos);
}

//********* FUNCION ORDENAR pedidos POR Componente ********
void ordenar_nombre_pedidos()
{

    pedidos registro1, registro2;

    long int i, d;
    int sw;
    FILE *ptrPedidos;

    ptrPedidos = fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);
    n = regPedid.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrPedidos, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrPedidos);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrPedidos, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrPedidos);

                if(strcmp(registro1.componente, registro2.componente)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrPedidos, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrPedidos);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrPedidos, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrPedidos);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrPedidos);
}




//******** FUNCION DE CONVERTIR A MAYUSCULAS PEDIDOS ********
void MintoMay_pedidosP(char string[])
{
    int i=0;
    int desp='a'-'A';
    for(i=0;string[i]!='\0';++i)
    {
        if(string[i]>='a'&&string[i]<='z')
        {
            string[i]=string[i]-desp;
        }
    }
}

// FIN DE LAS FUNCIONES DE PEDIDOS

//------------------------------------------
//------------------------------------------


// FUNCIONES DE PROVEEDORES DESARROLLADAS

void gestionproveedor()
{

int seleccion;
    int k;
    comprobar_proveedor();

    do{

        system("cls");
        printf("-----------------------------------------\n");
        printf("---------- GESTION DE PROVEEDORES -------\n");
        printf("-----------------------------------------\n");
        printf("| - 1) INSERTAR UN PROVEEDOR NUEVO      |\n");
        printf("| - 2) VER TODOS LOS PROVEEDORES        |\n");
        printf("| - 3) BUSCAR PROVEEDOR                 |\n");
        printf("| - 4) ELIMINAR PROVEEDOR               |\n");
        printf("| - 5) MODIFICAR PROVEEDOR              |\n");
        printf("| - 0) SALIR                            |\n");

        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("Hasta la proxima ");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    altas_proveedor();
                    break;
                }
            case 2:
                {
                    ordenar_proveedor();      //ORDENO POR CODIGO DEL PROVEEDOR
                    listados_proveedor();
                    break;
                }
            case 3:
                {
                    consultas_proveedor();
                    break;
                }
            case 4:
                {
                    bajas_proveedor();
                    break;
                }
            case 5:
                {
                    modificaciones_proveedor();
                    break;
                }
            default:
                {
                    printf("OPCION INCORRECTA\n");
                    getch();
                }
        }


    }while(1);

}

//******** FUNCION DE COMPROBAR FICHERO ********

void comprobar_proveedor()
{
    int k;
    ptrProveedor = fopen(fproveedor, "rb");
    if(ptrProveedor==NULL)
    {
        printf("NO HAY NINGUN ARCHIVO\n");
        getch();
        system("cls");
        ptrProveedor=fopen(fproveedor,"w+b");
        printf("ARCHIVO CREADO PROVEEDOR\n");
        getch();
        fseek(ptrProveedor, 0L, 0);
        regProv.nregistros = 0L;
        for(k=0;k<=240;k++)
        {
            regProv.blancos[k] =' ';
        }
        fwrite(&regProv, sizeof(regProv), 1, ptrProveedor);
    }
    fclose(ptrProveedor);
}


//******** ALTAS PROVEEDOR ********

void altas_proveedor(void)
{
    int k;

    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor, 0L, 0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);

    n= regProv.nregistros;

    do{
        n= n+1;
        system("cls");

        printf("INTRODUCE EL CODIGO DEL PROVEEDOR (NO PUEDE SER MAS DE 11 DIGITOS)=> ");
        fflush(stdin);
        gets(proveedor1.codigo);
        MintoMay_proveedor(proveedor1.codigo);
        printf("INTRODUCE UNA COMPONENTE=> ");
        fflush(stdin);
        gets(proveedor1.componente);
        MintoMay_proveedor(proveedor1.componente);

        printf("INTRODUCE EL NOMBRE DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.nombre);
        MintoMay_proveedor(proveedor1.nombre);

        printf("INTRODUCE EL TELEFONO DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.telefono);
        MintoMay_proveedor(proveedor1.telefono);

        printf("INTRODUCE LOS COLORES QUE TIENE EL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.color);
        MintoMay_proveedor(proveedor1.color);
        printf("INTRODUCE EL PAIS DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.pais);
        MintoMay_proveedor(proveedor1.pais);
        printf("INTRODUCE LA PROVINCIA DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.provincia);
        MintoMay_proveedor(proveedor1.provincia);
        printf("INTRODUCE LA LOCALIDAD DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.localidad);
        MintoMay_proveedor(proveedor1.localidad);
        printf("INTRODUCE LA DIRECCION DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.direcccion);
        MintoMay_proveedor(proveedor1.direcccion);

        printf("INTRODUCE EL CORREO DEL PROVEEDOR => ");
        fflush(stdin);
        gets(proveedor1.correo);
        MintoMay_proveedor(proveedor1.correo);



        desplazamiento =n *sizeof(proveedor1);
        fseek(ptrProveedor, desplazamiento, 0);
        fwrite(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);

        printf("PROVEEDOR REGISTRADO\n");

        printf("DESEA ANIADIR MAS PROVEEDORES?(s/n)=> ");
        fflush(stdin);

    }while(getchar()=='s'||getchar()=='S');

    fseek(ptrProveedor,0L,0);
    regProv.nregistros = n;
    for(k=0;k<240;k++)
    {
        regProv.blancos[k]=' ';
    }
    fwrite(&regProv, sizeof(regProv), 1, ptrProveedor);
    fclose(ptrProveedor);
}

//******** FUNCION LISTADOS DE PROVEEDOR ********
void listados_proveedor(void)
{

    int i;

    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor, 0L, 0);
    fread(&regProv, sizeof(regProv), 1,ptrProveedor);

    n = regProv.nregistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(proveedor1);
        fseek(ptrProveedor, desplazamiento, 0);
        fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
        if(strncmp(proveedor1.nombre,"#####", 5)==0){
            continue;
        }
        else{


            system("cls");
            printf("PROVEEDOR ===============> %d\n", i);
            printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
            printf("COMPONENTE ==============> %s\n", proveedor1.componente);
            printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
            printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
            printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
            printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
            printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
            printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
            printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
            printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
            getch();
        }
    }

    fclose(ptrProveedor);

}

//******** FUNCION DE CONSULTAS PROVEEDOR ********
void consultas_proveedor(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];

    proveedor proveedor1;
    registroProveedor regProv;
    FILE *ptrProveedor;
    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) CODIGO DEL PROVEEDOR\n");
        printf("2) NOMBRE DEL PROVEEDOR\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar_proveedor();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce el codigo del proveedor (FIN para salir) => ");
                        printf("INTRODUCE EL CODIGO DEL PROVEEDOR (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_proveedor(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                            if(strncmp(buscar,proveedor1.codigo,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,proveedor1.codigo, longitud)==0)
                                {
                                    //printf("PROVEEDOR ==============> %ld\n", cen);
                                    printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                    printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                    printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                    printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                    printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                    printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                    printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                    printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                    printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                    printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);

                                    getch();
                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,proveedor1.codigo,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }


                case 2:
                {
                    ordenar_nombre_proveedor();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce el nombre del proveedor (FIN para salir) => ");
                        scanf("%s", &buscar);
                        MintoMay_proveedor(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                            if(strncmp(buscar,proveedor1.nombre,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,proveedor1.nombre, longitud)==0)
                                {
                                    //printf("PROVEEDOR ==============> %ld\n", cen);
                                    printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                    printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                    printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                    printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                    printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                    printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                    printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                    printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                    printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                    printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);

                                    getch();
                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,proveedor1.nombre,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }


            default:
                {
                    printf("OPCION INCORRECTA\n");
                }
        }
    }

}

//******** FUNCION BAJAS ********
void bajas_proveedor(void)
{
    int k;

    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;



    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;

    ordenar_nombre_proveedor();        //ORDENO POR NOMBRE PARA QUE FUNCIONE LA BUSQUEDA DICOTOMICA
    do{
        system("cls");
        fflush(stdin);
        printf("INTRODUCE EL NOMBRE DEL PROVEEDOR QUE DESEAS ELIMINAR (FIN PARA SALIR) => ");
        gets(buscar);
        MintoMay_proveedor(buscar);
        longitud = strlen(buscar);
        /*for(i=0;i<longitud;i++)
        {
            buscar[i]=toupper(buscar[i]);
        }*/
        if(strncmp(buscar, "FIN",1)==0)
        {
            break;
        }
        sw =0;
        izq =1;
        der =n;
            do{
                cen=(izq+der)/2;

                desplazamiento = cen*sizeof(proveedor1);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                if(strncmp(buscar,proveedor1.nombre,longitud)==0||(izq>=der))
                {
                    sw =1;
                    if(strncmp(buscar,proveedor1.nombre, longitud)==0)
                    {

                        //printf("PROVEEDOR ===============> %d\n", cen);
                        printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                        printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                        printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                        printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                        printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                        printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                        printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                        printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                        printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                        printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                        getch();

                        printf("DESEAS ELIMINAR ESTE PROVEEDOR? (s/n) => ");
                        fflush(stdin);
                        scanf("%c", &respuesta);
                        if(respuesta=='n'|| respuesta=='N')
                        {
                            break;
                        }
                        if(respuesta=='s'|| respuesta =='S')
                        {
                            strcpy(proveedor1.nombre,"#####");
                            desplazamiento = n*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);

                            fwrite(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);

                            n--;

                            fseek(ptrProveedor, 0L, 0);
                            regProv.nregistros= n;
                            for(k=0;k<240;k++)
                            {
                                regProv.blancos[k]=' ';
                            }
                            fwrite(&regProv, sizeof(regProv), 1, ptrProveedor);
                        }
                        printf("PROVEEDOR ELIMINADO\n");
                        getch();
                    }
                    else
                    {
                        printf("PROVEEDOR NO ENCONTRADO\n");
                        getch();
                    }

                }
                else
                {
                    if(strncmp(buscar,proveedor1.nombre,longitud)<0)
                    {
                        der = cen-1;
                    }
                    else
                    {
                        izq = cen +1;
                    }
                }
                if(sw==1)
                {
                    break;
                }
            }while(1);
    }while(1);
    fclose(ptrProveedor);
    ordenar_proveedor();      //ORDENO POR CODIGO
}

//******** FUNCION MODIFICAR PROVEEDOR ********
/*void modificaciones_proveedor(void)
{
    int k;

    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;

    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;


    do{
        system("cls");
        fflush(stdin);

        printf("INTRODUCE EL NOMBRE DEL PROVEEDOR QUE DESEAS MODIFICAR (FIN PARA SALIR) => ");
        gets(buscar);
        MintoMay_proveedor(buscar);
        longitud = strlen(buscar);
        /*for(i=0;i<longitud;i++)
        {
            buscar[i]=toupper(buscar[i]);
        }*/
 /*       if(strncmp(buscar, "FIN",1)==0)
        {
            break;
        }
        sw =0;
        izq =1;
        der =n;
            do{
                cen=(izq+der)/2;

                desplazamiento = cen*sizeof(proveedor1);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                if(strncmp(buscar,proveedor1.nombre,longitud)==0||(izq>=der))
                {
                    sw =1;
                    if(strncmp(buscar,proveedor1.nombre, longitud)==0)
                    {

                        //printf("PROVEEDOR ===============> %d\n", cen);
                        printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                        printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                        printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                        printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                        printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                        printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                        printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                        printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                        printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                        getch();

                        printf("DESEAS MODIFICAR ESTE PROVEEDOR? (s/n) => ");
                        fflush(stdin);
                        scanf("%c", &respuesta);
                        if(respuesta=='n'|| respuesta=='N')
                        {
                            break;
                        }
                        if(respuesta=='s'|| respuesta =='S')
                        {
                            do{
                                system("cls");
                                 //printf("PROVEEDOR ===============> %d\n", cen);
                                printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                                printf("\n");


                                printf("1) CODIGO PROVEEDOR\n");
                                printf("2) NOMBRE DEL PROVEEDOR\n");
                                printf("3) TELEFONO DEL PROVEEDOR\n");
                                printf("4) COLOR DEL PROVEEDOR\n");
                                printf("5) PAIS DEL PROVEEDOR\n");
                                printf("6) PROVINCIA DEL PROVEEDOR\n");
                                printf("7) LOCALIDAD DEL PROVEEDOR\n");
                                printf("8) DIRECCION DEL PROVEEDOR\n");
                                printf("9) CORREO DEL PROVEEDOR\n");
                                printf("0) SALIR\n");
                                printf("ELIGE UNA OPCION =>");
                                fflush(stdin);
                                scanf("%d", &seleccion);
                                if(seleccion==0)
                                {
                                    break;
                                }
                                switch(seleccion)
                                {
                                    case 1:
                                        {
                                           printf("INTRODUCE EL NUEVO CODIGO DEL PROVEEDOR => ");
                                           fflush(stdin);
                                           gets(proveedor1.codigo);
                                           MintoMay_proveedor(proveedor1.codigo);
                                           break;
                                        }
                                    case 2:
                                        {
                                            printf("INTRODUCE EL NUEVO NOMBRE DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.nombre);
                                            MintoMay_proveedor(proveedor1.nombre);
                                            break;
                                        }

                                    case 3:
                                        {
                                            printf("INTRODUCE EL NUEVO TELEFONO DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.telefono);
                                            break;
                                        }
                                    case 4:
                                        {
                                            printf("INTRODUCE EL NUEVO COLOR DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.color);
                                            MintoMay_proveedor(proveedor1.color);
                                            break;
                                        }
                                    case 5:
                                        {
                                            printf("INTRODUCE EL NUEVO PAIS DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.pais);
                                            MintoMay_proveedor(proveedor1.pais);
                                            break;
                                        }
                                    case 6:
                                        {
                                            printf("INTRODUCE LA NUEVA PROVINCIA DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.provincia);
                                            break;
                                        }
                                    case 7:
                                        {
                                            printf("INTRODUCE LA NUEVA LOCALIDAD DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.localidad);
                                            MintoMay_proveedor(proveedor1.localidad);
                                            break;
                                        }
                                    case 8:
                                        {
                                            printf("INTRODUCE LA NUEVA DIRECCION DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.direcccion);
                                            MintoMay_proveedor(proveedor1.direcccion);
                                            break;
                                        }
                                    case 9:
                                        {
                                            printf("INTRODUCE EL NUEVO CORREO DEL PROVEEDOR => ");
                                            fflush(stdin);
                                            gets(proveedor1.correo);
                                            MintoMay_proveedor(proveedor1.correo);
                                            break;
                                        }
                                    default:
                                        printf("OPCION INCORRECTA\n");
                                        getch();
                                }

                            }while(1);

                            desplazamiento = cen*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fwrite(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);


                            printf("PROVEEDOR HA SIDO MODIFICADO\n");
                            getch();
                    }
                        }

                    else
                    {
                        printf("PROVEEDOR NO ENCONTRADO\n");
                        getch();
                    }

                }
                else
                {
                    if(strncmp(buscar,proveedor1.nombre,longitud)<0)
                    {
                        der = cen-1;
                    }
                    else
                    {
                        izq = cen +1;
                    }
                }
                if(sw==1)
                {
                    break;
                }
            }while(1);
    }while(1);
    fclose(ptrProveedor);
    ordenar_proveedor();
}

*/


//AÑADIMOS FUNCION DE MODIFICACIONES PROVEEDORES MEJORADA


void modificaciones_proveedor(void)
{
    /*int k;

    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;

    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;

        */


    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;
    int k;
    proveedor proveedor1;
    registroProveedor regProv;
    FILE *ptrProveedor;
    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;


    while(seleccion!=0)
    {
        system("cls");
        printf("1) MODIFICAR POR EL CODIGO DEL PROVEEDOR\n");
        printf("2) MODIFICAR POR EL NOMBRE DEL PROVEEDOR\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                        ordenar_proveedor();
                        do{
                                    system("cls");
                                    fflush(stdin);

                                    printf("INTRODUCE EL CODIGO DEL PROVEEDOR QUE DESEAS MODIFICAR (FIN PARA SALIR) => ");
                                    gets(buscar);
                                    MintoMay_proveedor(buscar);
                                    longitud = strlen(buscar);
                                    /*for(i=0;i<longitud;i++)
                                    {
                                        buscar[i]=toupper(buscar[i]);
                                    }*/
                                    if(strncmp(buscar, "FIN",1)==0)
                                    {
                                        break;
                                    }
                                    sw =0;
                                    izq =1;
                                    der =n;
                                        do{
                                            cen=(izq+der)/2;

                                            desplazamiento = cen*sizeof(proveedor1);
                                            fseek(ptrProveedor, desplazamiento, 0);
                                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                                            if(strncmp(buscar,proveedor1.codigo,longitud)==0||(izq>=der))
                                            {
                                                sw =1;
                                                if(strncmp(buscar,proveedor1.codigo, longitud)==0)
                                                {

                                                    //printf("PROVEEDOR ===============> %d\n", cen);
                                                    printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                                    printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                                    printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                                    printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                                    printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                                    printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                                    printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                                    printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                                    printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                                    printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                                                    getch();

                                                    printf("DESEAS MODIFICAR ESTE PROVEEDOR? (s/n) => ");
                                                    fflush(stdin);
                                                    scanf("%c", &respuesta);
                                                    if(respuesta=='n'|| respuesta=='N')
                                                    {
                                                        break;
                                                    }
                                                    if(respuesta=='s'|| respuesta =='S')
                                                    {
                                                        do{
                                                            system("cls");
                                                             //printf("PROVEEDOR ===============> %d\n", cen);
                                                            printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                                            printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                                            printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                                            printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                                            printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                                            printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                                            printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                                            printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                                            printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                                            printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                                                            printf("\n");


                                                            printf("1) CODIGO PROVEEDOR\n");
                                                            printf("2) COMPONENTE\n");
                                                            printf("3) NOMBRE DEL PROVEEDOR\n");
                                                            printf("4) TELEFONO DEL PROVEEDOR\n");
                                                            printf("5) COLOR DEL PROVEEDOR\n");
                                                            printf("6) PAIS DEL PROVEEDOR\n");
                                                            printf("7) PROVINCIA DEL PROVEEDOR\n");
                                                            printf("8) LOCALIDAD DEL PROVEEDOR\n");
                                                            printf("9) DIRECCION DEL PROVEEDOR\n");
                                                            printf("10) CORREO DEL PROVEEDOR\n");
                                                            printf("0) SALIR\n");
                                                            printf("ELIGE UNA OPCION =>");
                                                            fflush(stdin);
                                                            scanf("%d", &seleccion);
                                                            if(seleccion==0)
                                                            {
                                                                break;
                                                            }
                                                            switch(seleccion)
                                                            {
                                                                case 1:
                                                                    {
                                                                       printf("INTRODUCE EL NUEVO CODIGO DEL PROVEEDOR => ");
                                                                       fflush(stdin);
                                                                       gets(proveedor1.codigo);
                                                                       MintoMay_proveedor(proveedor1.codigo);
                                                                       break;
                                                                    }
                                                                case 2:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA COMPONENTE DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.componente);
                                                                        MintoMay_proveedor(proveedor1.componente);
                                                                        break;
                                                                    }
                                                                case 3:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO NOMBRE DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.nombre);
                                                                        MintoMay_proveedor(proveedor1.nombre);
                                                                        break;
                                                                    }

                                                                case 4:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO TELEFONO DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.telefono);
                                                                        break;
                                                                    }
                                                                case 5:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO COLOR DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.color);
                                                                        MintoMay_proveedor(proveedor1.color);
                                                                        break;
                                                                    }
                                                                case 6:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO PAIS DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.pais);
                                                                        MintoMay_proveedor(proveedor1.pais);
                                                                        break;
                                                                    }
                                                                case 7:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA PROVINCIA DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.provincia);
                                                                        break;
                                                                    }
                                                                case 8:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA LOCALIDAD DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.localidad);
                                                                        MintoMay_proveedor(proveedor1.localidad);
                                                                        break;
                                                                    }
                                                                case 9:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA DIRECCION DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.direcccion);
                                                                        MintoMay_proveedor(proveedor1.direcccion);
                                                                        break;
                                                                    }
                                                                case 10:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO CORREO DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.correo);
                                                                        MintoMay_proveedor(proveedor1.correo);
                                                                        break;
                                                                    }
                                                                default:
                                                                    printf("OPCION INCORRECTA\n");
                                                                    getch();
                                                            }

                                                        }while(1);

                                                        desplazamiento = cen*sizeof(proveedor1);
                                                        fseek(ptrProveedor, desplazamiento, 0);
                                                        fwrite(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);


                                                        printf("PROVEEDOR HA SIDO MODIFICADO\n");
                                                        getch();
                                                }
                                                    }

                                                else
                                                {
                                                    printf("PROVEEDOR NO ENCONTRADO\n");
                                                    getch();
                                                }

                                            }
                                            else
                                            {
                                                if(strncmp(buscar,proveedor1.codigo,longitud)<0)
                                                {
                                                    der = cen-1;
                                                }
                                                else
                                                {
                                                    izq = cen +1;
                                                }
                                            }
                                            if(sw==1)
                                            {
                                                break;
                                            }
                                        }while(1);
                    }while(1);
                    fclose(ptrProveedor);
                    ordenar_proveedor();



                        break;

                }


                case 2:
                {
                        ordenar_nombre_proveedor();
                        do{
                                    system("cls");
                                    fflush(stdin);

                                    printf("INTRODUCE EL NOMBRE DEL PROVEEDOR QUE DESEAS MODIFICAR (FIN PARA SALIR) => ");
                                    gets(buscar);
                                    MintoMay_proveedor(buscar);
                                    longitud = strlen(buscar);
                                    /*for(i=0;i<longitud;i++)
                                    {
                                        buscar[i]=toupper(buscar[i]);
                                    }*/
                                    if(strncmp(buscar, "FIN",1)==0)
                                    {
                                        break;
                                    }
                                    sw =0;
                                    izq =1;
                                    der =n;
                                        do{
                                            cen=(izq+der)/2;

                                            desplazamiento = cen*sizeof(proveedor1);
                                            fseek(ptrProveedor, desplazamiento, 0);
                                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                                            if(strncmp(buscar,proveedor1.nombre,longitud)==0||(izq>=der))
                                            {
                                                sw =1;
                                                if(strncmp(buscar,proveedor1.nombre, longitud)==0)
                                                {

                                                    //printf("PROVEEDOR ===============> %d\n", cen);
                                                    printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                                    printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                                    printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                                    printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                                    printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                                    printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                                    printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                                    printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                                    printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                                                    getch();

                                                    printf("DESEAS MODIFICAR ESTE PROVEEDOR? (s/n) => ");
                                                    fflush(stdin);
                                                    scanf("%c", &respuesta);
                                                    if(respuesta=='n'|| respuesta=='N')
                                                    {
                                                        break;
                                                    }
                                                    if(respuesta=='s'|| respuesta =='S')
                                                    {
                                                         do{
                                                            system("cls");
                                                             //printf("PROVEEDOR ===============> %d\n", cen);
                                                            printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                                            printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                                            printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                                            printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                                            printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                                            printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                                            printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                                            printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                                            printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                                            printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                                                            printf("\n");


                                                            printf("1) CODIGO PROVEEDOR\n");
                                                            printf("2) COMPONENTE\n");
                                                            printf("3) NOMBRE DEL PROVEEDOR\n");
                                                            printf("4) TELEFONO DEL PROVEEDOR\n");
                                                            printf("5) COLOR DEL PROVEEDOR\n");
                                                            printf("6) PAIS DEL PROVEEDOR\n");
                                                            printf("7) PROVINCIA DEL PROVEEDOR\n");
                                                            printf("8) LOCALIDAD DEL PROVEEDOR\n");
                                                            printf("9) DIRECCION DEL PROVEEDOR\n");
                                                            printf("10) CORREO DEL PROVEEDOR\n");
                                                            printf("0) SALIR\n");
                                                            printf("ELIGE UNA OPCION =>");
                                                            fflush(stdin);
                                                            scanf("%d", &seleccion);
                                                            if(seleccion==0)
                                                            {
                                                                break;
                                                            }
                                                            switch(seleccion)
                                                            {
                                                                case 1:
                                                                    {
                                                                       printf("INTRODUCE EL NUEVO CODIGO DEL PROVEEDOR => ");
                                                                       fflush(stdin);
                                                                       gets(proveedor1.codigo);
                                                                       MintoMay_proveedor(proveedor1.codigo);
                                                                       break;
                                                                    }
                                                                case 2:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA COMPONENTE DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.componente);
                                                                        MintoMay_proveedor(proveedor1.componente);
                                                                        break;
                                                                    }
                                                                case 3:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO NOMBRE DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.nombre);
                                                                        MintoMay_proveedor(proveedor1.nombre);
                                                                        break;
                                                                    }

                                                                case 4:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO TELEFONO DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.telefono);
                                                                        break;
                                                                    }
                                                                case 5:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO COLOR DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.color);
                                                                        MintoMay_proveedor(proveedor1.color);
                                                                        break;
                                                                    }
                                                                case 6:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO PAIS DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.pais);
                                                                        MintoMay_proveedor(proveedor1.pais);
                                                                        break;
                                                                    }
                                                                case 7:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA PROVINCIA DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.provincia);
                                                                        break;
                                                                    }
                                                                case 8:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA LOCALIDAD DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.localidad);
                                                                        MintoMay_proveedor(proveedor1.localidad);
                                                                        break;
                                                                    }
                                                                case 9:
                                                                    {
                                                                        printf("INTRODUCE LA NUEVA DIRECCION DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.direcccion);
                                                                        MintoMay_proveedor(proveedor1.direcccion);
                                                                        break;
                                                                    }
                                                                case 10:
                                                                    {
                                                                        printf("INTRODUCE EL NUEVO CORREO DEL PROVEEDOR => ");
                                                                        fflush(stdin);
                                                                        gets(proveedor1.correo);
                                                                        MintoMay_proveedor(proveedor1.correo);
                                                                        break;
                                                                    }
                                                                default:
                                                                    printf("OPCION INCORRECTA\n");
                                                                    getch();
                                                            }

                                                        }while(1);

                                                        desplazamiento = cen*sizeof(proveedor1);
                                                        fseek(ptrProveedor, desplazamiento, 0);
                                                        fwrite(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);


                                                        printf("PROVEEDOR HA SIDO MODIFICADO\n");
                                                        getch();
                                                }
                                                    }

                                                else
                                                {
                                                    printf("PROVEEDOR NO ENCONTRADO\n");
                                                    getch();
                                                }

                                            }
                                            else
                                            {
                                                if(strncmp(buscar,proveedor1.nombre,longitud)<0)
                                                {
                                                    der = cen-1;
                                                }
                                                else
                                                {
                                                    izq = cen +1;
                                                }
                                            }
                                            if(sw==1)
                                            {
                                                break;
                                            }
                                        }while(1);
                    }while(1);
                    fclose(ptrProveedor);
                    ordenar_proveedor();


                        break;

                }


            default:
                {
                    printf("OPCION INCORRECTA\n");
                }
        }
    }



}





//******** FUNCION ORDENAR PROVEEDOR POR CODIGO *********
void ordenar_proveedor(void)
{

    proveedor registro1, registro2;

    long int i, d;
    int sw;


    ptrProveedor = fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrProveedor);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrProveedor);

                if(strcmp(registro1.codigo, registro2.codigo)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrProveedor, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrProveedor);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrProveedor, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrProveedor);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrProveedor);
}


//********* FUNCION ORDENAR PROVEEDOR POR NOMBRE ********
void ordenar_nombre_proveedor()
{

    proveedor registro1, registro2;

    long int i, d;
    int sw;
    FILE *ptrProveedor;

    ptrProveedor = fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);
    n = regProv.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, ptrProveedor);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(ptrProveedor, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, ptrProveedor);

                if(strcmp(registro1.nombre, registro2.nombre)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(ptrProveedor, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, ptrProveedor);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(ptrProveedor, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, ptrProveedor);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(ptrProveedor);
}


//******** FUNCION DE CONVERTIR A MAYUSCULAS ********
void MintoMay_proveedor(char string[])
{
    int i=0;
    int desp='a'-'A';
    for(i=0;string[i]!='\0';++i)
    {
        if(string[i]>='a'&&string[i]<='z')
        {
            string[i]=string[i]-desp;
        }
    }
}


//FIN DE FUNCIONES DE PROVEEDORES

//------------------------------------
//------------------------------------

//INICIO DE FUNCIONES  DE APLICACION

void aplicacion()
{

    int seleccion;
    int k;
    //comprobar_articulos();

    do{
        system("cls");
        printf("-------------------------------------\n");
        printf("---------- GESTION DE APLICACION -----\n");
        printf("-------------------------------------\n");
        printf("| - 1) VER TODO LO QUE TIENE INSERTANDO UN COMPONENTE   |\n");
        printf("| - 2) TOTAL DE PEDIDOS                                 |\n");
        printf("| - 3) VER PROVEEDOR Y PEDIDOS POR CODIGO               |\n");
        printf("| - 4) VER ARTICULOS, PEDIDOS Y PROVEEDOR               |\n");
        printf("| - 0) SALIR                                            |\n");

        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ver_por_componente();
                    break;
                }
            case 2:
                {
                    conocer_total();
                    break;
                }

            case 3:
                {

                    ver_todo_codigo();
                    break;
                }
            case 4:
                {

                    ver_todo();
                    break;
                }

            default:
                {
                    printf("OPCION INCORRECTA\n");
                    getch();
                }
        }


    }while(1);

}


void ver_por_componente()
{
    long int n=0,n2=0,n3=0,desplazamiento;
    int seleccion=1,sw=0,sw1=0,sw2=0,sw3=0,longitud;
    char buscar[20];
    long busca1;
    int i,i2,i3;


    articulos artic1;
    registroArticulos regArti;
    FILE *ptrArticulos;
    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos,0L,0);
    fread(&regArti, sizeof(regArti), 1, ptrArticulos);
    n = regArti.nregistros;



    pedidos pedid1;
    registroPedidos regPedid;
    FILE *ptrPedidos;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);

    n2 = regPedid.nregistros;

    proveedor proveedor1;
    registroProveedor regProv;
    FILE *ptrProveedor;
    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor,0L,0);
    fread(&regProv, sizeof(regProv), 1, ptrProveedor);

    n3 = regProv.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) COMPONENTE DEL ARTICULO\n");
        //printf("2) MODELO DEL ARTICULO\n");
        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar_articulos();
                    do{
                        system("cls");
                        fflush(stdin);

                        printf("INTRODUCE LA COMPONENTE DEL ARTICULO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_articulos(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }

                        printf("COMPONENTES: \n");

                        for(i=1;i<=n;i++){
                            desplazamiento = i*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);


                            if(strncmp(buscar,artic1.componente, longitud)==0){

                                    printf("ARTICULO ======================> %d\n", i);
                                    printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                    printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                    printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                    printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                    printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);
                                    printf("\n");
                                    getch();
                                    sw1=1;

                            }

                        }
                          if(sw1==0){
                                printf("NO ENCONTRADO\n");
                                getch();
                            }

                        printf("PROVEEDOR: \n");
                        for(i2=1;i2<=n2;i2++){
                             desplazamiento = i2*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);


                            if(strncmp(buscar,proveedor1.componente, longitud)==0){
                            printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                            printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                            printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                            printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                            printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                            printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                            printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                            printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);
                            printf("\n");
                            getch();
                            sw2=1;
                            }

                        }
                        if(sw2==0){
                            printf("NO ENCONTRADO\n");
                            getch();
                        }


                        printf("PEDIDOS: \n");

                        for(i3=1;i3<=n3;i3++){

                            desplazamiento = i3*sizeof(pedid1);
                            fseek(ptrPedidos, desplazamiento, 0);
                            fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                              if(strncmp(buscar,pedid1.componente, longitud)==0){

                                printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                //printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);
                                printf("\n");
                                getch();
                                sw3=1;


                              }
                        }

                        if(sw3==0){
                            printf("NO ENCONTRADO\n");
                            getch();
                        }





                    }while(1);
                    break;
                }
            default:
                {
                    printf("OPCION INCORRECTA\n");
                    break;
                }
        }
    }

}

void conocer_total()
{

    int i;
    float suma=0,suma2=0,suma3=0,suma4=0,suma5=0,suma6=0,suma7=0,suma8=0;

    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos, 0L, 0);
    fread(&regPedid, sizeof(regPedid), 1,ptrPedidos);

    n = regPedid.nregistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(pedid1);
        fseek(ptrPedidos, desplazamiento, 0);
        fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);
        if(strncmp(pedid1.componente,"#####", 5)==0){
            continue;
        }
        else{




           /* system("cls");
            printf("PEDIDO ======================> %d\n", i);
            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);

            */
             suma += pedid1.pedido_total;
            suma2 += pedid1.recibido_total;
            suma3 += pedid1.pedido_total-pedid1.recibido_total;
            suma4 += pedid1.recibido_total;
            suma5 += pedid1.proceso;
            suma6 += pedid1.recibido_total-pedid1.proceso;
            suma7 += pedid1.necesitad_total;
            suma8 += pedid1.necesidad_actual;

            if(i==n){


            system("cls");
            printf("PEDIDO TOTAL ===================> %.2f\n", suma);
            printf("PEDIDO RECIBIDO TOTAL ==========> %.2f\n", suma2);
            printf("SUMA PENDIENTE TOTAL ===========> %.2f\n", suma3);
            printf("SUMA STOCK TOTAL ===============> %.2f\n", suma4);
            printf("SUMA EN PROCESO ================> %.2f\n", suma5);
            printf("SUMA STOCK EN DISPOSICION ======> %.2f\n", suma6);
            printf("SUMA NECESIDAD TOTAL ===========> %.2f\n", suma7);
            printf("SUMA NECESIDAD ACTUAL ==========> %.2f\n", suma8);

             getch();

            }





            //getch();



        }

    }

    fclose(ptrPedidos);





}

void ver_todo()
{
    int i;
    int seleccion;
    long int n2, n3;

    ptrArticulos =fopen(farticulos, "r+b");
    fseek(ptrArticulos, 0L, 0);
    fread(&regArti, sizeof(regArti), 1,ptrArticulos);


    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos, 0L, 0);
    fread(&regPedid, sizeof(regPedid), 1,ptrPedidos);

     ptrProveedor =fopen(fproveedor, "r+b");
        fseek(ptrProveedor, 0L, 0);
        fread(&regProv, sizeof(regProv), 1,ptrProveedor);

    n = regArti.nregistros;
    n2 = regPedid.nregistros;
    n3 = regProv.nregistros;


    do{
        system("cls");
        printf("--------------------------------------\n");
        printf("---------- VER TODO -----\n");
        printf("--------------------------------------\n");
        printf("| - 1) VER TODOS LOS ARTICULOS       |\n");
        printf("| - 2) VER TODOS LOS PEDIDOS         |\n");
        printf("| - 3) VER TODOS LOS PROVEEDORES     |\n");
        printf("| - 0) SALIR                         |\n");

        printf("| - ELIGE UNA OPCION => ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if(seleccion ==0){
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                        for(i=1; i<=n;i++)
                        {
                            desplazamiento = i*sizeof(artic1);
                            fseek(ptrArticulos, desplazamiento, 0);
                            fread(&artic1, sizeof(artic1), 1, ptrArticulos);


                            if(strncmp(artic1.componente,"#####", 5)==0){
                                continue;
                            }
                            else{


                                system("cls");
                                printf("ARTICULO ======================> %d\n", i);
                                printf("COMPONENTE DEL ARTICULO =======> %s\n", artic1.componente);
                                printf("MODELO DEL ARTICULO ===========> %s\n", artic1.modelo);
                                printf("TALLA DEL ARTICULO ============> %d\n", artic1.talla);
                                printf("COLOR DEL ARTICULO ============> %d\n", artic1.color);
                                printf("CONSUMO DEL ARTICULO ==========> %.2f\n", artic1.consumo);





                                getch();
                            }
                        }

                        fclose(ptrArticulos);

                    break;
                }
            case 2:
                {
                    for(i=1; i<=n2;i++)
                    {


                        desplazamiento = i*sizeof(pedid1);
                        fseek(ptrPedidos, desplazamiento, 0);
                        fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);



                        if(strncmp(artic1.componente,"#####", 5)==0){
                            continue;
                        }
                        else{


                            system("cls");
                            printf("PEDIDO ======================> %d\n", i);
                            printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                            printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                            printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                            printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                            printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                            printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                            printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                            printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                            printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                            printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);




                            getch();
                        }
                    }


                    fclose(ptrPedidos);

                    break;
                }

            case 3:
                {

                        for(i=1; i<=n3;i++)
                        {


                            desplazamiento = i*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);

                            if(strncmp(artic1.componente,"#####", 5)==0){
                                continue;
                            }
                            else{


                                system("cls");
                                printf("PROVEEDOR ===============> %d\n", i);
                                printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);


                                getch();
                            }
                        }


                        fclose(ptrProveedor);
                        break;
                }

            default:
                {
                    printf("OPCION INCORRECTA\n");
                    getch();
                }
        }


    }while(1);

}

void ver_todo_codigo(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];

    pedidos pedid1;
    registroPedidos regPedid;
    FILE *ptrPedidos;
    ptrPedidos =fopen(fpedidos, "r+b");
    fseek(ptrPedidos,0L,0);
    fread(&regPedid, sizeof(regPedid), 1, ptrPedidos);

    ptrProveedor =fopen(fproveedor, "r+b");
    fseek(ptrProveedor, 0L, 0);
    fread(&regProv, sizeof(regProv), 1,ptrProveedor);



    n = regPedid.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) CODIGO DEL PEDIDO\n");

        printf("0) SALIR\n");
        printf("ELIGE UNA OPCION => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar_pedidos();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("INTRODUCE EL CODIGO DEL PEDIDO (FIN PARA SALIR) => ");
                        scanf("%s", &buscar);
                        MintoMay_pedidosP(buscar);
                        longitud = strlen(buscar);
                        /*for(i=0;i<longitud;i++)
                        {
                            buscar[i]=toupper(buscar[i]);
                        }*/
                        if(strncmp(buscar, "FIN",1)==0)
                        {
                            break;
                        }
                        sw =0;
                        izq =1;
                        der =n;
                        do{
                            cen=(izq+der)/2;

                            desplazamiento = cen*sizeof(pedid1);
                            fseek(ptrPedidos, desplazamiento, 0);
                            fread(&pedid1, sizeof(pedid1), 1, ptrPedidos);

                            desplazamiento = cen*sizeof(proveedor1);
                            fseek(ptrProveedor, desplazamiento, 0);
                            fread(&proveedor1, sizeof(proveedor1), 1, ptrProveedor);
                            if(strncmp(buscar,pedid1.codigo,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,pedid1.codigo, longitud)==0)
                                {
                                    //printf("PEDIDO ======================> %d\n", i);
                                    printf("CODIGO PEDIDO ===============> %s\n", pedid1.codigo);
                                    printf("COMPONENTE DEL PEDIDO =======> %s\n", pedid1.componente);
                                    printf("PEDIDO ======================> %.2f\n", pedid1.pedido_total);
                                    printf("PEDIDO RECIBIDO TOTAL =======> %.2f\n", pedid1.recibido_total);
                                    printf("PEDIDO PENDIENTE ============> %.2f\n", pedid1.pedido_total-pedid1.recibido_total);
                                    printf("STOCK TOTAL =================> %.2f\n", pedid1.recibido_total);
                                    printf("EN PROCESO ==================> %.2f\n", pedid1.proceso);
                                    printf("STOCK EN DISPOSICION ========> %.2f\n", pedid1.recibido_total-pedid1.proceso);
                                    printf("NECESIDAD TOTAL =============> %.2f\n", pedid1.necesitad_total);
                                    printf("NECESIDAD ACTUAL ============> %.2f\n", pedid1.necesidad_actual);

                                    printf("\n");

                                    printf("CODIGO PROVEEDOR ========> %s\n", proveedor1.codigo);
                                    printf("COMPONENTE ==============> %s\n", proveedor1.componente);
                                    printf("NOMBRE DEL PROVEEDOR ====> %s\n", proveedor1.nombre);
                                    printf("TELEFONO DEL PROVEEDOR ==> %s\n", proveedor1.telefono);
                                    printf("COLORES DEL PROVEEDOR ===> %s\n", proveedor1.color);
                                    printf("PAIS DEL PROVEEDOOR =====> %s\n", proveedor1.pais);
                                    printf("PROVINCIA DEL PROVEEDOR => %s\n", proveedor1.provincia);
                                    printf("LOCALIDAD DEL PROVEEDOR => %s\n", proveedor1.localidad);
                                    printf("DIRECCION DEL PROVEEDOR => %s\n", proveedor1.direcccion);
                                    printf("CORREO DEL PROVEEDOR ====> %s\n", proveedor1.correo);

                                    getch();
                                }
                                else
                                {
                                    printf("NO ENCONTRADO\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,pedid1.codigo,longitud)<0)
                                {
                                    der = cen-1;
                                }
                                else
                                {
                                    izq = cen +1;
                                }
                            }
                            if(sw==1)
                            {
                                break;
                            }
                        }while(1);

                    }while(1);
                    break;

                }
    }

    }
}


