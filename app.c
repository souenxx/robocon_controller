#include "ev3api.h"
#include "app.h"
#include <stdio.h>
#include "BasicRun.h"
#include "D_Motor.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

Motor left_motor;
Motor right_motor;
Motor arm_motor;
Motor tail_motor;
BasicRun basicRun;

static FILE *bt = NULL;

int state=0;

void main_task(intptr_t unused) {
	bt = ev3_serial_open_file(EV3_SERIAL_BT);
	assert(bt != NULL);
	while (1) {
		//uint8_t c = fgetc(bt);
   		if(fgetc(bt)=='1'){
   		  Motor_setPower(&right_motor, 20);
          Motor_setPower(&left_motor, 20);
   		  //c = fgetc(bt);
		}else if(fgetc(bt)=='2'){
   		  Motor_setPower(&left_motor,20);
          Motor_setPower(&right_motor,-20);
   		  //c = fgetc(bt);
		}else if(fgetc(bt)=='3'){
   		  Motor_setPower(&left_motor,-20);
          Motor_setPower(&right_motor,20);
   		  //c = fgetc(bt);		
   		}else{
   		  Motor_stop(&left_motor,true);
          Motor_stop(&right_motor,true);
   		  //c = fgetc(bt);
        }
	}
}

