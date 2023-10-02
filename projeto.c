#include <stdio.h>
#include <string.h>
#include <ctype.h>

long long int inverso (long long int a, long long int b, long long int a1, long long int b1, long long int x, long long int y, long long int s, long long int t)
{
    if (s*a + t*b == 1)
    {
        if (s < 0)
        {
            s += b;
        }
        if (s > b)
        {
            while (s > b)
            {
                s -= b;
            }
        }

        return s;
    }
    else
    {
        int sn, tn;

        sn = x - (a1/b1)*s;
        tn = y - (a1/b1)*t;

        inverso (a, b, b1, a1%b1, s, t, sn, tn);
    }
}

int tamanho (char controle[], int x)
{
    int n;

    if (controle[x - 1] == ' ')
    {
        n = 0;
    }
    else
    {
        n = 1;
    }

    int i;
    for (i = 0; i < x; i++)
    {
        if (controle[i] == ' ')
        {
            n++;
        }
    }

    return n;
}

void conversao (long long int cifra[], char mensagem[], int tam)
{
    int ascii[tam];

    int i;
    for (i = 0; mensagem[i] != '\n' && mensagem[i] != '\0'; i++)
    {
        ascii[i] = mensagem[i];
    }

    long long int n, e;
    
    printf("\nDigite a chave pública:\n\n");
    
    printf("n: ");
    scanf("%lld", &n);

    printf("e: ");
    scanf("%lld", &e);

    or(i = 0; i < tam - 1; i++)
    {
        long long int pot = 1;
        for (int j = 0; j < e; j++)
        {
            pot = (pot * ascii[i])%n;
        }

        cifra[i] = pot;
    }

    cifra[i] = 0;

    return;
}

int mdc (long long int a, long long int b)
{
    if (a > b)
    {
        while (a%b != 0)
        {
            long long int aux;
            aux = a;

            a = b;
            b = aux%a;
        }

        return b;
    }
    else
    {
        while (b%a != 0)
        {
            long long int aux;
            aux = b;

            b = a;
            a = aux%b;
        }

        return a;
    }
}

int primo (long long int a)
{
    long long int b;

    if (a <= 1)
    {
        return 0;
    }
    else
    {
        for (b = a - 1; b > 1; b--)
        {
            if (a%b == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void desencriptando ()
{
    FILE *cripto;
    cripto = fopen("mensagem.txt", "r");

    if (cripto == NULL)
    {
        printf("Arquivo de mensagem não encontrado!\n");
    }
    else
    {
        printf("Arquivo de mensagem encontrado!\n");

        char controle[1000000];
        fgets(controle, 1000000, cripto);
        fclose(cripto);
        
        int x;
        x = strlen(controle);

        int n;
        n = tamanho(controle, x) + 1;

        long long int cifra[n];
        int j = 0;
    
        int i;
        for (i == 0; i < n && controle[j] != '\0'; i++)
        {
            cifra[i] = 0;
        
            if (isdigit(controle[j]) != 0)
            {
                while (isdigit(controle[j]) != 0)
                {
                    cifra[i] = 10*(cifra[i]) + (controle[j] - '0');

                    j++;
                }
            }
            else
            {
                j++;
                i--;    
            }
        }

        long long int e, p, q;
        printf("\nDigite os valores de...\n");
        printf("e: ");
        scanf("%lld", &e);
        printf("p: ");
        scanf("%lld", &p);
        printf("q: ");
        scanf("%lld", &q);

        long long int d;
        int phi = (p - 1)*(q - 1);
        d = inverso (e, phi);

        FILE *mensagem;
        mensagem = fopen ("mensagem.txt", "w");
        
        for (i = 0; i < n; i++)
        {
            long long int pot = 1;
            for (j = 0; j < d; j++) 
            {
                pot = (pot * cifra[i])%a;
            }

            char caractere = pot;

            fprintf(mensagem, "%c", caractere);
        }

        fclose(mensagem);

        printf("\nMENSAGEM DESENCRIPTADA COM SUCESSO!\n\n");
    }
    
    return;
}

void encriptando ()
{
    char mensagem[1000000];
    
    printf("Digite a mensagem:\n");
    scanf(" ");
    fgets(mensagem, 1000000, stdin);

    int tam;
    tam = strlen(mensagem);
    
    long long int cifra[tam];

    conversao (cifra, mensagem, tam);

    FILE *cripto = fopen("mensagem.txt", "w");
    
    int i;
    for (i = 0; cifra[i] != 0; i++)
    {
        fprintf(cripto, "%lld ", cifra[i]);
    }

    fclose(cripto);

    printf("\nMENSAGEM ENCRIPTADA COM SUCESSO\n\n");

    return;
}

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
