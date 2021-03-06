/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __PosCtrl_CtrlBase_h__
#define __PosCtrl_CtrlBase_h__

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: includes *********************************************************/


/*@CLASS_C CtrlBase @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct CtrlBase_t
{ 
  union { ObjectJc object; } base; 
} CtrlBase_s;
  

#define sizeof_CtrlBase_s sizeof(CtrlBase_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef CtrlBaseREFDEF
  #define CtrlBaseREFDEF
  typedef struct CtrlBaseREF_t { ObjectRefValuesJc refbase; struct CtrlBase_t* ref; } CtrlBaseREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct CtrlBase_X_t { ObjectArrayJc head; CtrlBaseREF data[50]; } CtrlBase_X;
typedef struct CtrlBase_Y_t { ObjectArrayJc head; CtrlBase_s data[50]; } CtrlBase_Y;

 extern struct ClassJc_t const reflection_CtrlBase_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_CtrlBase(OBJP) { CONST_ObjectJc(sizeof(CtrlBase_s), OBJP, &reflection_CtrlBase_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_CtrlBase_F(ObjectJc* othis, ThCxt* _thCxt);




/**Initialize the function. */
typedef void MT_init_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void init_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);

/**Reset to start values. */
typedef void MT_reset_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void reset_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);

/**It is a tick in the sampling time.*/
typedef void MT_step_CtrlBase(ObjectJc* ithis, int32 time, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void step_CtrlBase(ObjectJc* ithis, int32 time, ThCxt* _thCxt);

/**calculates the parameters.*/
typedef void MT_parametrize_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void parametrize_CtrlBase(ObjectJc* ithis, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_CtrlBase[]; //marker for methodTable check
typedef struct Mtbl_CtrlBase_t
{ MtblHeadJc head;
  MT_init_CtrlBase* init;
  MT_reset_CtrlBase* reset;
  MT_step_CtrlBase* step;
  MT_parametrize_CtrlBase* parametrize;
  Mtbl_ObjectJc ObjectJc;
} Mtbl_CtrlBase;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class CtrlBase : private CtrlBase_s
{ public:

  virtual void init()=0;

  virtual void parametrize()=0;

  virtual void reset()=0;

  virtual void step(int32 time)=0;
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__PosCtrl_CtrlBase_h__
