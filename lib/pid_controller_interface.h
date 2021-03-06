#ifndef __PID_CONTROLLER_INTERFACE_H
#define __PID_CONTROLLER_INTERFACE_H

#include <string.h> //for NULL
#include "pid_macros.h"

/** Generic pid controller interface allowing multiple implementations **/
typedef struct PidControllerInterfaceObject PidControllerInterface;

struct PidControllerInterfaceObject{
    /**
     * @brief update the pid controller and compute next value
     * @note this function needs to be called periodically
     */
    float (*update) (PidControllerInterface *self, float reference, float measured);
    /**
     * @brief tunning method to be used in runtime
     */
    void (*tune) (PidControllerInterface *self, float kp, float ki, float kd);
    
    /**
     * @brief perform controller internal states reset
     */
    void (*reset) (PidControllerInterface *self);
};


typedef struct {
    float kp;
    float ki;
    float kd;
    float windup_limit;
} PidControllerSettings;

#endif
