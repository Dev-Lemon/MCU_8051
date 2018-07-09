/*Thu vien dieu khien dong co
Author: Pham Duc Khanh
DateTime: 27/05/2018*/

#ifndef __CAR_H__
#define __CAR_H__
#include <REGX52.H>

/*Khai bao chan dieu khien banh xe*/
#define bxt1 P2_3  
#define bxt2 P2_2    
#define bxp1 P2_1
#define bxp2 P2_0
/*Khai bao chan dieu khien toc do quay*/
#define speed1 P2_4
#define speed2 P2_5
/*Khai bao cac chan den coi*/
#define dent P2_6
#define loa P2_7
#define dens1 P0_6 
#define dens2 P0_7
/*Cac Ham Dieu Khien*/
void tien();// ham giup oto di thang
void lui();// ham cho oto lui
void trai();// ham re trai
void phai();// ham re phai
void dung();// ham dung
void batdent();// ham bat den truoc
void tatdent();// ham tat den truoc
void batdens();// ham bat den sau
void tatdens();// ham tat den sau
void batloa();//ham bat loa
void tatloa();// ham tat loa
#endif