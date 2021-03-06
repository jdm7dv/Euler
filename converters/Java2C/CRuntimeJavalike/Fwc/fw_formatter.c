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
 * @version 0.83
 * @list of changes:
 * 2010-06-27: regarding time-conversions
 * 2010-06-27: typeCv-char for normal text is '$' now instead 't'
 * 2009-09-00: 
 *   bug: parsePrinfStyleString_fwFormatter: There was an overflow in the dst array, only if some more arguments are parsed.
 *   fix: The array is increased, the array borders are checked.
 * 2008-10-00: Hartmut Schorrig creation
 *
 * @author  Hartmut Schorrig www.vishia.org
 * @content Some routines to convert several data to string representation
 *          at low C-level, able to use without any other complex library concepts
 * @dependencies: libOSAL concept.
 * @note:   The macros STACKTRC_... may be defined in a simple way, 
 *          if the stacktrace-exception handling won't be use.
 *
 ****************************************************************************/

#include "fw_Formatter.h"
//#include "fw_Exception.h"       //STACKTRC_...
#include "fw_SimpleC.h"         //ARRAYLEN
#include "fw_Exception.h"
//#include "fw_ThreadContext.h"   //os_getCurrentStacktraceThreadContext()
#include <string.h>             //strchr(), strlen(), memset()


char const typedVaArg_VaArgBuffer[] = "typedVariableArgumentList_ObjectJc";

/*
void ctor_TimeYearSecond_Formatter_FW(TimeYearSecond_Formatter_FW* dst, int32 seconds, int baseyear, int32 offsetJan, bool GPS)
{
  int32 nYear4;  //NOTE: nDays is max 0xC22E, it should be either uint16 or int32.
  int nBaseYear = 1970;
  
  int nHour, nMinute, nSec;
  int nYear; 
  int32 nDays;  //NOTE: nDays is max 0xC22E, it should be either uint16 or int32.
  int nMonth;

  STACKTRC_ENTRY("ctor_TimeYearSecond_Formatter_FW");
  //NO, do not intialize! init0p_MemC(buffer, sizeBuffer); 

  //convert the  continuously counting seconds in year .. second:
  //

  { static const uint16 aMonth[]    ={31,28,31,30,31,30,31,31,30,31,30,31};
    static const uint16 aMonthSkip[]={31,29,31,30,31,30,31,31,30,31,30,31};
    const uint16* pDayOfMonth;
    
    //Millesekunden des Tages
    nDays  =(seconds/(24L*3600L));  //volle Tage
    nSec = seconds - nDays*(24L*3600L);

    nDays -= ((nBaseYear%4)+1)*365+1;  //Bezug auf 1.1. nach 1. Schaltjahr Bezug auf 1.1.1973, wenn 1970 das Baseyear ist. 
                                    //Hinweis: vor 1973 erfolgt falsche Darstellung
    nYear4 = (int16)(nDays/(4*365+1));         //Anzahl volle 4 Jahre
    nDays -= nYear4*(4*365+1);        //verbleibt Restzeit nach Schaltjahr
    nYear = (int16)(nDays/365);                //volle Jahre nach Schaltjahr
    if(nYear == 4)
    { //at last day, dec 31 of the last year, what is a sleep year, the nrof days = 1460 = 3*365 + 366 -1;  
      nYear = 3;  //That are 3 years of a period with 3 non-sleep year and the sleep year, not 4! 
    }
    nDays-=nYear*365;               //verbleibende Tage im Jahr

    nMonth=0;                       //zun"chst Index auf aMonth
    pDayOfMonth=aMonth;
    if(nYear==3) pDayOfMonth=aMonthSkip; //Schaltjahrestabelle
    while(nDays>=pDayOfMonth[nMonth])    //wenn zuviele Tage f?r Monat (1. Tag ab 0)
    { nDays-=pDayOfMonth[nMonth];        //dann diese subtr.
      nMonth++;                          //und index incr.
    }
    nMonth+=(uint8)(1);                           //+1 da Index ab 0 war
    nDays+=(uint8)(1);                            //+1 da Anzahl Tage im Monat ab 0 war
    nYear+=(short)
           ( ((nBaseYear+3)/4)*4 +1      //1. Jahr nach Schaltjahr nach baseyear
             +4*nYear4);                 //Jahre absolut nach  Christi Geburt


    { nHour=nSec/3600L; nSec-=3600L*nHour;
      nMinute=nSec/60L;  nSec-=60L*nMinute;
    }
  }
  dst->year = nYear;
  dst->month = (int8)nMonth;
  dst->weekInYear = 0; //TODO
  dst->dayOfWeek = 0; //TODO;
  dst->day = (int8)nDays;
  dst->hour = (int8)nHour;
  dst->minute = (int8)nMinute;
  dst->sec = (int8)nSec;
  
  STACKTRC_LEAVE;
}

*/


int toStringFormat_Fw(char* buffer, int sizeBuffer, OS_TimeStamp const* time, char const* sFormat, int timeZoneAdjustHours)
{
  int lenFormat = strlen(sFormat);
  TimeBytes_Fwc timeYsec;
  int maxPosBuffer = sizeBuffer;
  int posBuffer = 0;
  int nHour, nMonth;
  int32 nanos = time->time_nsec;
  STACKTRC_ENTRY("toStringFormat_DateFw");
  ctor_TimeBytes_Fwc(&timeYsec, seconds_OS_TimeStamp(*time), 1970, 0, isGPS_OS_TimeStamp(*time));

  { static const char* sMonthsFull[12] = {"January", "February", "March", "April", "May", "June"
                       , "July", "August", "September", "October", "November", "December"};
    static const char* sMonthsShort[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun"
                       , "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char sprintfBuffer[8];  //no more as 4 digits, but respect 4-byte-boundary
    nHour = timeYsec.hour;
    nMonth = timeYsec.month;
    while(lenFormat > 0)
    { //read and increment, decrement lenFormat
      char cFormat = *sFormat;
      int lenFormatToken = 1;
      sFormat +=1;
      lenFormat -=1;

      //detect number of equal chars one after another.
      while(lenFormat > 0 && *sFormat == cFormat)
      { lenFormatToken +=1;
        sFormat +=1;
        lenFormat -=1;
      }

      switch(cFormat)
      {
        case 'Y':
        case 'y':
        { int nYear = timeYsec.year;
          char const* format;
          if(lenFormatToken >=4)
          { //append_i_StringBufferJc(&buffer, nYear);
            format = "%4.4i";
          }
          else if(lenFormatToken >=2)
          { nYear -= 2000;
            if(nYear < 0) { nYear += 100; }
            if(nYear >= 100) { nYear -= 100; }
            //if(nYear < 10)
            { //append_c_StringBufferJc(&buffer, '0');
            }
            format = "%2.2i";
          }
          else
          { format = null;
          }
          if(format != null)
          { 
            int nrofChars = sprintf(sprintfBuffer, format, nYear);
            if(nrofChars > (maxPosBuffer - posBuffer))
            { nrofChars = maxPosBuffer - posBuffer; //truncate it.
            }
            memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
            posBuffer += nrofChars;
          }  
        } break;
        case 'M':
        { if(lenFormatToken >3)
          { int nrofChars = strlen(sMonthsFull[nMonth-1]);
            if(nrofChars > (maxPosBuffer - posBuffer))
            { nrofChars = maxPosBuffer - posBuffer; //truncate it.
            }
            memcpy(buffer+posBuffer, sMonthsFull[nMonth-1], nrofChars);
            posBuffer += nrofChars;
          }
          else if(lenFormatToken ==3)
          { int nrofChars = strlen(sMonthsShort[nMonth-1]);
            if(nrofChars > (maxPosBuffer - posBuffer))
            { nrofChars = maxPosBuffer - posBuffer; //truncate it.
            }
            memcpy(buffer+posBuffer, sMonthsShort[nMonth-1], nrofChars);
            posBuffer += nrofChars;
          }
          else
          {
            int nrofChars = sprintf(sprintfBuffer, "%2.2i", nMonth);
            if(nrofChars > (maxPosBuffer - posBuffer))
            { nrofChars = maxPosBuffer - posBuffer; //truncate it.
            }
            memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
            posBuffer += nrofChars;
          }
        } break;
        case 'd':
        { int nrofChars = sprintf(sprintfBuffer, "%2.2i", (int)timeYsec.day);
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 'H': 
        case 'h':  //temporary: convert h like H because application errors exists.
        { int nrofChars = sprintf(sprintfBuffer, "%2.2i", nHour);
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 'a':  //am/pm-Marker
        { const char* sAmPm = nHour >=12 ? "PM" : "AM";
          int nrofChars = 2;
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sAmPm, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 'K':  //hour from 1 to 12
        { int nrofChars = sprintf(sprintfBuffer, "%2.2i", (int)(nHour >=12 ? nHour-11 : nHour+1));
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 'm':
        { int nrofChars = sprintf(sprintfBuffer, "%2.2i", (int)timeYsec.minute);
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 's':
        { int nrofChars = sprintf(sprintfBuffer, "%2.2i", (int)timeYsec.sec);
          if(nrofChars > (maxPosBuffer - posBuffer))
          { nrofChars = maxPosBuffer - posBuffer; //truncate it.
          }
          memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
          posBuffer += nrofChars;
        } break;
        case 'S':  //millisecond
        { const char* format;
          int millisec = (int)(nanos/1000000L); 
          if(millisec < 0){ millisec +=1000; }
          switch(lenFormatToken)
          { case 1: format = "%1.1u"; millisec /= 100; break;
            case 2: format = "%2.2u"; millisec /= 10; break;
            default: format = "%3.3u"; break;
          }
          { int nrofChars = sprintf(sprintfBuffer, format, millisec);
            if(nrofChars > (maxPosBuffer - posBuffer))
            { nrofChars = maxPosBuffer - posBuffer; //truncate it.
            }
            memcpy(buffer+posBuffer, sprintfBuffer, nrofChars);
            posBuffer += nrofChars;
          }
        } break;
        default:
        { //transform the character itself.
          while(--lenFormatToken >=0 && posBuffer < maxPosBuffer)
          { buffer[posBuffer++] = cFormat;
          }
        }
      }
      ASSERT(posBuffer <= maxPosBuffer);  //detect errors.
    }
    //NO! The buffer may be a part of a string! buffer[posBuffer] = 0;    
  }
  STACKTRC_LEAVE; return posBuffer;
}




int parsePrinfStyleString_fwFormatter(ParseResultPrintfStyle_fwFormatter* dst, int zDst, char const* src, int* zSrc)
{ //int iDst = 0;
  int retError = 0;
  char const* sTextEnd = src + *zSrc;  //exclusive end
  ParseResultPrintfStyle_fwFormatter* dstAct = dst;
  ParseResultPrintfStyle_fwFormatter* dstMax = dst + zDst; //exclusive end address
  char const* sText1 = src;
  STACKTRC_ENTRY("parsePrinfStyleString_fw_Formatter");
  memset(dst,0, zDst * sizeof(*dst));  //clear all content
  while(sText1 < sTextEnd && dstAct < dstMax)
  { if(*sText1 != '%')
    { const char* sText2;
      sText2 = strchr(sText1, '%');
      if(sText2 == null)
      { sText2 = sTextEnd; //use string to its end.
      }
      if(dstAct < dstMax && sText2 > sText1)
      { //any text from actual position to found '%' or to end.
        dstAct->text.text = sText1;
        dstAct->text.nrofChars = sText2 - sText1;
        dstAct->text.specifier = '$'; 
        dstAct +=1;       //next array element.
        sText1 = sText2;  //continue after it.
      }
    }
    if(sText1 < sTextEnd)
    { //'%' found
      int nr = 0;
      int nrofChars2 = 0;
      char const* pos;
      char flag = 0;
      char lengthModifier = 0;
      char cFormat;
      
      if(dstAct >= dstMax)
      { //THROW_s0(IndexOutOfBoundsException, "to many %-chars (arguments) in text, 2*max=", zDst); 
      }
      ASSERT(dstAct < dstMax);
      sText1 +=1;   //skip over '%'
      cFormat = *(sText1++);
      while(cFormat >= '0' && cFormat <= '9')
      { nr = 10 * nr + (cFormat - '0');
        cFormat = *(sText1++);
      }
      if(cFormat == '$')
      { //the argument index:
        dstAct->value.indexArg = nr;
        cFormat = *(sText1++);
        //The width may be following:
        nr = 0;
      }
      if(cFormat == '<')
      { dstAct->value.indexArg = -1; //use the last 
        cFormat = *(sText1++);
      }
      while(cFormat >= '0' && cFormat <= '9')
      { nr = 10 * nr + (cFormat - '0');
        cFormat = *(sText1++);
      }
      pos = strchr("-+ #0", cFormat);   //test of flags
      if(pos != null)
      { flag = cFormat;
        cFormat = *sText1++;
      }
      dstAct->value.width = nr;  //0 if the argument isn't given.
      if(cFormat == '.')
      { //precision
        cFormat = *sText1++;
        while(cFormat >= '0' && cFormat <= '9')
        { nrofChars2 = 10 * nrofChars2 + (cFormat - '0');
          cFormat = *sText1++;
        }
        dstAct->value.precision = nrofChars2;
      }
      pos = strchr("lL", cFormat);  //chg: the short control chars from C are absolte.
      if(pos != null)
      { lengthModifier = cFormat;
        cFormat = *sText1++;
      }
      dstAct->value.specifier = cFormat;
      if(cFormat == 't'){
        char timeSpecifier = *sText1;
        if(strchr("HIklMSLNpzZsQBbhAaCYyjmdeRTrDFc", timeSpecifier) !=null){
          ++sText1; 
          dstAct->value.timeSpecifier = timeSpecifier;
        } else {
          dstAct->value.timeSpecifier = '?';
        }  
      }
      //The conclusion from the format specifier to the type of argument 
      //is a property from C-printf. It supports some applications without argument char designation.
      switch(cFormat)  
      { case 'c': dstAct->value.argument = 'C'; break;  //char
        case 's': dstAct->value.argument = 'z'; break;  //const char*
        case 'd': //int, short, long
        case 'x':
        case 'X':
        case 'o':
        case 'u':
        case 'i': 
        { dstAct->value.argument = lengthModifier == 'h' ? 'S' : lengthModifier == 'l' ? 'J' : 'I'; 
          if(cFormat != 'u')
          { //the precision is designated negativ, if a negativ value should be displayed, see toString_Integer_FW(...)
            dstAct->value.precision = - dstAct->value.precision;
            if( dstAct->value.precision == 0)
            { dstAct->value.precision = -1;  //the minimum of characters for number.
            }
          }
        } break;
        case 'e': //float, double
        case 'E':
        case 'f':
        case 'g':
        case 'G': 
        { //NOTE: it is always an double, no possiblility of float.
          //The variables in the argument list are converted to double automatically.
          //long double is not supported yet.
          dstAct->value.argument = lengthModifier == 'L' ? 'D' : 'D'; 
        } break;
        case 'p': dstAct->value.argument = 'P'; dstAct->value.width = 8; dstAct->value.precision = 8; break;
        case 'n': dstAct->value.argument = 'N'; break;
        case '%': dstAct->value.argument = '%'; break;
        default: dstAct->value.argument = '?';
      }
      dstAct +=1;  //next array element.
    }

  }
  *zSrc = sText1 - src; //number of chars proceed.
  STACKTRC_LEAVE; return retError < 0 ? retError : dstAct - dst;
}



/**Returns a string of argument types from given printf-style-string. 
 * This method is necessary especially for routines which processed variable arguments in a special way,
 * but don't use the printf-style format string.
 * @param typeArgs a char[..] to affiliate the type chars.
 * @param zTypeArgs lenght of the char[...]
 * @param text the text containing the type characters in the printf-style.  
 * @return number of type args chars.
 */ 
int detectTypeArgs_fwFormatter(char* typeArgs, int zTypeArgs, StringJc text)
{
  /**The types are not given in the argument list, than parse the text to get that informations,
   * write first in the same text form as possible given in typeArgs, to handle in same way: */
  ParseResultPrintfStyle_fwFormatter parseResult[22]; //NOTE: regard parse Results as text between the values.
  int zText;
  char const* sText = getCharsAndLength_StringJc(&text, &zText);
  int nrofArgs = parsePrinfStyleString_fwFormatter(parseResult, ARRAYLEN(parseResult), sText, &zText);
  int ii =0; int jj =0; 
  while( ii < nrofArgs && jj < zTypeArgs)
  { if(parseResult[ii].value.specifier != '$')
    {
      typeArgs[jj++] = parseResult[ii++].value.argument; 
    }
    else{ ii+=1; }
  }
  if(jj < zTypeArgs){ typeArgs[jj]= 0; } //terminate with 0. 
  return jj; 
}




/** found an algorithm unusing division, because some divisions may be expensive in time
  * at some processors.
*/
int toString_Integer_FW(char* buffer, int zBuffer, int32 value, int radix, int minNrofCharsAndNegative, ThCxt* _thCxt)
{ char cc;
  /**Array of values to test the position in digit. Fill it with 10, 100 etc if radix = 10;*/
  uint32 testValues[32]; //max 32
  uint32 uvalue; 

  int idxTestValues = 0;
  int nChars = 0;
  int minNrofChars;
  STACKTRC_TENTRY("insert_i_StringBufferJc");
  if(minNrofCharsAndNegative < 0 && value < 0)
  { uvalue = -value; //may be -0x80000000
    buffer[nChars++] = '-';
  }
  else
  { uvalue = value;
  }
  minNrofChars = minNrofCharsAndNegative < 0 ?  -minNrofCharsAndNegative : minNrofCharsAndNegative;
  //
  { //fill in digigts to detect positions in digit
    uint32 powerRadix = radix;
    uint32 powerRadixLast = 0;
    while(  uvalue >= powerRadix 
         && powerRadix > powerRadixLast  //prevent overflow.
         )
    { testValues[idxTestValues++] = powerRadix;
      powerRadixLast = powerRadix;
      powerRadix *= radix;
    }
  }
  //
  //idxTestValues is the number of digits -1, because testValues[0] contains 10.  
  { int nrofZero = minNrofChars - idxTestValues -1;
    while(--nrofZero >=0 && nChars < zBuffer) buffer[nChars++] = '0';
  }
  //test input digit
  { uint32 test;
    while(--idxTestValues >=0  && nChars < zBuffer)
    { cc = '0';
      test =testValues[idxTestValues];
      while(uvalue >= test)
      { cc += 1;
        uvalue -= test;
      }
      if(cc > '9')
      { cc += ('a' - '9' -1);
      }
      buffer[nChars++] = cc;
    }
  }
  cc = (char)('0' + uvalue); //last digit
  if(cc > '9')
  { cc += ('a' - '9' -1);
  }
  if(nChars < zBuffer)
  { buffer[nChars++] = cc;
  }
  STACKTRC_LEAVE; return nChars;
}



int toString_Float_FW(char* buffer, int zBuffer, float value, char cFormat, int width, int precision, ThCxt* _thCxt)
{ int nrofChars;
  if(strchr("eEfGg", cFormat)!=null)
  { char format[6] = "%9.9f";
    format[1] = '0' + width;
    format[3] = '0' + precision;
    format[4] = cFormat;
    nrofChars = sprintf(buffer, format, value);  //TODO check zBuffer.
    
  }
  else
  { nrofChars = -1;
  }  
  return nrofChars;
}

int toString_Double_FW(char* buffer, int zBuffer, double value, char cFormat, int width, int precision, ThCxt* _thCxt)
{ int nrofChars;
  if(strchr("eEfGg", cFormat)!=null)
  { char format[20] = {0};
    sprintf(format, "%%%d.%d%c", width, precision, cFormat);
    nrofChars = sprintf(buffer, format, value);
  }
  else
  { nrofChars = -1;
  }  
  return nrofChars;
}



typedef struct char8_t { char s[ 8]; } char8;
typedef struct char16_t{ char s[16]; } char16;
typedef struct char24_t{ char s[24]; } char24;
typedef struct char32_t{ char s[32]; } char32;
typedef struct char40_t{ char s[40]; } char40;
typedef struct char48_t{ char s[48]; } char48;
typedef struct char56_t{ char s[56]; } char56;
typedef struct char64_t{ char s[64]; } char64;

//NOTE: The following type is a non-left-value-array by GNU Compiler.
//typedef char char8[8];

/**The maximum of arguments have to be limited because there is space in stack necessary.
 * That is because the order of arguments is not fix like printf. It is variable.
 * Therefore all arguments should be accessible simplify. 
 * The addresses of it and the type is hold in the stack. */
#define maxNrofArgs_Formatter_FW 20

int format_va_arg_Formatter_FW(ThCxt* _thCxt, const char* sText, int zText, char* buffer, int zBuffer, Va_listFW typedArgs)
{
  va_list vargList = typedArgs.args;
  /**Type char for each arg, the string will be filled either from given, typedArgs,
   * or from the default type detected by parsePrinfStyleString_fwFormatter. */ 
  char sTypeArgs[maxNrofArgs_Formatter_FW] = {0};  //default: 0: no arguments given.
  /**List of addresses of the args, gotten in succession from va_list if need. */
  //void* addrArgs[maxNrofArgs_Formatter_FW] = {null};
  union argValues_t{
  	char c; int i; int32 i32; int64 i64; float f; double d;
  	void* p; char* z;
  	OS_TimeStamp t; StringJc s;
  	char8 c8;
  } *argValue, argValues [maxNrofArgs_Formatter_FW] = { {0} };
  int ixAddrArgs = -1;  //index of the last gotten argument for evaluating the addrArgs.
  int nrActArg = -1;     //index of the last gotten argument in argument order (without argument-index).
  //ParseResultPrintfStyle_fwFormatter parseResult[20]; 
  //int nrofParseResult;
  //int idxParseResult;
  int iBuffer = 0;
  char const* sTextEnd = sText + zText;  //exclusive end
  char const* sText1 = sText;
  /**A saved back-text. */
  char const* sTextBack =null;
  char const* sTextEndBack = null;
  /**Two places for converted time. */
  TimeBytes_Fwc timeYsec[2];  
  OS_TimeStamp timeStamp[2];
  /**The argument-number for timeplace. */
  int nrArgTime[2] = {-1, -1};
  /**The index of last used timePlace. */
  int ixArgTime = 0;
  bool overflow = 0;
  
  STACKTRC_TENTRY("format_BV_StringJc");
  //va_start(vargList, args->v[0]);
  //parse the output and control string:
  if(typedArgs.typeArgs !=null){
    //type of args is given, then take it!
    strncpy(sTypeArgs, typedArgs.typeArgs, sizeof(sTypeArgs));
  } //else: the 0 will be overwritten by a default selection in parsePrinfStyleString_fwFormatter.
  //
  //nrofParseResult = parsePrinfStyleString_fwFormatter(parseResult, ARRAYLEN(parseResult), sText, zText);
  
  while(  iBuffer < (zBuffer -1) &&  sText1 < sTextEnd) 
  { const char* sText2;
    int nrofCharsToCopy;
    sText2 = strchr(sText1, '%');  //search the next control-char for format control
    if(sText2 == null)
    { sText2 = sTextEnd; //use string to its end if not found
    }
    nrofCharsToCopy = sText2 - sText1;
    if(nrofCharsToCopy > 0)
    { //any text from actual position to found '%' or to end.
      if(nrofCharsToCopy > (zBuffer - iBuffer -1)){
        overflow = true;
        nrofCharsToCopy = (zBuffer - iBuffer -1);
      }
      strncpy(buffer+iBuffer, sText1, nrofCharsToCopy);
      iBuffer += nrofCharsToCopy; //may be reached zBuffer if buffer is full.
      sText1 = sText2;  //continue after it.
    }
    if(iBuffer < (zBuffer -1) && sText1 < sTextEnd){
      //now evaluate the %-format control char:
      int radixIntConversion = 0;
      char typeCv = '?';  //set to use the appropriate value from the following informations:
      char const* srcToCopy = null;
      int32 arg32;
      int64 arg64;
      float argFloat;
      double argDouble; 
      
      char cTypeArg;
      //nrArg1 is the number (the index) of the argument
      int nrArg1 = 0;
      ///void* pArg;  //pointer to an argument in the typedArgs-memory.
      
      ParseResultPrintfStyle_fwFormatter actParseResult[1];
      //evaluate using the parsing routine, but only for 1 result.
      
      nrofCharsToCopy = sTextEnd - sText1;  //
      parsePrinfStyleString_fwFormatter(actParseResult, 1, sText1, &nrofCharsToCopy);  //HINT: zText is not used, because there is only 1 element.
      sText1 += nrofCharsToCopy;  //return: the number of processed chars.

      nrofCharsToCopy = 0;
      if(actParseResult->value.indexArg > 0){
      	nrArg1 = actParseResult->value.indexArg-1;
      } else if(actParseResult->value.indexArg == -1){
      	//remain nrArg1 from last parameter, because the argument number isn't given
      } else {
      	nrArg1 = ++nrActArg;
      }
      if(sTypeArgs[nrArg1]==0){
        sTypeArgs[nrArg1] = actParseResult->value.argument;
      }
      cTypeArg = sTypeArgs[nrArg1];
      //get the variable argument:
      //the macro va_arg returns a value, but the value is located in the stack.
      //the & to reference the value is admissible. The gotten pointer is located in the stack area
      //where the argument is stored.
      while(ixAddrArgs < nrArg1 -1){
        //get all arguments in the order of variable argument list:
        switch(cTypeArg){
        case 'C': argValues[++ixAddrArgs].c = va_arg(vargList, char_va_list); break;
        case 'Z': argValues[++ixAddrArgs].i32 = va_arg(vargList, bool_va_list); break;
        case 'B': argValues[++ixAddrArgs].i32 = va_arg(vargList, int8_va_list); break;
        case 'S': argValues[++ixAddrArgs].i32 = va_arg(vargList, int16_va_list); break;
        case 'I': 
        case 'K': 
        case 'M': 
        case 'N': argValues[++ixAddrArgs].i32 = va_arg(vargList, int32); break;
        case 'J': argValues[++ixAddrArgs].i64 = va_arg(vargList, int64); break;
        case 'F': argValues[++ixAddrArgs].f = (float)va_arg(vargList, float_va_list); break;
        case 'D': argValues[++ixAddrArgs].d = va_arg(vargList, double); break;
        case 'P': argValues[++ixAddrArgs].p = va_arg(vargList, void*); break;
        case 'z': argValues[++ixAddrArgs].z = va_arg(vargList, char*); break;
        case 's': argValues[++ixAddrArgs].s = va_arg(vargList, StringJc); break;
        case 't': argValues[++ixAddrArgs].t = va_arg(vargList, OS_TimeStamp); break;
        case '1': argValues[++ixAddrArgs].c8 = va_arg(vargList, char8); break;
                  //Note: The types with more as 8 chars will be copied in the next elements too. Any element is sizeof(char8).
        case '2': if(ixAddrArgs < ARRAYLEN(argValues) - 2){ *(char16*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char16); ixAddrArgs+=1; } break;
        case '3': if(ixAddrArgs < ARRAYLEN(argValues) - 3){ *(char24*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char24); ixAddrArgs+=2; } break;
        case '4': if(ixAddrArgs < ARRAYLEN(argValues) - 4){ *(char32*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char32); ixAddrArgs+=3; } break;
        case '5': if(ixAddrArgs < ARRAYLEN(argValues) - 5){ *(char40*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char40); ixAddrArgs+=4; } break;
        case '6': if(ixAddrArgs < ARRAYLEN(argValues) - 6){ *(char48*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char48); ixAddrArgs+=5; } break;
        case '7': if(ixAddrArgs < ARRAYLEN(argValues) - 7){ *(char56*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char56); ixAddrArgs+=6; } break;
        case '8': if(ixAddrArgs < ARRAYLEN(argValues) - 8){ *(char64*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char64); ixAddrArgs+=7; } break;
        case '$': if(ixAddrArgs < ARRAYLEN(argValues) - 1){ *(char8*)&argValues[++ixAddrArgs].c8 = va_arg(vargList, char8); ixAddrArgs = nrArg1; } break;
        default: THROW_s0(IllegalArgumentException, "unknown type char:", cTypeArg);
        }//switch
      }
      ///pArg = addrArgs[nrActArg];
      argValue = &argValues[nrActArg];  //the reference of the requested argument value.
      //check the conversion char, get the value appropriate to the conversion char
      //and set conversion inputs:
      //typeCv: type of conversion. 
      //        's' srcToCopy is set, text copy
      //        'I' arg32 is set, int, maybe hex, check actParseResult->value.specifier
      //        'J' arg64 is set
      //        'F' argfloat is set
      //        'D' argDouble is set.

      //char* srcToCopy: If !=null than copy the text
      //nrofCharsToCopy: >0 than copy the text srcToCopy
      //arg32, arg64, argfloat, argdouble: Set for numeric conversions
      //
      switch(actParseResult->value.specifier)
      { case 's':
        { //text from argument
          typeCv= 's';
          switch(cTypeArg)
          { case 's': 
            { StringJc arg = argValue->s; //*(StringJc*)pArg;
              srcToCopy = getCharsAndLength_StringJc(&arg, &nrofCharsToCopy); 
            } break;
            case 'z':
            { srcToCopy = argValue->z; //*(char const**)pArg;
              if(srcToCopy == null)
              { srcToCopy = "(null)";   //a null pointer may be acceptable.
              }
              nrofCharsToCopy = strlen_Fwc(srcToCopy, zBuffer-iBuffer);
            } break;
            case '1': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 8);
            case '2': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 16);
            case '3': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 24);
            case '4': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 32);
            case '5': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 40);
            case '6': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 48);
            case '7': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 56);
            case '8': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, 64);
            case '$': srcToCopy = &argValue->c8.s[0]; nrofCharsToCopy = strlen_Fwc(srcToCopy, zBuffer-iBuffer);
            default:  srcToCopy="ERROR unknwon Type";nrofCharsToCopy = strlen(srcToCopy);
          }
        } break;
        case 'p':  //pointer, here only int-like pointer (not segmented)
        case 'i':
        case 'd':
        case 'x':
        case 'X':
        case 'c':
        { //integer or character types.
          switch(cTypeArg)
          { case 'C': typeCv = 'c'; arg32 = argValue->c; break; //*(char_va_list*)pArg; break;
            case 'Z': typeCv = 'Z'; arg32 = argValue->i32; break; //*(bool_va_list*)pArg; break;
            case 'B': typeCv = 'I'; arg32 = argValue->i32; break; //*(int8_va_list*)pArg; break;
            case 'S': typeCv = 'I'; arg32 = argValue->i32; break; //*(int16_va_list*)pArg; break;
            case 'I': 
            case 'K': 
            case 'M': 
            case 'N': typeCv = 'I'; arg32 = argValue->i32; break; //*(int32*)pArg; break;
            case 'J': typeCv = 'J'; arg64 = argValue->i64; break; //*(int64*)pArg; break;
            case 'F': typeCv = 'I'; arg32 = (int32)argValue->f; break; //*(int32*)pArg; break;
            case 'D': typeCv = 'J'; arg64 = (int32)argValue->d; break; //*(int64*)pArg; break;
            case 'P': typeCv = 'I'; arg32 = argValue->c; break; //*(int32*)pArg; break;  //get a pointer as 32-bit-value.
            default:  typeCv = '?'; arg32 = argValue->c; break; //*(int32*)pArg; break;
          }
          //typeCv = actParseResult->value.specifier == 'c' ? 'c' :'I';  //character or integer conversion type,
        } break;
    
        case 'e': //Floating point conversions:
        case 'E':
        case 'f':
        case 'g':
        case 'G':
        { //integer
          switch(cTypeArg)
          { case 'C': typeCv = 'F'; argFloat = argValue->f; break; //*(char_va_list*)pArg; break;
		  case 'Z': typeCv = 'F'; argFloat = argValue->i32 ? 1.0F : 0; break; //(float)(*(bool_va_list*)pArg); break;
            case 'B': typeCv = 'F'; argFloat = (int8)argValue->i32; break; //*(int8_va_list*)pArg; break; //conversion from int to float
            case 'S': typeCv = 'F'; argFloat = (int16)argValue->i32; break; //*(int16_va_list*)pArg; break;
            case 'I': 
            case 'K': 
            case 'M': 
            case 'N': typeCv = 'D'; argDouble = (float)argValue->i32; break; //*(int32*)pArg; break;
            case 'J': typeCv = 'D'; argDouble = (double)argValue->i64; break; //(double)*(int64*)pArg; break;  //conversion from int64 to double
            case 'D': typeCv = 'D'; argDouble = argValue->d; break; //*(double*)pArg; break;
            case 'F': typeCv = 'F'; argFloat = argValue->f; break; //(float)*(float_va_list*)pArg; break; //float may be a double in a va_list
            default:  typeCv = '?'; arg32 = argValue->i32; break; //*(int32*)pArg; break;
          }
        } break;
        case 't':  //Timing output
        { //check if the time is converted or not.
          if(nrArgTime[ixArgTime] != nrActArg){
            ixArgTime = (ixArgTime+1) & (sizeof(nrArgTime)-1);
            if(nrArgTime[ixArgTime] != nrActArg){
              //use this buffer newly:
              nrArgTime[ixArgTime] = nrActArg;
              switch(cTypeArg){
              case 'I': setUTC_OS_TimeStamp(timeStamp[ixArgTime], argValue->i32, 0); break; //seconds as int32-argument
              case 'J': {
                arg64 = argValue->i64;
                { int32 seconds = (int32)(arg64/1000);
                  int32 millisec = (int32)(arg64 - 1000*seconds);
                  setUTC_OS_TimeStamp(timeStamp[ixArgTime], seconds, 1000000 * millisec); break; //seconds as int32-argument
                } } break; 
              case 't': {
                timeStamp[ixArgTime] = argValue->t;
              } break; 
              }//switch
              ctor_TimeBytes_Fwc(&timeYsec[ixArgTime], seconds_OS_TimeStamp(timeStamp[ixArgTime]), 1970, 0, isGPS_OS_TimeStamp(timeStamp[ixArgTime]));
            }
          }
          switch(actParseResult[0].value.timeSpecifier){
          case 'k':
          case 'H': typeCv = 'I'; arg32 = timeYsec[ixArgTime].hour; break;
          case 'l':
          case 'I': typeCv = 'I'; arg32 = timeYsec[ixArgTime].hour +1; if(arg32 > 12){ arg32 -=12; } break;
          case 'M': typeCv = 'I'; arg32 = timeYsec[ixArgTime].minute; break;
          case 'S': typeCv = 'I'; arg32 = timeYsec[ixArgTime].sec; break;
          case 'L': typeCv = 'I'; arg32 = argValue->t.time_nsec/1000000; break;
          case 'N': typeCv = 'I'; arg32 = argValue->t.time_nsec; break;
          case 'p': typeCv = 's'; if(timeYsec[ixArgTime].hour>=12){ srcToCopy="pm";} else { srcToCopy = "am";} nrofCharsToCopy = -1 ; break;
          case 'z': typeCv = 'I'; arg32 = timeYsec[ixArgTime].hour; break;
          case 'Z': typeCv = 'I'; arg32 = timeYsec[ixArgTime].hour; break;
          case 's': typeCv = 'I'; arg32 = timeYsec[ixArgTime].hour; break;
            
          case 'R': typeCv = '-'; sTextBack = sText1; sTextEndBack = sTextEnd; sText1 = "%<tH:%<tM"; sTextEnd = sText1 + strlen(sText1); break;
          }//switch
        
        } break;
        default:
        { char arg[] = "?%???";
          arg[2] = actParseResult->value.specifier;
          srcToCopy = "???";   //do not use the stack instance, it is a mistake!
          nrofCharsToCopy = 3;
        }
      }//switch
      switch(actParseResult->value.specifier)
      { case 'i': case 'd': radixIntConversion = 10; break;
        case 't': radixIntConversion = 10; break;  //time
        case 'p': radixIntConversion = 16; break;  //pointer
        case 'x': radixIntConversion = 16; break;
        case 'X': radixIntConversion = 16; break;
        case 'o': radixIntConversion = 8; break;
        default: radixIntConversion = 10;
      }
      //convert a given number:
      switch(typeCv)
      { case 's':
        { if( (zBuffer - iBuffer) < nrofCharsToCopy)
          { nrofCharsToCopy = zBuffer - iBuffer -1;  //shorten it, but copy so much as possible, the user will see it. 
          }
          memcpy(buffer + iBuffer, srcToCopy, nrofCharsToCopy);
          iBuffer += nrofCharsToCopy;
          srcToCopy = null;
        } break;
        case 'c':
        { //A char is requested in representation, take the arg32.
          char cc = (char)arg32;
          if(cc < 0x20){ cc = '?'; }   //ctrl chars are not printable!
          if(iBuffer < (zBuffer -1))
          { buffer[iBuffer++] = cc;
          }
        } break;
        case 'I':
        { nrofCharsToCopy = toString_Integer_FW(buffer + iBuffer, zBuffer - iBuffer -1, arg32, radixIntConversion, actParseResult->value.precision, _thCxt);
          iBuffer += nrofCharsToCopy;
          radixIntConversion = 0;
        } break;
        case 'J':
        { //TODO toString_Long_FW
          nrofCharsToCopy = toString_Integer_FW(buffer + iBuffer, zBuffer - iBuffer -1, (int32)arg64, radixIntConversion, actParseResult->value.precision, _thCxt);
          iBuffer += nrofCharsToCopy;
          radixIntConversion = 0;
        } break;

        case 'D': 
        { nrofCharsToCopy = toString_Double_FW(buffer + iBuffer, zBuffer - iBuffer -1, argDouble, actParseResult->value.specifier, actParseResult->value.width, actParseResult->value.precision, _thCxt);
          if(nrofCharsToCopy >0)
          { iBuffer += nrofCharsToCopy;
          }
        } break; 
        case 'F':
        { nrofCharsToCopy = toString_Float_FW(buffer + iBuffer, zBuffer - iBuffer -1, argFloat, actParseResult->value.specifier, actParseResult->value.width, actParseResult->value.precision, _thCxt);
          if(nrofCharsToCopy >0)
          { iBuffer += nrofCharsToCopy;
          }
        } break;
        case '-': break; //do nothing.
      }
    }//if %-char
    if(sText1 >= sTextEnd && sTextBack != null)
    { sText1 = sTextBack;
      sTextEnd = sTextEndBack;
      sTextBack = null;
    }
  
    
  }//while 
  if(iBuffer < zBuffer)
  { buffer[iBuffer] = 0;  //should be always!
  }
  STACKTRC_LEAVE; return iBuffer;
}




