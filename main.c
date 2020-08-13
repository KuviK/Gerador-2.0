#include <stdio.h>
#include <stdlib.h>

/* Função: aplicação que gera aleatoriamente 100 numeros positivos entre 0 e 1000 e que calcula a soma e a media dos numeros que sao primos.
   Autor:  Luís Filipe */

//Declaração sub-rotinas
int Divisor(int numero);
int Primo(int divisor, int numero);

int main(int argc, char *argv[]) {

	//Declarar variaveis
	int numero,i,soma,divisor, contador;
	float media;
	
	//limpar ecra
	system("cls");
	
	//Inicializar Variaveis
	soma = 0;
	divisor = 0;
	contador = 0;
	
	//relacionar a geraçao aleatorio à hora do sistema
	srand(time(NULL));
	
	//gerar numeros aleatorios
	for(i = 0; i < 100; i++)
	{
		//gerar numero aleatorio
		numero = rand() % 1000;
		
		//Mostrar numero gerado 
		printf("%02dº gerado: %d\n", (i+1), numero);
		
		divisor = Divisor(numero);
		
		//Apresentar numeros primos e somar o numero de primos encontrados
		if(Primo(numero, divisor) == 1)
		{
			printf("\t%d e primo\n",numero);
			soma+=numero; //Soma de todos os numeros primos;
		}

		//Chamar função
		contador = contador + Primo(numero, divisor);
	}
	
	//Calculo da media
	media= (float)soma / contador;
	
	//Apresentação dos dados obtidos
	printf("\nA soma dos numeros primos e: %d", soma);
	printf("\nA media dos primos e: %.2f\n", media);
	
	//pausa
	getchar();
	
}




/*
	Esta função verifica se o numero é primo e retorna o numero de primos encontrados
*/	
int Primo(int numero, int divisor)
{	
	//Declarar Variaveis Locais
	int contador;
	
	//Inicializar Variaveis
	contador = 0;
	
	//verificar se o número é primo 
	if (divisor == 2)
	{
		contador++;	//Contar o numero de primos encontrados;
	}
	
	//Retornar numero de primos encontrados
	return contador;
	
}





/*
	Esta função descobre por quantos numeros é divisivel o numero gerado
*/	
int Divisor(int numero)
{	
	//Declarar Variaveis Locais
	int i, div;
	
	//Inicializar Variaveis
	div = 0;
	
	//Apurar por quantos números o numero gerado é divisivel 
	for (i = 1; i <= numero; i++)
	{
		if (numero % i == 0)
			div++;
	}
	
	//Retornar por quantos numeros e divisivel
	return div;
}
