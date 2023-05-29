//Incluimos Librerias y Variables
#include <LiquidCrystal_I2C.h>

int Motor_Derecha_A = 10;
int Motor_Derecha_B = 11;
int Motor_Izquierda_A = 12;
int Motor_Izquierda_B = 13;
int dato;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //Declarar pines de Salida
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(13,OUTPUT);
   Serial.begin(9600);

  //Iniciar Pantalla LCD
   lcd.init();
   lcd.backlight();
   lcd.clear();


}

void loop() {
  //Enviar dato al HC06
  if(Serial.available()){
    char dato = Serial.read();
    Serial.println(dato);

  if(dato==50){ //Adelante
    digitalWrite(Motor_Derecha_A, HIGH);
    digitalWrite(Motor_Derecha_B, LOW);
    digitalWrite(Motor_Izquierda_A, HIGH);
    digitalWrite(Motor_Izquierda_B, LOW);

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Adelante");
  }

  if(dato==51){ //Reversa
    digitalWrite(Motor_Derecha_A, LOW);
    digitalWrite(Motor_Derecha_B, HIGH);
    digitalWrite(Motor_Izquierda_A, LOW);
    digitalWrite(Motor_Izquierda_B, HIGH);

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Reversa");
  }

  if(dato==52){ //Derecha
    digitalWrite(Motor_Derecha_A, HIGH);
    digitalWrite(Motor_Derecha_B, LOW);
    digitalWrite(Motor_Izquierda_A, LOW);
    digitalWrite(Motor_Izquierda_B, HIGH);

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Derecha");
  }

  if(dato==53){ //Izquierda
    digitalWrite(Motor_Derecha_A, LOW);
    digitalWrite(Motor_Derecha_B, HIGH);
    digitalWrite(Motor_Izquierda_A, HIGH);
    digitalWrite(Motor_Izquierda_B, LOW);

    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Izquierda");
  }

  if(dato==54){ //Parar
    digitalWrite(Motor_Derecha_A, LOW);
    digitalWrite(Motor_Derecha_B, LOW);
    digitalWrite(Motor_Izquierda_A, LOW);
    digitalWrite(Motor_Izquierda_B, LOW);

    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Parar");
  }
}
}
