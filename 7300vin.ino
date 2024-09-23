void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;               // We might need this for some USB boards.  No harm
    }
}

void loop() {
    delay(10000);
    int vBand = analogRead(A0);
    Serial.print("Reading ");
    Serial.println(vBand);
}
