#pragma once
#include "ClassForward.h"
#include "ITest.h"
#include "Test.h"

namespace base // Intentionally conflict with C# 'base' keyword
{
	CLASS_FORWARD(HasTest);

	class HasTest : ITest
	{
	public:

		HasTest(const ITestPtr& test) : _test(test) 
		{
		}

		void SetValue(int value) override
		{
			_test->SetValue(value);
		}

		int GetValue() override
		{
			return _test->GetValue();
		}

	private:
		ITestPtr _test;
	};
}
