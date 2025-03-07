#pragma once
#include <fstream>


class ScriptDebugLogger
{
	std::ofstream logFile;
public:
	int numSpacesIndent = 0;
	
	void Open(const wchar_t* path)
	{
		Close();
		logFile.open(path);
	}

	void IncreaseIndent(int amount = 4)
	{
		numSpacesIndent += 4;
	}

	void DecreaseIndent(int amount = 4)
	{
		numSpacesIndent -= 4;
		if (numSpacesIndent < 0)
		{
			numSpacesIndent = 0;
		}
	}

	std::ofstream&& indent()
	{
		for (int i = 0; i < numSpacesIndent; ++i)
		{
			logFile << ' ';
		}
		return std::move(logFile);
	}

	std::ofstream&& out()
	{
		return std::move(logFile);
	}

	void Close()
	{
		if (logFile.is_open())
		{
			logFile.close();
		}
	}
};
