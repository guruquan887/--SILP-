#ifndef __TEST1_H
#define __TEST1_H
struct bit_def {		/* ビットアクセス喘			*/
    unsigned char  b0:1;	/* ビット0(LSB)				*/
    unsigned char  b1:1;	/* ビット1					*/
    unsigned char  b2:1;	/* ビット2					*/
    unsigned char  b3:1;	/* ビット3					*/
    unsigned char  b4:1;	/* ビット4					*/
    unsigned char  b5:1;	/* ビット5					*/
    unsigned char  b6:1;	/* ビット6					*/
    unsigned char  b7:1;	/* ビット7(MSB)				*/
};

union byte_def{				/* ビット/バイトアクセス喘	*/
  unsigned char  byte;		/* バイトアクセス喘			*/
  struct bit_def bit;		/* ビットアクセス喘			*/
};
#endif /*__TEST1_H*/