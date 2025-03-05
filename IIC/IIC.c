#include "IIC.h"
//在此处添加必要的库函数

//scl 和 sda 改成IIC硬件层接口函数
void sda_PinSet(unsigned char high_OR_low)
{
    ;
}
void scl_Pinset(unsigned char high_OR_low)
{
    ;
}

void SetSDA_Output(void)
{

}

void SetSDA_Input(void)
{

}

unsigned char ReadSDA(void)
{
    unsigned char readSDA;
    ;
    return readSDA;
}

void IICdelay_us(unsigned char ms)
{
    ;//编写该函数，或者把此处删除添加delay.h文件
}

void IIC_Start(void)
{
    SetSDA_Output();
    sda_PinSet(1);
    IICdelay_us(4);

    scl_Pinset(1);
    IICdelay_us(4);

    sda_PinSet(0);
    IICdelay_us(4);

    scl_Pinset(0);
    IICdelay_us(4);
}


void IIC_Stop(void)
{
    sda_PinSet(0);
    IICdelay_us(4);
    scl_Pinset(1);
    IICdelay_us(4);
    sda_PinSet(1);
    IICdelay_us(4);
}


void IIC_sendByte(unsigned char Data)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        sda_PinSet(Data & (0x80 >> i));
        IICdelay_us(4);
        scl_Pinset(1);
        IICdelay_us(4);
        scl_Pinset(0);
        IICdelay_us(4);
    }
}




unsigned char IIC_reciveByte(void)
{
    unsigned char i;
    unsigned char recv_data = 0x00;
    SetSDA_Input();
    sda_PinSet(1);//释放总线

    for(i = 0; i < 8; i++)
    {
        scl_Pinset(1);
        IICdelay_us(4);
        if(ReadSDA()) {recv_data |= (0x80 >> i);}
        IICdelay_us(4);
        scl_Pinset(0);
        IICdelay_us(4);
    }

    SetSDA_Output();
    return recv_data;
}


void IIC_sendACK(unsigned char ACK)
{
    sda_PinSet(ACK);
    IICdelay_us(4);
    scl_Pinset(1);
    IICdelay_us(4);
    scl_Pinset(0);
    IICdelay_us(4);
}
unsigned char IIC_recevieACK(void)
{
    unsigned char recv_ACK;

    sda_PinSet(1); //释放总线
    SetSDA_Input();
    scl_Pinset(1);
    IICdelay_us(4);
    recv_ACK = ReadSDA();
    IICdelay_us(4);
    scl_Pinset(0);
    SetSDA_Output();

    return recv_ACK;
}