int Motor1 = 7;
int Motor2 = 6;
int Motor3 = 5;
int Motor4 = 4;
int led1 = 8;
int led2 = 9;
int DataCheck = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
   
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, HIGH);
  Serial.print("Simulasi Pengendali Kipas dan Lampu Kamar dan Dapur");
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
   
}
void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(Motor2, LOW);digitalWrite(Motor1, HIGH); Serial.println("Kipas Kamar menyala");}
    if(data == '2'){DataCheck = 1; digitalWrite(Motor1, LOW);digitalWrite(Motor2,  LOW); Serial.println("Kipas Kamar dimatikan");}
    if(data == '3'){DataCheck = 1; digitalWrite(Motor3, LOW);digitalWrite(Motor4, HIGH); Serial.println("Kipas Dapur menyala");}
    if(data == '4'){DataCheck = 1; digitalWrite(Motor3, LOW);digitalWrite(Motor4,  LOW); Serial.println("Kipas Dapur dimatikan");}
    if(data == '5'){DataCheck = 1; digitalWrite(led1, HIGH); Serial.println("Lampu Kamar menyala");}
    if(data == '6'){DataCheck = 1; digitalWrite(led1, LOW); Serial.println("Lampu Kamar dimatikan");}
    if(data == '7'){DataCheck = 1; digitalWrite(led2,  HIGH); Serial.println("Lampu Dapur menyala");}
    if(data == '8'){DataCheck = 1; digitalWrite(led2,  LOW); Serial.println("Lampu Dapur dimatikan");}
    if(data == '9'){DataCheck = 1; digitalWrite(led1, LOW);digitalWrite(led2,  LOW); Serial.println("Lampu Kamar dan Dapur dimatikan");}
    if(data == '-'){DataCheck = 1; digitalWrite(led1, HIGH);digitalWrite(led2,  HIGH); Serial.println("Lampu Kamar dan Dapur menyala");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }
}
