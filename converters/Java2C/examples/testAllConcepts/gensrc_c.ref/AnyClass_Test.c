/**************************************************************************
 * This file is generated by Java2C
 **copyright***************************************************************
 *************************************************************************/
#include "AnyClass_Test.h"
#include <string.h>  //because using memset()
#include <Jc/ReflectionJc.h>   //Reflection concept 
#include <Fwc/fw_Exception.h>  //basic stacktrace concept


const char sign_Mtbl_AnyClass_Test[] = "AnyClass_Test"; //to mark method tables of all implementations

typedef struct MtblDef_AnyClass_Test_t { Mtbl_AnyClass_Test mtbl; MtblHeadJc end; } MtblDef_AnyClass_Test;
 extern MtblDef_AnyClass_Test const mtblAnyClass_Test;

/*Constructor */
struct AnyClass_Test_t* ctorO_AnyClass_Test(ObjectJc* othis, struct ImplIfcTest_t* ref, ThCxt* _thCxt)
{ AnyClass_Test_s* ythis = (AnyClass_Test_s*)othis;  //upcasting to the real class.
  STACKTRC_TENTRY("ctorO_AnyClass_Test");
  checkConsistence_ObjectJc(othis, sizeof(AnyClass_Test_s), null, _thCxt);  
  setReflection_ObjectJc(othis, &reflection_AnyClass_Test_s, sizeof(AnyClass_Test_s));  
  //j2c: Initialize all class variables:
  {
    ythis->x1 = 5;
  }
  { 
    
    SETREFJc(ythis->ref, ref, ImplIfcTest_s);
  }
  STACKTRC_LEAVE;
  return ythis;
}



/**Any final method to call. */
int32 addValue_AnyClass_Test(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("addValue_AnyClass_Test");
  
  { 
    
    ythis->x1 += value;
    { STACKTRC_LEAVE;
      return ythis->x1;
    }
  }
  STACKTRC_LEAVE;
}


/**Any override-able method to call. */
int32 addValueOverrideable_AnyClass_Test_F(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("addValueOverrideable_AnyClass_Test_F");
  
  { 
    
    ythis->x1 += value;
    { STACKTRC_LEAVE;
      return ythis->x1;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
int32 addValueOverrideable_AnyClass_Test(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ Mtbl_AnyClass_Test const* mtbl = (Mtbl_AnyClass_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_AnyClass_Test);
  return mtbl->addValueOverrideable(ythis, value, _thCxt);
}


/**Returns itself (this)*/
struct AnyClass_Test_t* returnThis_AnyClass_Test(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("returnThis_AnyClass_Test");
  
  { 
    
    ythis->x1 += value;
    { STACKTRC_LEAVE;
      return ythis;
    }
  }
  STACKTRC_LEAVE;
}


/**Returns itself (this), but the method is able to override*/
struct AnyClass_Test_t* returnThisOverrideable_AnyClass_Test_F(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("returnThisOverrideable_AnyClass_Test_F");
  
  { 
    
    ythis->x1 += value;
    { STACKTRC_LEAVE;
      return ythis;
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct AnyClass_Test_t* returnThisOverrideable_AnyClass_Test(AnyClass_Test_s* ythis, int32 value, ThCxt* _thCxt)
{ Mtbl_AnyClass_Test const* mtbl = (Mtbl_AnyClass_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_AnyClass_Test);
  return mtbl->returnThisOverrideable(ythis, value, _thCxt);
}


/**Returns any other instance.*/
struct ImplIfcTest_t* returnRef_AnyClass_Test(AnyClass_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("returnRef_AnyClass_Test");
  
  { 
    
    { STACKTRC_LEAVE;
      return REFJc(ythis->ref);
    }
  }
  STACKTRC_LEAVE;
}


/**Returns any other instance, but this method is able to override, non final.*/
struct ImplIfcTest_t* returnRefOverrideable_AnyClass_Test_F(AnyClass_Test_s* ythis, ThCxt* _thCxt)
{ 
  STACKTRC_TENTRY("returnRefOverrideable_AnyClass_Test_F");
  
  { 
    
    { STACKTRC_LEAVE;
      return REFJc(ythis->ref);
    }
  }
  STACKTRC_LEAVE;
}

/*J2C: dynamic call variant of the override-able method: */
struct ImplIfcTest_t* returnRefOverrideable_AnyClass_Test(AnyClass_Test_s* ythis, ThCxt* _thCxt)
{ Mtbl_AnyClass_Test const* mtbl = (Mtbl_AnyClass_Test const*)getMtbl_ObjectJc(&ythis->base.object, sign_Mtbl_AnyClass_Test);
  return mtbl->returnRefOverrideable(ythis, _thCxt);
}


void finalize_AnyClass_Test_F(ObjectJc* othis, ThCxt* _thCxt)
{ AnyClass_Test_s* ythis = (AnyClass_Test_s*)othis;  //upcasting to the real class.
 STACKTRC_TENTRY("finalize_AnyClass_Test_F");
  CLEAR_REFJc(ythis->ref);
  finalize_ObjectJc_F(&ythis->base.object, _thCxt); //J2C: finalizing the superclass.
  STACKTRC_LEAVE;
}




/**J2C: Reflections and Method-table *************************************************/
const MtblDef_AnyClass_Test mtblAnyClass_Test = {
{ { sign_Mtbl_AnyClass_Test//J2C: Head of methodtable.
  , (struct Size_Mtbl_t*)((3 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
  }
, addValueOverrideable_AnyClass_Test_F //addValueOverrideable
, returnThisOverrideable_AnyClass_Test_F //returnThisOverrideable
, returnRefOverrideable_AnyClass_Test_F //returnRefOverrideable
, { { sign_Mtbl_ObjectJc//J2C: Head of methodtable.
    , (struct Size_Mtbl_t*)((5 +2) * sizeof(void*)) //size. NOTE: all elements are standard-pointer-types.
    }
  , clone_ObjectJc_F //clone
  , equals_ObjectJc_F //equals
  , finalize_AnyClass_Test_F //finalize
  , hashCode_ObjectJc_F //hashCode
  , toString_ObjectJc_F //toString
  }
}, { signEnd_Mtbl_ObjectJc, null } }; //Mtbl


 extern struct ClassJc_t const reflection_ObjectJc;
 static struct superClasses_AnyClass_Test_s_t
 { ObjectArrayJc head;
   ClassOffset_idxMtblJc data[1];
 }superclasses_AnyClass_Test_s =
 { CONST_ObjectArrayJc(ClassOffset_idxMtblJc, 1, OBJTYPE_ClassOffset_idxMtblJc, null, null)
 , { {&reflection_ObjectJc, OFFSET_Mtbl(Mtbl_AnyClass_Test, ObjectJc) }
   }
 };

extern struct ClassJc_t const reflection_AnyClass_Test_s;
extern struct ClassJc_t const reflection_ImplIfcTest_s;
const struct Reflection_Fields_AnyClass_Test_s_t
{ ObjectArrayJc head; FieldJc data[2];
} reflection_Fields_AnyClass_Test_s =
{ CONST_ObjectArrayJc(FieldJc, 2, OBJTYPE_FieldJc, null, &reflection_Fields_AnyClass_Test_s)
, {
     { "x1"
    , 0 //nrofArrayElements
    , REFLECTION_int32
    , 4 << kBitPrimitiv_Modifier_reflectJc //bitModifiers
    , (int16)((int32)(&((AnyClass_Test_s*)(0x1000))->x1) - (int32)(AnyClass_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_AnyClass_Test_s
    }
   , { "ref"
    , 0 //nrofArrayElements
    , &reflection_ImplIfcTest_s
    , kEnhancedReference_Modifier_reflectJc /*@*/ //bitModifiers
    , (int16)((int32)(&((AnyClass_Test_s*)(0x1000))->ref) - (int32)(AnyClass_Test_s*)0x1000)
    , 0  //offsetToObjectifcBase
    , &reflection_AnyClass_Test_s
    }
} };
const ClassJc reflection_AnyClass_Test_s = 
{ CONST_ObjectJc(OBJTYPE_ClassJc + sizeof(ClassJc), &reflection_ObjectJc, &reflection_ClassJc) 
, "AnyClass_Test_s"
,  0 //position of ObjectJc
, sizeof(AnyClass_Test_s)
, (FieldJcArray const*)&reflection_Fields_AnyClass_Test_s
, null //method
, (ClassOffset_idxMtblJcARRAY*)&superclasses_AnyClass_Test_s //superclass
, null //interfaces
, 0    //modifiers
, &mtblAnyClass_Test.mtbl.head
};
