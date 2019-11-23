#define SERIAL_PORT_1 9600

// 初期化
void setup(){
  // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(SERIAL_PORT_1);
}

// 繰り返し処理
void loop(){
  if (Serial.available() > 0) {
    int operation = Serial.read();
  }
}

