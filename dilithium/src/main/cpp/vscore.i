#ifdef SWIGJAVA

%module vscore

%include "stdint.i"
%include "typemaps.i"
%include "cpointer.i"
%include "arrays_java.i"

%apply int[] { int32_t *finished };
%apply uintptr_t { const uint8_t *ptr };
%apply int { int32_t _0 };

%{
#include "vs-core.h"
%}

%include "vs-core.h"

#endif
