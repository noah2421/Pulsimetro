int IniciodeCuenta;
int Latidos;
boolean Encendido = 0;
int Tiempo = 0;
int Ritmo;
void setup() {
  //Milisegundos a minuto 60000
  Serial.begin(9600);

  pinMode(2, INPUT);
  delay(2000);
  Serial.println("Reiniciado");
}

void loop() {

  //Si esta recibiendo voltaje
  if ((digitalRead(2) == HIGH)) {
    IniciodeCuenta = millis();
    Serial.print("Inicio a los: ");
    Serial.println(IniciodeCuenta);
    Latidos = 1;
    Encendido = 1;
    Tiempo = Tiempo - IniciodeCuenta;
    Serial.println("Espere 20 segundos");
   //Serial.print("ESTAAAAAAAADOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO ");
   // Serial.println(Encendido);
    while (Encendido == 1) {
    //  Serial.println("Milllliiiiiiiiiiiiiiiiiiiiiiissssssssssssssssssssssssssssss");
     // Serial.println(millis());
       Tiempo = millis() - IniciodeCuenta;
       
     // Serial.println(Tiempo);
    //  delay(500);
   
        
    if (digitalRead(2) == HIGH) {
        Latidos = Latidos + 1;
        delay(500);
        //Serial.println(Latidos);
      
    }
        if (Tiempo >= 20000) {
            Encendido = 0;
           // Serial.println("Numero de latidos: ");
           // Serial.print(Latidos);
            Ritmo = Latidos * 3;
            Serial.println("Tu ritmo cardiaco es de ");
            Serial.println(Ritmo);
            Serial.println("Finalizado ");
            delay(5000);
            Serial.println("Listo para otra medicion");
            Serial.println("");
            
            ///Serial.println(Encendido);
          }
      
    }
  }

}
