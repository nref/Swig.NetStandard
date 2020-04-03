%module(directors="1") native_wrap
%feature("director") base::Test;
%feature("director") base::HasTest;

%include "std_shared_ptr.i"
%shared_ptr(base::ITest);
%shared_ptr(base::Test);
%shared_ptr(base::HasTest);

%include "ClassForward.h"
%include "ITest.h"
%include "Test.h"
%include "HasTest.h"

%{

#include "ClassForward.h"
#include "ITest.h"
#include "Test.h"
#include "HasTest.h"

%}
