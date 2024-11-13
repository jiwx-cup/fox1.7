#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXMetaClass.h"
#include "FXTextCodec.h"
#include "FXCP1250Codec.h"

namespace FX {

FXIMPLEMENT(FXCP1250Codec,FXTextCodec,nullptr,0)


//// Created by codec tool on 03/25/2005 from: CP1250.TXT ////
static const unsigned short forward_data[256]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   8364, 65533, 8218, 65533, 8222, 8230, 8224, 8225, 65533, 8240, 352,  8249, 346,  356,  381,  377,
   65533, 8216, 8217, 8220, 8221, 8226, 8211, 8212, 65533, 8482, 353,  8250, 347,  357,  382,  378,
   160,  711,  728,  321,  164,  260,  166,  167,  168,  169,  350,  171,  172,  173,  174,  379,
   176,  177,  731,  322,  180,  181,  182,  183,  184,  261,  351,  187,  317,  733,  318,  380,
   340,  193,  194,  258,  196,  313,  262,  199,  268,  201,  280,  203,  282,  205,  206,  270,
   272,  323,  327,  211,  212,  336,  214,  215,  344,  366,  218,  368,  220,  221,  354,  223,
   341,  225,  226,  259,  228,  314,  263,  231,  269,  233,  281,  235,  283,  237,  238,  271,
   273,  324,  328,  243,  244,  337,  246,  247,  345,  367,  250,  369,  252,  253,  355,  729,
  };


static const unsigned char reverse_plane[17]={
  0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
  };

static const unsigned char reverse_pages[73]={
  0,  46, 46, 46, 46, 46, 46, 46, 109,46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 46, 46,
  };

static const unsigned short reverse_block[173]={
  0,   16,  32,  48,  64,  80,  96,  112, 128, 128, 144, 160, 175, 190, 206, 221,
  235, 251, 128, 263, 278, 294, 310, 326, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 341, 349, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 363, 379,
  395, 128, 128, 128, 128, 128, 128, 406, 128, 128, 128, 128, 128, 128, 128, 420,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  };

static const unsigned char reverse_data[436]={
   0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   160,  26,   26,   26,   164,  26,   166,  167,  168,  169,  26,   171,  172,  173,  174,  26,
   176,  177,  26,   26,   180,  181,  182,  183,  184,  26,   26,   187,  26,   26,   26,   26,
   193,  194,  26,   196,  26,   26,   199,  26,   201,  26,   203,  26,   205,  206,  26,   26,
   26,   211,  212,  26,   214,  215,  26,   26,   218,  26,   220,  221,  26,   223,  26,   225,
   226,  26,   228,  26,   26,   231,  26,   233,  26,   235,  26,   237,  238,  26,   26,   26,
   243,  244,  26,   246,  247,  26,   26,   250,  26,   252,  253,  26,   26,   195,  227,  165,
   185,  198,  230,  26,   26,   26,   26,   200,  232,  207,  239,  208,  240,  26,   26,   26,
   26,   26,   26,   202,  234,  204,  236,  26,   26,   26,   26,   26,   26,   26,   26,   26,
   197,  229,  26,   26,   188,  190,  26,   163,  179,  209,  241,  26,   26,   210,  242,  26,
   26,   26,   26,   26,   26,   26,   213,  245,  26,   26,   192,  224,  26,   26,   216,  248,
   140,  156,  26,   26,   170,  186,  138,  154,  222,  254,  141,  157,  26,   26,   26,   26,
   26,   26,   26,   26,   217,  249,  219,  251,  26,   26,   26,   26,   26,   26,   26,   143,
   159,  175,  191,  142,  158,  26,   26,   26,   26,   26,   26,   26,   161,  26,   26,   26,
   26,   26,   26,   26,   26,   162,  255,  26,   178,  26,   189,  26,   26,   26,   150,  151,
   26,   26,   26,   145,  146,  130,  26,   147,  148,  132,  26,   134,  135,  149,  26,   26,
   26,   133,  26,   26,   26,   26,   26,   26,   26,   26,   26,   137,  26,   26,   26,   26,
   26,   26,   26,   26,   139,  155,  26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   128,  26,   26,   26,   153,  26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,
  };


FXint FXCP1250Codec::mb2wc(FXwchar& wc,const FXchar* src,FXint nsrc) const {
  if(nsrc<1) return -1;
  wc=forward_data[(FXuchar)src[0]];
  return 1;
  }


FXint FXCP1250Codec::wc2mb(FXchar* dst,FXint ndst,FXwchar wc) const {
  if(ndst<1) return -1;
  dst[0]=reverse_data[reverse_block[reverse_pages[reverse_plane[wc>>16]+((wc>>10)&63)]+((wc>>4)&63)]+(wc&15)];
  return 1;
  }

FXint FXCP1250Codec::mibEnum() const {
  return 2250;
  }


const FXchar* FXCP1250Codec::name() const {
  return "windows-1250";
  }


const FXchar* FXCP1250Codec::mimeName() const {
  return "windows-1250";
  }


const FXchar* const* FXCP1250Codec::aliases() const {
  static const FXchar *const list[]={"microsoft-cp1250","windows-1250","cp1250","latin2",nullptr};
  return list;
  }

}

