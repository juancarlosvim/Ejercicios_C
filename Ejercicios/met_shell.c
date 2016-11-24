//metodo shell

d=10 //tamaño del vector
while(d!=1){
    d = d/2;
    sw =1;
    while(sw==1){
        sw =0;
       for(i=0;i<10-d;i++)
       {
           if(v[i]>v[i+d])
           {
               aux = v[i+d];
               v[i+d] = v[i];
               v[i] = aux;
               sw = 1;
           }
       }
    }
}
//imprime vector ordenado
    puts("");
    printf("vector ordenado\n");
    for(i=0;i<10;i++)
    {
        printf("%3d\t", v[i]);
    }
