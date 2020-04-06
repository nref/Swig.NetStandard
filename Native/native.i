%module(directors="1") native_wrap
%feature("director") base::Test;
%feature("director") base::HasTest;

%include "std_shared_ptr.i"
%shared_ptr(base::ITest);
%shared_ptr(base::Test);
%shared_ptr(base::HasTest);
%shared_ptr(Output);

%include "ClassForward.h"
%include "ITest.h"
%include "Test.h"
%include "HasTest.h"

%include "std_string.i"
%include "std_function.i"

%callback("%s_cb");
double add(int a, double b);
%nocallback;

// TODO unwrap shared_ptr automatically
//%std_function(ReturnsVoid, void, std::string);
//%std_function(ReturnsDouble, double, int, double);
// C# Functor name, C++ type, C# type, C++ args
%std_function(ReturnsVoid, void, void, std::string);
%std_function(ReturnsDouble, double, double, int, double);

%inline %{
    static std::string string_side_effect = "";
    static double double_side_effect = 0;

    class Input
    {
    public:
        std::string Value = "";
    };

    class Output
    {
    public:
        Output(const Input* input) : Input(input) { }
        const Input* Input = nullptr;
    };

    std::function<void(std::string)> make_set_string_side_effect_callback() {
        return [](std::string s) {
            string_side_effect = s;
        };
    }

    using InputOutputFunc = std::function<std::shared_ptr<Output>(const Input*)>;
    InputOutputFunc test_shared_ptr() {
        return [=](const Input* input){
            return std::make_shared<Output>(input);
        };
    }

    std::function<double(int,double)> make_add_set_double_side_effect_callback() {
        return [](int x, double y) {
            double_side_effect = x + y;
            return x + y;
        };
    }

    double invoke_callback(std::function<double(int,double)> in) {
        return in(1, 2.5);
    }
%}
%std_function(ReturnsSharedPtr, std::shared_ptr<Output>, Output, const Input*);

%{

#include "ClassForward.h"
#include "ITest.h"
#include "Test.h"
#include "HasTest.h"

double add(int a, double b) 
{
    return a + b;
}

%}