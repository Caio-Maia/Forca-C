/* Projeto da Forca UFPB
Integrantes: Caio Jordan de Lima Maia
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Variavel Global para sorteio de uma palavra
unsigned int palavra_sorteada;

void main(){		//Primeiro Menu
	inicio();
}

void menu(){	//Segundo Menu
	int opcao;
	printf("\t\t\t _____________________________________\n");
	printf("\t\t\t|                                     |\n");
	printf("\t\t\t|            Jogo da Forca            |\n");
	printf("\t\t\t|                                     |\n");
	printf("\t\t\t=======================================\n\n");
	printf("\t\t\t0. Voltar ao Menu\n");
	printf("\t\t\t1. Objetos\n");
	printf("\t\t\t2. Animais\n");
	printf("\t\t\t3. Profissoes \n");
	printf("\t\t\t4. Paises\n");
	scanf("%i", &opcao);
	if(opcao==0){
		apagar();
		main();
	}
	else if(opcao==1){
		apagar();
		objetos();
	}
	else if(opcao==2){
		apagar();
		animais();
	}
	else if(opcao==3){
		apagar();
		profissoes();
	}
	else if(opcao==4){
		apagar();
		paises();
	}
	
}

int inicio() {
	int opcao;
	printf("\t\t\t _____________________________________\n");
	printf("\t\t\t|                                     |\n");
	printf("\t\t\t|            Jogo da Forca            |\n");
	printf("\t\t\t|                                     |\n");
	printf("\t\t\t=======================================\n\n");
	printf("\t\t\t1. Jogar Agora\n");
	printf("\t\t\t2. Sair do Jogo\n");
	scanf("%i", &opcao);
	if(opcao==1){
		apagar();
		menu();
	}
	else if(opcao==2){
		return 0;
	}
	else {
		apagar();
		main();
	}
}

void apagar(){	//Função para limpar a tela
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#endif
	
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void sortear(){	//Função para sortear uma palavra
	srand(time(NULL));
	palavra_sorteada = rand() % 25;
}

void objetos(){	//Função para forca de objetos
	
	//Declarações
	int j;
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    char letra;

    FILE *arquivo;
    arquivo = fopen("objetos.txt", "r"); //nome do arquivo txt onde encontra as palavras da forca

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor / matriz
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
    //Declarações 2
    int palavra_correta=0;
    int tamanho;
    int tentativas=0;
    int acertou=0;
    int errou=0;
    int letra_correta[10] = {0,0,0,0,0,0,0,0,0,0};
    int k;
    char sim = {'s'};
    char nao = {'n'};
    char jogar_novamente;
    sortear();   //Sorteia uma palavra
    tamanho =strlen(palavras[palavra_sorteada]) - 1; //tamanho da palavra
    printf("\n");
    for(k = 0; k<tamanho; k++){         //Representar cada letra da palavra ainda não descoberta
    	printf(" _ ");
	}
	printf("\n\nTentativas: 0 Errou: 0\n"); //Tentativas e Erros
	printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n"); //Forca
	//while para cada tentativa em descobrir a palavra
    while(1){
    	errou=0;
    	printf("\n\nDigite uma Letra: ");
    	//escaneia a letra e printa
		scanf("%s", &letra);
		//Função para limpar tela
		apagar();
    	printf("\nA letra digitada foi:%c\n", letra);
    	//Faz o teste, se a letra corresponder a alguma da palavra, substitui o _ pela letra
    	for(j = 0; j<tamanho; j++){
    		if((palavras[palavra_sorteada][j] == letra) || (letra_correta[j]==1)){
    			letra_correta[j]=1;
    			printf(" %c ", palavras[palavra_sorteada][j]);
			}
			else{
				printf(" _ ");
			}
		}
		for(j = 0; j<tamanho; j++){
			if(palavras[palavra_sorteada][j] == letra){
				acertou++;
				break;
			}
			else{
				continue;
			}
		}
		//Fim dos testes
		printf("\n\n");
		//Printa quantas vezes tentou e errou pelo numero de tentativas menos os acertos
		tentativas++;
		errou = tentativas - acertou;
		printf("Tentativas: %i Errou: %i \n", tentativas, errou);
		//Faz o teste para saber se a palavra está completa
		palavra_correta=0;
		for(k = 0; k<tamanho; k++){
			if(letra_correta[k]==1){
				palavra_correta++;
			}
			else if(letra_correta[k]==0){
				palavra_correta--;
			}
		}
		//Fim do teste
		//If else para erros na forca e para saber se ganhou ou perdeu
		if(palavra_correta == tamanho){
			apagar();
			printf("Parabens voce Venceu! A Palavra era: %s\n", palavras[palavra_sorteada]);
			break;
		}
		else if(errou==0){
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==1){
			printf("   ________\n   |      |\n   |      O\n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==2){
			printf("   ________\n   |      |\n   |      O\n   |      |  \n   |        \n   | \n==========\n");
		}
		else if(errou==3){
			printf("   ________\n   |      |\n   |      O\n   |     (|  \n   |        \n   | \n==========\n");
		}
		else if(errou==4){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |        \n   | \n==========\n");
		}
		else if(errou==5){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /   \n   | \n==========\n");
		}
		else if(errou==6){
			apagar();
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /) \n   | \n==========\n");
			printf("Voce foi ENFORCADO! A Palavra era: %s\n", palavras[palavra_sorteada]);
			printf("Tentativas: %i Errou: %i ", tentativas, errou);
			break;
		}
		else{
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
	}

	//fecha o arquivo
    fclose(arquivo);
	//Saber se o usuario deseja Jogar novamente ou não
	printf("\nDeseja Jogar Novamente?(s/n)");
	scanf("%s", &jogar_novamente);
	if(sim == jogar_novamente){
		apagar();
		objetos();
	}
	else if(jogar_novamente == nao){
		apagar();
		main();
	}
}

void animais(){	//Função para forca de animais
	
	//Declarações
	int j;
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    char letra;

    FILE *arquivo;
    arquivo = fopen("animais.txt", "r"); //nome do arquivo txt onde encontra as palavras da forca

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor / matriz
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
    //Declarações 2
    int palavra_correta=0;
    int tamanho;
    int tentativas=0;
    int acertou=0;
    int errou=0;
    int letra_correta[10] = {0,0,0,0,0,0,0,0,0,0};
    int k;
    char sim = {'s'};
    char nao = {'n'};
    char jogar_novamente;
    sortear();   //Sorteia uma palavra
    tamanho =strlen(palavras[palavra_sorteada]) - 1; //tamanho da palavra
    printf("\n");
    for(k = 0; k<tamanho; k++){         //Representar cada letra da palavra ainda não descoberta
    	printf(" _ ");
	}
	printf("\n\nTentativas: 0 Errou: 0\n"); //Tentativas e Erros
	printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n"); //Forca
	//while para cada tentativa em descobrir a palavra
    while(1){
    	errou=0;
    	printf("\n\nDigite uma Letra: ");
    	//escaneia a letra e printa
		scanf("%s", &letra);
		//Função para limpar tela
		apagar();
    	printf("\nA letra digitada foi:%c\n", letra);
    	//Faz o teste, se a letra corresponder a alguma da palavra, substitui o _ pela letra
    	for(j = 0; j<tamanho; j++){
    		if((palavras[palavra_sorteada][j] == letra) || (letra_correta[j]==1)){
    			letra_correta[j]=1;
    			printf(" %c ", palavras[palavra_sorteada][j]);
			}
			else{
				printf(" _ ");
			}
		}
		for(j = 0; j<tamanho; j++){
			if(palavras[palavra_sorteada][j] == letra){
				acertou++;
				break;
			}
			else{
				continue;
			}
		}
		//Fim dos testes
		printf("\n\n");
		//Printa quantas vezes tentou e errou pelo numero de tentativas menos os acertos
		tentativas++;
		errou = tentativas - acertou;
		printf("Tentativas: %i Errou: %i \n", tentativas, errou);
		//Faz o teste para saber se a palavra está completa
		palavra_correta=0;
		for(k = 0; k<tamanho; k++){
			if(letra_correta[k]==1){
				palavra_correta++;
			}
			else if(letra_correta[k]==0){
				palavra_correta--;
			}
		}
		//Fim do teste
		//If else para erros na forca e para saber se ganhou ou perdeu
		if(palavra_correta == tamanho){
			apagar();
			printf("Parabens voce Venceu! A Palavra era: %s\n", palavras[palavra_sorteada]);
			break;
		}
		else if(errou==0){
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==1){
			printf("   ________\n   |      |\n   |      O\n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==2){
			printf("   ________\n   |      |\n   |      O\n   |      |  \n   |        \n   | \n==========\n");
		}
		else if(errou==3){
			printf("   ________\n   |      |\n   |      O\n   |     (|  \n   |        \n   | \n==========\n");
		}
		else if(errou==4){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |        \n   | \n==========\n");
		}
		else if(errou==5){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /   \n   | \n==========\n");
		}
		else if(errou==6){
			apagar();
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /) \n   | \n==========\n");
			printf("Voce foi ENFORCADO! A Palavra era: %s\n", palavras[palavra_sorteada]);
			printf("Tentativas: %i Errou: %i ", tentativas, errou);
			break;
		}
		else{
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
	}

	//fecha o arquivo
    fclose(arquivo);
	//Saber se o usuario deseja Jogar novamente ou não
	printf("\nDeseja Jogar Novamente?(s/n)");
	scanf("%s", &jogar_novamente);
	if(sim == jogar_novamente){
		apagar();
		animais();
	}
	else if(jogar_novamente == nao){
		apagar();
		main();
	}
}

void profissoes(){	//Função para forca de profissões
	
	//Declarações
	int j;
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    char letra;

    FILE *arquivo;
    arquivo = fopen("profissoes.txt", "r"); //nome do arquivo txt onde encontra as palavras da forca

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor / matriz
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
    //Declarações 2
    int palavra_correta=0;
    int tamanho;
    int tentativas=0;
    int acertou=0;
    int errou=0;
    int letra_correta[10] = {0,0,0,0,0,0,0,0,0,0};
    int k;
    char sim = {'s'};
    char nao = {'n'};
    char jogar_novamente;
    sortear();   //Sorteia uma palavra
    tamanho =strlen(palavras[palavra_sorteada]) - 1; //tamanho da palavra
    printf("\n");
    for(k = 0; k<tamanho; k++){         //Representar cada letra da palavra ainda não descoberta
    	printf(" _ ");
	}
	printf("\n\nTentativas: 0 Errou: 0\n"); //Tentativas e Erros
	printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n"); //Forca
	//while para cada tentativa em descobrir a palavra
    while(1){
    	errou=0;
    	printf("\n\nDigite uma Letra: ");
    	//escaneia a letra e printa
		scanf("%s", &letra);
		//Função para limpar tela
		apagar();
    	printf("\nA letra digitada foi:%c\n", letra);
    	//Faz o teste, se a letra corresponder a alguma da palavra, substitui o _ pela letra
    	for(j = 0; j<tamanho; j++){
    		if((palavras[palavra_sorteada][j] == letra) || (letra_correta[j]==1)){
    			letra_correta[j]=1;
    			printf(" %c ", palavras[palavra_sorteada][j]);
			}
			else{
				printf(" _ ");
			}
		}
		for(j = 0; j<tamanho; j++){
			if(palavras[palavra_sorteada][j] == letra){
				acertou++;
				break;
			}
			else{
				continue;
			}
		}
		//Fim dos testes
		printf("\n\n");
		//Printa quantas vezes tentou e errou pelo numero de tentativas menos os acertos
		tentativas++;
		errou = tentativas - acertou;
		printf("Tentativas: %i Errou: %i \n", tentativas, errou);
		//Faz o teste para saber se a palavra está completa
		palavra_correta=0;
		for(k = 0; k<tamanho; k++){
			if(letra_correta[k]==1){
				palavra_correta++;
			}
			else if(letra_correta[k]==0){
				palavra_correta--;
			}
		}
		//Fim do teste
		//If else para erros na forca e para saber se ganhou ou perdeu
		if(palavra_correta == tamanho){
			apagar();
			printf("Parabens voce Venceu! A Palavra era: %s\n", palavras[palavra_sorteada]);
			break;
		}
		else if(errou==0){
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==1){
			printf("   ________\n   |      |\n   |      O\n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==2){
			printf("   ________\n   |      |\n   |      O\n   |      |  \n   |        \n   | \n==========\n");
		}
		else if(errou==3){
			printf("   ________\n   |      |\n   |      O\n   |     (|  \n   |        \n   | \n==========\n");
		}
		else if(errou==4){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |        \n   | \n==========\n");
		}
		else if(errou==5){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /   \n   | \n==========\n");
		}
		else if(errou==6){
			apagar();
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /) \n   | \n==========\n");
			printf("Voce foi ENFORCADO! A Palavra era: %s\n", palavras[palavra_sorteada]);
			printf("Tentativas: %i Errou: %i ", tentativas, errou);
			break;
		}
		else{
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
	}

	//fecha o arquivo
    fclose(arquivo);
	//Saber se o usuario deseja Jogar novamente ou não
	printf("\nDeseja Jogar Novamente?(s/n)");
	scanf("%s", &jogar_novamente);
	if(sim == jogar_novamente){
		apagar();
		profissoes();
	}
	else if(jogar_novamente == nao){
		apagar();
		main();
	}
}

void paises(){	//Função para forca de paises
	
	//Declarações
	int j;
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];
    char letra;

    FILE *arquivo;
    arquivo = fopen("paises.txt", "r"); //nome do arquivo txt onde encontra as palavras da forca

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor / matriz
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }
    //Declarações 2
    int palavra_correta=0;
    int tamanho;
    int tentativas=0;
    int acertou=0;
    int errou=0;
    int letra_correta[10] = {0,0,0,0,0,0,0,0,0,0};
    int k;
    char sim = {'s'};
    char nao = {'n'};
    char jogar_novamente;
    sortear();   //Sorteia uma palavra
    tamanho =strlen(palavras[palavra_sorteada]) - 1; //tamanho da palavra
    printf("\n");
    for(k = 0; k<tamanho; k++){         //Representar cada letra da palavra ainda não descoberta
    	printf(" _ ");
	}
	printf("\n\nTentativas: 0 Errou: 0\n"); //Tentativas e Erros
	printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n"); //Forca
	//while para cada tentativa em descobrir a palavra
    while(1){
    	errou=0;
    	printf("\n\nDigite uma Letra: ");
    	//escaneia a letra e printa
		scanf("%s", &letra);
		//Função para limpar tela
		apagar();
    	printf("\nA letra digitada foi:%c\n", letra);
    	//Faz o teste, se a letra corresponder a alguma da palavra, substitui o _ pela letra
    	for(j = 0; j<tamanho; j++){
    		if((palavras[palavra_sorteada][j] == letra) || (letra_correta[j]==1)){
    			letra_correta[j]=1;
    			printf(" %c ", palavras[palavra_sorteada][j]);
			}
			else{
				printf(" _ ");
			}
		}
		for(j = 0; j<tamanho; j++){
			if(palavras[palavra_sorteada][j] == letra){
				acertou++;
				break;
			}
			else{
				continue;
			}
		}
		//Fim dos testes
		printf("\n\n");
		//Printa quantas vezes tentou e errou pelo numero de tentativas menos os acertos
		tentativas++;
		errou = tentativas - acertou;
		printf("Tentativas: %i Errou: %i \n", tentativas, errou);
		//Faz o teste para saber se a palavra está completa
		palavra_correta=0;
		for(k = 0; k<tamanho; k++){
			if(letra_correta[k]==1){
				palavra_correta++;
			}
			else if(letra_correta[k]==0){
				palavra_correta--;
			}
		}
		//Fim do teste
		//If else para erros na forca e para saber se ganhou ou perdeu
		if(palavra_correta == tamanho){
			apagar();
			printf("Parabens voce Venceu! A Palavra era: %s\n", palavras[palavra_sorteada]);
			break;
		}
		else if(errou==0){
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==1){
			printf("   ________\n   |      |\n   |      O\n   |         \n   |        \n   | \n==========\n");
		}
		else if(errou==2){
			printf("   ________\n   |      |\n   |      O\n   |      |  \n   |        \n   | \n==========\n");
		}
		else if(errou==3){
			printf("   ________\n   |      |\n   |      O\n   |     (|  \n   |        \n   | \n==========\n");
		}
		else if(errou==4){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |        \n   | \n==========\n");
		}
		else if(errou==5){
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /   \n   | \n==========\n");
		}
		else if(errou==6){
			apagar();
			printf("   ________\n   |      |\n   |      O\n   |     (|) \n   |     /) \n   | \n==========\n");
			printf("Voce foi ENFORCADO! A Palavra era: %s\n", palavras[palavra_sorteada]);
			printf("Tentativas: %i Errou: %i ", tentativas, errou);
			break;
		}
		else{
			printf("   ________\n   |      |\n   |       \n   |         \n   |        \n   | \n==========\n");
		}
	}

	//fecha o arquivo
    fclose(arquivo);
	//Saber se o usuario deseja Jogar novamente ou não
	printf("\nDeseja Jogar Novamente?(s/n)");
	scanf("%s", &jogar_novamente);
	if(sim == jogar_novamente){
		apagar();
		paises();
	}
	else if(jogar_novamente == nao){
		apagar();
		main();
	}
}



