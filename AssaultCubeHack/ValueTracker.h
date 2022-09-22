#pragma once

template <typename T>
class ValueTracker
{
private:
	T m_OldValues;

public:
	template <typename Function>
	void Update(const T& currentValues, Function displayFunc)
	{
		if (m_OldValues != currentValues)
			Display(displayFunc);

		m_OldValues = currentValues;
	}

	template <typename Function>
	void Display(Function func)
	{
		system("cls");

		func();
	}
};