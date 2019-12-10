//PINS
int MOTOR_ANDAR_FRENTE=4;
int MOTOR_VIRAR_ESQUERDA=6;
int MOTOR_VIRAR_DIREITA=7;
int MOTOR_ANDAR_TRAS=5;
int BUZINA = 11;
int speed1 = 9;
int speed2 = 10;
//DEFINE
int mais = 16;
int MAX = 191;
int MIN = 40;
int valor = MIN;
char rc;
float seno;
int frequencia;
bool buzina = false;


void setup()
{
 pinMode(MOTOR_VIRAR_ESQUERDA, OUTPUT);
 pinMode(MOTOR_VIRAR_DIREITA, OUTPUT);
 pinMode(MOTOR_ANDAR_TRAS, OUTPUT);
 pinMode(MOTOR_ANDAR_FRENTE, OUTPUT);
 pinMode(speed1, OUTPUT);
 pinMode(speed2,OUTPUT);
  pinMode(BUZINA,OUTPUT);
 Serial.begin(9600);
}
 
void loop()
{
  analogWrite(speed2,MAX);
  analogWrite(speed1,valor);

  if(buzina){
    for(int x=0;x<180;x++){
             seno=(sin(x*3.1416/180));
             //gera uma frequência a partir do valor do seno
             frequencia = 2000+(int(seno*1100));
              tone(BUZINA,frequencia);
              delay(2);
            }
  }
  else{
    tone(BUZINA, 0);
  }
 
 
  if(Serial.available() > 0){
      rc = Serial.read();
      switch(rc){
        case '0':valor = MIN;
        break;
        case '1':valor = MIN+mais;
        break;
        case '2':valor = MIN+mais*2;
        break;
        case '3':valor = MIN+mais*3;
        break;
        case '4':valor = MIN+mais*4;
        break;
        case '5':valor = MIN+mais*5;
        break;
        case '6':valor = MIN+mais*6;
        break;
        case '7':valor = MIN+mais*7;
        break;
        case '8':valor = MIN+mais*8;
        break;
        case '9':valor = MIN+mais*9;
        break;
        case 'q':valor = MIN+mais*10;
        break;
        }
      switch (rc){
        case 'F':
           front();
           desligaVirar();
        break;
        case 'B':
          back();
          desligaVirar();
        break;
        case 'L':
          left();
          desligaAndar();
        break;
        case 'R':
          right();
          desligaAndar();
        break;
        case 'G':
          left();
          front();
        break;
        case 'I':
          right();
          front();          
        break;
        case 'H':
          left();
          back();
        break;
        case 'J':
          right();
          back();        
        break;
        case 'V':
          alternaBuzina();
        break;
        case 'v':
          alternaBuzina();
        break;      
        default:
          desligaAll();
        break;
      }
    }
    delay(200);
}

void front(){
  digitalWrite(MOTOR_ANDAR_FRENTE, HIGH);
  digitalWrite(MOTOR_ANDAR_TRAS, LOW);
}

void back(){
  digitalWrite(MOTOR_ANDAR_FRENTE, LOW);
  digitalWrite(MOTOR_ANDAR_TRAS, HIGH);
}

void left(){
  digitalWrite(MOTOR_VIRAR_ESQUERDA, HIGH);
  digitalWrite(MOTOR_VIRAR_DIREITA, LOW);
}

void right(){
  digitalWrite(MOTOR_VIRAR_ESQUERDA, LOW);
  digitalWrite(MOTOR_VIRAR_DIREITA, HIGH);
}

void desligaAndar(){
  digitalWrite(MOTOR_ANDAR_FRENTE, LOW);
  digitalWrite(MOTOR_ANDAR_TRAS, LOW);
}

void desligaVirar(){
  digitalWrite(MOTOR_VIRAR_ESQUERDA, LOW);
  digitalWrite(MOTOR_VIRAR_DIREITA, LOW);
}

void desligaAll(){
  desligaAndar();
  desligaVirar();
}

void alternaBuzina(){
  buzina = !buzina;
}
