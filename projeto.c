void chavepublica ()
{
    long long int p, q;

    printf("\nDigite dois números primos\n\n");
    printf("p: ");
    scanf("%lld", &p);

    int a = primo (p);

    while (a == 0)
    {
        printf("\nO número %lld não é primo! Tente novamente.\n", p);

        printf("p: ");
        scanf("%lld", &p);

        a = primo (p);
    }
    
    printf("q: ");
    scanf("%lld", &q);

    int b = primo(q);

    while (b == 0)
    {
        printf("\nO número %lld não é primo! Tente novamente.\n", q);

        printf("q: ");
        scanf("%lld", &q);

        b = primo(q);
    }

    long long int phi = (p - 1)*(q - 1);
    long long int e;

    printf("\nDigite um número relativamente primo a %lld:\n\ne: ", phi);
    scanf("%lld", &e);

    while (mdc(phi, e) != 1)
    {
        printf("\n%lld e %lld não são coprimos! Tente novamente.\n\n", phi, e);

        printf("Digite um número relativamente primo a %lld:\ne: ", phi);
        scanf("%lld", &e);
    }

    long long int n;
    n = p*q;

    FILE *chavepublica = fopen("chave.txt", "w");
    fprintf(chavepublica, "n: %lld\ne: %lld", n, e);
    fclose(chavepublica);
    
    printf("\nCHAVE PÚBLICA GERADA COM SUCESSO!\n\n");

    return;
}

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
