//Author: brunomirandades

//pino botão de acionamento
#define botao 5

//definicao dos pinos do primeiro dado
#define centro_1 12 // '.'
#define diagonal_esquerda_1 13 // '\'
#define diagonal_direita_1 10 // '/'
#define horizontal_1 11 // '..'

//definicao dos pinos do segundo dado
#define centro_2 8 // '.'
#define diagonal_esquerda_2 9 // '\'
#define diagonal_direita_2 6 // '/'
#define horizontal_2 7 // '..'

//variavel de intertravamento
int liberado_para_jogar = 1;

void setup()
{
  //botao pino de entrada com pullup interno
  pinMode(botao, INPUT_PULLUP);

  //pinos de saída do dado 1 para cada LED
  pinMode(centro_1, OUTPUT);
  pinMode(diagonal_esquerda_1, OUTPUT);
  pinMode(diagonal_direita_1, OUTPUT);
  pinMode(horizontal_1, OUTPUT);

  //pinos de saida do dado 2 para cada LED
  pinMode(centro_2, OUTPUT);
  pinMode(diagonal_esquerda_2, OUTPUT);
  pinMode(diagonal_direita_2, OUTPUT);
  pinMode(horizontal_2, OUTPUT);
  
  //inicialicação do gerador de numero aleatorio
  randomSeed(analogRead(0));
}


void loop()
{ 
  //quando pressionado o botão os dados irao rolar fazendo a animacao
  //a variavel liberado_para_jogar é intertravamento
  //enquanto a animação estiver ocorrendo nao deve ser possivel iniciar novamente até terminar
  if(digitalRead(botao) == 0 && liberado_para_jogar == 1){
	liberado_para_jogar = 0; //intertravamento desativado
	jogar_dados();
	liberado_para_jogar = 1; //intertravamento ativado
  }
}

//funcao de animacao de rolagem dos dados
void jogar_dados()
{
	//parametros da animacao com efeito de transicao de rapido para devagar
	int limite_superior = 1000; //tempo em ms do ultimo instante da animação
	int incremento = 50; //tempo em ms do primeiro instante de animacao e incremento
	
	//loop da animacao
	for(int i = incremento; i < limite_superior; i += incremento)
	{
		//dado 1 - mostra o numero
		acender_leds(1, sortear_numero());
		//dado 2 - mostra o numero
		acender_leds(2, sortear_numero());
		delay(i);
	}
}

//receber numeros aleatorios para sortear os dados
int sortear_numero()
{
	return random(1, 7); //retornar o valor sorteado pela função do sistema
}

void acender_leds(int dado, int numero)
{	
	//rotina de iluminacao dos leds para o dado 1
	if(dado == 1)
	{
    //todos os leds sao apagados antes de apresentar um novo numero
		digitalWrite(centro_1, LOW);
		digitalWrite(diagonal_direita_1, LOW);
		digitalWrite(diagonal_esquerda_1, LOW);
		digitalWrite(horizontal_1, LOW);

    //operador de decisao entre os numeros com o desenho formado pelos leds para cada um deles
		switch(numero){
			case 1:
			  digitalWrite(centro_1, HIGH);
			break;
			case 2:
			  digitalWrite(diagonal_esquerda_1, HIGH);
			break;
			case 3:
			  digitalWrite(centro_1, HIGH);
			  digitalWrite(diagonal_esquerda_1, HIGH);
			break;
			case 4:
			  digitalWrite(diagonal_direita_1, HIGH);
			  digitalWrite(diagonal_esquerda_1, HIGH);
			break;
			case 5:
			  digitalWrite(centro_1, HIGH);
			  digitalWrite(diagonal_direita_1, HIGH);
			  digitalWrite(diagonal_esquerda_1, HIGH);
			break;
			case 6:
			  digitalWrite(horizontal_1, HIGH);
			  digitalWrite(diagonal_direita_1, HIGH);
			  digitalWrite(diagonal_esquerda_1, HIGH);
			break;
		}
	}
	
	//rotina de iluminacao dos leds para o dado 2
	if(dado == 2)
	{
  //todos os leds sao apagados antes de apresentar um novo numero
		digitalWrite(centro_2, LOW);
		digitalWrite(diagonal_direita_2, LOW);
		digitalWrite(diagonal_esquerda_2, LOW);
		digitalWrite(horizontal_2, LOW);

    //operador de decisao entre os numeros com o desenho formado pelos leds para cada um deles
		switch(numero){
			case 1:
			  digitalWrite(centro_2, HIGH);
			break;
			case 2:
			  digitalWrite(diagonal_esquerda_2, HIGH);
			break;
			case 3:
			  digitalWrite(centro_2, HIGH);
			  digitalWrite(diagonal_esquerda_2, HIGH);
			break;
			case 4:
			  digitalWrite(diagonal_direita_2, HIGH);
			  digitalWrite(diagonal_esquerda_2, HIGH);
			break;
			case 5:
			  digitalWrite(centro_2, HIGH);
			  digitalWrite(diagonal_direita_2, HIGH);
			  digitalWrite(diagonal_esquerda_2, HIGH);
			break;
			case 6:
			  digitalWrite(horizontal_2, HIGH);
			  digitalWrite(diagonal_direita_2, HIGH);
			  digitalWrite(diagonal_esquerda_2, HIGH);
			break;
		}
	}
}
