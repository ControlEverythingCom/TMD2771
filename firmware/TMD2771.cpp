#include "TMD2771.h"

void TMD2771::init(){
    Wire.begin();
    Wire.beginTransmission(address);
    Wire.write(0x00 | 128);
    Wire.write(7);
    byte status = Wire.endTransmission();
    if(status != 0){
        Serial.println("init failed");
    }
    Wire.beginTransmission(address);
    Wire.write(0x02 | 128);
    Wire.write(0xFF);
    status = Wire.endTransmission();
    if(status != 0){
        Serial.println("init failed");
    }
    // Wire.beginTransmission(address);
    // Wire.write(0x0E | 128);
    // Wire.write(32);
    // status = Wire.endTransmission();
    // if(status != 0){
    //     Serial.println("init failed");
    // }
    Wire.beginTransmission(address);
    Wire.write(0x0F | 128);
    Wire.write(48);
    status = Wire.endTransmission();
    if(status != 0){
        Serial.println("init failed");
    }
}

int TMD2771::getDistance(){
    Wire.beginTransmission(address);
    Wire.write(proximityLSB);
    byte status = Wire.endTransmission();
    if(status != 0){
        Serial.println("failed to read proximity registers");
        return 0;
    }
    Wire.requestFrom(address, 2);
    int proxLSB = Wire.read();
    int proxMSB = Wire.read();
    
    int distance = (proxMSB * 256)+proxLSB;
    return distance;
}