//busqueda dicotomica

do{
    printf("buscar numero (fin=0)\n");
    scanf("%d", &x);
    if(x==0){
        break;
    }
    izq=0; //cuando el vector empieza a cero
    der = 10; //tamaño del vector
    do{
        cen = (izq+der)/2;
        if( (x==v[cen]) || (iz>=der)){
            break;
        }
        if(x>v[cen]){
            izq = cen +1;
        }
        else{
            der = cen -1;
        }
    }while(1);
    if(x==v[cen]){
        printf("el valor %d esta en la posicion %d\n", x, cen);
    }
    else{
        printf("No encontrado\n")
    }
}while(x!=0);
