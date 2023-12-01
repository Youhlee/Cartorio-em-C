#include <stdio.h>//Bilioteca de comunicação com o usuário
#include <stdlib.h>//Biblioteca de alocação de espaço em memória
#include <locale.h>//Bibliotea de alocações de texto por região
#include <string.h>//Biblioteca responsável por cuidar das strings

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[11];//"char" é para criar um texto, caracteres
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//final da criação de variáveis/string
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Você escolheu o registro de nomes!\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//"%s" salva dentro de uma string, ele vai salvar tudo em CPF
	
	strcpy(arquivo, cpf);//"strcopy" responsável por copiar os valores das strings
	
	FILE *file;//Aqui cria o arquivo, "FILE" é uma função, aqui está dizendo que o sistema vai procurar na biblioteca pois vai se criar uma arquivo
	file = fopen(arquivo, "w");//Aqui está que o file vai abrir o arquivo com o "fopen", o "w" é de write, escrever no arquivo
	fprintf(file,cpf);//"fprintf" salva o valor da varável
	fclose(file);//aqui fecha o arquivo
	
	file = fopen(arquivo, "a");//"fopen" abre o aquivo, o "a" é para atualizar a informação sem criar um novo arquivo
	fprintf(file,", "); //aqui ele colocar a vírgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[11];
	char conteudo[200];
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Você escolheu consultar os nomes!\n\n");
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" é de ler
	
	if(file == NULL)//Se o que o usuário estiver tentando procurar for nulo/não existe
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!.");
		printf("\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//"while" é esquanto, um laço de repetição, "fgets" busca no arquivo, "!=" retorna true se os operandos não tiverem o mesmo valor; caso contrário, retorna false, enquanto for diferente de nulo ele vai escrevendo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[11];
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Você escolheu deletar nomes!\n\n");
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!.\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//"opcao=0" significa que estamos alocando um espaço na mémoria que não está disponível, apenas um "=" significa que está atribuindo um valor a ela
	int laco=1;
	
	for(laco=1;laco=1;)//"for" é faça, repita quantas vezes o usuário pedir, "x=1;x=1" começa quando o x for 1 e continua enquanto o x for 1, assim sempre vai voltar no começo
 	{
 		
 		system("cls");//"system" a gente consegue falar com o sistema, o "cls" limpa a tela depois que o usuário digitar a opção
 	
		setlocale(LC_ALL, "Portuguese"); //É para localizar qual o idioma estamos, para colocar acentos
		
		printf("### Cartório da EBAC ###\n\n"); // O "#" é só para deixar bonito e o "\n" pula linha
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registro de nomes\n"); //O "\t" da um espaço
		printf("\t2 - Consulta de nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao); //Aqui armazina a opção do usuário "scanf" escaneia a opção que o usuário coloca, para armazenar uma variável se usa "%d" do tipo inteiro e o "&" referencia a variável
		
		system("cls"); 
		
		switch(opcao)//Analisa a variável
		{
			case 1: //"case" é caso, ":" é como se tivesse abrindo uma chave
			registro();
			break;//"break" é o fechamento da variável
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default://"default" faz com que caso a opção selecionada não for mapeada ela vai ele vai dar o que está na chaves
			printf("### Cartório da EBAC ###\n\n");
			printf("Essa opção não está disponível\n\n");
			system("pause");
			break;
		}
	}
}

//NÃO TIREI PARA NÃO PERDER AS ANOTAÇÕES

	//	if(opcao==1) //O "if" é se, é uma tomara de decisão e os dois "==" é uma comparação, é uma se fosse "opcao é igual a 1? Sim ou Não?", não vai ter um ";" pois não é uma instrução
	//	{
	//		printf("### Cartório da EBAC ###\n\n");
	//		printf("Você escolheu o registro de nomes!\n");
	//		system("pause"); //"pause" vai aparecer a mensagem pro usuário até ele não querer mais
	//	}
	//	if (opcao==2)
	//	{
	//		printf("### Cartório da EBAC ###\n\n");
	//		printf("Você escolheu consultar os nomes!\n");
	//		system("pause");
	//	}
	//	if (opcao==3)
	//	{
	//		printf("### Cartório da EBAC ###\n\n");
	//		printf("Você escolheu deletar nomes!\n");
	//		system("pause");
	//	}
	//	if(opcao>=4 || opcao<=0) //">=" siginifica se a opção for maior ou igual que o número "<=" seria se a opçõo for menor ou maior que o número, "||" é o ou
	//	{
	//		printf("### Cartório da EBAC ###\n\n");
	//		printf("Essa opção não está disponível\n");
	//		system("pause");
	//	}
