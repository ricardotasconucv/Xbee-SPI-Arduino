#include "Xbee.h"


Xbee::Xbee(uint8_t _sselpin, uint8_t _attnpin, uint16_t _spispeed){

    uint8_t ssel_pin=_sselpin;
    uint8_t attn_pin=_attnpin;
    uint16_t spi_speed=_spispeed;

    pinMode(ssel_pin, OUTPUT);
    pinMode(attn_pin, INPUT);
    
    digitalWrite(ssel_pin,HIGH);


}
Xbee::Xbee(uint8_t _sselpin, uint8_t _attnpin){
    uint8_t ssel_pin=_sselpin;
    uint8_t attn_pin=_attnpin;
    uint16_t spi_speed=16000000;

    pinMode(ssel_pin, OUTPUT);
    pinMode(attn_pin, INPUT);

    digitalWrite(ssel_pin,HIGH);
}

void begin(){
    
    



}



uint8_t Xbee::CheckSum(uint8_t *data, uint16_t len){

    checksum.valor=0;
    for(uint8_t i=0;i<len;i++){
        checksum.valor=checksum.valor+*data;
        data++;
    }
    return 0xFF - checksum.aux[0];
}

uint8_t *Xbee::FrameData(uint8_t *data,uint16_t len){

    length.valor=len;

    frame_data[0]=Start_Delimeter;
    frame_data[1]=length.aux[1];
    frame_data[2]=length.aux[0];
    frame_data[len+3]=CheckSum(data,len);
    for (uint16_t i=0;i<len;i++){
        frame_data[i+3]=*data;
        data++;
    }
    return  &frame_data[0];
}