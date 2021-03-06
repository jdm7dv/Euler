/************************************************************************************************
 * Copyright/Copyleft:
 *
 * For this source the LGPL Lesser General Public License,
 * published by the Free Software Foundation is valid.
 * It means:
 * 1) You can use this source without any restriction for any desired purpose.
 * 2) You can redistribute copies of this source to everybody.
 * 3) Every user of this source, also the user of redistribute copies
 *    with or without payment, must accept this license for further using.
 * 4) But the LPGL ist not appropriate for a whole software product,
 *    if this source is only a part of them. It means, the user
 *    must publish this part of source,
 *    but don't need to publish the whole source of the own product.
 * 5) You can study and modify (improve) this source
 *    for own using or for redistribution, but you have to license the
 *    modified sources likewise under this LGPL Lesser General Public License.
 *    You mustn't delete this Copyright/Copyleft inscription in this source file.
 *
 * This source may be used also with another licence, if the author 
 * and all other here named co-authors have agreed to this contract.
 * Especially a company can use a copy of this sources in its products without publishing.
 * The user should have a underwritten contract therefore.
 *
 * @author Hartmut Schorrig, Germany, Pinzberg, www.vishia.org
 *
 **copyright***************************************************************************************
 *
 * @content Conversion routines from numeric values to Strings and revers
 *
 * @version 0.92
 * list of changes:
 * 2010-04-22: Hartmut creation as extra file from given routines in StringBufferJc.
 *
 ****************************************************************************/

#include <Jc/ObjectJc.h>


int32 floatToRawIntBits_FloatJc(float val)
{ return *(int32*)&val;  //returns the bit representation in memory.
}


int32 floatToIntBits_FloatJc(float val)
{ int32 bits = *(int32*)&val;  //gets the bit representation in memory.
  //TODO check some NAN representations
  return bits;
}


float intBitsToFloat_FloatJc(int32 val)
{
  return *(float*)&val;   //returns the bit representation in memory.
}




int64 doubleToLongBits_DoubleJc(double val)
{ return *(int64*)&val;  //returns the bit representation in memory.
}


int64 doubleToRawLongBits_DoubleJc(double val)
{ int64 bits = *(int64*)&val;  //gets the bit representation in memory.
  //TODO check some NAN representations
  return bits;
}


double longBitsToDouble_DoubleJc(int64 val)
{
  return *(double*)&val;   //returns the bit representation in memory.
}
