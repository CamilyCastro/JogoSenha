#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarSenha(int SENHA[4]);

int main()
{
    int SENHA[4], senhadig[4], result[4];
    int i, j, tentativa = 0, aux = 0;

    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    gerarSenha(SENHA);

    printf("\nBem-vindo ao jogo da senha!!\nVocê terá 10 tentativas para acertar a senha gerada aleatoriamente de 4 dígitos.\n");
    printf("\nPara um dígito correto na posição correta, resultado 1.\nPara um dígito correto na posição errada, resultado 0.\nPara um dígito incorreto, resultado -1.\n");

    while (tentativa < 10)
    {
        tentativa++;
        aux = 0;

        printf("\nTentativa %d: Insira 4 números (0 a 9):\n", tentativa);
        for (i = 0; i < 4; i++)
        {
            printf("%dº número: ", i + 1);
            scanf("%d", &senhadig[i]);
        }

        printf("\nTentativa: ");
        for (i = 0; i < 4; i++)
        {
            printf("%d ", senhadig[i]);
        }
        printf("\n");

        // Inicializa o resultado com -1 (incorreto)
        for (i = 0; i < 4; i++)
        {
            result[i] = -1;
        }

        // Verifica dígitos na posição correta
        for (i = 0; i < 4; i++)
        {
            if (SENHA[i] == senhadig[i])
            {
                result[i] = 1;  // Posição correta
            }
        }

        // Verifica dígitos corretos na posição errada
        for (i = 0; i < 4; i++)
        {
            if (result[i] == 1) continue; // Ignora os já corretos
            for (j = 0; j < 4; j++)
            {
                if (i != j && SENHA[i] == senhadig[j] && result[j] != 1)
                {
                    result[j] = 0; // Posição errada
                    break;
                }
            }
        }

        printf("\nResultado: ");
        for (i = 0; i < 4; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");

        // Conta dígitos na posição correta
        aux = 0;
        for (i = 0; i < 4; i++)
        {
            if (result[i] == 1)
                aux++;
        }

        if (aux == 4)
        {
            printf("\nParabéns, você acertou a senha!\n");
            break;
        }

        if (tentativa == 10)
        {
            printf("\nSuas tentativas acabaram. A senha era: ");
            for (i = 0; i < 4; i++)
            {
                printf("%d", SENHA[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

void gerarSenha(int SENHA[4])
{
    int i, j, numero;
    for (i = 0; i < 4; i++)
    {
        do
        {
            numero = rand() % 10; // Gera números de 0 a 9
            for (j = 0; j < i; j++)
            {
                if (SENHA[j] == numero)
                    break; // Evita duplicados
            }
        } while (j < i);
        SENHA[i] = numero;
    }
}
