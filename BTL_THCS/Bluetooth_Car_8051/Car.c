/*Cac Ham Dieu Khien Dong Co*/
#include"Car.h"
/*cac ham dieu khien*/
void batdent(){
	dent=0;
}
void tatdent(){
	dent=1;
}
void batdens(){
	dens1 = dens2 = 0;
}
void tatdens(){
	dens1 = dens2 = 1;
}
void dung(){
   bxt1=bxt2=bxp1=bxp2=0;
}
void trai(){
	bxt1 = bxt2 = 0;
	bxp1 = 1;
	bxp2 = 0;
}
void phai(){
	bxp1 = bxp2 = 0;
	bxt1 = 1;
	bxt2 = 0;
}
void tien(){
 	bxt1 = bxp1 = 1;
	bxt2 = bxp2 = 0;
}
void lui(){
 	bxt1 = bxp1 = 0;
	bxt2 = bxp2 = 1;
}
void batloa(){
   loa = 1;
}
void tatloa(){
   loa = 0;
}