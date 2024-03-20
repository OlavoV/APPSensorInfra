#include <IRremote.h> // incluindo a biblioteca responsável pela decodificação do infravermelho
#include "control.h" // incluindo a função responsavel por armazenar as variaveis responsaveis por cada botão do controle 
#include <LiquidCrystal.h> // incluindo a biblioteca do display
LiquidCrystal lcd(13,12,11,10,9,8); // declaração de casas do display
IRrecv receptor(2); // declaração da casa do receptor infravermelho
int ledvermelho = 3; // declaração da casa do led vermelho
int ledverde = 4; // declaração da casa do led verde
int ledbranco = 5; // declaração da casa do led branco
int buzina = 6; /// declaração da casa da buzina
decode_results resultado; // criação de uma variável que armazena o código hex emitido pelo controle

void Ligar(int saida) // criação de uma função responsável por ligar algo
{
  digitalWrite(saida, HIGH);
  
}

void Desligar(int saida) // criação de uma função responsável por desligar algo
{
  digitalWrite(saida, LOW);
  
}
void setup() {
  Serial.begin(9600); // iniciar o monitor serial
  receptor.enableIRIn(); // iniciar o receptor
  pinMode(buzina, OUTPUT); 
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledbranco, OUTPUT);
  lcd.begin(16,2); // iniciar o display
}

void loop() {
  if (receptor.decode(&resultado))   { // Condição de decodificação
    switch (resultado.value) { // Seleção da Variável Resultado 
      case (btn1) : //Condições que executam os comandos  
        Serial.println("Tecla 1"); // Monitor Serial
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Luz da sala"); // exibição do Display
        lcd.setCursor(0,1);
        lcd.print("ligada!");
        Ligar(ledbranco); // Comando modularizado
        Desligar(ledvermelho);
        Desligar(ledverde);
        break;
         
      case (btn3): 
        Serial.println("Tecla 3");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Luz do banheiro");
        lcd.setCursor(0,1);
        lcd.print("ligada!");
        Desligar(ledbranco);
        Desligar(ledvermelho);
        Ligar(ledverde);
        break;
        
      case (btn4): 
        Serial.println("Tecla 4");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Luz do quarto");
        lcd.setCursor(0,1);
        lcd.print("ligada!");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        Desligar(ledbranco);
        Ligar(ledvermelho);
        Desligar(ledverde);
        break;
        
      case (btn5): 
        Serial.println("Tecla 5");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tecla 5");
        break;
        
      case (btn6): 
        Serial.println("Tecla 6");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tecla 6");
        break; 
        
      case (btn7): 
        Serial.println("Tecla 7");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tecla 7");
        break;
        
      case (btn8): 
        Serial.println("Tecla 8");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tecla 8");
        break;
        
      case (btn9): 
        Serial.println("Tecla 9");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tecla 9");
        break;
        
      case (btn_ligar): 
        Serial.println("Tecla ON");
        lcd.clear();
        Ligar(ledbranco);
        Ligar(ledvermelho);
        Ligar(ledverde);
        lcd.setCursor(0,0);
        lcd.print("Luzes acesas!");
        break; 

      case (btn_desligar): 
        Serial.println("Tecla OFF");
          lcd.clear();
          Desligar(ledbranco);
          Desligar(ledvermelho);
          Desligar(ledverde);
          lcd.setCursor(0,0);
          lcd.print("Luzes apagadas!");
        break; 
        
      case (btn_aumentar): 
          Serial.println("Tecla volume+");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Buzina ligada!");
          Ligar(buzina);
       break;

      case (btn_diminuir): 
        Serial.println("Tecla volume-");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Buzina deslig.!");
        Desligar(buzina);
     break;
        
      case (btn_cima): 
        Serial.println("Tecla seta para cima");
        lcd.clear();
          lcd.setCursor(0,0);
        lcd.print("Botao pra cima");
        break;
        
      case (btn_esquerda): 
        Serial.println("Tecla <-");
        lcd.clear();
          lcd.setCursor(0,0);
        lcd.print("Botao pra esq.");
        break; 
        
      case (btn_direita): 
        Serial.println("Tecla ->");
        lcd.clear();
          lcd.setCursor(0,0);
        lcd.print("Botao pra dir.");
        break;
        
        
      case (btn_baixo): 
        Serial.println("Tecla para baixo");
        lcd.clear();
          lcd.setCursor(0,0);
        lcd.print("Botao p/ baixo");
        break;                 
    } 
    receptor.resume(); 
  }
  delay(500);
}
