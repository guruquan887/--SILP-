/* ----------------------------------------------------------------------------
*   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
*   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
*
* [FILE]
*     target.h
*
* [DESCRIPTION]
*     R8C/Tiny�ذ�ޗpSFR��`̧��(C����p)
*
* [NOTE]
*     1. ���̃v���O�����͋���p�ł��B(�]�p�s��)
*     2. OAKS8-LCD Board�Ή�
*     3. OAKS8-R5F21114FP(R8C/11�O���[�v,20MHz)�Ή�
*
* [VERSION]
*     v1.00  2011/05/20 RENESAS Semiconductor Training Center  �V�K�쐬
* ---------------------------------------------------------------------------*/

#ifndef __TARGET_H
#define __TARGET_H

/******************************************************************************
*  SFR�̈�̌^�錾
******************************************************************************/
struct bit_def {			/* �r�b�g�A�N�Z�X�p			*/
    unsigned char  b0:1;	/* �r�b�g0(LSB)				*/
    unsigned char  b1:1;	/* �r�b�g1					*/
    unsigned char  b2:1;	/* �r�b�g2					*/
    unsigned char  b3:1;	/* �r�b�g3					*/
    unsigned char  b4:1;	/* �r�b�g4					*/
    unsigned char  b5:1;	/* �r�b�g5					*/
    unsigned char  b6:1;	/* �r�b�g6					*/
    unsigned char  b7:1;	/* �r�b�g7(MSB)				*/
};

union byte_def{				/* �r�b�g/�o�C�g�A�N�Z�X�p	*/
  unsigned char  byte;		/* �o�C�g�A�N�Z�X�p			*/
  struct bit_def bit;		/* �r�b�g�A�N�Z�X�p			*/
};


/*-----------------------------------------------------------------------------
 *	�v���e�N�g���W�X�^
 *---------------------------------------------------------------------------*/
#define		PRCR_ADDR	(*(volatile union byte_def *)0x000A)
#define		PRCR		PRCR_ADDR.byte

/* �v���e�N�g�r�b�g0	*/
#define		PRC0		PRCR_ADDR.bit.b0/* CM0,CM1,OCD,HR0,HR1���W�X�^�ւ�
																�������݋���*/
/* �v���e�N�g�r�b�g1	*/
#define		PRC1		PRCR_ADDR.bit.b1/* PM0,PM1���W�X�^�ւ̏������݋���	*/
/* �v���e�N�g�r�b�g2	*/
#define		PRC2		PRCR_ADDR.bit.b2/* PD0���W�X�^�ւ̏������݋���		*/

/*-----------------------------------------------------------------------------
 *	INT0���̓t�B���^�I�����W�X�^
 *---------------------------------------------------------------------------*/
#define		INT0F_ADDR	(*(volatile unsigned char *)0x001E)
#define		INT0F		INT0F_ADDR

/*-----------------------------------------------------------------------------
 * �^�C�}X���荞�ݐ��䃌�W�X�^
 *---------------------------------------------------------------------------*/
#define		TXIC_ADDR	(*(volatile union byte_def *)0x0056)
#define		TXIC		TXIC_ADDR.byte

/* �^�C�}X���荞�ݗv���r�b�g	*/
#define		IR_TXIC		 TXIC_ADDR.bit.b3

/*-----------------------------------------------------------------------------
 * �^�C�}Y���荞�ݐ��䃌�W�X�^
 *---------------------------------------------------------------------------*/
#define		TYIC_ADDR	(*(volatile unsigned char *)0x0057)
#define		TYIC		TYIC_ADDR

/*-----------------------------------------------------------------------------
 * �R���y�A0���荞�ݐ��䃌�W�X�^
 *---------------------------------------------------------------------------*/
#define		CMP0IC_ADDR	(*(volatile union byte_def *)0x005C)
#define		CMP0IC		CMP0IC_ADDR.byte

/* �R���y�A0���荞�ݗv���r�b�g	*/
#define		IR_CMP0IC	CMP0IC_ADDR.bit.b3

/*-----------------------------------------------------------------------------
 * INT0���荞�ݐ��䃌�W�X�^
 *---------------------------------------------------------------------------*/
#define		INT0IC_ADDR	(*(volatile union byte_def *)0x005D)
#define		INT0IC		INT0IC_ADDR.byte

/* INT0���荞�ݗv���r�b�g	*/
#define		IR_INT0IC	INT0IC_ADDR.bit.b3

/*-----------------------------------------------------------------------------
 *	�^�C�}Y,Z���[�h���W�X�^
 *---------------------------------------------------------------------------*/
#define		TYZMR_ADDR	(*(volatile union byte_def *)0x0080)
#define		TYZMR		TYZMR_ADDR.byte

/* �^�C�}Y�J�E���g�J�n�t���O	*/
#define		TYS			TYZMR_ADDR.bit.b3

/*-----------------------------------------------------------------------------
 *	�v���X�P�[��Y���W�X�^
 *---------------------------------------------------------------------------*/
#define		PREY_ADDR	(*(volatile unsigned char *)0x0081)
#define		PREY		PREY_ADDR

/*-----------------------------------------------------------------------------
 *	�^�C�}Y�v���C�}�����W�X�^
 *---------------------------------------------------------------------------*/
#define		TYPR_ADDR	(*(volatile unsigned char *)0x0083)
#define		TYPR		TYPR_ADDR

/*-----------------------------------------------------------------------------
 *	�^�C�}X���[�h���W�X�^
 *---------------------------------------------------------------------------*/
#define		TXMR_ADDR	(*(volatile union byte_def *)0x008B)
#define		TXMR		TXMR_ADDR.byte

/* �^�C�}X�J�E���g�J�n�t���O	*/
#define		TXS			TXMR_ADDR.bit.b3

/*-----------------------------------------------------------------------------
 *�v���X�P�[��X���W�X�^
 *---------------------------------------------------------------------------*/
#define		PREX_ADDR	(*(volatile unsigned char *)0x008C)
#define		PREX		PREX_ADDR

/*-----------------------------------------------------------------------------
 * �^�C�}X
 *---------------------------------------------------------------------------*/
#define		TX_ADDR		(*(volatile unsigned char *)0x008D)
#define		TX			TX_ADDR

/*-----------------------------------------------------------------------------
 * �^�C�}�J�E���g�\�[�X�I�����W�X�^
 *---------------------------------------------------------------------------*/
#define		TCSS_ADDR	(*(volatile union byte_def *)0x008E)
#define		TCSS		TCSS_ADDR

/*-----------------------------------------------------------------------------
 * �^�C�}C
 *---------------------------------------------------------------------------*/
#define		TC_ADDR		(*(volatile unsigned int *)0x0090)
#define		TC			TC_ADDR

/*-----------------------------------------------------------------------------
 *  �O�����͋����W�X�^
 *---------------------------------------------------------------------------*/
#define		INTEN_ADDR	(*(volatile union byte_def *)0x0096)
#define		INTEN		INTEN_ADDR.byte

/* INT0���͋��r�b�g	*/
#define		INT0EN		INTEN_ADDR.bit.b0

/*-----------------------------------------------------------------------------
 * �^�C�}C���䃌�W�X�^0
 *---------------------------------------------------------------------------*/
#define		TCC0_ADDR	(*(volatile union byte_def *)0x009A)
#define		TCC0		TCC0_ADDR.byte

/* �^�C�}C�J�E���g�J�n�r�b�g	*/
#define		TCC00		TCC0_ADDR.bit.b0

/*-----------------------------------------------------------------------------
 * �^�C�}C���䃌�W�X�^1
 *---------------------------------------------------------------------------*/
#define		TCC1_ADDR	(*(volatile unsigned char  *)0x009B)
#define		TCC1		TCC1_ADDR

/*-----------------------------------------------------------------------------
 * �L���v�`���A�R���y�A0���W�X�^
 *---------------------------------------------------------------------------*/
#define		TM0_ADDR	(*(volatile unsigned int *)0x009C)
#define		TM0			TM0_ADDR

/*-----------------------------------------------------------------------------
 * A-D���W�X�^
 *---------------------------------------------------------------------------*/
#define		AD_ADDR		(*(volatile unsigned int *)0x00C0)
#define		AD			AD_ADDR

/*-----------------------------------------------------------------------------
 * A-D���䃌�W�X�^2
 *---------------------------------------------------------------------------*/
#define		ADCON2_ADDR	(*(volatile unsigned char *)0x00D4)
#define		ADCON2		ADCON2_ADDR

/*-----------------------------------------------------------------------------
 * A-D���䃌�W�X�^0
 *---------------------------------------------------------------------------*/
#define		ADCON0_ADDR	(*(volatile union byte_def *)0x00D6)
#define		ADCON0		ADCON0_ADDR.byte

/* A-D�ϊ��J�n�t���O	*/
#define		ADST		ADCON0_ADDR.bit.b6

/*-----------------------------------------------------------------------------
 * A-D���䃌�W�X�^1
 *---------------------------------------------------------------------------*/
#define		ADCON1_ADDR	(*(volatile unsigned char *)0x00D7)
#define		ADCON1		ADCON1_ADDR

/*-----------------------------------------------------------------------------
 * �|�[�gP0���W�X�^
 *---------------------------------------------------------------------------*/
#define		P0_ADDR		(*(volatile union byte_def *)0x00E0)
#define		P0			P0_ADDR.byte

#define		P0_0		P0_ADDR.bit.b0		/* �|�[�gP0�̃r�b�g0 */
#define		P0_1		P0_ADDR.bit.b1		/* �|�[�gP0�̃r�b�g1 */
#define		P0_2		P0_ADDR.bit.b2		/* �|�[�gP0�̃r�b�g2 */
#define		P0_3		P0_ADDR.bit.b3		/* �|�[�gP0�̃r�b�g3 */
#define		P0_4		P0_ADDR.bit.b4		/* �|�[�gP0�̃r�b�g4 */
#define		P0_5		P0_ADDR.bit.b5		/* �|�[�gP0�̃r�b�g5 */
#define		P0_6		P0_ADDR.bit.b6		/* �|�[�gP0�̃r�b�g6 */
#define		P0_7		P0_ADDR.bit.b7		/* �|�[�gP0�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP1���W�X�^
 *---------------------------------------------------------------------------*/
#define		P1_ADDR		(*(volatile union byte_def *)0x00E1)
#define		P1			P1_ADDR.byte

#define		P1_0		P1_ADDR.bit.b0		/* �|�[�gP1�̃r�b�g0 */
#define		P1_1		P1_ADDR.bit.b1		/* �|�[�gP1�̃r�b�g1 */
#define		P1_2		P1_ADDR.bit.b2		/* �|�[�gP1�̃r�b�g2 */
#define		P1_3		P1_ADDR.bit.b3		/* �|�[�gP1�̃r�b�g3 */
#define		P1_4		P1_ADDR.bit.b4		/* �|�[�gP1�̃r�b�g4 */
#define		P1_5		P1_ADDR.bit.b5		/* �|�[�gP1�̃r�b�g5 */
#define		P1_6		P1_ADDR.bit.b6		/* �|�[�gP1�̃r�b�g6 */
#define		P1_7		P1_ADDR.bit.b7		/* �|�[�gP1�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP0�������W�X�^
 *---------------------------------------------------------------------------*/
#define		PD0_ADDR	(*(volatile union byte_def *)0x00E2)
#define		PD0			PD0_ADDR.byte

#define		PD0_0		PD0_ADDR.bit.b0		/* �|�[�gP0�������W�X�^�̃r�b�g0 */
#define		PD0_1		PD0_ADDR.bit.b1		/* �|�[�gP0�������W�X�^�̃r�b�g1 */
#define		PD0_2		PD0_ADDR.bit.b2		/* �|�[�gP0�������W�X�^�̃r�b�g2 */
#define		PD0_3		PD0_ADDR.bit.b3		/* �|�[�gP0�������W�X�^�̃r�b�g3 */
#define		PD0_4		PD0_ADDR.bit.b4		/* �|�[�gP0�������W�X�^�̃r�b�g4 */
#define		PD0_5		PD0_ADDR.bit.b5		/* �|�[�gP0�������W�X�^�̃r�b�g5 */
#define		PD0_6		PD0_ADDR.bit.b6		/* �|�[�gP0�������W�X�^�̃r�b�g6 */
#define		PD0_7		PD0_ADDR.bit.b7		/* �|�[�gP0�������W�X�^�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP1�������W�X�^
 *---------------------------------------------------------------------------*/
#define		PD1_ADDR	(*(volatile union byte_def *)0x00E3)
#define		PD1			PD1_ADDR.byte

#define		PD1_0		PD1_ADDR.bit.b0		/* �|�[�gP1�������W�X�^�̃r�b�g0 */
#define		PD1_1		PD1_ADDR.bit.b1		/* �|�[�gP1�������W�X�^�̃r�b�g1 */
#define		PD1_2		PD1_ADDR.bit.b2		/* �|�[�gP1�������W�X�^�̃r�b�g2 */
#define		PD1_3		PD1_ADDR.bit.b3		/* �|�[�gP1�������W�X�^�̃r�b�g3 */
#define		PD1_4		PD1_ADDR.bit.b4		/* �|�[�gP1�������W�X�^�̃r�b�g4 */
#define		PD1_5		PD1_ADDR.bit.b5		/* �|�[�gP1�������W�X�^�̃r�b�g5 */
#define		PD1_6		PD1_ADDR.bit.b6		/* �|�[�gP1�������W�X�^�̃r�b�g6 */
#define		PD1_7		PD1_ADDR.bit.b7		/* �|�[�gP1�������W�X�^�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP3���W�X�^
 *---------------------------------------------------------------------------*/
#define		P3_ADDR		(*(volatile union byte_def *)0x00E5)
#define		P3			P3_ADDR.byte

#define		P3_0		P3_ADDR.bit.b0		/* �|�[�gP3�̃r�b�g0 */
#define		P3_1		P3_ADDR.bit.b1		/* �|�[�gP3�̃r�b�g1 */
#define		P3_2		P3_ADDR.bit.b2		/* �|�[�gP3�̃r�b�g2 */
#define		P3_3		P3_ADDR.bit.b3		/* �|�[�gP3�̃r�b�g3 */
#define		P3_7		P3_ADDR.bit.b7		/* �|�[�gP3�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP3�������W�X�^
 *---------------------------------------------------------------------------*/
#define		PD3_ADDR	(*(volatile union byte_def *)0x00E7)
#define		PD3			PD3_ADDR.byte

#define		PD3_0		PD3_ADDR.bit.b0		/* �|�[�gP3�������W�X�^�̃r�b�g0 */
#define		PD3_1		PD3_ADDR.bit.b1		/* �|�[�gP3�������W�X�^�̃r�b�g1 */
#define		PD3_2		PD3_ADDR.bit.b2		/* �|�[�gP3�������W�X�^�̃r�b�g2 */
#define		PD3_3		PD3_ADDR.bit.b3		/* �|�[�gP3�������W�X�^�̃r�b�g3 */
#define		PD3_7		PD3_ADDR.bit.b7		/* �|�[�gP3�������W�X�^�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP4���W�X�^
 *---------------------------------------------------------------------------*/
#define		P4_ADDR		(*(volatile union byte_def *)0x00E8)
#define		P4			P4_ADDR.byte

#define		P4_5		P4_ADDR.bit.b5		/* �|�[�gP4�̃r�b�g5 */
#define		P4_6		P4_ADDR.bit.b6		/* �|�[�gP4�̃r�b�g6 */
#define		P4_7		P4_ADDR.bit.b7		/* �|�[�gP4�̃r�b�g7 */

/*-----------------------------------------------------------------------------
 * �|�[�gP4�������W�X�^
 *---------------------------------------------------------------------------*/
#define		PD4_ADDR	(*(volatile union byte_def *)0x00EA)
#define		PD4			PD4_ADDR.byte

#define		PD4_5		PD4_ADDR.bit.b5		/* �|�[�gP4�������W�X�^�̃r�b�g5 */

/*-----------------------------------------------------------------------------
 * �v���A�b�v���䃌�W�X�^0
 *---------------------------------------------------------------------------*/
#define		PUR0_ADDR	(*(volatile union byte_def *)0x00FC)
#define		PUR0		PUR0_ADDR.byte

/* �|�[�gP0�r�b�g4����r�b�g7�̃v���A�b�v	*/
/* (���̓��[�h�̒[�q�ɑ΂��ėL��)			*/
#define    PU01    PUR0_ADDR.bit.b1
/* �|�[�gP3�r�b�g0����r�b�g3�̃v���A�b�v	*/
/* (���̓��[�h�̒[�q�ɑ΂��ėL��)			*/
#define    PU06    PUR0_ADDR.bit.b6

/*-----------------------------------------------------------------------------
 * �v���A�b�v���䃌�W�X�^1
 *---------------------------------------------------------------------------*/
#define		PUR1_ADDR	(*(volatile union byte_def *)0x00FD)
#define		PUR1		PUR1_ADDR.byte

/* �|�[�gP5�r�b�g5�̃v���A�b�v				*/
/* (���̓��[�h�̒[�q�ɑ΂��ėL��)			*/
#define    PU11    PUR1_ADDR.bit.b1 


#endif /*__TARGET_H*/

/******************************************************************************
    end of file
******************************************************************************/
