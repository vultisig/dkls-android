#ifdef SWIGJAVA
%module goschnorr

%include "stdint.i"
%include "typemaps.i"
%include "cpointer.i"
%include "arrays_java.i"

%apply int[] { uint32_t *finished };
%apply int[] { int32_t *finished };
%apply uintptr_t { const uint8_t *ptr };
%apply int { int32_t _0 };

%{
#include "go-schnorr.h"
%}

%include "go-schnorr.h"
#endif