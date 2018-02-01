; ----------------------------------------------------------------------------
;   COPYRIGHT(C) 2011 RENESAS TECHNOLOGY CORPORATION
;   AND RENESAS SOLUTIONS CORPORATION ALL RIGHTS RESERVED
;
; [FILE]
;     sect.inc
;
; [DESCRIPTION]
;     section definition (for OAKS8-LCDBoard support library)
;
; [NOTE]
;     1. for eduction (NO TRANSFERRING)
;     2. for OAKS8-LCD Board
;     3. for OAKS8-R5F21114FP(R8C/11 group,20MHz)
;
; [VERSION]
;     v1.00  2011/05/20 RENESAS Semiconductor Training Center  New
; ---------------------------------------------------------------------------*/

;===============================================================================
; section arrenge
;===============================================================================
;-------------------------------------------------------------------------------
; variable data section (RAM)
;-------------------------------------------------------------------------------
; static variable with initial value 
        .section        data_NE,DATA            ; static variable with even size
        .org            0400H                   ; start address 00400H
data_NE_top:
        .section        data_NO,DATA,ALIGN      ; static variable with odd size
data_NO_top:

;-------------------------------------------------------------------------------
; static variable without initial value
        .section        bss_NE,DATA             ; static variable with even size
        .org            0500H                   ; start address 00500H
bss_NE_top:
        .section        bss_NO,DATA,ALIGN       ; static variable with odd size
bss_NO_top:

;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; stack section
;-------------------------------------------------------------------------------
        .section        stack,DATA              ; stack section
        .org            0600H                   ; start address 00600H
STACKSIZE               .equ    255             ; set stack size(256 bytes)
stack_top:
        .blkb           STACKSIZE               ; confirm stack section
                                                ; with stack size
STACK_INI:                                      ; start up program section
                                                ; start address CC00H
;-------------------------------------------------------------------------------
; code section
;-------------------------------------------------------------------------------
        .section        startup,CODE            ; start up program section
        .org            0CC00H                  ; start address CC00H
;-------------------------------------------------------------------------------
        .section        program,CODE            ; program section
;-------------------------------------------------------------------------------
; fixed data section(ROM)
;-------------------------------------------------------------------------------
; section to save constant, string
        .section        rom_NE,ROMDATA          ; constant with even size
        .org            0F000H                  ; start address F000H
rom_NE_top:
        .section        rom_NO,ROMDATA,ALIGN    ; constant with odd size
rom_NO_top:
;-------------------------------------------------------------------------------
; section to save initial value of static variable with initial value
        .section        data_NEI,ROMDATA        ; initial value with even size
        .org            0FC00H
data_NEI_top:
        .section        data_NOI,ROMDATA,ALIGN  ; initial value with odd size
data_NOI_top:

;-------------------------------------------------------------------------------
; variable interrupt vector section
;-------------------------------------------------------------------------------
        .section        interrupt_vector,CODE   ; interrupt_vector section
                
        .org            (0FEDCH + 22*4)         ; start address 0FEDCH
        .glb            _IntrTimerX            ; control key matrix
        .lword          _IntrTimerX             ; timer X (for OAKS8-LCDBoard)
                
        .org            (0FEDCH + 23*4)         ; start address 0FEDCH
        .glb            TimerY                  ; control key matrix
        .lword          TimerY                  ; timer Y (for OAKS8-LCDBoard)

        .org            (0FEDCH + 28*4)         ; 
        .glb            Cmp0                    ; control LCD
        .lword          Cmp0                    ; timer C (for OAKS8-LCDBoard)
;
;-------------------------------------------------------------------------------
; fixed interrupt vector section
; *set ID1 to ID7 code at 00HÅAset FFH at FFFC(for KD30 to exchange RS232C to FoUSB)
; *when using KD30, fixed vector interrupt can not run in user program
;-------------------------------------------------------------------------------
        .section        fix_interrupt_vector,CODE
                                                ; fix_interrupt_vector section
        .org            0FFDCH
        .lword          DUMMY_INT               ; FFDC to F undefined command
        .lword          DUMMY_INT               ; FFE0 to 3 overflow
        .lword          DUMMY_INT               ; FFE4 to 7 BRK command
        .lword          DUMMY_INT               ; FFE8 to B same address
        .lword          DUMMY_INT               ; FFEC to F single step
        .lword          DUMMY_INT               ; FFF0 to 3 monitor timer
        .lword          DUMMY_INT               ; FFF4 to 7 DBC
        .lword          DUMMY_INT               ; FFF8 to B NMI
;
        .org            0FFFCH
reset:
        .lword          start + 0FF000000H      ; FFFC to F set reset vector

;******************************************************************************
;       end of file
;******************************************************************************
