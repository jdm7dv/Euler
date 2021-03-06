/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "simPc/SendActValues.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept
#include "Ipc/InterProcessComm.h"  //reference-association: InterProcessCommFactoryAccessor
#include "Jc/StringJc.h"  //embedded type in class data

/**This class sends actual values to a Operation-and-Monitoring system via UDP-telegrams
using the Inspector-datagram-definition.
<br><br>
The data will be accumulated in a buffer of 1400 byte (one UDP-datagram). If the OaM-System
sends a request telegram, the buffer will be sent to the requestor's address. If no request
is received, nothing will be sent.
<br><br>
The class builds a receive-thread in an anonymous private class which waits for the UDP-telegrams
from the OaM-system.
@author Hartmut Schorrig

*/


const char sign_Mtbl_SendActValues[] = "SendActValues"; //to mark method tables of all implementations

typedef struct MtblDef_SendActValues_t { Mtbl_SendActValues mtbl; MtblHeadJc end; } MtblDef_SendActValues;
 extern MtblDef_SendActValues const mtblSendActValues;
const int32 recordsize_SendActValues = sizeofHead_Info_InspcDataExchangeAccess_Inspc + sizeofHead_OamVariablesByteAccess_OamVariables;

/*Constructor */
struct SendActValues_t* ctorO_SendActValues(ObjectJc* othis, ThCxt* _thCxt)
{ SendActValues_s* ythis = (SendActValues_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_SendActValues");
  checkConsistence_ObjectJc(othis, sizeof(SendActValues_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_SendActValues_s, sizeof(SendActValues_s));  
  //j2c: Initialize all class variables:
  {ObjectJc *newObj0_1=null; //J2C: temporary Objects for new operations
      struct InterProcessCommFactory_t* _temp0_1; //J2C: temporary references for concatenation
      
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(ythis->oamVariableAccess.base.object), sizeof(ythis->oamVariableAccess), 0); 
      ctorO_OamVariablesByteAccess_OamVariables(/*static*/&(ythis->oamVariableAccess.base.object), _thCxt);
    /*J2C: newArray*/
      init_ObjectJc(&ythis->valueBuffer.head.object, sizeof_ARRAYJc(int8, 1400), 0);   //J2C: ctor embedded array.
      ctorO_ObjectArrayJc(&ythis->valueBuffer.head.object, 1400, sizeof(int8), null, 0);//J2C: constructor for embedded array;
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(ythis->datagram.base.object), sizeof(ythis->datagram), 0); 
      ctorO_Datagram_InspcDataExchangeAccess_Inspc(/*static*/&(ythis->datagram.base.object), _thCxt);
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(ythis->infoHead.base.object), sizeof(ythis->infoHead), 0); 
      ctorO_Info_InspcDataExchangeAccess_Inspc(/*static*/&(ythis->infoHead.base.object), _thCxt);
    SETREFJc(ythis->udpSocket, 
    ( _temp0_1= getInstance_InterProcessCommFactoryAccessor()
    , ((Mtbl_InterProcessCommFactory const*)getMtbl_ObjectJc(&(_temp0_1)->base.object, sign_Mtbl_InterProcessCommFactory) )->create(&((_temp0_1)->base.object), s0_StringJc("UDP:0.0.0.0:60083"), _thCxt)
    ), InterProcessComm_i);
    SETREFJc(ythis->dstAddress, ctorO_Address_InterProcessComm(/*static*/(newObj0_1 = alloc_ObjectJc(sizeof_Address_InterProcessComm_s, 0, _thCxt)), _thCxt), Address_InterProcessComm_s);
    //J2C: constructor for embedded element-ObjectJc
      init_ObjectJc(&(ythis->rxThread.base.object), sizeof(ythis->rxThread), 0); 
      ctorO_C_rxThread_SendActValues(ythis, &(ythis->rxThread.base.object), _thCxt);
    activateGarbageCollectorAccess_BlockHeapJc(newObj0_1, null);
  }
  { 
    int32 ix = 345; 
    StringJc test = CONST_z_StringJc("test"); 
    
     //J2C: temporary Stringbuffer for String concatenation
    StringBuilderJc* _tempString1_1=null; 
    
    setBigEndian_ByteDataAccessJc_F(& ((ythis->datagram).base.super), true, _thCxt);
    assignEmpty_ByteDataAccessJc(& ((ythis->datagram).base.super), (struct int8_Y_t*)(&( ythis->valueBuffer)), _thCxt);
    ix = 345;
    test = 
      ( _tempString1_1 = new_StringBuilderJc(-1, _thCxt)
      , setStringConcatBuffer_StringBuilderJc(_tempString1_1)
      , append_z_StringBuilderJc(_tempString1_1, "test", _thCxt)
      , append_I_StringBuilderJc(_tempString1_1, (ix + 5), _thCxt)
      , toString_StringBuilderJc(&(_tempString1_1)->base.object, _thCxt)
      )/*J2C:non-persistent*/;
    activateGarbageCollectorAccess_BlockHeapJc(&_tempString1_1->base.object, null);
  }
  STACKTRC_LEAVE;
  return ythis;
}


void start_SendActValues_F(SendActValues_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("start_SendActValues_F");
  
  { //:Address_InterProcessComm ownAddress = InterProcessCommFactory.createAddress("Socket:0.0.0.0:60083");
    
    struct InterProcessComm_t* udpSocket1; 
    int32 success; 
    
    
    udpSocket1 = REFJc(ythis->udpSocket);
    success = ((Mtbl_InterProcessComm const*)getMtbl_ObjectJc(&(udpSocket1)->base.object, sign_Mtbl_InterProcessComm) )->open(&((udpSocket1)->base.object), null, ((/*J2C:cast% from bool*/int32)(true)));
    if(success < 0) 
    { 
       //J2C: temporary Stringbuffer for String concatenation
      StringBuilderJc* _tempString2_1=null; 
      
      { throw_sJc(ident_IllegalArgumentExceptionJc, 
        ( _tempString2_1 = new_StringBuilderJc(-1, _thCxt)
        , setStringConcatBuffer_StringBuilderJc(_tempString2_1)
        , append_z_StringBuilderJc(_tempString2_1, "Error on open:", _thCxt)
        , append_z_StringBuilderJc(_tempString2_1, ((Mtbl_InterProcessComm const*)getMtbl_ObjectJc(&(udpSocket1)->base.object, sign_Mtbl_InterProcessComm) )->translateErrorMsg(&((udpSocket1)->base.object), success), _thCxt)
        , toString_StringBuilderJc(&(_tempString2_1)->base.object, _thCxt)
        ), 0, &_thCxt->stacktraceThreadContext, __LINE__); };
      activateGarbageCollectorAccess_BlockHeapJc(&_tempString2_1->base.object, null);
    }
    ythis->rxRun = true;
    start_ThreadJc(& ((ythis->rxThread).base.super), -1, _thCxt);
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void start_SendActValues(SendActValues_s* ythis, ThCxt* _thCxt)
{ Mtbl_SendActValues const* mtbl = (Mtbl_SendActValues const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_SendActValues);
  mtbl->start(ythis, _thCxt);
}


/**Writes the values in the buffer and sends the datagram, if sending is requested.*/
void write_SendActValues_F(SendActValues_s* ythis, struct OamVariables_t* oamVariables, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("write_SendActValues_F");
  
  { 
    int32 actSize; 
    
    
    actSize = getLengthTotal_ByteDataAccessJc(& ((ythis->datagram).base.super), _thCxt);
    ASSERT(/*static*/actSize - recordsize_SendActValues < ythis->valueBuffer.head.length);
    TRY
    { 
      
      addChild_ByteDataAccessJc(& ((ythis->datagram).base.super), & ((ythis->infoHead).base.super), _thCxt);
      addToAndSetBinData_OamVariablesByteAccess_OamVariables_F(& (ythis->oamVariableAccess), & ((ythis->infoHead).base.super), oamVariables, _thCxt);
      setInfoHead_Info_InspcDataExchangeAccess_Inspc(& (ythis->infoHead), getLength_ByteDataAccessJc(& ((ythis->infoHead).base.super), _thCxt), 0xaaaa, ++ythis->orderSend, _thCxt);
    }_TRY
    CATCH(IllegalArgumentException, exc)
    
      { 
        
        
      }
    END_TRY//do nothing, the buffer is enough.
    
    actSize = getLengthTotal_ByteDataAccessJc(& ((ythis->datagram).base.super), _thCxt);
    if(ythis->bSendReq) 
    { //:the last: send it.
      
      struct InterProcessComm_t* udpSocket1; 
      
      
      setLengthDatagram_Datagram_InspcDataExchangeAccess_Inspc(& (ythis->datagram), actSize, _thCxt);
      udpSocket1 = REFJc(ythis->udpSocket);
      ((Mtbl_InterProcessComm const*)getMtbl_ObjectJc(&(udpSocket1)->base.object, sign_Mtbl_InterProcessComm) )->send(&((udpSocket1)->base.object), buildFromArrayX_MemC(&((struct int8_Y_t*)(&( ythis->valueBuffer)))->head) , actSize, ((/*J2C:cast from Address_InterProcessComm_s*/Address_InterProcessComm_s*)(REFJc(ythis->dstAddress))));
      ythis->bSendReq = false;
      ythis->bSent = true;
    }
    if(actSize >= ythis->valueBuffer.head.length - recordsize_SendActValues || ythis->bSent) 
    { 
      
      ythis->bSent = false;
      TRY
      { 
        
        assignData_iYi_ByteDataAccessJc_F(& ((ythis->datagram).base.super), (struct int8_Y_t*)(&( ythis->valueBuffer)), 0, _thCxt);
      }_TRY
      CATCH(IllegalArgumentException, exc)
      
        { 
          
          
        }
      END_TRY//do nothing, the buffer is enough.
      
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void write_SendActValues(SendActValues_s* ythis, struct OamVariables_t* oamVariables, ThCxt* _thCxt)
{ Mtbl_SendActValues const* mtbl = (Mtbl_SendActValues const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_SendActValues);
  mtbl->write(ythis, oamVariables, _thCxt);
}


void finalize_SendActValues_F(ObjectJc* othis, ThCxt* _thCxt)
{ SendActValues_s* ythis = (SendActValues_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_SendActValues_F");
  finalize_ObjectJc_F(&ythis->oamVariableAccess.base.object, _thCxt); //J2C: finalizing the embedded instance.
  finalize_ObjectJc_F(&ythis->datagram.base.object, _thCxt); //J2C: finalizing the embedded instance.
  finalize_ObjectJc_F(&ythis->infoHead.base.object, _thCxt); //J2C: finalizing the embedded instance.
  CLEAR_REFJc(ythis->udpSocket);
  CLEAR_REFJc(ythis->dstAddress);
  finalize_ObjectJc_F(&ythis->rxThread.base.object, _thCxt); //J2C: finalizing the embedded instance.
  finalize_ObjectJc_F(&ythis->base.object, _thCxt); //J2C: finalizing the superclass.
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_SendActValues mtblSendActValues = {
{ { sign_Mtbl_SendActValues//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((2 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, start_SendActValues_F //start
, write_SendActValues_F //write
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_SendActValues_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_SendActValues_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_SendActValues_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_SendActValues, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_SendActValues_s;
extern struct ClassJc_t const reflection_Address_InterProcessComm_s;
extern struct ClassJc_t const reflection_C_rxThread_SendActValues_s;
extern struct ClassJc_t const reflection_Datagram_InspcDataExchangeAccess_Inspc_s;
extern struct ClassJc_t const reflection_Info_InspcDataExchangeAccess_Inspc_s;
extern struct ClassJc_t const reflection_InterProcessComm_i;
extern struct ClassJc_t const reflection_OamVariablesByteAccess_OamVariables_s;
const struct Reflection_Fields_SendActValues_s_t
{ ObjectArrayJc head; FieldJc data[12];
} reflection_Fields_SendActValues_s =
{ CONST_ObjectArrayJc(FieldJc, 12, OBJTYPE_FieldJc, null, &reflection_Fields_SendActValues_s)
, {
     { "oamVariableAccess"
    , 0 //nrofArrayElements
    , &reflection_OamVariablesByteAccess_OamVariables_s
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->oamVariableAccess) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "rxRun"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->rxRun) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "bSendReq"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->bSendReq) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "bSent"
    , 0 //nrofArrayElements
    , REFLECTION_bool
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->bSent) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "orderSend"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->orderSend) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "valueBuffer"
    , 1400 //nrofArrayElements
    , REFLECTION_int8
    , 1 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc |kEmbeddedContainer_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->valueBuffer) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "datagram"
    , 0 //nrofArrayElements
    , &reflection_Datagram_InspcDataExchangeAccess_Inspc_s
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->datagram) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "infoHead"
    , 0 //nrofArrayElements
    , &reflection_Info_InspcDataExchangeAccess_Inspc_s
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->infoHead) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "udpSocket"
    , 0 //nrofArrayElements
    , &reflection_InterProcessComm_i
    , kEnhancedReference_Modifier_reflectJc /*@*/ //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->udpSocket) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "dstAddress"
    , 0 //nrofArrayElements
    , &reflection_Address_InterProcessComm_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ |mObjectJc_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->dstAddress) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "rxThread"
    , 0 //nrofArrayElements
    , &reflection_C_rxThread_SendActValues_s
    , kEmbedded_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((SendActValues_s*)(0x1000))->rxThread) - (int32)(SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_SendActValues_s
    }
   , { "recordsize"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc |mSTATIC_Modifier_reflectJc //bitModifiers
    , 0 //compiler problem, not a constant,TODO: (int16)(&recordsize_SendActValues) //lo part of memory address of static member
    , 0 //compiler problem, not a constant,TODO: (int16)((int32)(&recordsize_SendActValues)>>16) //hi part of memory address of static member instead offsetToObjectifcBase, TRICKY because compatibilty.
    , &reflection_SendActValues_s
    }
} };
const ClassJc reflection_SendActValues_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "SendActValues_s"
,  0 //position of ObjectJc
, sizeof(SendActValues_s)
, (FieldJcArray const*)&reflection_Fields_SendActValues_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_SendActValues_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblSendActValues.mtbl.head
};


const char sign_Mtbl_C_rxThread_SendActValues[] = "C_rxThread_SendActValues"; //to mark method tables of all implementations

typedef struct MtblDef_C_rxThread_SendActValues_t { Mtbl_C_rxThread_SendActValues mtbl; MtblHeadJc end; } MtblDef_C_rxThread_SendActValues;
 extern MtblDef_C_rxThread_SendActValues const mtblC_rxThread_SendActValues;

/**Run-method to receive*/
void run_C_rxThread_SendActValues_F(ObjectJc* ithis, ThCxt* _thCxt)
{ C_rxThread_SendActValues_s* ythis = (C_rxThread_SendActValues_s*)ithis;
  
  STACKTRC_TENTRY("run_C_rxThread_SendActValues_F");
  
  { 
    struct InterProcessComm_t* udpSocket1; 
    
    
    udpSocket1 = REFJc(ythis->outer->udpSocket);
    
    while(ythis->outer->rxRun)
      { 
        int32 success; 
        
        
        ythis->nrofBytes[0] = 0;
        ((Mtbl_InterProcessComm const*)getMtbl_ObjectJc(&(udpSocket1)->base.object, sign_Mtbl_InterProcessComm) )->receiveData(&((udpSocket1)->base.object), &ythis->nrofBytes[0], buildFromArrayX_MemC(&((struct int8_Y_t*)(&( ythis->rxBuffer)))->head) , ((/*J2C:cast from Address_InterProcessComm_s*/Address_InterProcessComm_s*)(REFJc(ythis->outer->dstAddress))));////
        
        success = ythis->nrofBytes[0];
        if(success >= 0) 
        { 
          
          ythis->outer->bSendReq = true;//bSent = false;
          
        }
      }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
void run_C_rxThread_SendActValues(ObjectJc* ithis, ThCxt* _thCxt)
{ Mtbl_RunnableJc const* mtbl = (Mtbl_RunnableJc const*)getMtbl_ObjectJc(ithis, sign_Mtbl_RunnableJc);
  mtbl->run(ithis, _thCxt);
}


/*Constructor *//**J2C: autogenerated as default constructor. */
struct C_rxThread_SendActValues_t* ctorO_C_rxThread_SendActValues(struct SendActValues_t* outer, ObjectJc* othis, ThCxt* _thCxt)
{ C_rxThread_SendActValues_s* ythis = (C_rxThread_SendActValues_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_C_rxThread_SendActValues");
  checkConsistence_ObjectJc(othis, sizeof(C_rxThread_SendActValues_s), null, _thCxt);  
  //J2C:super Constructor
  ctorO_ThreadJc(&ythis->base.object, _thCxt);
  setReflection_ObjectJc(othis, &reflection_C_rxThread_SendActValues_s, sizeof(C_rxThread_SendActValues_s));  
  ythis->outer = outer;
  //j2c: Initialize all class variables:
  {
    init0_MemC(build_MemC(&ythis->nrofBytes, 1 * sizeof(int32))); //J2C: init the embedded simple array;
    /*J2C: newArray*/
      init_ObjectJc(&ythis->rxBuffer.head.object, sizeof_ARRAYJc(int8, 100), 0);   //J2C: ctor embedded array.
      ctorO_ObjectArrayJc(&ythis->rxBuffer.head.object, 100, sizeof(int8), null, 0);//J2C: constructor for embedded array;
  }/*J2C:No body for constructor*/

  STACKTRC_LEAVE;
  return ythis;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_C_rxThread_SendActValues mtblC_rxThread_SendActValues = {
{ { sign_Mtbl_C_rxThread_SendActValues//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((0 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, { { sign_Mtbl_ThreadJc//J2C: Head of methodtable.
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
    /**J2C: Mtbl-interfaces of C_rxThread_SendActValues: */
  , { { sign_Mtbl_RunnableJc//J2C: Head of methodtable.
      , (struct Size_Mtbl_t*)((1 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
      }
    , run_C_rxThread_SendActValues_F //run
    , { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
        , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
        }
      , clone_ObjectJc_F //clone
      , equals_ObjectJc_F //equals
      , finalize_ObjectJc_F //finalize
      , hashCode_ObjectJc_F //hashCode
      , toString_ObjectJc_F //toString
      }
    }
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ThreadJc_s;
 static struct superClasses_C_rxThread_SendActValues_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_C_rxThread_SendActValues_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ThreadJc_s, OFFSET_Mtbl(Mtbl_C_rxThread_SendActValues, ThreadJc) }
   }
 };

extern struct ClassJc_t const reflection_C_rxThread_SendActValues_s;
extern struct ClassJc_t const reflection_Address_InterProcessComm_s;
extern struct ClassJc_t const reflection_C_rxThread_SendActValues_s;
extern struct ClassJc_t const reflection_Datagram_InspcDataExchangeAccess_Inspc_s;
extern struct ClassJc_t const reflection_Info_InspcDataExchangeAccess_Inspc_s;
extern struct ClassJc_t const reflection_InterProcessComm_i;
extern struct ClassJc_t const reflection_OamVariablesByteAccess_OamVariables_s;
const struct Reflection_Fields_C_rxThread_SendActValues_s_t
{ ObjectArrayJc head; FieldJc data[2];
} reflection_Fields_C_rxThread_SendActValues_s =
{ CONST_ObjectArrayJc(FieldJc, 2, OBJTYPE_FieldJc, null, &reflection_Fields_C_rxThread_SendActValues_s)
, {
     { "nrofBytes"
    , 1 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((C_rxThread_SendActValues_s*)(0x1000))->nrofBytes) - (int32)(C_rxThread_SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_C_rxThread_SendActValues_s
    }
   , { "rxBuffer"
    , 100 //nrofArrayElements
    , REFLECTION_int8
    , 1 << kBitPrimitiv_Modifier_reflectJc |kStaticArray_Modifier_reflectJc |kEmbeddedContainer_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((C_rxThread_SendActValues_s*)(0x1000))->rxBuffer) - (int32)(C_rxThread_SendActValues_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_C_rxThread_SendActValues_s
    }
} };
const ClassJc reflection_C_rxThread_SendActValues_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "C_rxThread_SendActValues_s"
,  0 //position of ObjectJc
, sizeof(C_rxThread_SendActValues_s)
, (FieldJcArray const*)&reflection_Fields_C_rxThread_SendActValues_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_C_rxThread_SendActValues_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblC_rxThread_SendActValues.mtbl.head
};
