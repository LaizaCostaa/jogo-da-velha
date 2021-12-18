#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
	
	char tabuleiro[3][3];
	char resposta[2];
	char opcao_menu;
	int i = 0;
	int j = 0;
	int jogador;
	int retorno_funcao = -1;
	
	//menu
	while(1){
		printf("\n*** Menu ***\n");
		printf("1 - Jogar\n");
		printf("2 - Ver Ranking\n");
		printf("3 - Creditos\n");
		printf("4 - Sair\n");
		printf("Digite uma opcao: ");
		scanf(" %c", &opcao_menu);
		
		if(opcao_menu != '1' && opcao_menu != '2' && opcao_menu != '3' && opcao_menu != '4'){
			printf("Digite uma opcao valida: 1,2,3 ou 4\n");
			continue;
		}
		
		if(opcao_menu == '1'){
			//Jogar
			
			//inicializacao do tabuleiro com espacos vazios
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					tabuleiro[i][j] = ' ';
				}
			}
			printf("\n\n*** Modo de jogar ***\n\n");
			printf("Digite o numero da linha junto com o numero da coluna\n");
			printf("Por exemplo, jogar no meio do tabuleiro, digite 22\n");
			printf("Divirta-se!!!\n\n");
			
			while(1){
				//jogador 1
				jogador = 1;
				while(retorno_funcao != 1){
					pega_jogada(jogador, resposta);
					retorno_funcao = escreve_tabuleiro(tabuleiro, resposta, jogador);	
				}
				//retorna variavel da condicao do While para nao passar direto pelo proximo while
				retorno_funcao = -1;
				atualiza_tabuleiro(tabuleiro);
				if(verifica_ganhador(tabuleiro, jogador) == 1)
					break;
				
				
				//jogador 2
				jogador = 2;
				while(retorno_funcao != 1){
					pega_jogada(jogador, resposta);
					retorno_funcao = escreve_tabuleiro(tabuleiro, resposta, jogador);	
				}
				//retorna variavel da condicao do While para nao passar direto pelo proximo while
				retorno_funcao = -1;
				atualiza_tabuleiro(tabuleiro);
				if(verifica_ganhador(tabuleiro, jogador) == 1)
					break;
				
			}
			continue;		
		}
		
		//Ranking
		if(opcao_menu == '2'){
			printf("\n*** Ranking ***\n");
			printf("Ranking nao disponivel no momento!\n");
			continue;
		}
		
		//Creditos
		if(opcao_menu == '3'){
			printf("\n*** Creditos ***\n");
			printf("Jogo desenvolvido por Laiza da Costa Oliveira, todos os direitos reservados\n");
			continue;
		}
		
		//Sair do jogo
		if(opcao_menu == '4'){
			printf("Ate a proxima ;)\n");
			break;
		}
		
	}
	
	return 0;
}
