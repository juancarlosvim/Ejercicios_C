//******** LIBRERIAS *********
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//******** DEFINICION DE ARCHIVO ********

#define fpedidos "pedidos.jc"

//******** ESTRUCTURA DE pedidos ********

typedef struct
{
    char codigopedido[12];
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

}primer_registro;

//******** FUNCIONES ********
void comprobar();              //Comprueba si el fichero esta vacio o no
void altas();
void listados();
void consultas();
void bajas();
void modificaciones();
void ordenar();                //ORDENA POR CODIGO DE PROVEEDOR
void ordenar_nombre();         // ORDENA POR NOMBRE DEL PROVEEDOR
void MintoMay(char string[]);  // FUNCION PARA CONVERTIR A MAYUSCULAS


//******** VARIABLES GLOBALES ********
FILE *p1;                       //Puntero que apunta al fichero
long int n;                    //Numero de registros
long int desplazamiento;       //Desplazamiento

pedidos pedidos1;
primer_registro registro0;


//******* FUNCION MAIN ********

int main()
{

    printf("Tamaño de la estructura de pedidos %d \n", sizeof(pedidos));
    printf("Tamaño de la estructura de primer_registro  %d \n", sizeof(primer_registro));
    int seleccion;
    int k;
    comprobar();

    do{
        system("cls");
        printf("1) Insertar pedidos nuevo\n");
        printf("2) Ver todos los pedidos\n");
        printf("3) Buscar pedidos\n");
        printf("4) Eliminar pedido\n");
        printf("5) Modificar pedido \n");
        printf("0) Salir\n");
        printf("Elige una opcion => ");
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
                    altas();
                    break;
                }
            case 2:
                {
                    ordenar();      //ORDENO POR COMPONENTE DE pedido
                    listados();
                    break;
                }
            case 3:
                {

                    consultas();
                    break;
                }
            case 4:
                {
                    bajas();
                    break;
                }
            case 5:
                {
                    modificaciones();
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

//******** ALTAS PEDIDOS ********

void altas()
{
    int k;

    p1 =fopen(fpedidos, "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1, p1);

    n= registro0.nregistros;

    do{
        n= n+1;
        system("cls");
        printf("Introduce el codigo del pedido => ");
        fflush(stdin);
        gets(pedidos1.codigopedido);
        MintoMay(pedidos1.codigopedido);

        printf("Introduce la componente => ");
        fflush(stdin);
        gets(pedidos1.componente);
        MintoMay(pedidos1.componente);

        printf("Introduce el pedido total =>");
        fflush(stdin);
        scanf("%f", &pedidos1.pedido_total);
        printf("Introduce el pedido recibido total => ");
        fflush(stdin);
        scanf("%f", &pedidos1.recibido_total);

        printf("Introduce la necesidad total => ");
        fflush(stdin);
        scanf("%f", &pedidos1.necesitad_total);

        printf("Introduce la cantidad en proceso => ");
        fflush(stdin);
        scanf("%f", &pedidos1.proceso);

        printf("Introduce la necesidad actual => ");
        fflush(stdin);
        scanf("%f", &pedidos1.necesidad_actual);






        desplazamiento =n *sizeof(pedidos1);
        fseek(p1, desplazamiento, 0);
        fwrite(&pedidos1, sizeof(pedidos1), 1, p1);

        printf("pedido registrado\n");

        printf("Desea aniadir mas pedidos?(s/n)=> ");
        fflush(stdin);

    }while(getchar()=='s'||getchar()=='S');

    fseek(p1,0L,0);
    registro0.nregistros = n;
    for(k=0;k<44;k++)
    {
        registro0.blancos[k]=' ';
    }
    fwrite(&registro0, sizeof(registro0), 1, p1);
    fclose(p1);

}

//******** FUNCION LISTADOS DE PEDIDOS ********
void listados()
{

    int i;

    p1 =fopen(fpedidos, "r+b");
    fseek(p1, 0L, 0);
    fread(&registro0, sizeof(registro0), 1,p1);

    n = registro0.nregistros;
    for(i=1; i<=n;i++)
    {
        desplazamiento = i*sizeof(pedidos1);
        fseek(p1, desplazamiento, 0);
        fread(&pedidos1, sizeof(pedidos1), 1, p1);
        if(strncmp(pedidos1.componente,"#####", 5)==0){
            continue;
        }
        else{


            system("cls");
            printf("pedido ======================> %d\n", i);
            printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
            printf("Componente del pedido =======> %s\n", pedidos1.componente);
            printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
            printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
            printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
            printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
            printf("En proceso ==================> %.2f\n", pedidos1.proceso);
            printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
            printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
            printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);


            getch();
        }
    }

    fclose(p1);

}




void consultas(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];

    pedidos pedidos1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen(fpedidos, "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) Codigo del pedido\n");
        printf("2) Nombre del componente\n");
        printf("0) Salir\n");
        printf("Elige una opcion => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                    ordenar();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce el codigo del pedido (FIN para salir) => ");
                        scanf("%s", &buscar);
                        MintoMay(buscar);
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

                            desplazamiento = cen*sizeof(pedidos1);
                            fseek(p1, desplazamiento, 0);
                            fread(&pedidos1, sizeof(pedidos1), 1, p1);
                            if(strncmp(buscar,pedidos1.codigopedido,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,pedidos1.codigopedido, longitud)==0)
                                {
                                    printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                    printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                    printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                    printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                    printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                    printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                    printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                    printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                    printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                    printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);

                                    getch();
                                }
                                else
                                {
                                    printf("No encontrado\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,pedidos1.codigopedido,longitud)<0)
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
                    ordenar_nombre();
                    do{
                        system("cls");
                        fflush(stdin);
                        printf("Introduce la componente del pedido (FIN para salir) => ");
                        scanf("%s", &buscar);
                        MintoMay(buscar);
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

                            desplazamiento = cen*sizeof(pedidos1);
                            fseek(p1, desplazamiento, 0);
                            fread(&pedidos1, sizeof(pedidos1), 1, p1);
                            if(strncmp(buscar,pedidos1.componente,longitud)==0||(izq>=der))
                            {
                                sw =1;
                                if(strncmp(buscar,pedidos1.componente, longitud)==0)
                                {
                                    printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                    printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                    printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                    printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                    printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                    printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                    printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                    printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                    printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                    printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);

                                    getch();
                                }
                                else
                                {
                                    printf("No encontrado\n");
                                    getch();
                                }

                            }
                            else
                            {
                                if(strncmp(buscar,pedidos1.componente,longitud)<0)
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
                    printf("Opcion incorrecta\n");
                }
        }
    }

}


//******** FUNCION DE BAJAS PEDIDOS  2º VERSION ********

void bajas(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;
    int k;
    pedidos pedidos1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen(fpedidos, "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) Eliminar por Codigo del pedido\n");
        printf("2) Eliminar por Nombre del componente\n");
        printf("0) Salir\n");
        printf("Elige una opcion => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                     ordenar();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("Introduce el codigo del pedido que deseas eliminar (FIN para salir) => ");
                            scanf("%s", &buscar);
                            MintoMay(buscar);
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

                                    desplazamiento = cen*sizeof(pedidos1);
                                    fseek(p1, desplazamiento, 0);
                                    fread(&pedidos1, sizeof(pedidos1), 1, p1);
                                    if(strncmp(buscar,pedidos1.codigopedido,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedidos1.codigopedido, longitud)==0)
                                        {
                                            printf("Pedido => %ld\n", cen);


                                            printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                            printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                            printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                            printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                            printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                            printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                            printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                            printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                            printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                            printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);
                                            getch();

                                            printf("Deseas eliminar este pedido? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                desplazamiento = n*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fread(&pedidos1, sizeof(pedidos1), 1, p1);

                                                desplazamiento = cen*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fwrite(&pedidos1, sizeof(pedidos1), 1, p1);

                                                n = n -1;

                                                fseek(p1, 0L, 0);
                                                registro0.nregistros= n;
                                                for(k=0;k<44;k++)
                                                {
                                                    registro0.blancos[k]=' ';
                                                }
                                                fwrite(&registro0, sizeof(registro0), 1, p1);
                                            }
                                            printf("Pedido eliminado\n");
                                            getch();
                                        }
                                        else
                                        {
                                            printf("No encontrado\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedidos1.codigopedido,longitud)<0)
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
                                fclose(p1);
                                ordenar();
                                    break;

                }

            case 2:
                {
                        ordenar_nombre();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("Introduce el codigo del pedido que deseas eliminar (FIN para salir) => ");
                            scanf("%s", &buscar);
                            MintoMay(buscar);
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

                                    desplazamiento = cen*sizeof(pedidos1);
                                    fseek(p1, desplazamiento, 0);
                                    fread(&pedidos1, sizeof(pedidos1), 1, p1);
                                    if(strncmp(buscar,pedidos1.componente,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedidos1.componente, longitud)==0)
                                        {
                                            printf("Pedido => %ld\n", cen);


                                            printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                            printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                            printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                            printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                            printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                            printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                            printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                            printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                            printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                            printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);
                                            getch();

                                            printf("Deseas eliminar este pedido? (s/n) => ");
                                            fflush(stdin);
                                            scanf("%c", &respuesta);
                                            if(respuesta=='n'|| respuesta=='N')
                                            {
                                                break;
                                            }
                                            if(respuesta=='s'|| respuesta =='S')
                                            {
                                                desplazamiento = n*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fread(&pedidos1, sizeof(pedidos1), 1, p1);

                                                desplazamiento = cen*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fwrite(&pedidos1, sizeof(pedidos1), 1, p1);

                                                n = n -1;

                                                fseek(p1, 0L, 0);
                                                registro0.nregistros= n;
                                                for(k=0;k<44;k++)
                                                {
                                                    registro0.blancos[k]=' ';
                                                }
                                                fwrite(&registro0, sizeof(registro0), 1, p1);
                                            }
                                            printf("Pedido eliminado\n");
                                            getch();
                                        }
                                        else
                                        {
                                            printf("No encontrado\n");
                                            getch();
                                        }

                                    }
                                    else
                                    {
                                        if(strncmp(buscar,pedidos1.componente,longitud)<0)
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
                                fclose(p1);
                                ordenar();
                                    break;





                }


            default:
                {
                    printf("Opcion incorrecta\n");
                }
        }
    }



}


//FUNCION MODIFICACIONES VERSION DE MODIFICAR POR CODIGO Y NOMBRE

void modificaciones(void)
{
    long int n=0, desplazamiento;
    long int longitud, cen, izq, der, seleccion, sw, i;
    char buscar[20];
    char respuesta;
    int k;
    pedidos pedidos1;
    primer_registro registro0;
    FILE *p1;
    p1 =fopen(fpedidos, "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nregistros;

    while(seleccion!=0)
    {
        system("cls");
        printf("1) Modificar por Codigo del pedido\n");
        printf("2) Modificar por Nombre del componente\n");
        printf("0) Salir\n");
        printf("Elige una opcion => ");
        scanf("%ld", &seleccion);
        if(seleccion==0)
        {
            break;
        }
        switch(seleccion)
        {
            case 1:
                {
                        ordenar();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("Introduce el codigo del pedido que deseas modificar (FIN para salir) => ");
                            scanf("%s", &buscar);
                            MintoMay(buscar);
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

                                    desplazamiento = cen*sizeof(pedidos1);
                                    fseek(p1, desplazamiento, 0);
                                    fread(&pedidos1, sizeof(pedidos1), 1, p1);
                                    if(strncmp(buscar,pedidos1.codigopedido,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedidos1.codigopedido, longitud)==0)
                                        {
                                            printf("Pedido => %ld\n", cen);

                                            printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                            printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                            printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                            printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                            printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                            printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                            printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                            printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                            printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                            printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);


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
                                                    printf("Pedido => %ld\n", cen);
                                                    printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                                    printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                                    printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                                    printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                                    printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                                    printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                                    printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                                    printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                                    printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                                    printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);
                                                    printf("\n");
                                                    printf("1) Codigo pedido\n");
                                                    printf("2) Componente del pedido\n");
                                                    printf("3) Pedido realizado\n");
                                                    printf("4) Pedido recibido total\n");
                                                    printf("5) En proceso\n");
                                                    printf("6) Necesidad_total\n");
                                                    printf("7) Necesidad actual\n");
                                                    printf("0) Salir\n");
                                                    printf("Elige una opcion =>");
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
                                                               printf("Introduce el nuevo codigo del pedido => ");
                                                               fflush(stdin);
                                                               gets(pedidos1.codigopedido);
                                                               MintoMay(pedidos1.codigopedido);
                                                               break;
                                                            }
                                                        case 2:
                                                            {
                                                                printf("Introduce la nueva componente  => ");
                                                                fflush(stdin);
                                                                gets(pedidos1.componente);
                                                                MintoMay(pedidos1.componente);
                                                                break;
                                                            }
                                                        case 3:
                                                            {
                                                                printf("Introduce el nuevo pedido realizado => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.pedido_total);
                                                                break;
                                                            }
                                                        case 4:
                                                            {
                                                                printf("Introduce el nuevo pedido recibido total => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.recibido_total);
                                                                break;
                                                            }
                                                        case 5:
                                                            {
                                                                printf("Introduce el nuevo proceso => ");
                                                                fflush(stdin);
                                                                 scanf("%f", &pedidos1.proceso);
                                                                break;
                                                            }
                                                        case 6:
                                                            {
                                                                printf("Introduce la nueva necesidad total => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.necesitad_total);

                                                                break;
                                                            }

                                                        case 7:
                                                            {

                                                                printf("Introduce la nueva necesidad actual => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.necesidad_actual);
                                                            }
                                                        default:
                                                            printf("Opcion incorrecta\n");
                                                            break;
                                                    }

                                                }while(1);

                                                desplazamiento = cen*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fwrite(&pedidos1, sizeof(pedidos1), 1, p1);


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
                                        if(strncmp(buscar,pedidos1.codigopedido,longitud)<0)
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
                        fclose(p1);
                        ordenar();



                        break;

                }


                case 2:
                {
                        ordenar_nombre();
                        do{
                            system("cls");
                            fflush(stdin);
                            printf("Introduce la componente del pedido que deseas modificar (FIN para salir) => ");
                            scanf("%s", &buscar);
                            MintoMay(buscar);
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

                                    desplazamiento = cen*sizeof(pedidos1);
                                    fseek(p1, desplazamiento, 0);
                                    fread(&pedidos1, sizeof(pedidos1), 1, p1);
                                    if(strncmp(buscar,pedidos1.componente,longitud)==0||(izq>=der))
                                    {
                                        sw =1;
                                        if(strncmp(buscar,pedidos1.componente, longitud)==0)
                                        {
                                            printf("Pedido => %ld\n", cen);

                                            printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                            printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                            printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                            printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                            printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                            printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                            printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                            printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                            printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                            printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);


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
                                                    printf("Registro => %ld\n", cen);
                                                    printf("Codigo pedido ===============> %s\n", pedidos1.codigopedido);
                                                    printf("Componente del pedido =======> %s\n", pedidos1.componente);
                                                    printf("Pedido ======================> %.2f\n", pedidos1.pedido_total);
                                                    printf("Pedido Recibido Total =======> %.2f\n", pedidos1.recibido_total);
                                                    printf("Pedido pendiente ============> %.2f\n", pedidos1.pedido_total-pedidos1.recibido_total);
                                                    printf("Stock Total =================> %.2f\n", pedidos1.recibido_total);
                                                    printf("En proceso ==================> %.2f\n", pedidos1.proceso);
                                                    printf("Stock en disposicion ========> %.2f\n", pedidos1.recibido_total-pedidos1.proceso);
                                                    printf("Necesidad Total =============> %.2f\n", pedidos1.necesitad_total);
                                                    printf("Necesidad Actual =============>%.2f\n", pedidos1.necesidad_actual);
                                                    printf("\n");
                                                    printf("1) Codigo pedido\n");
                                                    printf("2) Componente del pedido\n");
                                                    printf("3) Pedido realizado\n");
                                                    printf("4) Pedido recibido total\n");
                                                    printf("5) En proceso\n");
                                                    printf("6) Necesidad_total\n");
                                                    printf("7) Necesidad actual\n");
                                                    printf("0) Salir\n");
                                                    printf("Elige una opcion =>");
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
                                                               printf("Introduce el nuevo codigo del pedido => ");
                                                               fflush(stdin);
                                                               gets(pedidos1.codigopedido);
                                                               MintoMay(pedidos1.codigopedido);
                                                               break;
                                                            }
                                                        case 2:
                                                            {
                                                                printf("Introduce la nueva componente  => ");
                                                                fflush(stdin);
                                                                gets(pedidos1.componente);
                                                                MintoMay(pedidos1.componente);
                                                                break;
                                                            }
                                                        case 3:
                                                            {
                                                                printf("Introduce el nuevo pedido realizado => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.pedido_total);
                                                                break;
                                                            }
                                                        case 4:
                                                            {
                                                                printf("Introduce el nuevo pedido recibido total => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.recibido_total);
                                                                break;
                                                            }
                                                        case 5:
                                                            {
                                                                printf("Introduce el nuevo proceso => ");
                                                                fflush(stdin);
                                                                 scanf("%f", &pedidos1.proceso);
                                                                break;
                                                            }
                                                        case 6:
                                                            {
                                                                printf("Introduce la nueva necesidad total => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.necesitad_total);

                                                                break;
                                                            }

                                                        case 7:
                                                            {

                                                                printf("Introduce la nueva necesidad actual => ");
                                                                fflush(stdin);
                                                                scanf("%f", &pedidos1.necesidad_actual);
                                                            }
                                                        default:
                                                            printf("Opcion incorrecta\n");
                                                            break;
                                                    }

                                                }while(1);

                                                desplazamiento = cen*sizeof(pedidos1);
                                                fseek(p1, desplazamiento, 0);
                                                fwrite(&pedidos1, sizeof(pedidos1), 1, p1);


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
                                        if(strncmp(buscar,pedidos1.componente,longitud)<0)
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
                        fclose(p1);
                        ordenar();



                        break;

                }


            default:
                {
                    printf("Opcion incorrecta\n");
                }
        }
    }



}




//******** FUNCION DE COMPROBAR FICHERO ********

void comprobar()
{
    int k;
    p1 = fopen(fpedidos, "rb");
    if(p1==NULL)
    {
        printf("No hay ningun archivo \n");
        getch();
        system("cls");
        p1=fopen(fpedidos,"w+b");
        printf("Archivo creado\n");
        getch();
        fseek(p1, 0L, 0);
        registro0.nregistros = 0L;
        for(k=0;k<=44;k++)
        {
            registro0.blancos[k] =' ';
        }
        fwrite(&registro0, sizeof(registro0), 1, p1);
    }
    fclose(p1);
}

//******** FUNCION ORDENAR pedidos POR codigp *********
void ordenar(void)
{

    pedidos registro1, registro2;

    long int i, d;
    int sw;


    p1 = fopen(fpedidos, "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(p1, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, p1);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(p1, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, p1);

                if(strcmp(registro1.codigopedido, registro2.codigopedido)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, p1);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, p1);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(p1);
}

//********* FUNCION ORDENAR pedidos POR Componente ********
void ordenar_nombre()
{

    pedidos registro1, registro2;

    long int i, d;
    int sw;
    FILE *p1;

    p1 = fopen(fpedidos, "r+b");
    fseek(p1,0L,0);
    fread(&registro0, sizeof(registro0), 1, p1);
    n = registro0.nregistros;
    d = n;

    while(d>=1)
    {
        d = d/2;
        do{
            sw =0;
            for(i=1;i<=n-d;i++)
            {
                desplazamiento=i*sizeof(registro1);
                fseek(p1, desplazamiento, 0);
                fread(&registro1, sizeof(registro1), 1, p1);

                desplazamiento=(i+d)*sizeof(registro2);
                fseek(p1, desplazamiento, 0);
                fread(&registro2, sizeof(registro2), 1, p1);

                if(strcmp(registro1.componente, registro2.componente)>0)
                {
                    desplazamiento=i*sizeof(registro2);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&registro2, sizeof(registro2), 1, p1);

                    desplazamiento=(i+d)*sizeof(registro1);
                    fseek(p1, desplazamiento, 0);
                    fwrite(&registro1, sizeof(registro1), 1, p1);

                    sw =1;
                }
            }

        }while(sw);
    }
    fclose(p1);
}




//******** FUNCION DE CONVERTIR A MAYUSCULAS ********
void MintoMay(char string[])
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

