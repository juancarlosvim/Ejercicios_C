#include <stdio.h>
//Ant_4_32_V1. Algoritmo que escriba un programa en C que calcule y muestre los valores de un
//intervalo de temperatura en grados Fahrenheit y grados cent�grados. El usuario seleccionar� la temperatura
//m�s baja y m�s alta, as� como el incremento de temperatura. La relaci�n matem�tica es:
//F=(9/5)C+32, donde F= Temperatura en grados Fahrenheit. C= Temperatura en grados cent�grados.

float miFuncion(float, float, float);
float pasarGrados();
int main()
{
    float minVal, maxVal, incremento;
    printf("Introduce la temperatura minima: ");
    scanf("%f", &minVal);
    printf("Introduce la maxima temperatura: ");
    scanf("%f", &maxVal);
    printf("Introduce el incremento: ");
    scanf("%f", &incremento);

    miFuncion(minVal,maxVal, incremento);
}

float miFuncion(float minVal, float maxVal, float incremento)
{
    float contador, f;
    printf("�C\t�F\n");
    for(contador=minVal;contador<=maxVal;contador+=incremento)
    {

        f = (9.0/5.0)*minVal+32;


        printf("%.2f\t%.2f\n", f, contador);
        minVal =minVal+ incremento;
    }
return 0;
}
