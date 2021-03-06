/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "TestThread_Test.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Jc/FileIoJc.h"  //reference-association: out
#include "Jc/StringJc.h"  //string concatenation
#include "Jc/SystemJc.h"  //reference-association: SystemJc
#include "TestWaitNotify_Test.h"  //reference-association: theNotifyingDataMtbl


/* J2C: Method-table-references *********************************************************/
#ifndef WaitNotifyData_TestWaitNotify_TestMTBDEF
  #define WaitNotifyData_TestWaitNotify_TestMTBDEF
  typedef struct WaitNotifyData_TestWaitNotify_TestMTB_t { struct Mtbl_WaitNotifyData_TestWaitNotify_Test_t const* mtbl; struct WaitNotifyData_TestWaitNotify_Test_t* ref; } WaitNotifyData_TestWaitNotify_TestMTB;
#endif


/**This class demonstrates and tests the usage of threads with the synchronized access to data (mutex).
It implements the run()-Method of the Thread defined in the interface Runnable.
<br><br>
The threads private data which should be able to access only by the current thread are stored
in an extra class, here defined as static inner class.

*/


const char sign_Mtbl_TestThread_Test[] = "TestThread_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestThread_Test_t { Mtbl_TestThread_Test mtbl; MtblHeadJc end; } MtblDef_TestThread_Test;
 extern MtblDef_TestThread_Test const mtblTestThread_Test;

/*Constructor */
struct TestThread_Test_t* ctorO_TestThread_Test(ObjectJc* othis, struct WaitNotifyData_TestWaitNotify_Test_t* theNotifyingData, ThCxt* _thCxt)
{ TestThread_Test_s* ythis = (TestThread_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestThread_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestThread_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestThread_Test_s, sizeof(TestThread_Test_s));  
  //j2c: Initialize all class variables:
  {
    ythis->testCt1 = 0;
    ythis->testCt2 = 0;
    ythis->testCtInterrupted = 0;
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(ythis->theThread.base.object), sizeof(ythis->theThread), 0); 
      ctorO_Runnable_s_ThreadJc(/*static*/&(ythis->theThread.base.object), & ((* (ythis)).base.RunnableJc), s0_StringJc("TestThread"), _thCxt);
  }
  { 
    
    SETREFJc(ythis->theNotifyingData, theNotifyingData, WaitNotifyData_TestWaitNotify_Test_s);
  }
  STACKTRC_LEAVE;
  return ythis;
}



/**This is the thread main-routine complying the Java rules*/
void run_TestThread_Test_F(ObjectJc* ithis, ThCxt* _thCxt)
{ TestThread_Test_s* ythis = (TestThread_Test_s*)ithis;
  
  STACKTRC_TENTRY("run_TestThread_Test_F");
  
  { 
    WaitNotifyData_TestWaitNotify_TestMTB theNotifyingDataMtbl;   /*Use local variable to enforce only one preparation of the method table for dynamic call:*/
    TestThreadLocalData_TestThread_Test_s threadLocalData = { 0 };   /*This instance is only visible in the threads context*/
    
     //J2C: temporary Stringbuffer for String concatenation
    StringBuilderJc* _tempString1_1=null; 
    
    ythis->threadRunning = true;
    SETMTBJc(theNotifyingDataMtbl, REFJc(ythis->theNotifyingData), WaitNotifyData_TestWaitNotify_Test);
    
    //J2C: constructor for embedded element-ObjectJc
    init_ObjectJc(&(threadLocalData.base.object), sizeof(threadLocalData), 0); 
    ctorO_TestThreadLocalData_TestThread_Test(/*static*/&(threadLocalData.base.object), _thCxt);
    { int32 liveCt; 
      for(liveCt = 0; liveCt < 200; liveCt++)
        { 
          
          testSynchronized_TestThread_Test(ythis, & (threadLocalData), _thCxt);
          notify_WaitNotifyData_TestWaitNotify_Test( (theNotifyingDataMtbl.ref), ythis->testCt1, _thCxt);
          TRY
          { 
            
            sleep_ThreadJc(/*static*/10, _thCxt);
          }_TRY
          CATCH(InterruptedException, exc)
          
            { 
              
              ythis->testCtInterrupted += 1;
            }
          END_TRY
        }//for
        
    }
    println_s_PrintStreamJc(REFJc(out_SystemJc), 
      ( _tempString1_1 = new_StringBuilderJc(-1, _thCxt)
      , setStringConcatBuffer_StringBuilderJc(_tempString1_1)
      , append_z_StringBuilderJc(_tempString1_1, "test-thread stopped at ", _thCxt)
      , append_F_StringBuilderJc(_tempString1_1, threadLocalData.x, _thCxt)
      , toString_StringBuilderJc(&(_tempString1_1)->base.object, _thCxt)
      ), _thCxt);
    ythis->threadFinished = true;
    activateGarbageCollectorAccess_BlockHeapJc(&_tempString1_1->base.object, null);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void run_TestThread_Test(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_RunnableJc const* mtbl = (Mtbl_RunnableJc const*)getMtbl_ObjectJc(ithis, sign_Mtbl_RunnableJc);
  mtbl->run(ithis, _thCxt);
}


/**This routine shows and support test of a mutex-access.*/
void testSynchronized_TestThread_Test(TestThread_Test_s* ythis, struct TestThreadLocalData_TestThread_Test_t* threadLocalData, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("testSynchronized_TestThread_Test");
  
  { 
    
    
    synchronized_ObjectJc(& ((* (ythis)).base.RunnableJc.base.object)); {
      
      { 
        
        ASSERT(/*static*/ythis->testCt1 == ythis->testCt2);
        ythis->testCt1 -= 2;
        /**Let the thread sleeping to provoke a switch to the other thread.*/
        TRY
        { 
          
          sleep_ThreadJc(/*static*/5, _thCxt);
        }_TRY
        CATCH(InterruptedException, e)
        
          { 
            
            
          }
        END_TRY
        ythis->testCt2 -= 2;
        threadLocalData->x = (float)ythis->testCt1;
      }
    } endSynchronized_ObjectJc(& ((* (ythis)).base.RunnableJc.base.object));
  }
  STACKTRC_LEAVE;
}


/**Facade routine to start the Thread.*/
void start_TestThread_Test_F(TestThread_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("start_TestThread_Test_F");
  
  { 
    
    /***/
    start_ThreadJc(& (ythis->theThread), sizeof(TestThreadLocalData_TestThread_Test_s)+2000, _thCxt);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void start_TestThread_Test(TestThread_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestThread_Test const* mtbl = (Mtbl_TestThread_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestThread_Test);
  mtbl->start(ythis, _thCxt);
}


/**This routine is called from outside in another thread*/
void otherThreadRoutine_TestThread_Test_F(TestThread_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("otherThreadRoutine_TestThread_Test_F");
  
  { 
    int32 ctWaitFinished = 0;   /*Wait unil the thread of the instance is finished: */
    
     //J2C: temporary Stringbuffer for String concatenation
    StringBuilderJc* _tempString1_1=null; 
    
    { int32 i; 
      for(i = 0; i < 200; i++)
        { 
          
          
          synchronized_ObjectJc(& ((* (ythis)).base.RunnableJc.base.object)); {
            
            { 
              
              ASSERT(/*static*/ythis->testCt1 == ythis->testCt2);
              ythis->testCt1 += 3;
              ythis->testCt2 += 3;
            }
          } endSynchronized_ObjectJc(& ((* (ythis)).base.RunnableJc.base.object));
          TRY
          { 
            
            sleep_ThreadJc(/*static*/10, _thCxt);
          }_TRY
          CATCH(InterruptedException, e)
          
            { 
              
              
            }
          END_TRY
        }//for
        
    }
    ctWaitFinished = 0;
    
    while(!isThreadFinished_TestThread_Test(ythis, _thCxt))
      { 
        
        ctWaitFinished++;
        /**This is a polling loop. It should be contain a reasonable wait statement to release the CPU-ressource while polling: */
        TRY
        { 
          
          sleep_ThreadJc(/*static*/5, _thCxt);
        }_TRY
        CATCH(InterruptedException, e)
        
          { 
            
            
          }
        END_TRY
      }
    println_s_PrintStreamJc(REFJc(out_SystemJc), 
      ( _tempString1_1 = new_StringBuilderJc(-1, _thCxt)
      , setStringConcatBuffer_StringBuilderJc(_tempString1_1)
      , append_z_StringBuilderJc(_tempString1_1, "main-thread stopped at ", _thCxt)
      , append_I_StringBuilderJc(_tempString1_1, ythis->testCt1, _thCxt)
      , append_z_StringBuilderJc(_tempString1_1, ", ctWaitFinished=", _thCxt)
      , append_I_StringBuilderJc(_tempString1_1, ctWaitFinished, _thCxt)
      , toString_StringBuilderJc(&(_tempString1_1)->base.object, _thCxt)
      ), _thCxt);
    activateGarbageCollectorAccess_BlockHeapJc(&_tempString1_1->base.object, null);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void otherThreadRoutine_TestThread_Test(TestThread_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestThread_Test const* mtbl = (Mtbl_TestThread_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestThread_Test);
  mtbl->otherThreadRoutine(ythis, _thCxt);
}


/**Returns true if the class private variable {@link #threadFinished} is set*/
bool isThreadFinished_TestThread_Test(TestThread_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("isThreadFinished_TestThread_Test");
  
  { 
    
    { STACKTRC_LEAVE;
      return ythis->threadFinished;
    }
  }
  STACKTRC_LEAVE;
}


void finalize_TestThread_Test_F(ObjectJc* othis, ThCxt* _thCxt)
{ TestThread_Test_s* ythis = (TestThread_Test_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_TestThread_Test_F");
  finalize_ObjectJc_F(&ythis->theThread.base.object, _thCxt); //J2C: finalizing the embedded instance.
  CLEAR_REFJc(ythis->theNotifyingData);
  finalize_ObjectJc_F(&ythis->base.object, _thCxt); //J2C: finalizing the superclass.
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestThread_Test mtblTestThread_Test = {
{ { sign_Mtbl_TestThread_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((2 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, start_TestThread_Test_F //start
, otherThreadRoutine_TestThread_Test_F //otherThreadRoutine
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_TestThread_Test_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
  /**J2C: Mtbl-interfaces of TestThread_Test: */
, { { sign_Mtbl_RunnableJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , run_TestThread_Test_F //run
  , { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
      , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
      }
    , clone_ObjectJc_F //clone
    , equals_ObjectJc_F //equals
    , finalize_TestThread_Test_F //finalize
    , hashCode_ObjectJc_F //hashCode
    , toString_ObjectJc_F //toString
    }
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_TestThread_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestThread_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestThread_Test, ObjectJc) }
   }
 };

 extern struct ClassJc_t const reflection_RunnableJc_s;
 static struct ifcClasses_TestThread_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }interfaces_TestThread_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
, { {&reflection_RunnableJc_s, OFFSET_Mtbl(Mtbl_TestThread_Test, RunnableJc) }
  }
};

extern struct ClassJc_t const reflection_TestThread_Test_s;
extern struct ClassJc_t const reflection_ThreadJc_s;
extern struct ClassJc_t const reflection_WaitNotifyData_TestWaitNotify_Test_s;
const struct Reflection_Fields_TestThread_Test_s_t
{ ObjectArrayJc head; FieldJc data[7];
} reflection_Fields_TestThread_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 7, OBJTYPE_FieldJc, null, &reflection_Fields_TestThread_Test_s)
, {
     { "threadRunning"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->threadRunning) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "threadFinished"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->threadFinished) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "testCt1"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->testCt1) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "testCt2"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->testCt2) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "testCtInterrupted"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->testCtInterrupted) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "theThread"
    , 0 //nrofArrayElements
    , &reflection_ThreadJc_s
    , kEmbedded_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->theThread) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
   , { "theNotifyingData"
    , 0 //nrofArrayElements
    , &reflection_WaitNotifyData_TestWaitNotify_Test_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThread_Test_s*)(0x1000))->theNotifyingData) - (int32)(TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThread_Test_s
    }
} };
const ClassJc reflection_TestThread_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestThread_Test_s"
, (int16)((int32)(&((TestThread_Test_s*)(0x1000))->base.object) - (int32)(TestThread_Test_s*)0x1000)
, sizeof(TestThread_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestThread_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestThread_Test_s //superclass
, (ClassOffset_idxMtblJcARRAY*)&interfaces_TestThread_Test_s //interfaces
, mObjectJc_Modifier_reflectJc
, &mtblTestThread_Test.mtbl.head
};

/**This class is defined only to use in the threads context. No other thread should have access to it.
Therefore the instance can be defined in a thread-local data range. For Java2C it is possible
to create a stack-instance. It is done in the {@link TestThread#run()}. routine.
<br><br>

*/


const char sign_Mtbl_TestThreadLocalData_TestThread_Test[] = "TestThreadLocalData_TestThread_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestThreadLocalData_TestThread_Test_t { Mtbl_TestThreadLocalData_TestThread_Test mtbl; MtblHeadJc end; } MtblDef_TestThreadLocalData_TestThread_Test;
 extern MtblDef_TestThreadLocalData_TestThread_Test const mtblTestThreadLocalData_TestThread_Test;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct TestThreadLocalData_TestThread_Test_t* ctorO_TestThreadLocalData_TestThread_Test(ObjectJc* othis, ThCxt* _thCxt)
{ TestThreadLocalData_TestThread_Test_s* ythis = (TestThreadLocalData_TestThread_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestThreadLocalData_TestThread_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestThreadLocalData_TestThread_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestThreadLocalData_TestThread_Test_s, sizeof(TestThreadLocalData_TestThread_Test_s));  
  //j2c: Initialize all class variables:
  {
    //J2C: constructor for embedded fix-size-StringBuffer
      init_ObjectJc(&ythis->threadownBuffer.sb.base.object, sizeof(StringBuilderJc) + 3000 - 4, 0);
      ctorO_I_StringBuilderJc(&ythis->threadownBuffer.sb.base.object, 3000, _thCxt);
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return ythis;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestThreadLocalData_TestThread_Test mtblTestThreadLocalData_TestThread_Test = {
{ { sign_Mtbl_TestThreadLocalData_TestThread_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
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
 static struct superClasses_TestThreadLocalData_TestThread_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestThreadLocalData_TestThread_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestThreadLocalData_TestThread_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_TestThreadLocalData_TestThread_Test_s;
extern struct ClassJc_t const reflection_StringBuilderJc;
const struct Reflection_Fields_TestThreadLocalData_TestThread_Test_s_t
{ ObjectArrayJc head; FieldJc data[3];
} reflection_Fields_TestThreadLocalData_TestThread_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 3, OBJTYPE_FieldJc, null, &reflection_Fields_TestThreadLocalData_TestThread_Test_s)
, {
     { "x"
    , 0 //nrofArrayElements
    , REFLECTION_float
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestThread_Test_s*)(0x1000))->x) - (int32)(TestThreadLocalData_TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestThread_Test_s
    }
   , { "y"
    , 0 //nrofArrayElements
    , REFLECTION_float
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestThread_Test_s*)(0x1000))->y) - (int32)(TestThreadLocalData_TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestThread_Test_s
    }
   , { "threadownBuffer"
    , 0 //nrofArrayElements
    , &reflection_StringBuilderJc
    , kEmbedded_Modifier_reflectJc |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestThread_Test_s*)(0x1000))->threadownBuffer) - (int32)(TestThreadLocalData_TestThread_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestThread_Test_s
    }
} };
const ClassJc reflection_TestThreadLocalData_TestThread_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestThreadLocalDat_ad_Test_s"
,  0 //position of ObjectJc
, sizeof(TestThreadLocalData_TestThread_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestThreadLocalData_TestThread_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestThreadLocalData_TestThread_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestThreadLocalData_TestThread_Test.mtbl.head
};
