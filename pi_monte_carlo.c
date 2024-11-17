#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
double x_do_ponto = 0, y_do_ponto = 0, pi = 0, total_pontos = 0, pontos_no_circulo = 0;

srand(time(NULL));
total_pontos = rand() % 100000000 + 1;

for(int i = 0; i < total_pontos; i++)
{

x_do_ponto = rand() % 100000000 + 1;
y_do_ponto = rand() % 100000000 + 1;
x_do_ponto = x_do_ponto / 100000000;
y_do_ponto = y_do_ponto / 100000000;
 pontos_no_circulo = (((x_do_ponto * x_do_ponto) + (y_do_ponto * y_do_ponto)) <= 1) ?
(pontos_no_circulo + 1) : pontos_no_circulo;
}
pi = (4 * pontos_no_circulo / total_pontos);
printf("\n o número de simulações (total de pontos): %i \n", (int)total_pontos);
printf(" π é aproximadamente: %.10lf \n", pi, );
 return 0;
}