#ifndef __SD_H__
#define __SD_H__

#include "STC12C5A60S2.H"

sbit SD_CS =P2^6; //SD��Ƭѡ 	  ����
sbit SD_SI =P0^5; //SD��ͬ������  ���� 
sbit SD_SCL=P0^7; //SD��ͬ��ʱ��  ����
sbit SD_SO =P0^6; //SD��ͬ������  ���

#define DELAY_TIME 20 //SD���ĸ�λ���ʼ��ʱSPI����ʱ����������ʵ�������޸���ֵ����������SD����λ���ʼ��ʧ��
#define TRY_TIME 50   //��SD��д������֮�󣬶�ȡSD���Ļ�Ӧ����������TRY_TIME�Σ������TRY_TIME���ж�������Ӧ��������ʱ��������д��ʧ��

//�����붨��
//-------------------------------------------------------------
#define INIT_CMD0_ERROR     0x01 //CMD0����
#define INIT_CMD1_ERROR     0x02 //CMD1����
#define WRITE_BLOCK_ERROR   0x03 //д�����
#define READ_BLOCK_ERROR    0x04 //�������
//-------------------------------------------------------------

unsigned char SD_Reset();
unsigned char SD_Init();
unsigned char SD_Write_Sector(unsigned long addr,unsigned char *Buffer);
unsigned char SD_Read_Sector(unsigned long addr,unsigned char *buffer);

#endif