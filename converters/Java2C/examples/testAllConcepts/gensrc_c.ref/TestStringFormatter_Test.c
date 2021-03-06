/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "TestStringFormatter_Test.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "J1c/StringFormatterJc.h"  //new object
#include "Jc/StringJc.h"  //embedded ctor


const char sign_Mtbl_TestStringFormatter_Test[] = "TestStringFormatter_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestStringFormatter_Test_t { Mtbl_TestStringFormatter_Test mtbl; MtblHeadJc end; } MtblDef_TestStringFormatter_Test;
 extern MtblDef_TestStringFormatter_Test const mtblTestStringFormatter_Test;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct TestStringFormatter_Test_t* ctorO_TestStringFormatter_Test(ObjectJc* othis, ThCxt* _thCxt)
{ TestStringFormatter_Test_s* ythis = (TestStringFormatter_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestStringFormatter_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestStringFormatter_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestStringFormatter_Test_s, sizeof(TestStringFormatter_Test_s));  
  //j2c: Initialize all class variables:
  {
    //J2C: constructor for embedded fix-size-StringBuffer
      init_ObjectJc(&ythis->buffer.sb.base.object, sizeof(StringBuilderJc) + 200 - 4, 0);
      ctorO_I_StringBuilderJc(&ythis->buffer.sb.base.object, 200, _thCxt);
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return ythis;
}


void test_TestStringFormatter_Test_F(TestStringFormatter_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("test_TestStringFormatter_Test_F");
  
  { 
    struct StringFormatterJc_t* formatter = null; 
    
    ObjectJc *newObj1_1=null; //J2C: temporary Objects for new operations
    
    
    formatter = ctorO_Sb_StringFormatterJc(/*static*/(newObj1_1 = alloc_ObjectJc(sizeof_StringFormatterJc_s, 0, _thCxt)), & (ythis->buffer.sb), _thCxt);
    addFloatPicture_StringFormatterJc_F(formatter, 1.54E7F, s0_StringJc("-221.1"), _thCxt);
    activateGarbageCollectorAccess_BlockHeapJc(newObj1_1, null);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void test_TestStringFormatter_Test(TestStringFormatter_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestStringFormatter_Test const* mtbl = (Mtbl_TestStringFormatter_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestStringFormatter_Test);
  mtbl->test(ythis, _thCxt);
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestStringFormatter_Test mtblTestStringFormatter_Test = {
{ { sign_Mtbl_TestStringFormatter_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, test_TestStringFormatter_Test_F //test
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_ObjectJc_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_TestStringFormatter_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestStringFormatter_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestStringFormatter_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_TestStringFormatter_Test_s;
extern struct ClassJc_t const reflection_StringBuilderJc;
const struct Reflection_Fields_TestStringFormatter_Test_s_t
{ ObjectArrayJc head; FieldJc data[1];
} reflection_Fields_TestStringFormatter_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 1, OBJTYPE_FieldJc, null, &reflection_Fields_TestStringFormatter_Test_s)
, {
     { "buffer"
    , 0 //nrofArrayElements
    , &reflection_StringBuilderJc
    , kEmbedded_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestStringFormatter_Test_s*)(0x1000))->buffer) - (int32)(TestStringFormatter_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestStringFormatter_Test_s
    }
} };
const ClassJc reflection_TestStringFormatter_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestStringFormatter_Test_s"
,  0 //position of ObjectJc
, sizeof(TestStringFormatter_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestStringFormatter_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestStringFormatter_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestStringFormatter_Test.mtbl.head
};
