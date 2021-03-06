/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "TestgarbageCollector_Test.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Jc/FileIoJc.h"  //reference-association: out
#include "Jc/StringJc.h"  //string concatenation
#include "Jc/SystemJc.h"  //reference-association: SystemJc
#include "Jc/ThreadJc.h"  //reference-association: ThreadJc_s
#include "SimpleClass_Test.h"  //new object


const char sign_Mtbl_TestgarbageCollector_Test[] = "TestgarbageCollector_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestgarbageCollector_Test_t { Mtbl_TestgarbageCollector_Test mtbl; MtblHeadJc end; } MtblDef_TestgarbageCollector_Test;
 extern MtblDef_TestgarbageCollector_Test const mtblTestgarbageCollector_Test;
SimpleClass_TestREF staticData_TestgarbageCollector_Test = { 0, null };

/*Constructor *//**J2C: autogenerated as default constructor. */
struct TestgarbageCollector_Test_t* ctorO_TestgarbageCollector_Test(ObjectJc* othis, ThCxt* _thCxt)
{ TestgarbageCollector_Test_s* ythis = (TestgarbageCollector_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestgarbageCollector_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestgarbageCollector_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestgarbageCollector_Test_s, sizeof(TestgarbageCollector_Test_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return ythis;
}


void useCreatedInstanceInternal_TestgarbageCollector_Test(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("useCreatedInstanceInternal_TestgarbageCollector_Test");
  
  { 
    
    /**Creates a new instance, works with it, but after them the instance isn't need furthermore.*/
    
    { 
      struct SimpleClass_Test_t* dataTemp = null; 
      
      ObjectJc *newObj2_1=null; //J2C: temporary Objects for new operations
       //J2C: temporary Stringbuffer for String concatenation
      StringBuilderJc* _tempString2_1=null; 
      
      
      dataTemp = ctorO_SimpleClass_Test(/*static*/(newObj2_1 = alloc_ObjectJc(sizeof_SimpleClass_Test_s, 0, _thCxt)), _thCxt);
      dataTemp->x1 = 34;
      /**To concat a temporary variable will be used and freed from GC. */
      println_s_PrintStreamJc(REFJc(out_SystemJc), 
        ( _tempString2_1 = new_StringBuilderJc(-1, _thCxt)
        , setStringConcatBuffer_StringBuilderJc(_tempString2_1)
        , append_z_StringBuilderJc(_tempString2_1, "test:", _thCxt)
        , append_I_StringBuilderJc(_tempString2_1, dataTemp->x1, _thCxt)
        , toString_StringBuilderJc(&(_tempString2_1)->base.object, _thCxt)
        ), _thCxt);
      activateGarbageCollectorAccess_BlockHeapJc(newObj2_1, null);
      activateGarbageCollectorAccess_BlockHeapJc(&_tempString2_1->base.object, null);
    }
  }
  STACKTRC_LEAVE;
}


/**This class creates a new instance and returns the pointer to them*/
struct SimpleClass_Test_t* createAndReturnInstance_TestgarbageCollector_Test_F(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("createAndReturnInstance_TestgarbageCollector_Test_F");
  
  { 
    struct SimpleClass_Test_t* obj = null; 
    
    ObjectJc *newObj1_1=null; //J2C: temporary Objects for new operations
    
    
    obj = ctorO_SimpleClass_Test(/*static*/(newObj1_1 = alloc_ObjectJc(sizeof_SimpleClass_Test_s, 0, _thCxt)), _thCxt);
    /**Because this obj is returned, it won't be activated for garbage collection. */
    { STACKTRC_LEAVE;
      activateGarbageCollectorAccess_BlockHeapJc(newObj1_1, obj);
      return obj;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct SimpleClass_Test_t* createAndReturnInstance_TestgarbageCollector_Test(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestgarbageCollector_Test const* mtbl = (Mtbl_TestgarbageCollector_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestgarbageCollector_Test);
  return mtbl->createAndReturnInstance(ythis, _thCxt);
}


/**This method calls the method {@link #createAndReturnInstance()} to create an instance, which is not stored*/
void testNewInstance_TestgarbageCollector_Test_F(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestgarbageCollector_Test const* mtthis = (Mtbl_TestgarbageCollector_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestgarbageCollector_Test);
  
  STACKTRC_TENTRY("testNewInstance_TestgarbageCollector_Test_F");
  
  { 
    struct SimpleClass_Test_t* data;   /*Because the data are returned from an method, it will be activated for garbage collection*/
    
    struct SimpleClass_Test_t* _new1_1; //J2C: temporary references for concatenation
    
    data = (_new1_1 = mtthis->createAndReturnInstance(ythis, _thCxt));
    { int32 ii; 
      for(ii = 0; ii < 5; ii++)
        { 
           //J2C: temporary Stringbuffer for String concatenation
          StringBuilderJc* _tempString3_1=null; 
          
          TRY
          { 
            
            sleep_ThreadJc(/*static*/1000, _thCxt);
          }_TRY
          CATCH(InterruptedException, e)
          
            { 
              
              
            }
          END_TRY
          data->x1 += 234;
          println_s_PrintStreamJc(REFJc(out_SystemJc), 
          ( _tempString3_1 = new_StringBuilderJc(-1, _thCxt)
          , setStringConcatBuffer_StringBuilderJc(_tempString3_1)
          , append_z_StringBuilderJc(_tempString3_1, "testNewInstance: ", _thCxt)
          , append_I_StringBuilderJc(_tempString3_1, data->x1, _thCxt)
          , toString_StringBuilderJc(&(_tempString3_1)->base.object, _thCxt)
          ), _thCxt);
          activateGarbageCollectorAccess_BlockHeapJc(&_tempString3_1->base.object, null);
        }
    }
    activateGarbageCollectorAccess_BlockHeapJc(_new1_1, null);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void testNewInstance_TestgarbageCollector_Test(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestgarbageCollector_Test const* mtbl = (Mtbl_TestgarbageCollector_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestgarbageCollector_Test);
  mtbl->testNewInstance(ythis, _thCxt);
}

void test_TestgarbageCollector_Test_F(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("test_TestgarbageCollector_Test_F");
  
  { 
    
    /**Creates a new instance and referes it to a static reference: */
    
    { 
      struct SimpleClass_Test_t* data = null; 
      
      ObjectJc *newObj2_1=null; //J2C: temporary Objects for new operations
      
      
      data = ctorO_SimpleClass_Test(/*static*/(newObj2_1 = alloc_ObjectJc(sizeof_SimpleClass_Test_s, 0, _thCxt)), _thCxt);
      SETREFJc(staticData_TestgarbageCollector_Test, data, SimpleClass_Test_s);
      activateGarbageCollectorAccess_BlockHeapJc(newObj2_1, null);
    }
    gc_SystemJc(/*static*/_thCxt);
    useCreatedInstanceInternal_TestgarbageCollector_Test(ythis, _thCxt);
    gc_SystemJc(/*static*/_thCxt);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void test_TestgarbageCollector_Test(TestgarbageCollector_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestgarbageCollector_Test const* mtbl = (Mtbl_TestgarbageCollector_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestgarbageCollector_Test);
  mtbl->test(ythis, _thCxt);
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestgarbageCollector_Test mtblTestgarbageCollector_Test = {
{ { sign_Mtbl_TestgarbageCollector_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((3 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, createAndReturnInstance_TestgarbageCollector_Test_F //createAndReturnInstance
, testNewInstance_TestgarbageCollector_Test_F //testNewInstance
, test_TestgarbageCollector_Test_F //test
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
 static struct superClasses_TestgarbageCollector_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestgarbageCollector_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestgarbageCollector_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_TestgarbageCollector_Test_s;
extern struct ClassJc_t const reflection_SimpleClass_Test_s;
const struct Reflection_Fields_TestgarbageCollector_Test_s_t
{ ObjectArrayJc head; FieldJc data[1];
} reflection_Fields_TestgarbageCollector_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 1, OBJTYPE_FieldJc, null, &reflection_Fields_TestgarbageCollector_Test_s)
, {
     { "staticData"
    , 0 //nrofArrayElements
    , &reflection_SimpleClass_Test_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc |mSTATIC_Modifier_reflectJc //bitModifiers
    , 0 //compiler problem, not a constant,TODO: (int16)(&staticData_TestgarbageCollector_Test) //lo part of memory address of static member
    , 0 //compiler problem, not a constant,TODO: (int16)((int32)(&staticData_TestgarbageCollector_Test)>>16) //hi part of memory address of static member instead offsetToObjectifcBase, TRICKY because compatibilty.
    , &reflection_TestgarbageCollector_Test_s
    }
} };
const ClassJc reflection_TestgarbageCollector_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestgarbageCollector_Test_s"
,  0 //position of ObjectJc
, sizeof(TestgarbageCollector_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestgarbageCollector_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestgarbageCollector_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestgarbageCollector_Test.mtbl.head
};
