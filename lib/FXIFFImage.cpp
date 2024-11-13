/********************************************************************************
*                                                                               *
*                         I F F   I m a g e   O b j e c t                       *
*                                                                               *
*********************************************************************************
* Copyright (C) 2004,2024 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or modify          *
* it under the terms of the GNU Lesser General Public License as published by   *
* the Free Software Foundation; either version 3 of the License, or             *
* (at your option) any later version.                                           *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 *
* GNU Lesser General Public License for more details.                           *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public License      *
* along with this program.  If not, see <http://www.gnu.org/licenses/>          *
********************************************************************************/
#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "fxmath.h"
#include "FXElement.h"
#include "FXMetaClass.h"
#include "FXHash.h"
#include "FXStream.h"
#include "FXMemoryStream.h"
#include "FXIFFImage.h"



/*
  Notes:
*/

using namespace FX;

/*******************************************************************************/

namespace FX {


// Suggested file extension
const FXchar FXIFFImage::fileExt[]="iff";


// Suggested mime type
const FXchar FXIFFImage::mimeType[]="image/x-iff";


// Object implementation
FXIMPLEMENT(FXIFFImage,FXImage,nullptr,0)


// Initialize
FXIFFImage::FXIFFImage(FXApp* a,const FXuchar *pix,FXuint opts,FXint w,FXint h):FXImage(a,nullptr,opts,w,h){
  if(pix){
    FXMemoryStream ms(FXStreamLoad,const_cast<FXuchar*>(pix));
    loadPixels(ms);
    }
  }


// Save object to stream
FXbool FXIFFImage::savePixels(FXStream&) const {
  return false;
  }


// Load object from stream
FXbool FXIFFImage::loadPixels(FXStream& store){
  FXColor *pixels; FXint w,h;
  if(fxloadIFF(store,pixels,w,h)){
    setData(pixels,IMAGE_OWNED,w,h);
    return true;
    }
  return false;
  }


// Clean up
FXIFFImage::~FXIFFImage(){
  }

}
