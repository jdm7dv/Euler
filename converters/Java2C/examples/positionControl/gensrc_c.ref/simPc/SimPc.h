/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __simPc_SimPc_h__
#define __simPc_SimPc_h__

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: Enhanced references *********************************************************
 * In this part all here used enhanced references are defined conditionally.
 * The inclusion of all that header files isn't necessary, to prevent circular inclusion.
 * It is adequate a struct pointer forward declaration.
 */
#ifndef WaitThread_SimPcREFDEF
  #define WaitThread_SimPcREFDEF
  typedef struct WaitThread_SimPcREF_t { ObjectRefValuesJc refbase; struct WaitThread_SimPc_t* ref; } WaitThread_SimPcREF;
#endif


/* J2C: includes *********************************************************/
#include "PosCtrl/WaitThreadOrganizer.h"  //interface
#include "PosCtrl/WayActuator.h"  //interface
#include "PosCtrl/WaySensor.h"  //interface
#include "simPc/SendActValues.h"  //embedded type in class data
#include "simPc/iRequireMainController.h"  //interface


/*@CLASS_C C_waySensor1_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct C_waySensor1_SimPc_t
{ 
  union { ObjectJc object; WaySensor_s WaySensor;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} C_waySensor1_SimPc_s;
  

#define sizeof_C_waySensor1_SimPc_s sizeof(C_waySensor1_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef C_waySensor1_SimPcREFDEF
  #define C_waySensor1_SimPcREFDEF
  typedef struct C_waySensor1_SimPcREF_t { ObjectRefValuesJc refbase; struct C_waySensor1_SimPc_t* ref; } C_waySensor1_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct C_waySensor1_SimPc_X_t { ObjectArrayJc head; C_waySensor1_SimPcREF data[50]; } C_waySensor1_SimPc_X;
typedef struct C_waySensor1_SimPc_Y_t { ObjectArrayJc head; C_waySensor1_SimPc_s data[50]; } C_waySensor1_SimPc_Y;

 extern struct ClassJc_t const reflection_C_waySensor1_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_C_waySensor1_SimPc(OBJP) { CONST_ObjectJc(sizeof(C_waySensor1_SimPc_s), OBJP, &reflection_C_waySensor1_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_C_waySensor1_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 getWay_C_waySensor1_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 getWay_C_waySensor1_SimPc(ObjectJc* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_C_waySensor1_SimPc[]; //marker for methodTable check
typedef struct Mtbl_C_waySensor1_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_WaySensor WaySensor;
} Mtbl_C_waySensor1_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class C_waySensor1_SimPc : private C_waySensor1_SimPc_s
{ public:

  virtual int32 getWay(){  return getWay_C_waySensor1_SimPc_F(&this->base.WaySensor.base.object,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/


/**Default constructor. */
METHOD_C struct C_waySensor1_SimPc_t* ctorO_C_waySensor1_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);


/*@CLASS_C C_waySensor2_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct C_waySensor2_SimPc_t
{ 
  union { ObjectJc object; WaySensor_s WaySensor;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} C_waySensor2_SimPc_s;
  

#define sizeof_C_waySensor2_SimPc_s sizeof(C_waySensor2_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef C_waySensor2_SimPcREFDEF
  #define C_waySensor2_SimPcREFDEF
  typedef struct C_waySensor2_SimPcREF_t { ObjectRefValuesJc refbase; struct C_waySensor2_SimPc_t* ref; } C_waySensor2_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct C_waySensor2_SimPc_X_t { ObjectArrayJc head; C_waySensor2_SimPcREF data[50]; } C_waySensor2_SimPc_X;
typedef struct C_waySensor2_SimPc_Y_t { ObjectArrayJc head; C_waySensor2_SimPc_s data[50]; } C_waySensor2_SimPc_Y;

 extern struct ClassJc_t const reflection_C_waySensor2_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_C_waySensor2_SimPc(OBJP) { CONST_ObjectJc(sizeof(C_waySensor2_SimPc_s), OBJP, &reflection_C_waySensor2_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_C_waySensor2_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 getWay_C_waySensor2_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 getWay_C_waySensor2_SimPc(ObjectJc* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_C_waySensor2_SimPc[]; //marker for methodTable check
typedef struct Mtbl_C_waySensor2_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_WaySensor WaySensor;
} Mtbl_C_waySensor2_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class C_waySensor2_SimPc : private C_waySensor2_SimPc_s
{ public:

  virtual int32 getWay(){  return getWay_C_waySensor2_SimPc_F(&this->base.WaySensor.base.object,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/


/**Default constructor. */
METHOD_C struct C_waySensor2_SimPc_t* ctorO_C_waySensor2_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);


/*@CLASS_C C_wayActuator1_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct C_wayActuator1_SimPc_t
{ 
  union { ObjectJc object; WayActuator_s WayActuator;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} C_wayActuator1_SimPc_s;
  

#define sizeof_C_wayActuator1_SimPc_s sizeof(C_wayActuator1_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef C_wayActuator1_SimPcREFDEF
  #define C_wayActuator1_SimPcREFDEF
  typedef struct C_wayActuator1_SimPcREF_t { ObjectRefValuesJc refbase; struct C_wayActuator1_SimPc_t* ref; } C_wayActuator1_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct C_wayActuator1_SimPc_X_t { ObjectArrayJc head; C_wayActuator1_SimPcREF data[50]; } C_wayActuator1_SimPc_X;
typedef struct C_wayActuator1_SimPc_Y_t { ObjectArrayJc head; C_wayActuator1_SimPc_s data[50]; } C_wayActuator1_SimPc_Y;

 extern struct ClassJc_t const reflection_C_wayActuator1_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_C_wayActuator1_SimPc(OBJP) { CONST_ObjectJc(sizeof(C_wayActuator1_SimPc_s), OBJP, &reflection_C_wayActuator1_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_C_wayActuator1_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void setMotorVoltage_i_C_wayActuator1_SimPc_F(ObjectJc* ithis, int16 voltage, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void setMotorVoltage_i_C_wayActuator1_SimPc(ObjectJc* ithis, int16 voltage, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_C_wayActuator1_SimPc[]; //marker for methodTable check
typedef struct Mtbl_C_wayActuator1_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_WayActuator WayActuator;
} Mtbl_C_wayActuator1_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class C_wayActuator1_SimPc : private C_wayActuator1_SimPc_s
{ public:

  virtual void setMotorVoltage(int16 voltage){ setMotorVoltage_i_C_wayActuator1_SimPc_F(&this->base.WayActuator.base.object, voltage,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/


/**Default constructor. */
METHOD_C struct C_wayActuator1_SimPc_t* ctorO_C_wayActuator1_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);


/*@CLASS_C C_wayActuator2_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct C_wayActuator2_SimPc_t
{ 
  union { ObjectJc object; WayActuator_s WayActuator;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} C_wayActuator2_SimPc_s;
  

#define sizeof_C_wayActuator2_SimPc_s sizeof(C_wayActuator2_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef C_wayActuator2_SimPcREFDEF
  #define C_wayActuator2_SimPcREFDEF
  typedef struct C_wayActuator2_SimPcREF_t { ObjectRefValuesJc refbase; struct C_wayActuator2_SimPc_t* ref; } C_wayActuator2_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct C_wayActuator2_SimPc_X_t { ObjectArrayJc head; C_wayActuator2_SimPcREF data[50]; } C_wayActuator2_SimPc_X;
typedef struct C_wayActuator2_SimPc_Y_t { ObjectArrayJc head; C_wayActuator2_SimPc_s data[50]; } C_wayActuator2_SimPc_Y;

 extern struct ClassJc_t const reflection_C_wayActuator2_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_C_wayActuator2_SimPc(OBJP) { CONST_ObjectJc(sizeof(C_wayActuator2_SimPc_s), OBJP, &reflection_C_wayActuator2_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_C_wayActuator2_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void setMotorVoltage_i_C_wayActuator2_SimPc_F(ObjectJc* ithis, int16 voltage, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void setMotorVoltage_i_C_wayActuator2_SimPc(ObjectJc* ithis, int16 voltage, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_C_wayActuator2_SimPc[]; //marker for methodTable check
typedef struct Mtbl_C_wayActuator2_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_WayActuator WayActuator;
} Mtbl_C_wayActuator2_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class C_wayActuator2_SimPc : private C_wayActuator2_SimPc_s
{ public:

  virtual void setMotorVoltage(int16 voltage){ setMotorVoltage_i_C_wayActuator2_SimPc_F(&this->base.WayActuator.base.object, voltage,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/


/**Default constructor. */
METHOD_C struct C_wayActuator2_SimPc_t* ctorO_C_wayActuator2_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);


/*@CLASS_C C_broker2_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct C_broker2_SimPc_t
{ 
  union { ObjectJc object; iRequireMainController_s iRequireMainController;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} C_broker2_SimPc_s;
  

#define sizeof_C_broker2_SimPc_s sizeof(C_broker2_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef C_broker2_SimPcREFDEF
  #define C_broker2_SimPcREFDEF
  typedef struct C_broker2_SimPcREF_t { ObjectRefValuesJc refbase; struct C_broker2_SimPc_t* ref; } C_broker2_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct C_broker2_SimPc_X_t { ObjectArrayJc head; C_broker2_SimPcREF data[50]; } C_broker2_SimPc_X;
typedef struct C_broker2_SimPc_Y_t { ObjectArrayJc head; C_broker2_SimPc_s data[50]; } C_broker2_SimPc_Y;

 extern struct ClassJc_t const reflection_C_broker2_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_C_broker2_SimPc(OBJP) { CONST_ObjectJc(sizeof(C_broker2_SimPc_s), OBJP, &reflection_C_broker2_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_C_broker2_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C struct WayActuator_t* requireWay1Actuator_C_broker2_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C struct WayActuator_t* requireWay1Actuator_C_broker2_SimPc(ObjectJc* ithis, ThCxt* _thCxt);

/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C struct WaySensor_t* requireWay1Sensor_C_broker2_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C struct WaySensor_t* requireWay1Sensor_C_broker2_SimPc(ObjectJc* ithis, ThCxt* _thCxt);

/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C struct WayActuator_t* requireWay2Actuator_C_broker2_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C struct WayActuator_t* requireWay2Actuator_C_broker2_SimPc(ObjectJc* ithis, ThCxt* _thCxt);

/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C struct WaySensor_t* requireWay2Sensor_C_broker2_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C struct WaySensor_t* requireWay2Sensor_C_broker2_SimPc(ObjectJc* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_C_broker2_SimPc[]; //marker for methodTable check
typedef struct Mtbl_C_broker2_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_iRequireMainController iRequireMainController;
} Mtbl_C_broker2_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class C_broker2_SimPc : private C_broker2_SimPc_s
{ public:

  virtual struct WayActuator_t* requireWay1Actuator(){  return requireWay1Actuator_C_broker2_SimPc_F(&this->base.iRequireMainController.base.object,  null/*_thCxt*/); }

  virtual struct WaySensor_t* requireWay1Sensor(){  return requireWay1Sensor_C_broker2_SimPc_F(&this->base.iRequireMainController.base.object,  null/*_thCxt*/); }

  virtual struct WayActuator_t* requireWay2Actuator(){  return requireWay2Actuator_C_broker2_SimPc_F(&this->base.iRequireMainController.base.object,  null/*_thCxt*/); }

  virtual struct WaySensor_t* requireWay2Sensor(){  return requireWay2Sensor_C_broker2_SimPc_F(&this->base.iRequireMainController.base.object,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/


/**Default constructor. */
METHOD_C struct C_broker2_SimPc_t* ctorO_C_broker2_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);


/*@CLASS_C WaitThread_SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct WaitThread_SimPc_t
{ 
  union { ObjectJc object; WaitThreadOrganizer_s WaitThreadOrganizer;} base; 
  struct SimPc_t* outer;  //J2C: Reference to outer class, implicit in Java
} WaitThread_SimPc_s;
  

#define sizeof_WaitThread_SimPc_s sizeof(WaitThread_SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef WaitThread_SimPcREFDEF
  #define WaitThread_SimPcREFDEF
  typedef struct WaitThread_SimPcREF_t { ObjectRefValuesJc refbase; struct WaitThread_SimPc_t* ref; } WaitThread_SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct WaitThread_SimPc_X_t { ObjectArrayJc head; WaitThread_SimPcREF data[50]; } WaitThread_SimPc_X;
typedef struct WaitThread_SimPc_Y_t { ObjectArrayJc head; WaitThread_SimPc_s data[50]; } WaitThread_SimPc_Y;

 extern struct ClassJc_t const reflection_WaitThread_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_WaitThread_SimPc(OBJP) { CONST_ObjectJc(sizeof(WaitThread_SimPc_s), OBJP, &reflection_WaitThread_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_WaitThread_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct WaitThread_SimPc_t* ctorO_WaitThread_SimPc(struct SimPc_t* outer, ObjectJc* othis, ThCxt* _thCxt);

/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void waitCycle_WaitThread_SimPc_F(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void waitCycle_WaitThread_SimPc(ObjectJc* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_WaitThread_SimPc[]; //marker for methodTable check
typedef struct Mtbl_WaitThread_SimPc_t
{ MtblHeadJc head;
  Mtbl_ObjectJc ObjectJc;
  //Method table of interfaces:
  Mtbl_WaitThreadOrganizer WaitThreadOrganizer;
} Mtbl_WaitThread_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class WaitThread_SimPc : private WaitThread_SimPc_s
{ public:

  virtual void waitCycle(){ waitCycle_WaitThread_SimPc_F(&this->base.WaitThreadOrganizer.base.object,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/



/*@CLASS_C SimPc @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct SimPc_t
{ 
  union { ObjectJc object; } base; 
  struct MainController_t* mainController;   /*Reference to the mainController, independent of singleton or not.*/
  bool bRun; 
  double way1;   /*Way in microMeter */
  double way2;   /*Way in microMeter */
  double disturbance1; 
  int16 voltage1;   /*Voltage as output from controller to the both movement motors. */
  int16 voltage2;   /*Voltage as output from controller to the both movement motors. */
  int32 time;   /*The continuously time. */
  int32 samplingInverval;   /*The sampling interval in microsecond. */
  SendActValues_s oamWriter; 
  WaitThread_SimPcREF waitThreadOrganizer;   /*Instance to implementing the agent class. */
  C_waySensor1_SimPc_s waySensor1;   /*An instance of interface WaySensor implemented as anonymous class definition*/
  C_waySensor2_SimPc_s waySensor2;   /*A second instance of interface WaySensor implemented as anonymous class definition*/
  C_wayActuator1_SimPc_s wayActuator1;   /*An instance of interface WayActuator implemented as anonymous class definition*/
  C_wayActuator2_SimPc_s wayActuator2;   /*An instance of interface WayActuator implemented as anonymous class definition*/
  C_broker2_SimPc_s broker2;   /*The anonymous class for broker implements the methods*/
} SimPc_s;
  

#define sizeof_SimPc_s sizeof(SimPc_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef SimPcREFDEF
  #define SimPcREFDEF
  typedef struct SimPcREF_t { ObjectRefValuesJc refbase; struct SimPc_t* ref; } SimPcREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct SimPc_X_t { ObjectArrayJc head; SimPcREF data[50]; } SimPc_X;
typedef struct SimPc_Y_t { ObjectArrayJc head; SimPc_s data[50]; } SimPc_Y;

 extern struct ClassJc_t const reflection_SimPc_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_SimPc(OBJP) { CONST_ObjectJc(sizeof(SimPc_s), OBJP, &reflection_SimPc_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_SimPc_F(ObjectJc* othis, ThCxt* _thCxt);




METHOD_C struct SimPc_t* ctorO_SimPc(ObjectJc* othis, ThCxt* _thCxt);

/**This is the run method of the execution. */
METHOD_C void execute_SimPc(SimPc_s* ythis, ThCxt* _thCxt);

/**The step routine to build the simulation environment values.*/
METHOD_C void step_SimPc(SimPc_s* ythis, ThCxt* _thCxt);

typedef void MT_stop_SimPc(SimPc_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void stop_SimPc_F(SimPc_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void stop_SimPc(SimPc_s* ythis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_SimPc[]; //marker for methodTable check
typedef struct Mtbl_SimPc_t
{ MtblHeadJc head;
  MT_stop_SimPc* stop;
  Mtbl_ObjectJc ObjectJc;
} Mtbl_SimPc;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class SimPc : private SimPc_s
{ public:

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_C_broker2_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_C_wayActuator1_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_C_wayActuator2_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_C_waySensor1_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_C_waySensor2_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_SimPc(&this->base.object,  null/*_thCxt*/); }

  SimPc(){ init_ObjectJc(&this->base.object, sizeof(SimPc_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_SimPc_s, 0); ctorO_WaitThread_SimPc(&this->base.object,  null/*_thCxt*/); }

  void execute(){ execute_SimPc(this,  null/*_thCxt*/); }

  void step(){ step_SimPc(this,  null/*_thCxt*/); }

  virtual void stop(){ stop_SimPc_F(this,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__simPc_SimPc_h__
