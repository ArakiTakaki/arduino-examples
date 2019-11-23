// 抵抗 Resistor120PCS?  GND -
// WMd 13 +
#define START_OF_OPERATION 's'
#define END_OF_OPERATION 'e'

#define COLOR_RED 'r'
#define LED_RED_PIN 5
#define COLOR_GREEN 'g'
#define LED_GREEN_PIN 6
#define COLOR_BLUE 'b'
#define LED_BLUE_PIN 9

int colorChar = 0;
int serialInputR = 0;
float rialSerialInputR = 0.1;
int serialInputG = 0;
float rialSerialInputG = 0.1;
int serialInputB = 0;
float rialSerialInputB = 0.1;

// 初期化
void setup(){
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(9600);
}

void colorPick() {
  if (Serial.available() > 0) {
    int operation = Serial.read();
    if (colorChar == 0) {
      colorChar = operation;
      return;
    } else {
      switch (colorChar) {
        case COLOR_RED:
          serialInputR = operation;
          Serial.print("red: ");
          Serial.println(operation);
          colorChar = 0;
          break;
        case COLOR_GREEN:
          serialInputG = operation;
          Serial.print("green: ");
          Serial.println(operation);
          colorChar = 0;
          break;
        case COLOR_BLUE:
          serialInputB = operation;
          Serial.print("blue: ");
          Serial.println(operation);
          colorChar = 0;
          break;
        default:
          colorChar = 0;
      }
    }
  }
}

// 繰り返し処理
void loop(){
  colorPick();
  rialSerialInputR += ((float)serialInputR - rialSerialInputR) * 0.05;
  rialSerialInputG += ((float)serialInputG - rialSerialInputG) * 0.05;
  rialSerialInputB += ((float)serialInputB - rialSerialInputB) * 0.05;
  setColor((int)rialSerialInputR, (int)rialSerialInputG, (int)rialSerialInputB);
}


void setColor(int red, int green, int blue) {
  analogWrite(LED_RED_PIN, red);
  Serial.println(rialSerialInputR);
  analogWrite(LED_GREEN_PIN, green);
  analogWrite(LED_BLUE_PIN, blue);
}

