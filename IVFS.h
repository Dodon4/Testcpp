#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>

namespace TestTask
{
	struct File
	{
		bool isReadOnly;
		std::ifstream is;
		std::ofstream os;
		std::filesystem::path path;

		File(const bool isReadOnly) : isReadOnly(isReadOnly), is(std::ifstream()), os(std::ofstream()), path(std::filesystem::path()) {};
	};

	struct IVFS
	{
		virtual File* Open(const char* name) = 0; // open file in readonly mode. If this file doesn't exist or is already opened in writeonly mode, return nullptr 
		virtual File* Create(const char* name) = 0; // open or create file in writeonly mode. If required, create all mentioned directories. If file is already opened in readonly mode, return nullptr
		virtual size_t Read(File* f, char* buff, size_t len) = 0; // read data from the file. Return the number of read bytes
		virtual size_t Write(File* f, char* buff, size_t len) = 0; // write data to the file. Return the number of written bytes
		virtual void Close(File* f) = 0; // close file

		virtual ~IVFS() = default;
	};
}