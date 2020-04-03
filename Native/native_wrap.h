/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_native_wrap_WRAP_H_
#define SWIG_native_wrap_WRAP_H_

class SwigDirector_Test : public base::Test, public Swig::Director {

public:
    SwigDirector_Test();
    virtual void SetValue(int value);
    virtual int GetValue();

    typedef void (SWIGSTDCALL* SWIG_Callback0_t)(int);
    typedef int (SWIGSTDCALL* SWIG_Callback1_t)();
    void swig_connect_director(SWIG_Callback0_t callbackSetValue, SWIG_Callback1_t callbackGetValue);

private:
    SWIG_Callback0_t swig_callbackSetValue;
    SWIG_Callback1_t swig_callbackGetValue;
    void swig_init_callbacks();
};

class SwigDirector_HasTest : public base::HasTest, public Swig::Director {

public:
    SwigDirector_HasTest(base::ITestPtr const &test);
    virtual void SetValue(int value);
    virtual int GetValue();

    typedef void (SWIGSTDCALL* SWIG_Callback0_t)(int);
    typedef int (SWIGSTDCALL* SWIG_Callback1_t)();
    void swig_connect_director(SWIG_Callback0_t callbackSetValue, SWIG_Callback1_t callbackGetValue);

private:
    SWIG_Callback0_t swig_callbackSetValue;
    SWIG_Callback1_t swig_callbackGetValue;
    void swig_init_callbacks();
};


#endif
