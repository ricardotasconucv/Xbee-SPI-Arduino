#ifndef __XbeeSPI_H__
#define __XbeeSPI_H__

#include <stdint.h>
#include <Arduino.h>
//#include <SPI.h>

//Defenicion de datos fijos

#define Start_Delimeter 0x7E

#define Frame_size 200

//Definicion de comandos

//Definicion de estructuras

union{
    uint8_t aux[4];
    uint32_t valor;
}checksum;

union{
    uint8_t aux[2];
    uint16_t valor;
}length;

//Definicion de variables

uint8_t frame_data[Frame_size];

//Defenicion de clase

class Xbee
{
private:
    uint8_t ssel_pin;
    uint8_t attn_pin;
    uint16_t spi_speed;
    //uint8_t data[];
    //uint16_t len;
public:
    Xbee(uint8_t _sselpin, uint8_t _attnpin, uint16_t _spispeed);
    Xbee(uint8_t _sselpin, uint8_t _attnpin);
    uint8_t CheckSum (uint8_t *data, uint16_t len);
    uint8_t *FrameData(uint8_t *data,uint16_t len);
    void begin();
};
#endif