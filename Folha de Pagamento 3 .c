#include <stdio.h>

float calcularAdicionalNoturno(float sal);
float calcularInsalubridade(float sal);
float calcularINSS(float salbru);
float calcularImpostoDeRenda(float salbru);
void calcularPessoaJuridica(float salbru, float aux1, float aux2, float aux3, float aux4);

/**
 *  o que a função faz
 *
 * @param variaveis
 */
void calcularPessoaJuridica(float salbru, float aux1, float aux2, float aux3, float aux4) {
    float acres, pessju, pessju2;
    int reg;

    printf("Deseja calcular para pessoa jurídica?\nDigite 1-sim / 2-não\n");
    int jurid;
    scanf("%d", &jurid);

    if (jurid == 1) {
        printf("Regime tributário:\nDigite 1-Simples Nacional ou MEI\nDigite 2-Lucro Presumido ou Lucro Real\n");
        scanf("%d", &reg);
        if (reg == 1) {
            acres = salbru * 0.3937;
            pessju = salbru + acres;
            printf("\nCusto sem benefícios: R$ %.2f\n", pessju);
            pessju2 = pessju + aux1 + aux2 + aux3 + aux4;
            printf("\nCusto total: R$ %.2f\n", pessju2);
            
      printf("\nFrações: \nFérias: 11,11%% \n13º: 8,33%% \nFGTS: 8%% \nFGTS/Multa Rescisão: 4%% \nPrevidenciário: 7,93%% \nTotal: 39,37%%\n");
            
        } else if (reg == 2) {
            acres = salbru * 0.7324;
            pessju = salbru + acres;   
            printf("\nCusto sem benefícios: R$ %.2f\n", pessju);
            pessju2 = pessju + aux1 + aux2 + aux3 + aux4;
           printf("\nCusto total: R$ %.2f\n", pessju2);
           
    printf("\nFrações: \nFérias: 11,11%% \n13º: 8,33%% \nFGTS: 8%% \nINSS patronal: 20%% \nSistema S: 3,3%% \nDescanso semanal remunerado: 20%% \nSalário Educação: 2,5%% \nTotal: 73,24%%\n");
        }
    }
}

float calcularAdicionalNoturno(float sal) {
    float saln = 0;
    int addn, addnru;

    printf("Possui adicional noturno?\nDigite 1-sim / 2-não\n");
    scanf("%d", &addn);
    if (addn == 1) {
        printf("Digite 1- Rural \nDigite 2- Urbano\n");
        scanf("%d", &addnru);
        if (addnru == 1)
            saln = sal * 0.25;
        else if (addnru == 2)
            saln = sal * 0.2;
    }
    return saln;
}

float calcularInsalubridade(float sal) {
    float salins = 0;
    int lins, ins;

    printf("Trabalha em local insalubre?\nDigite 1-sim / 2-não\n");
    scanf("%d", &lins);
    if (lins == 1) {
        printf("Qual o nível de insalubridade?\nDigite 1 para máxima\nDigite 2 para média\nDigite 3 para mínima\n");
        scanf("%d", &ins);
        if (ins == 1)
            salins = sal * 0.4;
        else if (ins == 2)
            salins = sal * 0.2;
        else if (ins == 3)
            salins = sal * 0.1;
    }
    return salins;
}

float calcularINSS(float salbru) {
    float inss = 0;

    if (salbru <= 1412)
        inss = salbru * 0.075;
    else if (salbru > 1412 && salbru <= 2666.68)
        inss = salbru * 0.09;
    else if (salbru > 2666.68 && salbru <= 4000.03)
        inss = salbru * 0.12;
    else if (salbru > 4000.03)
        inss = salbru * 0.14;

    return inss;
}

float calcularImpostoDeRenda(float salbru) {
    float imprenda = 0;

    if (salbru <= 2259.2)
        imprenda = 0;
    else if (salbru > 2259.21 && salbru <= 2826.65)
        imprenda = salbru * 0.075;
    else if (salbru > 2826.66 && salbru <= 3751.05)
        imprenda = salbru * 0.15;
    else if (salbru > 3751.05 && salbru <= 4664.68)
        imprenda = salbru * 0.225;
    else if (salbru > 4664.68)
        imprenda = salbru * 0.275;

    return imprenda;
}

void calcularFolhaPagamento(float* aux1, float* aux2, float* aux3, float* aux4) {
    float sal, salh, adhex = 0, saln, salp, salins, salbru, salbru2, salliq, inss, imprenda, descontos;
    int hextra, aux, auxt, auxe, auxs;

    printf("Folha de pagamento \n");
    printf("Digite o salário base mensal: ");
    scanf("%f", &sal);

    if (sal < 1412) {
        printf("Não pode ser calculado\n");
        return;
    }

    printf("Digite o valor do salário-hora:\n(Utilize ponto para separar os centavos)\n");
    scanf("%f", &salh);

    printf("\nPossui hora extra?\nDigite 1-sim / 2-não\n");
    scanf("%d", &hextra);
    if (hextra == 1) {
        printf("Quantas horas extras?\n");
        scanf("%f", &adhex);
        adhex = adhex * (salh * 1.5);
    }

    saln = calcularAdicionalNoturno(sal);
    salp = (adhex > 0) ? sal * 0.3 : 0; // Adicional de periculosidade

    salins = calcularInsalubridade(sal);

    printf("Recebe auxílio alimentação?\nDigite 1-sim / 2-não\n");
    scanf("%d", &aux);
    if (aux == 1) {
        printf("Digite o valor do auxílio alimentação: ");
        scanf("%f", aux1);
    }

    printf("Recebe auxílio transporte?\nDigite 1-sim / 2-não\n");
    scanf("%d", &auxt);
    if (auxt == 1) {
        printf("Digite o valor do auxílio transporte: ");
        scanf("%f", aux2);
    }

    printf("Recebe auxílio educação?\nDigite 1-sim / 2-não\n");
    scanf("%d", &auxe);
    if (auxe == 1) {
        printf("Digite o valor do auxílio educação: ");
        scanf("%f", aux3);
    }

    printf("Recebe auxílio saúde?\nDigite 1-sim / 2-não\n");
    scanf("%d", &auxs);
    if (auxs == 1) {
        printf("Digite o valor do auxílio saúde: ");
        scanf("%f", aux4);
    }

    salbru2 = sal + adhex + saln + salp + salins + *aux1 + *aux2 + *aux3 + *aux4;
    printf("\nSalário bruto: %.2f\n", salbru2);

    salbru = sal + adhex + saln + salp + salins;
    inss = calcularINSS(salbru);
    imprenda = calcularImpostoDeRenda(salbru);

    descontos = inss + imprenda;
    salliq = salbru - descontos + *aux1 + *aux2 + *aux3 + *aux4;
    printf("Salário líquido: %.2f\n", salliq);
    printf("Descontos: %.2f\n", descontos);

    
    calcularPessoaJuridica(salbru2, *aux1, *aux2, *aux3, *aux4);
}


int main(void) {
    float aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;
    calcularFolhaPagamento(&aux1, &aux2, &aux3, &aux4);

    return 0;
}
