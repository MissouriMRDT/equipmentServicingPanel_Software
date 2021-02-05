#define _EquipmentServicePanel

#include "Energia.h"

#define JOY_ELEV_PLUS       PE_0
#define JOY_ELEV_MINUS      PE_1
#define JOY_AZI_PLUS        PE_2
#define JOY_AZI_MINUS       PE_3

#define DIAL_AZI_CTL        PM_4
#define DIAL_ELEV_CTL       PM_5

//#define LCD_TX              PC_5
//#define K_BOARD_TX          PP_1
//#define K_BOARD_RX          PP_0

int ELEV_DIAL = 100;
int AZI_DIAL = 100;
int plus = 0;
int minus = 0;
