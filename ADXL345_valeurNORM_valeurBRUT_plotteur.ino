#include <ADXL345.h>
#include <ESP8266WiFi.h> 
#include <Wire.h>

//-----------------code adxl345 valeurs normalisées sur plot-------------------
 
ADXL345 accelerometer;

//------------------gestion du range-----------------------
void showRange(void)
{
  Serial.print("Plage de mesure selectionnee : ");
 
  switch(accelerometer.getRange())
  {
    case ADXL345_RANGE_16G: Serial.println("+/- 16 g"); break;
    case ADXL345_RANGE_8G:  Serial.println("+/- 8 g");  break;
    case ADXL345_RANGE_4G:  Serial.println("+/- 4 g");  break;
    case ADXL345_RANGE_2G:  Serial.println("+/- 2 g");  break;
    default: Serial.println("Portée incorrecte"); break;
  }
}

//------------gestion de la vitesse de transmission--------
void showDataRate(void)
{
  Serial.print("Vitesse de transmission selectionnee: ");
 
  switch(accelerometer.getDataRate())
  {
    case ADXL345_DATARATE_3200HZ: Serial.println("3200 Hz"); break;
    case ADXL345_DATARATE_1600HZ: Serial.println("1600 Hz"); break;
    case ADXL345_DATARATE_800HZ:  Serial.println("800 Hz");  break;
    case ADXL345_DATARATE_400HZ:  Serial.println("400 Hz");  break;
    case ADXL345_DATARATE_200HZ:  Serial.println("200 Hz");  break;
    case ADXL345_DATARATE_100HZ:  Serial.println("100 Hz");  break;
    case ADXL345_DATARATE_50HZ:   Serial.println("50 Hz");   break;
    case ADXL345_DATARATE_25HZ:   Serial.println("25 Hz");   break;
    case ADXL345_DATARATE_12_5HZ: Serial.println("12.5 Hz"); break;
    case ADXL345_DATARATE_6_25HZ: Serial.println("6.25 Hz"); break;
    case ADXL345_DATARATE_3_13HZ: Serial.println("3.13 Hz"); break;
    case ADXL345_DATARATE_1_56HZ: Serial.println("1.56 Hz"); break;
    case ADXL345_DATARATE_0_78HZ: Serial.println("0.78 Hz"); break;
    case ADXL345_DATARATE_0_39HZ: Serial.println("0.39 Hz"); break;
    case ADXL345_DATARATE_0_20HZ: Serial.println("0.20 Hz"); break;
    case ADXL345_DATARATE_0_10HZ: Serial.println("0.10 Hz"); break;
    default: Serial.println("Vitesse de transmission incorrecte"); break;
  }
}

//----------------set up--------------------
void setup() {
  Serial.begin(115200);
  Serial.println();
  // initialisation accéléromètre
  if (!accelerometer.begin())
  {
    delay(500);
  }
  // accéléromètre Range initialisation 
  accelerometer.setRange(ADXL345_RANGE_2G);
  // Affichage range et vitesse de transmission
  showRange();
  showDataRate();
  
}

//---------------------boucle---------------
void loop() {
  // Lecture valeur brute
  Vector raw = accelerometer.readRaw();
  // Affichage valeur brute
  //Serial.print(raw.XAxis);
  //Serial.print(", ");
  //Serial.print(raw.YAxis);
  //Serial.print(", ");
  //Serial.println(raw.ZAxis);
  
  //lecture valeur normalisé
  Vector norm = accelerometer.readNormalize();
  // Affichage valeur normalisé 
  // 2G:  limite plot, 21/-21
  // 4G:  limite plot, 41/-41
  // 8G:  limite plot, 81/-81
  // 16G: limite plot, 160/-160
  Serial.print(21);
  Serial.print(", ");
  Serial.print(-21);
  Serial.print(", ");
  Serial.print(norm.XAxis);
  Serial.print(", ");
  Serial.print(norm.YAxis);
  Serial.print(", ");
  Serial.println(norm.ZAxis);
}
