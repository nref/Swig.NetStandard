# Swig.NetStandard
Using SWIG to wrap a nontrivial C++ DLL in C#

Covers the following use cases:

- Source library DLL is standard C++11 compiled with MSVC 142 (Visual Studio 2019)
- Target library DLL is .NET Standard 2.1
- Cross-language polymorphism with SWIG Directors. 
    - See the Tests project.
- Shared Pointers (std::shared_ptr) are mapped correctly
- Verify that SWIG maps C++ macros that contain shared pointer forward-declarations
- Pseudo-interfaces wth C++ pure virtual classes 
    - Actual C# interfaces are not supported well by SWIG
- Verify that SWIG handles C++ namespace conflicts with C# "base" keyword
- Project-based segregation of C++ and C# code.
    - Automatic copying of the generated C# code to the C# project
    - Automatic copying of the source library DLL to the C# project output directory
