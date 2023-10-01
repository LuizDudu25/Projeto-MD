int main()
{
    printf("Escolha uma das opções abaixo:\n\n");
    printf("1 - Gerar chave pública\n");
    printf("2 - Encriptar mensagem\n");
    printf("3 - Desencrpitar mensagem\n\n");

    int x;
    printf("Digite a opção escolhida: ");
    scanf("%d", &x);
    
    while (x < 1 || x > 3)
    {
        printf("\nNúmero digatado inválido! Tente novamente.\n\n");

        printf("Digite a opção escolhida: ");
        scanf("%d", &x);
    }
    
    if (x == 1)
    {
        printf("\nGERAR CHAVE PÚBLICA\n");

        chavepublica();
    }
    else if (x == 2)
    {
        printf("\nENCRIPTAR MENSAGEM\n\n");

        encriptando();
    }
    else
    {
        printf("\nDESENCRIPTAR MENSAGEM\n\n");

        desencriptando();
    }

    return 0;
}
