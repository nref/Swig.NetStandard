# Swig.NetStandard
Using SWIG to wrap a nontrivial C++ DLL in C#

# Requirements

- MSVC 142 (Visual Studio 2019)
- SWIG 4 must be in the PATH

    ``` batch
	C:\>path
	PATH=...;C:\Program Files (x86)\swigwin-4.0.1;...
    ``` 

# Features

- Source library DLL is standard C++11
- Target library DLL is .NET Standard 2.1
- Cross-language polymorphism with SWIG Directors
    - Pseudo-interfaces with C++ pure virtual classes.
    - Actual C# interfaces are not supported well by SWIG
        
    ``` cs
    /// <summary>
    /// Verify that Swig Director enables cross-language inheritance,
    /// i.e. a base C++ class member calls a derived C# class member
    /// </summary>
    [Test]
    public void Cpp_Calls_Cs_ClassMember()
    {
        var hasTest = new HasTest(new DerivedTest());

        hasTest.SetValue(4);
        Assert.AreEqual(8, hasTest.GetValue());
    }
    ``` 
    
    C#
    ``` cs
    class DerivedTest : Test
    {
        public override void SetValue(int value)
        {
            _myValue = 2 * value;
        }

        public override int GetValue()
        {
            return _myValue;
        }

        private int _myValue = 0;
    }
    ``` 

    Test.h
    ``` cpp
	class Test : public ITest
	{
    public:
        ...
        virtual void SetValue(int value) ...
        virtual int GetValue() ...
        int Value;
	};
    ``` 

    ITest.h
    ``` cpp
    class ITest 
    {
	public:
        virtual void SetValue(int value) = 0;
        virtual int GetValue() = 0;
        ...
	};
    ``` 

- Support for mapping std::function to C# delgates and vice-versa
    
    C#
    ``` cs
    /// <summary>
    /// Verify that C++ can call a C# callback
    /// </summary>
    [Test]
    public void Cpp_Calls_Cs_Callback()
    {
        var result = native_wrap.invoke_callback(new ReturnsDouble((i, d) => i + d));
        Assert.AreEqual(1 + 2.5, result); // Value set in native.i
    }
    ``` 

    C++
    ``` cpp
    double invoke_callback(std::function<double(int,double)> in) {
        return in(1, 2.5);
    }
    ``` 

- Shared Pointers (std::shared_ptr) are mapped correctly

    C#
    ``` cs
    /// <summary>
    /// Verify that std::function returning std::shared_ptr and taking a const pointer can be called in C#
    /// </summary>
    [Test]
    public void Cs_Calls_func_taking_const_pointer_returning_shared_pointer()
    {
        var callback = native_wrap.test_shared_ptr();
        var output = callback.Invoke(new Input { Value = "test" });
        Assert.AreEqual("test", output.Input.Value);
    }
    ``` 

    C++
    ``` cpp
    using InputOutputFunc = std::function<std::shared_ptr<Output>(const Input*)>;
    InputOutputFunc test_shared_ptr() {
        return [=](const Input* input){
            return std::make_shared<Output>(input);
        };
    }
    ``` 

- Verify that SWIG maps C++ macros that contain shared pointer forward-declarations
  
    C#
    ``` cs
    public class Test : ITest 
    { 
        /* No shared_ptr garbage e.g. SWIGTYPE_p_std__shared_ptrT_Test */ 
    }
    ``` 

    C++
    ``` cpp
    #define CLASS_FORWARD(C)
        class C;
        using C##Ptr = std::shared_ptr<C>

	CLASS_FORWARD(Test);
	class Test : public ITest {	... };
    ``` 

  swig:
    ``` cpp
    %shared_ptr(base::Test);
    ``` 
    
- Verify that SWIG handles C++ namespace conflicts with C# "base" keyword

    ``` cpp
    namespace base { ... } // Intentionally conflict with C# 'base' keyword
    ``` 
    
    ``` cs
    1>Test.h(7): warning 314: 'base' is a C# keyword, renaming to 'base_'
    ``` 

# Acknowledgements

Thanks to https://github.com/xkbeyer/example_swig_cs_cpp for providing a starting point.
