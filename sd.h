#ifndef __SD_H__
#define __SD_H__

#include "STC12C5A60S2.H"

sbit SD_CS =P2^6; //SD卡片选 	  输入
sbit SD_SI =P0^5; //SD卡同步数据  输入 
sbit SD_SCL=P0^7; //SD卡同步时钟  输入
sbit SD_SO =P0^6; //SD卡同步数据  输出

#define DELAY_TIME 20 //SD卡的复位与初始化时SPI的延时参数，根据实际速率修改其值，否则会造成SD卡复位或初始化失败
#define TRY_TIME 50   //向SD卡写入命令之后，读取SD卡的回应次数，即读TRY_TIME次，如果在TRY_TIME次中读不到回应，产生超时错误，命令写入失败

//错误码定义
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0错误
#define INIT_CMD1_ERROR     0x02 //CMD1错误
#define WRITE_BLOCK_ERROR   0x03 //写块错误
#define READ_BLOCK_ERROR    0x04 //读块错误
//-------------------------------------------------------------

unsigned char SD_Reset();
unsigned char SD_Init();
unsigned char SD_Write_Sector(unsigned long addr,unsigned char *Buffer);
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);

#endif