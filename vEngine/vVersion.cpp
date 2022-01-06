#include "vVersion.h"

#include <string>

namespace wi::version
{
	// Main engine core
	const int major = 1;
	// Minor features, major updates, breaking compatibility changes
	const int minor = 0;
	// Minor bug fixes, alterations, refactors, updates
	const int revision = 0;

	const std::string version_string = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(revision);

	int GetMajor()
	{
		return major;
	}
	int GetMinor()
	{
		return minor;
	}
	int GetRevision()
	{
		return revision;
	}
	const char* GetVersionString()
	{
		return version_string.c_str();
	}

}