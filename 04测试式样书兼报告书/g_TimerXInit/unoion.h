#ifndef __TEST1_H
#define __TEST1_H
struct bit_def {		/* �ӥåȥ���������			*/
    unsigned char  b0:1;	/* �ӥå�0(LSB)				*/
    unsigned char  b1:1;	/* �ӥå�1					*/
    unsigned char  b2:1;	/* �ӥå�2					*/
    unsigned char  b3:1;	/* �ӥå�3					*/
    unsigned char  b4:1;	/* �ӥå�4					*/
    unsigned char  b5:1;	/* �ӥå�5					*/
    unsigned char  b6:1;	/* �ӥå�6					*/
    unsigned char  b7:1;	/* �ӥå�7(MSB)				*/
};

union byte_def{				/* �ӥå�/�Х��ȥ���������	*/
  unsigned char  byte;		/* �Х��ȥ���������			*/
  struct bit_def bit;		/* �ӥåȥ���������			*/
};
#endif /*__TEST1_H*/