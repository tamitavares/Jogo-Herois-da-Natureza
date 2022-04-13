
//================================================================inclus�o dos headers para funcionamento do programa=======================================================================================================
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>

//=========================================================================================================================================================================================================================



//==================================================================================declara��o inicial das vari�veis=======================================================================================================


bool jogando = false, inicio, coordenadaCorreta, difpes1, difpes2, difpes3, diferente, noJogo = true;
char letra, let, continuar = 's', letB;
int numero, numeroReal, i, j, botLinha, botColuna, voltar, jogadas = 0, pontos = 0, pontosBot = 0, fase = 1, numlet, numletB, letraReal, modoDeJogo;
int jogadasMax = 20;


char campoBase[7][30] = {     //campo que ser� usado de base para os outros ao serem reiniciados
	"  A  B  C  D  E  F ",
	"1[ ][ ][ ][ ][ ][ ]",
	"2[ ][ ][ ][ ][ ][ ]",
	"3[ ][ ][ ][ ][ ][ ]",
	"4[ ][ ][ ][ ][ ][ ]",
	"5[ ][ ][ ][ ][ ][ ]",
	"6[ ][ ][ ][ ][ ][ ]"
	}; 

char campo1[7][30] = {        //campo do bot
	"  A  B  C  D  E  F ",
	"1[ ][ ][ ][ ][ ][ ]",
	"2[ ][ ][ ][ ][ ][ ]",
	"3[ ][ ][ ][ ][ ][ ]",
	"4[ ][ ][ ][ ][ ][ ]",
	"5[ ][ ][ ][ ][ ][ ]",
	"6[ ][ ][ ][ ][ ][ ]"
	}; 

char campo2[7][30] = { 		//campo do jogador
	"  A  B  C  D  E  F ",
	"1[ ][ ][ ][ ][ ][ ]",
	"2[ ][ ][ ][ ][ ][ ]",
	"3[ ][ ][ ][ ][ ][ ]",
	"4[ ][ ][ ][ ][ ][ ]",
	"5[ ][ ][ ][ ][ ][ ]",
	"6[ ][ ][ ][ ][ ][ ]"
	}; 
	
//==========================================================================================================================================================================================================================

	
//===========================================================================fun��o para limpar o campo para recome�ar=======================================================================================================
	
void resetarCampo(){
	int q = 0, w = 0, e = 0, r = 0; //todas as vari�veis para percorrer ambos os campos
	for(q = 0; q < 7; q++){
		for(w = 0; w < 30; w++ ){
			campo1[q][w] = campoBase[q][w];  //substituir o conte�do do espa�o do jogo passado por o que est� no campo base
		}
	}
	for(e = 0; e < 7; e++){
		for(r = 0; r < 30; r++ ){
			campo2[e][r] = campoBase[e][r];  //substituir o conte�do do espa�o do jogo passado por o que est� no campo base
		}
	}
 pontos = 0;
 pontosBot = 0; //zerar quantas jogadas o jogador j� fez e quantos pontos cada um fez
 jogadas = 0;
}

//===========================================================================================================================================================================================


//================================================================================fun��o para printar o campo na tela=======================================================================================================

void printarCampo(){
	system ("cls");
		printf("Digite uma coordenada (ex: a1, b2, c3) \n L = Lixo: - 2 pontos \n F = Flores: +1 ponto \n A = �rvores: +3 pontos\n I = Inf�rtil: 0 pontos\n\n");
		printf("\t\t\t\tFase: %i\n", fase);            //printar na tela todas as instru��es do jogo, em qual fase o jogador est� e quantos pontos ele tem 
		printf("\t\t\tJogadas restantes: %i\n", jogadasMax - jogadas);
		printf("\n     Seu Campo   pontos: %i\n\n", pontos);
		
		for(i = 0; i < 7; i++){     //Loop para mostrar na tela todo o campo do jogador
			printf("     %s\n", campo2[i]);
			}
		printf("\n\n   Campo do bot   pontos: %i\n\n", pontosBot);

		for(i = 0; i < 7; i++){
			printf("     %s\n", campo1[i]);  //Loop para mostrar na tela todo o campo do bot
			}
}

//=========================================================================================================================================================================================================================


//==========================================================================fun��o para executar a jogada do jogador=======================================================================================================

void jogadaPessoa(){
	
//############ sortear qual letra ser� colocada na jogada do player #############


	//sortear a letra do campo
	numlet = rand() % 4;  //0 a 3
	if (numlet == 0)
		let = 'L';  //lixo
	else if (numlet == 1)
		let = 'F';  //flor
	else if (numlet == 2)
		let = 'A';  //�rvore
	else if (numlet == 3)
		let = 'I';	//inf�rtil
		
//#############################################################################
	
	do{
//############ perguntar em que coordenada o jogador deseja jogar #############

	printf("\nDigite a coordenada (ex: a1): ");
	scanf("%c %i", &letra, &numero);
	fflush(stdin);
	
//#############################################################################
	
	difpes1 = true; difpes2 = true; difpes3 = true; coordenadaCorreta = true;  //bools para checar se alguma condi��o da coordenada foi descumprida
	
	
//############ transformar a letra digitada em um n�mero para ser inserida na matriz #############	
	
	letra = tolower(letra);  //tornar min�scula
	if(letra == 'a'){
			letraReal = 0; 
		}else if(letra == 'b'){
			letraReal = 3;
		}else if(letra == 'c'){
			letraReal = 6;
		}else if(letra == 'd'){
			letraReal = 9;
		}else if(letra == 'e'){
			letraReal = 12;
		}else if(letra == 'f'){
			letraReal = 15;
		}
		
//#################################################################################################		
		
		
		
//############ checar se alguma parte da coordenada foi digitada de forma inv�lida #############	
		
		else{
			coordenadaCorreta = false;
			printf("Letra inv�lida, digite novamente \n");
			difpes1 = false;
		} //letra errada

		if(numero > 6 || numero < 1){
			coordenadaCorreta = false;
			printf("N�mero inv�lido, digite novamente! \n");
			difpes2 = false;
		} //n�mero errado 

		if(coordenadaCorreta && campo2[numero][letraReal + 2] != ' '){
			printf("Casa repetida, digite novamente! \n");
			difpes3 = false;
		} //se o espa�o j� foi usado
		
		if (!(difpes1 && difpes2 && difpes3)){
			printf("\n");
			system("pause");
			printarCampo();
		}  //caso alguma das condi��es anteriores tenha sido real
		
		
	} while(!(difpes1 && difpes2 && difpes3));
	
//#################################################################################################	


	
		campo2[numero][letraReal + 2] = let;  //colocar no campo a letra sorteada
		jogadas++; //aumentar o n�mero de jogadas
		
		
		
//############ contabilizar os pontos de acordo com a letra sorteada #############

		if(let == 'L'){
			pontos -= 2;
		}else if(let == 'F'){
			pontos += 1;
		}else if(let == 'A'){
			pontos += 3;
		}
		
//#################################################################################

}

//========================================================================================================================================================================================================================



//=======================================================================fun��o para executar a jogada do computador=======================================================================================================

void jogadaBot(){
//############ sortear qual letra ser� colocada na jogada do bot #############

	numletB = rand() % 4;
	
	if (numletB == 0)
		letB = 'L';
	else if (numletB == 1)
		letB = 'F';
	else if (numletB == 2)
		letB = 'A';
	else if (numletB == 3)
		letB = 'I';	
		
//############################################################################



//############ sortear em qual posi��o o bot ir� jogar #############	
	
	do{
	diferente = true;  

	botLinha = rand() % 6;
	botColuna = rand() % 6;	
	if(botColuna == 0){
		botColuna = 2;
	}else if(botColuna == 1){  //transformar o n�mero gerado no sorteio no n�mero correto d� coluna, j� que existem coisas entre elas, como "[ ]"
		botColuna = 5;
	}else if(botColuna == 2){
		botColuna = 8;
	}else if(botColuna == 3){
		botColuna = 11;
	}else if(botColuna == 4){
		botColuna = 14;
	}else if(botColuna == 5){
		botColuna = 17;
	}	
	
//##################################################################




//############ Confirmar que � uma posi��o ainda n�o usada #############

	if(campo1[botLinha][botColuna] != ' '){
		diferente = false;
	}  //se n�o for espa�o em branco
	} while(!diferente);
	
//##################################################################



	campo1[botLinha][botColuna] = letB;	 //colocar a letra usada no campo	
	
	
	
//############ contabilizar os pontos de acordo com a letra sorteada #############

	if(letB == 'L'){
		pontosBot -= 2;
	}else if(letB == 'F'){
		pontosBot += 1;
	}else if(letB == 'A'){
		pontosBot += 3;
	}
	
//#################################################################################
	
}



//===========================================================================================================================================================================================


//==============================================fun��o principal==============================================================================================================================

int main(){
srand(time(NULL));  //ao sortear sempre ser n�meros diferentes
system("color B0");  //definir cor: fundo = azul claro; escrita = preto
setlocale(LC_ALL, "portuguese"); //linguagem = portugu�s

//inicio do programa

while(noJogo){ //enquanto o programa est� aberto


//############################ Funcionamento do MENU ########################################


do{
	inicio = true;
	system("cls");
	
	jogadas = 0;
	jogadasMax = 20;
	
	resetarCampo();
	
	printf("Bem vindo ao jogo Her�is da Natureza");
	
	printf("\nPara jogar digite 1, para ver o menu de instru��es, digite 2:  ");
	scanf("%i",&modoDeJogo);  
	fflush(stdin);
	
	
//############################ Para come�ar a jogar ########################################	


	if(modoDeJogo == 1){
		fase = 1;
		jogadasMax = 20;
		jogando = true;
		continuar = 's';
	}
	
	
//##########################################################################################


//############################ Para ler o menu de instru��es ########################################

	
	else if(modoDeJogo == 2){
		system("cls");
		printf("FUNCIONAMENTO:\n\nO jogo consiste em 2 tabuleiros de 6x6, que representam terrenos, um do jogador e um do bot.\n Para jogar, digite uma coordenada(ex: a1, b2, c3), assim, voc� tentar� plantar\n uma semente na coordenada selecionada. Ap�s isso, aparecer� na tela, um dos \nelementos descritos abaixo e, de acordo com qual voc� encontrar, ganhar� ou perder� pontos. \n\nOS ELEMENTOS:\n\n L = lixo, - 2 pontos \n F = flores, +1 ponto \n A = �rvores, +3 pontos ");
		printf("\n\nPara voltar ao menu principal, digite 3: ");
		scanf("%i", &voltar);
		fflush(stdin);
		if(voltar == 3){  //para voltar ao menu
			inicio = false;
		}
	}
	
	
//###################################################################################################

	else{
		inicio = false;
	} //se digitar errado
	
	}while(!inicio);


//########################################################################################## Final do MENU



//############################ Enquanto o jogo est� em execu��o ########################################

while(continuar == 's'){


//############################ Loop principal do jogo ########################################
	while(jogando){
		do{
		printarCampo();
		jogadaPessoa();
		jogadaBot();		
		} while(jogadas <= jogadasMax); //quebrar o loop caso o jogador passe das jogadas m�ximas
		jogando = false;
		
	}
	
//########################################################################################## Fim Loop principal


//############################ mostrar como o campo ficou e quantos pontos cada um fez ao final da fase ########################################

	printarCampo();
	printf("\n\n");
	printf("Seus pontos: %i\nPontos do bot: %i\n",pontos, pontosBot);
	
//##############################################################################################################################################
	
	
//############################ Caso o bot tenha ganhado ########################################
	
	if(pontosBot > pontos){
		printf("\nQue pena, voc� perdeu :( \n");
		printf("Deseja jogar a fase novamente? (S / N) \n");
		scanf("%c", &continuar);
		resetarCampo();
		jogando = true;
	}
	
//##############################################################################################


//############################ Caso ambos tenham empatado ########################################
	else if(pontos == pontosBot){
		printf("Empatou :p\n");
		printf("Deseja jogar a fase novamente? (S / N) \n");
		scanf("%c", &continuar);
		resetarCampo();
		jogando = true;
	}
	
//################################################################################################

//############################ Caso o jogador tenha feito mais pontos ########################################
	else{
		if(jogadasMax == 11){       //Caso o jogador ven�a EEEEE j� esteja na �ltima fase
		system("cls");
		printf("Parab�ns, voc� ganhou o jogo!!!\n");
		continuar = 'n'; //para encerrar o jogo
		inicio = true;	 //para retornar ao menu
		system("pause");
		}
		
		
		
		else{                       //Caso o jogador ven�a a fase
		printf("Parabeeens, voc� passou!! :)\n");
		printf("Deseja jogar pr�xima fase? (S / N) \n");
		scanf("%c", &continuar);
		if(tolower(continuar) == 's'){
			fase++;
			jogadasMax-=2; //diminuir 2 das jogadas m�ximas para aumentar dificuldade
			resetarCampo();
			jogando = true;
			jogadasMax -= 1;
		}  //pr�xima fase
	}
		
	}
	
//#############################################################################################################
	fflush(stdin);
	
}

//################################################################################################### Fim execu��o do jogo
	fflush(stdin);
	system("cls");

} //enquanto continuar == 's'
return 0;
}
	
