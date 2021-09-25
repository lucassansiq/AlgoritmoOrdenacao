#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Quick sort function
void Quick(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);  

}


//BubbleSort Function
void bubbleSort (int TAM,int v[TAM]) {
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}


//Function para Imprimir o QuickSort
void imprimeQuick(int vetor[],int inicio,int fim,int tam){
   int i;   
   printf("Vetor desordenado:\n");
   for(i = 0; i < tam; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");   
   
   Quick(vetor, inicio, fim);
   
   printf("Vetor ordenado:\n");
   for(i = 0; i < tam; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");   
}


//Function para imprimir o BubbleSort
void imprimeBubble(int TAM,int numeros[TAM]){
int i;	
printf("Ordem atual dos itens no array:\n");
for (i = 0; i < TAM; i++) {
 printf("%4d", numeros[i]);
}

bubbleSort(TAM,numeros);

printf("\nElementos do array em ordem crescente:\n");
for (i = 0; i < TAM; i++) {
 printf("%4d", numeros[i]);
}
printf("\n");
}


// Function pra mostrar o tempo de exec. BubbleSort
int tempoBubble(int TAM,int vetor[TAM]){
	
	clock_t Ticks[2];
    Ticks[0] = clock();
    bubbleSort(TAM,vetor);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 100.0 / CLOCKS_PER_SEC;
    //printf("\nTempo gasto pelo BubbleSort: %g ms.\n", Tempo);
    return Tempo;
}


// Function pra mostrar o tempo de exec. QuickSort
int tempoQuick(int vetor[], int inicio, int fim){
	clock_t Ticks[2];
    Ticks[0] = clock();
    Quick(vetor,inicio,fim);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 100.0 / CLOCKS_PER_SEC;
    //printf("\nTempo gasto em QuickSort: %g ms.\n", Tempo);
    return Tempo;	
}


//Funcao para Menu de vetores Aleatorios
void escolhaAleatoria(){
	int i,res,TAM;
	int tempoB,tempoQ;
	
	printf("Informe o tamanho do vetor desejado:");
	scanf("%d",&TAM);
	
	int vetor[TAM];
	//geração aleatório dos valores do vetor
 	srand(time(NULL));
	for(i=0;i<TAM;i++){
		vetor[i] = ("%d ", rand() %100);
	}
	getch();
	
	tempoB = tempoBubble(TAM,vetor);
	printf("\nTempo gasto pelo BubbleSort: %d ms.\n",tempoB) ;
	
	tempoQ = tempoQuick(vetor,0,TAM);
	printf("\nTempo gasto em QuickSort: %d ms.\n",tempoQ);
	
	if(tempoB > tempoQ){
		res = tempoB - tempoQ;}
	else{
		res = tempoQ - tempoB;}
	
	printf("\nA diferenca de tempo eh:%d\n\n\n", res);
}


//Imprimir ordenacao de vetor em arquivo txt
void arquivoImprime(){
	int i = 0;
    	int numPalavras = 0;
    	int* numeros[50];
    	int line[50];
    	int TAM,vezes;
    	char c, letra = '\n';
    	int res;
    	
    	printf("ARQUIVO TXT: \n");
		printf("TENHA OS DADOS ARMAZENADOS NO ARQUIVO NOTAS! \n");
		printf("NA PASTA RAIZ\n\n");

   	 	FILE *arquivo;
    	arquivo = fopen("notas.txt", "r");

    	if (arquivo == NULL)
        	return EXIT_FAILURE;
        	
    	//Lendo o arquivo 1 por 1
        while(fread (&c, sizeof(char), 1, arquivo)) {
            if(c == letra) {
                vezes++;
            }
        } 
        
        TAM = vezes;

    	while(fgets(line, sizeof line, arquivo) != NULL)
    	{
        	//Adiciona cada palavra no vetor
        	numeros[i] = strdup(line);

        	i++;

        	//Conta a quantidade de palavras
        	numPalavras++;
    	}
    	fclose(arquivo);
    	
    	printf("*Digite 1 - QUICKSORT                              *\n");
		printf("*Digite 2 - BUBBLESORT                             *\n");
		scanf("%d", &res);
		if (res == 1) imprimeQuick(numeros,0,TAM,TAM);
		else if(res == 2) imprimeBubble(TAM,numeros);
}


//imprime vetor ordenado aleatorio
void aleatorioImprime(){
		int res,TAM,i;
		int vetor[TAM];
		printf("****************************************************\n");
		printf("* VETOR ALEATORIO:                                 *\n");
		printf("*Digite 1 - QUICKSORT                              *\n");
		printf("*Digite 2 - BUBBLESORT                             *\n");
		scanf("%d", &res);
		if(res == 1){
			printf("QUICKSORT: \n");
			printf("Informe o tamanho do vetor desejado:");
			scanf("%d",&TAM);
			
 			srand(time(NULL));
			for(i=0;i<TAM;i++){
				vetor[i] = ("%d ", rand() %100);
			}
			getch();
			imprimeQuick(vetor,0,TAM,TAM);
		}
		else if(res == 2){
			printf("BUBBLESORT: \n");
			printf("Informe o tamanho do vetor desejado:");
			scanf("%d",&TAM);
			
 			srand(time(NULL));
			for(i=0;i<TAM;i++){
				vetor[i] = ("%d ", rand() %100);
			}
			getch();
			imprimeBubble(TAM,vetor);
		}
		else{
			printf("Valor invalido\n\n");
			main();
		} 
		
	}
	

//Medi tempo de ordenacao em arquivo txt	
void arquivoTempo(){
		int i = 0;
    	int numPalavras = 0;
    	int* numeros[50];
    	int line[50];
    	int TAM,vezes;
    	char c, letra = '\n';
    	int res,resultado;
    	int tempoB,tempoQ;
    	
    	printf("ARQUIVO TXT: \n");
		printf("TENHA OS DADOS ARMAZENADOS NO ARQUIVO NOTAS! \n");
		printf("NA PASTA RAIZ\n\n");

   	 	FILE *arquivo;
    	arquivo = fopen("notas.txt", "r");

    	if (arquivo == NULL)
        	return EXIT_FAILURE;
        	
    	//Lendo o arquivo 1 por 1
        while(fread (&c, sizeof(char), 1, arquivo)) {
            if(c == letra) {
                vezes++;
            }
        } 
        
        TAM = vezes;

    	while(fgets(line, sizeof line, arquivo) != NULL)
    	{
        	//Adiciona cada palavra no vetor
        	numeros[i] = strdup(line);

        	i++;

        	//Conta a quantidade de palavras
        	numPalavras++;
    	}
    	fclose(arquivo);
    	
		tempoB = tempoBubble(TAM,numeros);
		printf("\nTempo gasto pelo BubbleSort: %d ms.\n",tempoB) ;
	
		tempoQ = tempoQuick(numeros,0,TAM);
		printf("\nTempo gasto em QuickSort: %d ms.\n",tempoQ);
	
		if(tempoB > tempoQ){
		resultado = tempoB - tempoQ;}
		else{
		resultado = tempoQ - tempoB;}
	
		printf("\nA diferenca de tempo eh:%d\n\n\n", resultado);
}


//menu de ordenacao
void escolhaOrdenar(){
	int res;

	printf("****************************************************\n");
	printf("* ORDENAR VETOR:                                   *\n");
	printf("*Se o vetor for aleatorio      - digite 1          *\n");
	printf("*Se o vetor for um arquivo txt - digite 2          *\n");	
	scanf("%d",&res);
	if(res == 1){		
		aleatorioImprime();
	}
	
	//Implementar arquivo txt                                                       AAAAAQUIIIIIII
	else if(res == 2){
		arquivoImprime();
	}
	else{
		printf("Valor invalido\n\n");
		main();
	}
	
}


//menu de medicao de tempo
void escolhaTempo(){
	int res,TAM,i;
	int vetor[TAM];
	
	printf("****************************************************\n");
	printf("* TEMPO DE EXECUCAO PELOS DOIS METODOS:            *\n");
	printf("*Se o vetor for aleatorio      - digite 1          *\n");
	printf("*Se o vetor for um arquivo txt - digite 2          *\n");	
	scanf("%d",&res);
	if (res == 1){
		printf("VETOR ALEATORIO: \n");
		escolhaAleatoria();
	}
	else if(res == 2){
		arquivoTempo();	
	}
	else{
		printf("Valor Invalido \n \n");
		main();
	}
	
}


int main(){
	int res;
	char resposta;
	
	printf("****************************************************\n");
	printf("*##################################################*\n");
	printf("*####   ###   ###        ###   #### ### ###### ####*\n"); 
	printf("*#### # ### # ### ########## ## ### ### ###### ####*\n");
	printf("*#### ## # ## ###      ##### ### ## ### ###### ####*\n");
	printf("*#### ### ### ### ########## #### # ### ###### ####*\n");
	printf("*#### ####### ### ########## #####  ### ###### ####*\n");
	printf("*#### ####### ###        ### ###### ###        ####*\n");
	printf("*##################################################*\n");
	printf("*                                                  *\n");
	printf("*Se deseja Ordenar um vetor        - digite 1      *\n");
	printf("*Se deseja medir tempo de execucao - digite 2      *\n");
	printf("*Digite:                                           *\n");
	scanf("%d",&res);
	if(res == 1){
		escolhaOrdenar();
	}
	else if(res == 2){
		escolhaTempo();
	}
	else{
		printf("Valor Invalido \n \n");
		main();
	}
	printf("DESEJA CONSULTAR NOVAMENTE:");
	scanf("%s",&resposta);
	if (resposta == 'sim' || resposta == 's') main();
	
	
	
	system("pause");
	}
 

