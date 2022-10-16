#include <stdio.h>
#include <stdlib.h>

void gerarSenha(int SENHA[4]);

int main()
{
	int SENHA[4], senhadig[4], result[4];
	int i, tentativa=0, aux=0;
	
	gerarSenha(SENHA);
	
	printf("\nBem vindo ao jogo da senha!!\nVoce tera 10 tentativas para acertar a senha gerada aleatoriamente de 4 digitos.\n");
	printf("\nPara um digito correto na posicao correta, resultado 1.\nPara um digito correto na posicao errada, resultado 0.\nPara um digito incorreto, resultado -1.\n");
	
	while(tentativa<10)
	{
		tentativa=tentativa+1;
		aux=0;
		
		for(i=0;i<4;i++)
		{
			printf("\n%d numero:\n", i+1);
			scanf("%d", &senhadig[i]);
		}
		
		printf("\nTentativa:");
		
		for(i=0;i<4;i++)
		{
			printf(" %i ", senhadig[i]);
		}
		
			printf("\n");
		
		for(i=0;i<4;i++)
		{
			result[i]=-1;
		}
	
		for(i=0;i<4;i++)
		{
			if(SENHA[i]==senhadig[i])
			{
				result[i]=1;
			}
				
			if((SENHA[i]==senhadig[i+1])||(SENHA[i]==senhadig[i+2])||(SENHA[i]==senhadig[i+3]))
			{
				result[i]=0;
			}	
		}
		
		printf("\nResultado:");
		
		for(i=0;i<4;i++)
		{
			printf(" %i ", result[i]);
		}
		
		for(i=0;i<4;i++)
		{
			if(result[i]==1)
			{
				aux=aux+1;
			}
			
		}
		
		if(aux==4)
		{
			printf("\nParabenss, objetivo concluido.\n");
			tentativa=10;	
			break;
		}
		
		if(tentativa==10)
		{
			printf("\nSuas tentativas acabaram.   :( \n");
		}
	}
		
	
	
	
return 0;
}
	

void gerarSenha(int SENHA[4])
{
	int i;
	
	for(i=0;i<4;i++)
	{
		SENHA[i]=rand()%9;
	}
}

