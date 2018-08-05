/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#ifndef __TestAllConcepts_Test_h__
#define __TestAllConcepts_Test_h__

#include "Jc/ObjectJc.h"        //basic concept

#include "Jc/StringJc.h"        //used often

#include "Fwc/fw_Exception.h"   //basic concept


/* J2C: Enhanced references *********************************************************
 * In this part all here used enhanced references are defined conditionally.
 * The inclusion of all that header files isn't necessary, to prevent circular inclusion.
 * It is adequate a struct pointer forward declaration.
 */
#ifndef AnyClass_TestREFDEF
  #define AnyClass_TestREFDEF
  typedef struct AnyClass_TestREF_t { ObjectRefValuesJc refbase; struct AnyClass_Test_t* ref; } AnyClass_TestREF;
#endif
#ifndef IfcToTestREFDEF
  #define IfcToTestREFDEF
  typedef struct IfcToTestREF_t { ObjectRefValuesJc refbase; struct IfcToTest_t* ref; } IfcToTestREF;
#endif
#ifndef ImplIfcTestREFDEF
  #define ImplIfcTestREFDEF
  typedef struct ImplIfcTestREF_t { ObjectRefValuesJc refbase; struct ImplIfcTest_t* ref; } ImplIfcTestREF;
#endif
#ifndef SimpleDataStruct_TestREFDEF
  #define SimpleDataStruct_TestREFDEF
  typedef struct SimpleDataStruct_TestREF_t { ObjectRefValuesJc refbase; struct SimpleDataStruct_Test_t* ref; } SimpleDataStruct_TestREF;
#endif


/* J2C: includes *********************************************************/
#include "ExpandedDataStruct_Test.h"  //embedded type in class data
#include "ExtendsImpl_Test.h"  //embedded type in class data
#include "Java2cTest/ImplTest.h"  //embedded type in class data
#include "SimpleDataStruct_Test.h"  //embedded type in class data
#include "TestAnonymous_Test.h"  //embedded type in class data
#include "TestStringFormatter_Test.h"  //embedded type in class data
#include "TestString_Test.h"  //embedded type in class data
#include "TestThread_Test.h"  //embedded type in class data
#include "TestWaitNotify_Test.h"  //embedded type in class data


/*@CLASS_C TestAllConcepts_Test @@@@@@@@@@@@@@@@@@@@@@@@*/

typedef struct TestAllConcepts_Test_t
{ 
  union { ObjectJc object; } base; 
  int32 simpleInt;   /*A simple class variable*/
  SimpleDataStruct_Test_s embeddedData;   /*In Java it is a fix build instance at construction time. In C it is an embedded instance.  */
  SimpleDataStruct_Test_s embeddedDataNotEnpand;   /*In Java it is a fix build instance at construction time*/
  ExpandedDataStruct_Test_s embeddedDataExpand;   /*In Java it is a fix build instance at construction time*/
  WaitNotifyData_TestWaitNotify_Test_s testWaitNotifyData; 
  TestThread_Test_s testThread; 
  TestWaitNotify_Test_s testWaitNotify; 
  struct SbY_stringBufferMain_t { StringBufferJc sb; char _b[19996]; }stringBufferMain; 
  TestString_Test_s testString; 
  TestStringFormatter_Test_s testStringFormatter; 
  struct intArray_Y { ObjectArrayJc head; int32 data[1000]; }intArray;   /*A initialized array, it is embedded because it's final. */
  int32_Y* intArrayRef;   /*A initialized array, but it is not embedded because it isn't final. */
  int32_Y* intArrayRef2;   /*A simple reference to an array. */
  int32 intArraySimple[1000];   /*A initialized array, it is embedded because it's final. */
  int32_Y* intArrayRefSimple;   /*A initialized array, but it is not embedded because it isn't final.  */
  SimpleDataStruct_Test_Y* dataArrayRef;   /**/
  struct dataArrayEmbedded_Y { ObjectArrayJc head; SimpleDataStruct_Test_s data[12]; }dataArrayEmbedded;   /**/
  SimpleDataStruct_Test_s dataArraySimpleEmbedded[12];   /**/
  struct dataRefArrayEmbedded_Y { ObjectArrayJc head; SimpleDataStruct_Test_s data[12]; }dataRefArrayEmbedded;   /**/
  struct dataRefArray_Y { ObjectArrayJc head; SimpleDataStruct_TestREF data[12]; }dataRefArray;   /*A array of references, but the head is embedded */
  SimpleDataStruct_Test_Y* dataAssociatedEmbeddedArray;   /*A array of embedded elements, not final. */
  SimpleDataStruct_Test_Y* dataAssociatedRefArray;   /**/
  ImplIfcTest_s implifc;   /*A initialized array, it is embedded because it's final. */
  ImplIfcTest_s ifc3; 
  ImplIfcTestREF implifc2;   /*A second instance which implements a interface, using to test interface access. */
  IfcToTestREF ifc;   /*A class reference to an interface, set one time final. */
  IfcToTestREF ifcNonVirtual;   /*A class reference to an interface,*/
  IfcToTestREF ifc2;   /*A class reference to an interface, but set only if used.*/
  ExtendsImpl_Test_s extendsImpl; 
  ImplIfcTestREF ifc4;   /*A initialized but not final reference. */
  AnyClass_TestREF anyRef; 
  TestAnonymous_Test_s testAnonymous; 
} TestAllConcepts_Test_s;
  

#define sizeof_TestAllConcepts_Test_s sizeof(TestAllConcepts_Test_s)


/**J2c: Definitions of the enhanced reference. It's conditinally because it may be defined in a included header before. */
#ifndef TestAllConcepts_TestREFDEF
  #define TestAllConcepts_TestREFDEF
  typedef struct TestAllConcepts_TestREF_t { ObjectRefValuesJc refbase; struct TestAllConcepts_Test_t* ref; } TestAllConcepts_TestREF;
#endif

/**J2c: Definitions of the array forms. NOTE: The number of elements are a helper for debug, the really used number depends on the memory size! */
typedef struct TestAllConcepts_Test_X_t { ObjectArrayJc head; TestAllConcepts_TestREF data[50]; } TestAllConcepts_Test_X;
typedef struct TestAllConcepts_Test_Y_t { ObjectArrayJc head; TestAllConcepts_Test_s data[50]; } TestAllConcepts_Test_Y;

 extern struct ClassJc_t const reflection_TestAllConcepts_Test_s;
  


/**CONST_Type useable as initializer for embedded/stack-instances*/
#define CONST_TestAllConcepts_Test(OBJP) { CONST_ObjectJc(sizeof(TestAllConcepts_Test_s), OBJP, &reflection_TestAllConcepts_Test_s), 0 }

/**J2C: finalize declaration. It is called by Garbage collector and inside other finalized methods.
 * It should be called by the user if the instance is removed. */
void finalize_TestAllConcepts_Test_F(ObjectJc* othis, ThCxt* _thCxt);


#define kMsgBlockHeap_TestAllConcepts_Test 9000  /*A total constant value, it is a #define kMsgBlockHeap 9000 in C.*/
#define kIdxMsgOutputFile_TestAllConcepts_Test 2
 extern const char kCharConst_TestAllConcepts_Test;   /*A final constant not-int-value, it is a const variable in C. */
 extern int32 nrofInstances_TestAllConcepts_Test;   /*A static, but not final variable*/
 extern const int32 intArrayStaticConst_TestAllConcepts_Test[3]; 


/**The Constructor of this example.*/
METHOD_C struct TestAllConcepts_Test_t* ctorO_TestAllConcepts_Test(ObjectJc* othis, ThCxt* _thCxt);

typedef int32 MT_access_i_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, int32 x, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 access_i_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, int32 x, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 access_i_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, int32 x, ThCxt* _thCxt);

/**This method shows some calls of interface methods, see {@link org.vishia.java2C.Docu.SuperClassesAndInterfaces#callingOverrideableMethods()}.*/
typedef int32 MT_checkSomeDynamicCalls_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 checkSomeDynamicCalls_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 checkSomeDynamicCalls_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/**Example to show concatenated calls in a simple variant*/
METHOD_C int32 checkConcatenationSimple_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/**Example to show concatenated calls of override-able methods*/
typedef int32 MT_checkConcatenationDynamicCall_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 checkConcatenationDynamicCall_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 checkConcatenationDynamicCall_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/**Example to test dynamic and static calls to methods, which are methods of the base class.*/
typedef int32 MT_checkConcatenationDynamicCallToBaseMethods_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 checkConcatenationDynamicCallToBaseMethods_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 checkConcatenationDynamicCallToBaseMethods_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/**Example to show concatenated calls with the special kind: The methods returns this itself.*/
typedef int32 MT_checkConcatCallReturnThisTypefixNonVirtual_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 checkConcatCallReturnThisTypefixNonVirtual_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 checkConcatCallReturnThisTypefixNonVirtual_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

typedef int32 MT_checkConcatCallReturnAnything_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 checkConcatCallReturnAnything_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 checkConcatCallReturnAnything_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/**This method helps to test concatenations with return-this, but override-able.*/
typedef struct TestAllConcepts_Test_t* MT_returnThisOverrideable_Test_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, int32 value);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C struct TestAllConcepts_Test_t* returnThisOverrideable_Test_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, int32 value);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C struct TestAllConcepts_Test_t* returnThisOverrideable_Test_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, int32 value);

/**Example for a non-dynamic call of an interface referenced method.*/
typedef void MT_checkNonVirtual_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void checkNonVirtual_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void checkNonVirtual_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis);

/**Check whether Object.equals() will be overridden.*/
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C bool equals_O_TestAllConcepts_Test_F(ObjectJc* ithis, struct ObjectJc_t* cmp, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C bool equals_O_TestAllConcepts_Test(ObjectJc* ithis, struct ObjectJc_t* cmp, ThCxt* _thCxt);

/**This method doesn't override Object.equals. */
typedef bool MT_equals_S_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, StringJc cmp, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C bool equals_S_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, StringJc cmp, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C bool equals_S_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, StringJc cmp, ThCxt* _thCxt);

/**A method with same name but other parameter types.*/
typedef void MT_access_f_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, float x, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void access_f_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, float x, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void access_f_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, float x, ThCxt* _thCxt);

typedef int32 MT_testAccessIfc_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 testAccessIfc_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 testAccessIfc_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

typedef int32 MT_testAccessIfcMtbl_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 testAccessIfcMtbl_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 testAccessIfcMtbl_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

typedef int32 MT_testAccessIfcMtbl2_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, bool bTest, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C int32 testAccessIfcMtbl2_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, bool bTest, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C int32 testAccessIfcMtbl2_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, bool bTest, ThCxt* _thCxt);

/**Example to check how an dynamic call of own methods is implemented in C.*/
METHOD_C void testInternalDynCall_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

/****/
typedef void MT_main_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Implementation of the method, used for an immediate non-dynamic call: */
METHOD_C void main_TestAllConcepts_Test_F(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);
/* J2C:Call of the method at this class level, executes a dynamic call of the override-able method: */
METHOD_C void main_TestAllConcepts_Test(TestAllConcepts_Test_s* ythis, ThCxt* _thCxt);

METHOD_C void main_SY_TestAllConcepts_Test(/*static*/ StringJc_Y* args, ThCxt* _thCxt);


/* J2C: Method table contains all dynamic linked (virtual) methods
 * of the class and all super classes and interfaces. */
 extern const char sign_Mtbl_TestAllConcepts_Test[]; //marker for methodTable check
typedef struct Mtbl_TestAllConcepts_Test_t
{ MtblHeadJc head;
  MT_access_i_TestAllConcepts_Test* access_i;
  MT_checkSomeDynamicCalls_TestAllConcepts_Test* checkSomeDynamicCalls;
  MT_checkConcatenationDynamicCall_TestAllConcepts_Test* checkConcatenationDynamicCall;
  MT_checkConcatenationDynamicCallToBaseMethods_TestAllConcepts_Test* checkConcatenationDynamicCallToBaseMethods;
  MT_checkConcatCallReturnThisTypefixNonVirtual_TestAllConcepts_Test* checkConcatCallReturnThisTypefixNonVirtual;
  MT_checkConcatCallReturnAnything_TestAllConcepts_Test* checkConcatCallReturnAnything;
  MT_returnThisOverrideable_Test_TestAllConcepts_Test* returnThisOverrideable_Test;
  MT_checkNonVirtual_TestAllConcepts_Test* checkNonVirtual;
  MT_equals_S_TestAllConcepts_Test* equals_S;
  MT_access_f_TestAllConcepts_Test* access_f;
  MT_testAccessIfc_TestAllConcepts_Test* testAccessIfc;
  MT_testAccessIfcMtbl_TestAllConcepts_Test* testAccessIfcMtbl;
  MT_testAccessIfcMtbl2_TestAllConcepts_Test* testAccessIfcMtbl2;
  MT_main_TestAllConcepts_Test* main;
  Mtbl_ObjectJc ObjectJc;
} Mtbl_TestAllConcepts_Test;



#if defined(__CPLUSPLUSJcpp) && defined(__cplusplus)
/* J2C: The C++-class-definition. */
class TestAllConcepts_Test : private TestAllConcepts_Test_s
{ public:

  virtual void access(float x){ access_f_TestAllConcepts_Test_F(this, x,  null/*_thCxt*/); }

  virtual int32 access(int32 x){  return access_i_TestAllConcepts_Test_F(this, x,  null/*_thCxt*/); }

  virtual int32 checkConcatCallReturnAnything(){  return checkConcatCallReturnAnything_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  virtual int32 checkConcatCallReturnThisTypefixNonVirtual(){  return checkConcatCallReturnThisTypefixNonVirtual_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  virtual int32 checkConcatenationDynamicCallToBaseMethods(){  return checkConcatenationDynamicCallToBaseMethods_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  virtual int32 checkConcatenationDynamicCall(){  return checkConcatenationDynamicCall_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  int32 checkConcatenationSimple(){  return checkConcatenationSimple_TestAllConcepts_Test(this,  null/*_thCxt*/); }

  virtual void checkNonVirtual(){ checkNonVirtual_TestAllConcepts_Test_F(this); }

  virtual int32 checkSomeDynamicCalls(){  return checkSomeDynamicCalls_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  TestAllConcepts_Test(){ init_ObjectJc(&this->base.object, sizeof(TestAllConcepts_Test_s), 0); setReflection_ObjectJc(&this->base.object, &reflection_TestAllConcepts_Test_s, 0); ctorO_TestAllConcepts_Test(&this->base.object,  null/*_thCxt*/); }

  virtual bool equals(struct ObjectJc_t* cmp){  return equals_O_TestAllConcepts_Test_F(&this->base.object, cmp,  null/*_thCxt*/); }

  virtual bool equals(StringJcpp cmp){  return equals_S_TestAllConcepts_Test_F(this, cmp,  null/*_thCxt*/); }

  void main(StringJc_Y* args){ main_SY_TestAllConcepts_Test(args,  null/*_thCxt*/); }

  virtual void main(){ main_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  virtual TestAllConcepts_Test& returnThisOverrideable_Test(int32 value){ returnThisOverrideable_Test_TestAllConcepts_Test_F(this, value);  return *this; }

  virtual int32 testAccessIfcMtbl2(bool bTest){  return testAccessIfcMtbl2_TestAllConcepts_Test_F(this, bTest,  null/*_thCxt*/); }

  virtual int32 testAccessIfcMtbl(){  return testAccessIfcMtbl_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  virtual int32 testAccessIfc(){  return testAccessIfc_TestAllConcepts_Test_F(this,  null/*_thCxt*/); }

  void testInternalDynCall(){ testInternalDynCall_TestAllConcepts_Test(this,  null/*_thCxt*/); }
};

#endif /*__CPLUSPLUSJcpp*/

#endif //__TestAllConcepts_Test_h__