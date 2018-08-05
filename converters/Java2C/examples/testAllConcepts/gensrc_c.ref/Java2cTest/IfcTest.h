/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __Java2cTest_IfcTest_h__
#define __Java2cTest_IfcTest_h__

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: includes *********************************************************/


/*@CLASS_C IfcToTest @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct IfcToTest_t
{ 
  union { ObjectJc object; } base; 
} IfcToTest_s;
  

#define sizeof_IfcToTest_s sizeof(IfcToTest_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef IfcToTestREFDEF
  #define IfcToTestREFDEF
  typedef struct IfcToTestREF_t { ObjectRefValuesJc refbase; struct IfcToTest_t* ref; } IfcToTestREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct IfcToTest_X_t { ObjectArrayJc head; IfcToTestREF data[50]; } IfcToTest_X;
typedef struct IfcToTest_Y_t { ObjectArrayJc head; IfcToTest_s data[50]; } IfcToTest_Y;

 extern struct ClassJc_t const reflection_IfcToTest_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_IfcToTest(OBJP) { CONST_ObjectJc(sizeof(IfcToTest_s), OBJP, &reflection_IfcToTest_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_IfcToTest_F(ObjectJc* othis, ThCxt* _thCxt);


#define constValue_IfcToTest 24  /*Example for a simple constant declared in java*/
 extern StringJc constString_IfcToTest;   /*Example for a simple constant string literal*/
 extern const int32 constValue2_IfcToTest;   /*Example for a calculated constant.At this time this constant is declared in Headerfile as*/


/**Example for a calculated constant using another calculated constant as input.*/
typedef int32 MT_processIfcMethod_IfcToTest(ObjectJc* ithis, int32 input, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 processIfcMethod_IfcToTest(ObjectJc* ithis, int32 input, ThCxt* _thCxt);

/**Example for a second interface method, not a recentness, but see next {@link #anotherIfcmethod(float)}.*/
typedef int32 MT_anotherIfcmethod_i_IfcToTest(ObjectJc* ithis, int32 input, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 anotherIfcmethod_i_IfcToTest(ObjectJc* ithis, int32 input, ThCxt* _thCxt);

/**Example for an interface method with same name as another in the same class, but other parameter set.*/
typedef float MT_anotherIfcmethod_f_IfcToTest(ObjectJc* ithis, float input, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C float anotherIfcmethod_f_IfcToTest(ObjectJc* ithis, float input, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_IfcToTest[]; //marker for methodTable check
typedef struct Mtbl_IfcToTest_t
{ MtblHeadJc head;
  MT_processIfcMethod_IfcToTest* processIfcMethod;
  MT_anotherIfcmethod_i_IfcToTest* anotherIfcmethod_i;
  MT_anotherIfcmethod_f_IfcToTest* anotherIfcmethod_f;
  Mtbl_ObjectJc ObjectJc;
} Mtbl_IfcToTest;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class IfcToTest : private IfcToTest_s
{ public:

  virtual float anotherIfcmethod(float input)=0;

  virtual int32 anotherIfcmethod(int32 input)=0;

  virtual int32 processIfcMethod(int32 input)=0;
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__Java2cTest_IfcTest_h__