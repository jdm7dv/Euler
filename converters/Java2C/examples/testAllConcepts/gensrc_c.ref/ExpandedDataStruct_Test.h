/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __ExpandedDataStruct_Test_h__
#define __ExpandedDataStruct_Test_h__

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: includes *********************************************************/
#include "SimpleDataStruct_Test.h"  //superclass


/*@CLASS_C ExpandedDataStruct_Test @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct ExpandedDataStruct_Test_t
{ 
  union { SimpleDataStruct_Test_s super;} base; 
  double e;   /*Some variables in the data class respectively <code>struct</code>. */
  double f;   /*Some variables in the data class respectively <code>struct</code>. */
} ExpandedDataStruct_Test_s;
  

#define sizeof_ExpandedDataStruct_Test_s sizeof(ExpandedDataStruct_Test_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef ExpandedDataStruct_TestREFDEF
  #define ExpandedDataStruct_TestREFDEF
  typedef struct ExpandedDataStruct_TestREF_t { ObjectRefValuesJc refbase; struct ExpandedDataStruct_Test_t* ref; } ExpandedDataStruct_TestREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct ExpandedDataStruct_Test_X_t { ObjectArrayJc head; ExpandedDataStruct_TestREF data[50]; } ExpandedDataStruct_Test_X;
typedef struct ExpandedDataStruct_Test_Y_t { ObjectArrayJc head; ExpandedDataStruct_Test_s data[50]; } ExpandedDataStruct_Test_Y;

 extern struct ClassJc_t const reflection_ExpandedDataStruct_Test_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_ExpandedDataStruct_Test(OBJP) { CONST_ObjectJc(sizeof(ExpandedDataStruct_Test_s), OBJP, &reflection_ExpandedDataStruct_Test_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_ExpandedDataStruct_Test_F(ExpandedDataStruct_Test_s* ythis, ThCxt* _thCxt);




/**Default constructor. */
METHOD_C struct ExpandedDataStruct_Test_t* ctorM_ExpandedDataStruct_Test(MemC mthis, ThCxt* _thCxt);


#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class ExpandedDataStruct_Test : private ExpandedDataStruct_Test_s
{ public:
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__ExpandedDataStruct_Test_h__
