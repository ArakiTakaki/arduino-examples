// 変数の定義
#define LED_PIN 13
 
// 初期化
void setup(){
  pinMode(LED_PIN, OUTPUT);
  // シリアルポートを9600 bps[ビット/秒]で初期化 
  Serial.begin(9600);
}
 
// 繰り返し処理
void loop(){
  int inputchar;

  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
  switch(inputchar){
    case 'o':
      // 読み込みデータが　o の場合
      digitalWrite(LED_PIN, HIGH);
      delay(100);

      digitalWrite(LED_PIN, LOW);
      break;
    case 'p':  
      // 読み込みデータが　p の場合
      digitalWrite(LED_PIN, HIGH);
      delay(10000);

      digitalWrite(LED_PIN, LOW);
      break;
    default:
      break;
  }
}