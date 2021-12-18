
void atualiza_tabuleiro(char tabuleiro[3][3]){
	//funcao que atualiza o tabuleiro na tela apos uma jogada
	
	printf("\nTabuleiro: \n\n");
	printf("%c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
	printf("----------\n");
	printf("%c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
	printf("----------\n");
	printf("%c | %c | %c\n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);	
}

char *pega_jogada(int jogador, char resposta[2]){
	//Funcao que solicita as jogadas aos jogadores

	printf("\nVez do jogador %i: \n", jogador);
	scanf("%s", resposta);
	return resposta;
}

int escreve_tabuleiro(char tabuleiro[3][3], char resposta[2], int jogador){
	//Funcao que escreve no tabuleiro
	
	int linha;
	int coluna;
	int retorno_avalia_jogada;
	//escreve no tabuleiro
	linha = (int)resposta[0] - 48;
	coluna = (int)resposta[1] - 48;
	//printf("valor de linha: %i, valor de coluna: %i", linha, coluna);
	
	retorno_avalia_jogada = avalia_jogada(linha, coluna, tabuleiro);
	
	if(retorno_avalia_jogada == 1){
		if(jogador == 1)
			tabuleiro[linha-1][coluna-1] = 'X';
		else
			tabuleiro[linha-1][coluna-1] = 'O';
	}
	else
		return -1;
	
	return 1;	
}

int avalia_jogada(int linha, int coluna, char tabuleiro[3][3]){
	//Funcao que verifica que uma jogada eh valida
	
	// O jogador nao pode escrever numa posicao invalida
	if( (linha > 3 || linha < 1) || (coluna > 3 || coluna < 1) ){
		printf("Erro: O jogador nao pode escrever numa posicao invalida, digite novamente\n");
		return -1; 
	}
		
	// O jogador nao pode escrever em uma posicao ja preenchida
	else if(tabuleiro[linha-1][coluna-1] != ' '){
		printf("Erro: O jogador nao pode escrever em uma posicao ja preenchida, digite novamente\n");
		return -1;	
	}
	
	//retorna 1 caso esteja tudo certo
	return 1;
}

int verifica_ganhador(char tabuleiro[3][3], int jogador){
	//Funcao que verifica se ja existe um ganhador
	
	int i;
	int j;
	char marcador;
	
	if(jogador == 1)
		marcador = 'X';
	else
		marcador = 'O';
	
	
	//verifica as linhas
	for(i=0;i<3;i++){
		if(tabuleiro[i][0] == marcador && tabuleiro[i][1] == marcador && tabuleiro[i][2] == marcador){
			printf("Parabens o jogador %i ganhou!!!", jogador);
			return 1;
		}
	}
	
	//verifica as colunas
	for(i=0;i<3;i++){
		if(tabuleiro[0][i] == marcador && tabuleiro[1][i] == marcador && tabuleiro[2][i] == marcador){
			printf("Parabens o jogador %i ganhou!!!", jogador);
			return 1;
		}
	}
	
	//verifica as diagonais
	//diagonal esquerda superior pra direita inferior
	if((tabuleiro[0][0] == marcador && tabuleiro[1][1] == marcador && tabuleiro[2][2] == marcador)){
		printf("Parabens o jogador %i ganhou!!!", jogador);
		return 1;
	}
	
	//diagonal direita superior pra esquerda inferior
	if((tabuleiro[0][2] == marcador && tabuleiro[1][1] == marcador && tabuleiro[2][0] == marcador)){
		printf("Parabens o jogador %i ganhou!!!", jogador);
		return 1;
	}
	
	//nao tem vencedor ainda
	return -1;
}
