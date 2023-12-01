#include <stdio.h>//Bilioteca de comunica��o com o usu�rio
#include <stdlib.h>//Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//Bibliotea de aloca��es de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[11];//"char" � para criar um texto, caracteres
	char nome[60];
	char sobrenome[60];
	char cargo[60];
	//final da cria��o de vari�veis/string
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Voc� escolheu o registro de nomes!\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//"%s" salva dentro de uma string, ele vai salvar tudo em CPF
	
	strcpy(arquivo, cpf);//"strcopy" respons�vel por copiar os valores das strings
	
	FILE *file;//Aqui cria o arquivo, "FILE" � uma fun��o, aqui est� dizendo que o sistema vai procurar na biblioteca pois vai se criar uma arquivo
	file = fopen(arquivo, "w");//Aqui est� que o file vai abrir o arquivo com o "fopen", o "w" � de write, escrever no arquivo
	fprintf(file,cpf);//"fprintf" salva o valor da var�vel
	fclose(file);//aqui fecha o arquivo
	
	file = fopen(arquivo, "a");//"fopen" abre o aquivo, o "a" � para atualizar a informa��o sem criar um novo arquivo
	fprintf(file,", "); //aqui ele colocar a v�rgula
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
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Voc� escolheu consultar os nomes!\n\n");
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" � de ler
	
	if(file == NULL)//Se o que o usu�rio estiver tentando procurar for nulo/n�o existe
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!.");
		printf("\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//"while" � esquanto, um la�o de repeti��o, "fgets" busca no arquivo, "!=" retorna true se os operandos n�o tiverem o mesmo valor; caso contr�rio, retorna false, enquanto for diferente de nulo ele vai escrevendo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[11];
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Voc� escolheu deletar nomes!\n\n");
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//"opcao=0" significa que estamos alocando um espa�o na m�moria que n�o est� dispon�vel, apenas um "=" significa que est� atribuindo um valor a ela
	int laco=1;
	
	for(laco=1;laco=1;)//"for" � fa�a, repita quantas vezes o usu�rio pedir, "x=1;x=1" come�a quando o x for 1 e continua enquanto o x for 1, assim sempre vai voltar no come�o
 	{
 		
 		system("cls");//"system" a gente consegue falar com o sistema, o "cls" limpa a tela depois que o usu�rio digitar a op��o
 	
		setlocale(LC_ALL, "Portuguese"); //� para localizar qual o idioma estamos, para colocar acentos
		
		printf("### Cart�rio da EBAC ###\n\n"); // O "#" � s� para deixar bonito e o "\n" pula linha
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registro de nomes\n"); //O "\t" da um espa�o
		printf("\t2 - Consulta de nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao); //Aqui armazina a op��o do usu�rio "scanf" escaneia a op��o que o usu�rio coloca, para armazenar uma vari�vel se usa "%d" do tipo inteiro e o "&" referencia a vari�vel
		
		system("cls"); 
		
		switch(opcao)//Analisa a vari�vel
		{
			case 1: //"case" � caso, ":" � como se tivesse abrindo uma chave
			registro();
			break;//"break" � o fechamento da vari�vel
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default://"default" faz com que caso a op��o selecionada n�o for mapeada ela vai ele vai dar o que est� na chaves
			printf("### Cart�rio da EBAC ###\n\n");
			printf("Essa op��o n�o est� dispon�vel\n\n");
			system("pause");
			break;
		}
	}
}

//N�O TIREI PARA N�O PERDER AS ANOTA��ES

	//	if(opcao==1) //O "if" � se, � uma tomara de decis�o e os dois "==" � uma compara��o, � uma se fosse "opcao � igual a 1? Sim ou N�o?", n�o vai ter um ";" pois n�o � uma instru��o
	//	{
	//		printf("### Cart�rio da EBAC ###\n\n");
	//		printf("Voc� escolheu o registro de nomes!\n");
	//		system("pause"); //"pause" vai aparecer a mensagem pro usu�rio at� ele n�o querer mais
	//	}
	//	if (opcao==2)
	//	{
	//		printf("### Cart�rio da EBAC ###\n\n");
	//		printf("Voc� escolheu consultar os nomes!\n");
	//		system("pause");
	//	}
	//	if (opcao==3)
	//	{
	//		printf("### Cart�rio da EBAC ###\n\n");
	//		printf("Voc� escolheu deletar nomes!\n");
	//		system("pause");
	//	}
	//	if(opcao>=4 || opcao<=0) //">=" siginifica se a op��o for maior ou igual que o n�mero "<=" seria se a op��o for menor ou maior que o n�mero, "||" � o ou
	//	{
	//		printf("### Cart�rio da EBAC ###\n\n");
	//		printf("Essa op��o n�o est� dispon�vel\n");
	//		system("pause");
	//	}
