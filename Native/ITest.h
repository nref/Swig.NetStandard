#pragma once
#include "ClassForward.h"

namespace base // Intentionally conflict with C# 'base' keyword
{
	CLASS_FORWARD(ITest);
	class ITest {
	public:
		virtual void SetValue(int value) = 0;
		virtual int GetValue() = 0;

	protected:
		~ITest() = default;
	};
}