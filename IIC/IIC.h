#ifndef __IIC_H__
#define __IIC_H__

void IIC_Start(void);
void IIC_Stop(void);
void IIC_sendByte(unsigned char Data);
unsigned char IIC_reciveByte(void);
void IIC_sendACK(unsigned char ACK);
unsigned char IIC_recevieACK(void);

#endif