#include <stdio.h>
#include <math.h>

void calcular_hexagono(float l, float *area, float *perimetro){
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    *perimetro = 6 * l;
}

int main(void){
    float l, area, perimetro;
    printf("Informe o valor do lado: ");
    scanf("%f", &l);
    calcular_hexagono(l, &area, &perimetro);
    printf("O valor da área é: %.2f\n", area);
    printf("O valor do perímetro é: %.2f\n", perimetro);
    return 0;
}