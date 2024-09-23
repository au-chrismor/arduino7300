#define BAND_IN A0
#define NUM_SAMPLES 3

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;               // We might need this for some USB boards.  No harm
    }
}

void loop() {
    delay(1000);
    int i = 0;
    int vBand = 0;
    int vRes = 0;
    for(i=0; i < NUM_SAMPLES; i++) {
        vBand += analogRead(BAND_IN);
        delay(200);
    }
    vRes = vBand / NUM_SAMPLES;
    Serial.print("Reading ");
    Serial.print(vRes);

    if(vRes == 0)
      Serial.println(" Transceiver OFF");
    else if(vRes > 0 && vRes < 100)
      Serial.println(" 30m");
    else if(vRes >= 100 && vRes < 200)
      Serial.println(" 6m");
    else if(vRes >= 200 && vRes < 235)
      Serial.println(" 10m/12m");
    else if(vRes >= 250 && vRes < 350)
      Serial.println(" 17m/15m");
    else if(vRes >= 350 && vRes < 450)
      Serial.println(" 20m");
    else if(vRes >= 450 && vRes < 550)
      Serial.println(" 40m/60m");
    else if(vRes >= 550 && vRes < 650)
      Serial.println(" 80m");
    else if(vRes >= 650 && vRes < 800)
      Serial.println(" 160m/630m");
}
