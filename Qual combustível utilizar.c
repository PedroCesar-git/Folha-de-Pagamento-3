#include <stdio.h>

// UNIVERSIDADE ESTADUAL DE SANTA CRUZ
// DISCENTE: José de Carvalho Costa Neto
// Atividade de Qual combustível utilizar
// Para o GNV foi usado um cilindro de 7.5m3

int cetanol;
int ggsnv;
int disesc;
int combesc;
int mediac;
int medesc;




int main(void) {



  printf("Qual distância deseja percorrer em Km?\n\n");
  scanf("%d",&disesc);

  printf("Qual a média de consumo do seu automóvel(Valor dado/L)? (Digite 0 para usar a média de consumo)\n\n");
  scanf("%d",&medesc);

  if (medesc == 0){

  float mediag = 10.7;
  float mediae = 7.5;
  float mediagnv = 13.2;

  float valorg = 6.07;
  float valore = 4.04;
  float valorgnv = 5.24;

  float valort1 = (disesc/mediag)*valorg;
  float valort2 = (disesc/mediae)*valore;
  float valort3 = (disesc/mediagnv)*valorgnv;

  

  if ((valort1 < valort2) && (valort1 < valort3)){
    printf("O melhor combustível custo/benefício a ser utilizado é: Gasolina\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort1);
  }

  if ((valort2< valort3) && (valort2< valort3)) {
    printf("O melhor combustível custo/benefício a ser utilizado é: Etanol\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort2);
  }

  if ((valort3 < valort1) && (valort3 < valort2)) {
    printf("O melhor combustível custo/benefício a ser utilizado é: GNV\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort3);
  }

}

if (medesc != 0){

  float valorg = 6.07;
  float valore = 4.04;
  float valorgnv = 5.24;

  float valort1 = (disesc/medesc)*valorg;
  float valort2 = (disesc/medesc)*valore;
  float valort3 = (disesc/medesc)*valorgnv;



  if ((valort1 < valort2) && (valort1 < valort3)){
    printf("O melhor combustível custo/benefício a ser utilizado é: Gasolina\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort1);
  }

  if ((valort2< valort3) && (valort2< valort3)) {
    printf("O melhor combustível custo/benefício a ser utilizado é: Etanol\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort2);
  }

  if ((valort3 < valort1) && (valort3 < valort2)) {
    printf("O melhor combustível custo/benefício a ser utilizado é: GNV\n\n");
    printf("VALOR GASTO:\n""$""%f""\n\n\n\n",valort3);
  }
}
  return 0;
}
