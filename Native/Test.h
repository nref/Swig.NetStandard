#pragma once
#include "ClassForward.h"
#include "ITest.h"

namespace base // Intentionally conflict with C# 'base' keyword
{
	CLASS_FORWARD(Test);

	class Test : public ITest
	{
	public:
		Test() : Value(0)
		{
		}

		virtual void SetValue(int value) override 
		{
			Value = value;
		}

		virtual int GetValue() override
		{
			return Value;
		}

		int Value;
	};
}
