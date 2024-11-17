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
