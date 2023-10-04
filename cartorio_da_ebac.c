#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <stdio.h> //biblioteca de comunicação com o usuario
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca de strings

int main() //"INT" Função responsavel por 
{
	int opcao=0; //variavel das opções
	int laco=1; //variavel de repetição
	
	for (laco=1;laco=1;) //laço de repetição
	{
	  
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); // definindo o idioma
	
	    printf("### Cartório da EBAC ###\n\n"); // inicio do menu
	    printf("Escolha a opção desejada: \n\n");
	    printf("\t1- Cadastro de nomes\n");
	    printf("\t2- Consulta de nomes\n");
	    printf("\t3- Deletar nomes\n");
	    printf("Opção: "); // fim do menu
	
	    scanf("%d", &opcao); //armazena a escolha do usuario
	
	    system("cls"); //limpa a tela após a seleção do usuario
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();
			break;
	    		
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
			deletar();
			break;
	    		
	    	default:
	    	printf("Essa opção não está disponivel!\n\n");
	    	system("pause");
	    	break;
	    
		}
	   
    }
	
}

int registro()//"INT" Função responsavel pelo registro de usuarios
{
	//inicio da criação de variaveis
	char arquivo[20];
	char cpf[20];
	char nome[20];
	char sobrenome[40];
	char cargo[40];
	//fim das variaveis
	
	printf("Você escolheu Registro de Nomes \n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // "w" cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system ("pause");
	
	
}

int consulta() //"INT" Função responsavel pela consulta de usuarios
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[20];
	char conteudo[200];
	char *token;
		
	printf("Você escolheu Consulta de Nomes\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo CPF e "R" (Read/Ler) a informação dentro do arquivo
	
	if(file == NULL) //Se a o arquivo for "NULL" (Nulo) 
	{
		printf("\nEsse CPF não está cadastrado.\n"); //você escreve esse mensagem
	}
	    
	while(fgets(conteudo, 200, file) != NULL) //"while" (enquanto) tiver informação, armazene em CONTEUDO se o ARQUIVO for diferente de NULL
	{
		printf("Essas são as informações do cadastro: \n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
		
		
		printf("\n");
	} 
	
	system("pause");
}

int deletar() //"INT" Função responsavel por deletar usuarios
{
	char cpf[20]; //variavel CPF
	
	printf("Você escolheu Deletar Nomes\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); //armazena os dados que o usuario digitou
	
	remove(cpf);
	
	FILE *file;//abre o arquivo file
	file = fopen(cpf, "r"); //dentro do arquivo file ele abre o CPF e "r" le o arquivo
	
	if (file == NULL)//"IF" se o arquivo for "==" igual a "NULL" nulo
	{
	printf("Esse CPF não está cadastrado.\n");
    }
	if (file != NULL)// "IF" se o arquivo for "!=" diferente de NULL 
	{
	printf("CPF deletado com sucesso.\n");
	}
	
	system("pause");
}
