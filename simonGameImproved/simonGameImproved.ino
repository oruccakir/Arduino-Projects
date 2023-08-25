int startPin = D12;
int startPinvalue = 0;

int redButtonPin = D11;
int redPinvalue = 0;

int blueButtonPin = D10;
int bluePinvalue = 0;

int yellowButtonPin = D9;
int yellowPinvalue = 0;

int redLedPin = D8;
int blueLedPin = D7;
int yellowLedPin = D6;

int timeControllerPin = A0;
int readTimeValue = 0;

const int rows = 10000;
const int cols = 3;

int whichRow = 0;
int gamerRow = 0;
int gamerCol = 0;

bool isGameStarted = false;
bool isGameFinished = false;


const int RANDOM_ON_STATE = 1;
const int INPUT_STATE = 2;
const int LED_STATE = 3;
const int GAME_OVER_STATE = 4;

int STATE = RANDOM_ON_STATE;

int rnd = 0;

int matrix[rows][cols];

int delayTime = 750;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(yellowButtonPin,INPUT);
  pinMode(redLedPin,OUTPUT);
  pinMode(blueLedPin,OUTPUT);
  pinMode(yellowLedPin,OUTPUT);
  pinMode(timeControllerPin,INPUT);

}

void loop() {
  
  
  if(isGameStarted == false){
    while(digitalRead(startPin) == 0){

    }

    isGameStarted = true;

  }
    
  
  if(isGameStarted){

    digitalWrite(LED_BUILTIN, HIGH);

    switch(STATE){

      case RANDOM_ON_STATE :

        Serial.println("RANDOM STATE");

        rnd = random(0,3);

        matrix[whichRow][rnd] = 1;
        whichRow = whichRow+1;

        for(int i=0; i<whichRow; i++){
          for(int k=0; k<cols; k++){
            Serial.print(matrix[i][k]);
            Serial.print(" ");
          }
          Serial.println();
        }

        switch(rnd){
          case 0:
            digitalWrite(redLedPin,HIGH);
            delay(delayTime);
            digitalWrite(redLedPin,LOW);
            delay(delayTime);
            break;
          case 1:
            digitalWrite(blueLedPin,HIGH);
            delay(delayTime);
            digitalWrite(blueLedPin,LOW);
            delay(delayTime);
            break;
          case 2:
            digitalWrite(yellowLedPin,HIGH);
            delay(delayTime);
            digitalWrite(yellowLedPin,LOW);
            delay(delayTime);
            break;
        }

        STATE = INPUT_STATE;
          
        break;

      case INPUT_STATE :

        Serial.println("INPUT STATE");
        
        gamerRow = 0;

        for(int i=0; i<whichRow && isGameFinished == false; i++){

          while(digitalRead(redButtonPin) == 0 && digitalRead(blueButtonPin) == 0 && digitalRead(yellowButtonPin) == 0){

          }

          redPinvalue = digitalRead(redButtonPin);
          bluePinvalue = digitalRead(blueButtonPin);
          yellowPinvalue = digitalRead(yellowButtonPin);

          if(redPinvalue)
            gamerCol = 0;
          else if(bluePinvalue)
            gamerCol = 1;
          else
            gamerCol = 2;
          
          redPinvalue = 0;
          bluePinvalue = 0;
          yellowPinvalue = 0;

          if(matrix[gamerRow][gamerCol] != 1){
            isGameFinished = true;
          }
          else{
            gamerRow = gamerRow+1;
          }

          delay(500);

        }
        
        if(isGameFinished)
          STATE = GAME_OVER_STATE;
        else
          STATE = LED_STATE;

        break;

      case LED_STATE :
        
        Serial.println("LED STATE");

        for(int i=0; i<whichRow; i++){

        for(int k=0; k<cols; k++){

          if(matrix[i][k] == 1){

            if(k == 0){
      
              digitalWrite(redLedPin,HIGH);
              delay(delayTime);
              digitalWrite(redLedPin,LOW);
              delay(delayTime);

            }
            else if(k == 1){

            digitalWrite(blueLedPin,HIGH);
            delay(delayTime);
            digitalWrite(blueLedPin,LOW);
            delay(delayTime);

          }
          else if(k == 2){

            digitalWrite(yellowLedPin,HIGH);
            delay(delayTime);
            digitalWrite(yellowLedPin,LOW);
            delay(delayTime);

          }

          }
        }
      }

        STATE = RANDOM_ON_STATE;

        break;
      case GAME_OVER_STATE :

        Serial.println("GAME OVER STATE");

        digitalWrite(LED_BUILTIN, LOW);
        delay(3000);
        whichRow = 0;
        isGameFinished = false;
        isGameStarted = false;
        for(int i=0; i<rows; i++){
        for(int k=0; k<cols; k++){
          matrix[i][k] = 0;
        }
      }

        

        STATE = RANDOM_ON_STATE;

        break;
    }


  }
  






}
