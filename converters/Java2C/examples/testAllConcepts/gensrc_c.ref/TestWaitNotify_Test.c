/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "TestWaitNotify_Test.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Jc/FileIoJc.h"  //reference-association: out
#include "Jc/StringJc.h"  //string concatenation
#include "Jc/SystemJc.h"  //reference-association: SystemJc

/**This class demonstrates and tests the usage of threads with wait and notify.
It implements the run()-Method of the Thread defined in the interface Runnable, which is inherited from the super class Thread.
The class based on Thread, therefore no other instance is necessary to organize the thread.
<br><br>
The threads private data which should be able to access only by the current thread are stored
in an extra class, here defined as static inner class.

*/


const char sign_Mtbl_TestWaitNotify_Test[] = "TestWaitNotify_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestWaitNotify_Test_t { Mtbl_TestWaitNotify_Test mtbl; MtblHeadJc end; } MtblDef_TestWaitNotify_Test;
 extern MtblDef_TestWaitNotify_Test const mtblTestWaitNotify_Test;

/*Constructor */
struct TestWaitNotify_Test_t* ctorO_TestWaitNotify_Test(ObjectJc* othis, struct WaitNotifyData_TestWaitNotify_Test_t* theAwaitingDataP, ThCxt* _thCxt)
{ TestWaitNotify_Test_s* ythis = (TestWaitNotify_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestWaitNotify_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestWaitNotify_Test_s), null, _thCxt);  
  //J2C:super Constructor
  ctorO_ThreadJc(/*static*/othis, _thCxt);
  setReflection_ObjectJc(othis, &reflection_TestWaitNotify_Test_s, sizeof(TestWaitNotify_Test_s));  
  //j2c: Initialize all class variables:
  {
    ythis->shouldRun = true;
  }
  { 
    
    SETREFJc(ythis->theAwaitingData, theAwaitingDataP, WaitNotifyData_TestWaitNotify_Test_s);
  }
  STACKTRC_LEAVE;
  return ythis;
}



/**This routine overrides <code>Thread.start()</code>, it's a facade*/
void start_TestWaitNotify_Test_F(TestWaitNotify_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("start_TestWaitNotify_Test_F");
  
  { 
    
    /***/
    start_ThreadJc((&ythis->base.super), sizeof(TestThreadLocalData_TestWaitNotify_Test_s)+500, _thCxt);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void start_TestWaitNotify_Test(TestWaitNotify_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_TestWaitNotify_Test const* mtbl = (Mtbl_TestWaitNotify_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_TestWaitNotify_Test);
  mtbl->start(ythis, _thCxt);
}


/**This is the thread main-routine complying the Java rules*/
void run_TestWaitNotify_Test_F(ObjectJc* ithis, ThCxt* _thCxt)
{ TestWaitNotify_Test_s* ythis = (TestWaitNotify_Test_s*)ithis;
  
  STACKTRC_TENTRY("run_TestWaitNotify_Test_F");
  
  { 
    TestThreadLocalData_TestWaitNotify_Test_s threadLocalData = { 0 };   /*This instance is only visible in the threads context*/
    
     //J2C: temporary Stringbuffer for String concatenation
    StringBuilderJc* _tempString1_1=null; 
    StringBuilderJc* _tempString1_2=null; 
    
    
    //J2C: constructor for embedded element-ObjectJc
    init_ObjectJc(&(threadLocalData.base.object), sizeof(threadLocalData), 0); 
    ctorO_TestThreadLocalData_TestWaitNotify_Test(/*static*/&(threadLocalData.base.object), REFJc(ythis->theAwaitingData), _thCxt);
    
    while(ythis->shouldRun)
      { 
        
        awaitData_TestThreadLocalData_TestWaitNotify_Test(& (threadLocalData), _thCxt);
      }//while
      
    println_s_PrintStreamJc(REFJc(out_SystemJc), 
      ( _tempString1_1 = new_StringBuilderJc(-1, _thCxt)
      , setStringConcatBuffer_StringBuilderJc(_tempString1_1)
      , append_z_StringBuilderJc(_tempString1_1, "wait/notify-thread stopped at ", _thCxt)
      , append_I_StringBuilderJc(_tempString1_1, threadLocalData.x, _thCxt)
      , toString_StringBuilderJc(&(_tempString1_1)->base.object, _thCxt)
      ), _thCxt);
    println_s_PrintStreamJc(REFJc(out_SystemJc), 
      ( _tempString1_2 = new_StringBuilderJc(-1, _thCxt)
      , setStringConcatBuffer_StringBuilderJc(_tempString1_2)
      , append_z_StringBuilderJc(_tempString1_2, "wait/notify-thread: nothingRcv=", _thCxt)
      , append_I_StringBuilderJc(_tempString1_2, threadLocalData.testCtNothingReceived, _thCxt)
      , append_z_StringBuilderJc(_tempString1_2, ", successfull=", _thCxt)
      , append_I_StringBuilderJc(_tempString1_2, threadLocalData.testCtSuccessNotify, _thCxt)
      , append_z_StringBuilderJc(_tempString1_2, ", missNotify=", _thCxt)
      , append_I_StringBuilderJc(_tempString1_2, threadLocalData.testCtMissNotify, _thCxt)
      , toString_StringBuilderJc(&(_tempString1_2)->base.object, _thCxt)
      ), _thCxt);
    activateGarbageCollectorAccess_BlockHeapJc(&_tempString1_1->base.object, null);
    activateGarbageCollectorAccess_BlockHeapJc(&_tempString1_2->base.object, null);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void run_TestWaitNotify_Test(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_RunnableJc const* mtbl = (Mtbl_RunnableJc const*)getMtbl_ObjectJc(ithis, sign_Mtbl_RunnableJc);
  mtbl->run(ithis, _thCxt);
}


void finalize_TestWaitNotify_Test_F(ObjectJc* othis, ThCxt* _thCxt)
{ TestWaitNotify_Test_s* ythis = (TestWaitNotify_Test_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_TestWaitNotify_Test_F");
  CLEAR_REFJc(ythis->theAwaitingData);
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestWaitNotify_Test mtblTestWaitNotify_Test = {
{ { sign_Mtbl_TestWaitNotify_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, start_TestWaitNotify_Test_F //start
, { { sign_Mtbl_ThreadJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
      , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
      }
    , clone_ObjectJc_F //clone
    , equals_ObjectJc_F //equals
    , finalize_TestWaitNotify_Test_F //finalize
    , hashCode_ObjectJc_F //hashCode
    , toString_ObjectJc_F //toString
    }
    /**J2C: Mtbl-interfaces of TestWaitNotify_Test: */
  , { { sign_Mtbl_RunnableJc//J2C: Head of methodtable.
      , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
      }
    , run_TestWaitNotify_Test_F //run
    , { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
        , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
        }
      , clone_ObjectJc_F //clone
      , equals_ObjectJc_F //equals
      , finalize_TestWaitNotify_Test_F //finalize
      , hashCode_ObjectJc_F //hashCode
      , toString_ObjectJc_F //toString
      }
    }
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ThreadJc_s;
 static struct superClasses_TestWaitNotify_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestWaitNotify_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ThreadJc_s, OFFSET_Mtbl(Mtbl_TestWaitNotify_Test, ThreadJc) }
   }
 };

extern struct ClassJc_t const reflection_TestWaitNotify_Test_s;
extern struct ClassJc_t const reflection_WaitNotifyData_TestWaitNotify_Test_s;
const struct Reflection_Fields_TestWaitNotify_Test_s_t
{ ObjectArrayJc head; FieldJc data[2];
} reflection_Fields_TestWaitNotify_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 2, OBJTYPE_FieldJc, null, &reflection_Fields_TestWaitNotify_Test_s)
, {
     { "shouldRun"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestWaitNotify_Test_s*)(0x1000))->shouldRun) - (int32)(TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestWaitNotify_Test_s
    }
   , { "theAwaitingData"
    , 0 //nrofArrayElements
    , &reflection_WaitNotifyData_TestWaitNotify_Test_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestWaitNotify_Test_s*)(0x1000))->theAwaitingData) - (int32)(TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestWaitNotify_Test_s
    }
} };
const ClassJc reflection_TestWaitNotify_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestWaitNotify_Test_s"
,  0 //position of ObjectJc
, sizeof(TestWaitNotify_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestWaitNotify_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestWaitNotify_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestWaitNotify_Test.mtbl.head
};

/**This class is visible from outside, it is used from the notifying thread and from this thread,
which waits for data.

*/


const char sign_Mtbl_WaitNotifyData_TestWaitNotify_Test[] = "WaitNotifyData_TestWaitNotify_Test"; //to mark method tables of all implementations

typedef struct MtblDef_WaitNotifyData_TestWaitNotify_Test_t { Mtbl_WaitNotifyData_TestWaitNotify_Test mtbl; MtblHeadJc end; } MtblDef_WaitNotifyData_TestWaitNotify_Test;
 extern MtblDef_WaitNotifyData_TestWaitNotify_Test const mtblWaitNotifyData_TestWaitNotify_Test;

/*Constructor *//**J2C: autogenerated as default constructor. */
struct WaitNotifyData_TestWaitNotify_Test_t* ctorO_WaitNotifyData_TestWaitNotify_Test(ObjectJc* othis, ThCxt* _thCxt)
{ WaitNotifyData_TestWaitNotify_Test_s* ythis = (WaitNotifyData_TestWaitNotify_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_WaitNotifyData_TestWaitNotify_Test");
  checkConsistence_ObjectJc(othis, sizeof(WaitNotifyData_TestWaitNotify_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_WaitNotifyData_TestWaitNotify_Test_s, sizeof(WaitNotifyData_TestWaitNotify_Test_s));  
  //j2c: Initialize all class variables:
  {
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return ythis;
}



/**Notify routine, it may be called from outside*/
void notify_WaitNotifyData_TestWaitNotify_Test(WaitNotifyData_TestWaitNotify_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("notify_WaitNotifyData_TestWaitNotify_Test");
  
  { 
    
    
    synchronized_ObjectJc(& ((* (ythis)).base.object)); {
      
      { 
        
        ythis->x = value;
        ythis->ctNewData += 1;
        notify_ObjectJc(& ((* (ythis)).base.object), _thCxt);
      }
    } endSynchronized_ObjectJc(& ((* (ythis)).base.object));
  }
  STACKTRC_LEAVE;
}



/**J2C: Reflections and Method-table *************************************************/
const MtblDef_WaitNotifyData_TestWaitNotify_Test mtblWaitNotifyData_TestWaitNotify_Test = {
{ { sign_Mtbl_WaitNotifyData_TestWaitNotify_Test//J2C: Head of methodtable.
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
 static struct superClasses_WaitNotifyData_TestWaitNotify_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_WaitNotifyData_TestWaitNotify_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_WaitNotifyData_TestWaitNotify_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_WaitNotifyData_TestWaitNotify_Test_s;
const struct Reflection_Fields_WaitNotifyData_TestWaitNotify_Test_s_t
{ ObjectArrayJc head; FieldJc data[2];
} reflection_Fields_WaitNotifyData_TestWaitNotify_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 2, OBJTYPE_FieldJc, null, &reflection_Fields_WaitNotifyData_TestWaitNotify_Test_s)
, {
     { "x"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((WaitNotifyData_TestWaitNotify_Test_s*)(0x1000))->x) - (int32)(WaitNotifyData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_WaitNotifyData_TestWaitNotify_Test_s
    }
   , { "ctNewData"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((WaitNotifyData_TestWaitNotify_Test_s*)(0x1000))->ctNewData) - (int32)(WaitNotifyData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_WaitNotifyData_TestWaitNotify_Test_s
    }
} };
const ClassJc reflection_WaitNotifyData_TestWaitNotify_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "WaitNotifyData_Tes_fy_Test_s"
,  0 //position of ObjectJc
, sizeof(WaitNotifyData_TestWaitNotify_Test_s)
, (FieldJcArray const*)&reflection_Fields_WaitNotifyData_TestWaitNotify_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_WaitNotifyData_TestWaitNotify_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblWaitNotifyData_TestWaitNotify_Test.mtbl.head
};

/**This class is defined only to use in the threads context. No other thread should have access to it.
Therefore the instance can be defined in a thread-local data range. For Java2C it is possible
to create a stack-instance.
<br><br>

*/


const char sign_Mtbl_TestThreadLocalData_TestWaitNotify_Test[] = "TestThreadLocalData_TestWaitNotify_Test"; //to mark method tables of all implementations

typedef struct MtblDef_TestThreadLocalData_TestWaitNotify_Test_t { Mtbl_TestThreadLocalData_TestWaitNotify_Test mtbl; MtblHeadJc end; } MtblDef_TestThreadLocalData_TestWaitNotify_Test;
 extern MtblDef_TestThreadLocalData_TestWaitNotify_Test const mtblTestThreadLocalData_TestWaitNotify_Test;

/*Constructor */
struct TestThreadLocalData_TestWaitNotify_Test_t* ctorO_TestThreadLocalData_TestWaitNotify_Test(ObjectJc* othis, struct WaitNotifyData_TestWaitNotify_Test_t* theAwaitingDataP, ThCxt* _thCxt)
{ TestThreadLocalData_TestWaitNotify_Test_s* ythis = (TestThreadLocalData_TestWaitNotify_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_TestThreadLocalData_TestWaitNotify_Test");
  checkConsistence_ObjectJc(othis, sizeof(TestThreadLocalData_TestWaitNotify_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_TestThreadLocalData_TestWaitNotify_Test_s, sizeof(TestThreadLocalData_TestWaitNotify_Test_s));  
  //j2c: Initialize all class variables:
  {
    ythis->seqCtLast = -1;
    ythis->testCtInterrupted = 0;
    ythis->testCtNothingReceived = 0;
    ythis->testCtSuccessNotify = 0;
    ythis->testCtMissNotify = 0;
  }
  { 
    
    SETREFJc(ythis->theAwaitingData, theAwaitingDataP, WaitNotifyData_TestWaitNotify_Test_s);///
    
  }
  STACKTRC_LEAVE;
  return ythis;
}



/**In this routine the thread is waiting for data*/
void awaitData_TestThreadLocalData_TestWaitNotify_Test(TestThreadLocalData_TestWaitNotify_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("awaitData_TestThreadLocalData_TestWaitNotify_Test");
  
  { 
    int32 valueFromAwaitingData = 0; 
    int32 seqCtDiff;   /*All data to process are stored in this instance, it is accessible only be the own thread. */
    
    
    /*no initvalue*/
    TRY
    { 
      
      
      synchronized_ObjectJc(& ((* (REFJc(ythis->theAwaitingData))).base.object)); {
        
        { 
          
          if(ythis->seqCtLast == -1) 
          { 
            
            /**initial:*/
            ythis->seqCt = ythis->seqCtLast = /*? assignment*/REFJc(ythis->theAwaitingData)->ctNewData;
          }
          /**Wait at maximum 1 second. */
          wait_ObjectJc(& ((*(REFJc(ythis->theAwaitingData))).base.object), 1000, _thCxt);
          /**the thread is waken up either because notify or because time.*/
          ythis->seqCt = REFJc(ythis->theAwaitingData)->ctNewData;//same as seqCtLast if no notify is called.
          
          /**Copy the value to a stack variable, because after synchronized-end the value may be changed already.*/
          valueFromAwaitingData = REFJc(ythis->theAwaitingData)->x;
        }
      } endSynchronized_ObjectJc(& ((* (REFJc(ythis->theAwaitingData))).base.object));
    }_TRY
    CATCH(InterruptedException, exc)
    
      { 
        
        ythis->testCtInterrupted += 1;
        valueFromAwaitingData = 0;
      }
    END_TRY
    seqCtDiff = ythis->seqCt - ythis->seqCtLast;
    ythis->seqCtLast = ythis->seqCt;
    if(seqCtDiff == 1) 
    { 
      
      /**The next data are received.*/
      ythis->x += valueFromAwaitingData;
      ythis->testCtSuccessNotify += 1;
    }
    else if(seqCtDiff == 0) 
    { 
      
      /**A wake up because time cycle has occurred ; */
      ythis->testCtNothingReceived += 1;
    }
    else if(seqCtDiff > 0) 
    { 
      
      ythis->testCtMissNotify += 1;
    }
    else 
    { 
      
      ASSERT(/*static*/false);
    }
  }
  STACKTRC_LEAVE;
}


void finalize_TestThreadLocalData_TestWaitNotify_Test_F(ObjectJc* othis, ThCxt* _thCxt)
{ TestThreadLocalData_TestWaitNotify_Test_s* ythis = (TestThreadLocalData_TestWaitNotify_Test_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_TestThreadLocalData_TestWaitNotify_Test_F");
  CLEAR_REFJc(ythis->theAwaitingData);
  finalize_ObjectJc_F(&ythis->base.object, _thCxt); //J2C: finalizing the superclass.
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_TestThreadLocalData_TestWaitNotify_Test mtblTestThreadLocalData_TestWaitNotify_Test = {
{ { sign_Mtbl_TestThreadLocalData_TestWaitNotify_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_TestThreadLocalData_TestWaitNotify_Test_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_TestThreadLocalData_TestWaitNotify_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_TestThreadLocalData_TestWaitNotify_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_TestThreadLocalData_TestWaitNotify_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_TestThreadLocalData_TestWaitNotify_Test_s;
extern struct ClassJc_t const reflection_WaitNotifyData_TestWaitNotify_Test_s;
const struct Reflection_Fields_TestThreadLocalData_TestWaitNotify_Test_s_t
{ ObjectArrayJc head; FieldJc data[9];
} reflection_Fields_TestThreadLocalData_TestWaitNotify_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 9, OBJTYPE_FieldJc, null, &reflection_Fields_TestThreadLocalData_TestWaitNotify_Test_s)
, {
     { "x"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->x) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "y"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->y) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "seqCtLast"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->seqCtLast) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "seqCt"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->seqCt) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "testCtInterrupted"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->testCtInterrupted) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "testCtNothingReceived"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->testCtNothingReceived) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "testCtSuccessNotify"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->testCtSuccessNotify) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "testCtMissNotify"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->testCtMissNotify) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
   , { "theAwaitingData"
    , 0 //nrofArrayElements
    , &reflection_WaitNotifyData_TestWaitNotify_Test_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((TestThreadLocalData_TestWaitNotify_Test_s*)(0x1000))->theAwaitingData) - (int32)(TestThreadLocalData_TestWaitNotify_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_TestThreadLocalData_TestWaitNotify_Test_s
    }
} };
const ClassJc reflection_TestThreadLocalData_TestWaitNotify_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "TestThreadLocalDat_fy_Test_s"
,  0 //position of ObjectJc
, sizeof(TestThreadLocalData_TestWaitNotify_Test_s)
, (FieldJcArray const*)&reflection_Fields_TestThreadLocalData_TestWaitNotify_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_TestThreadLocalData_TestWaitNotify_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblTestThreadLocalData_TestWaitNotify_Test.mtbl.head
};