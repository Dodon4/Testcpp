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
		virtual File* Open(const char* name) = 0; // ������� ���� � readonly ������. ���� ��� ������ ����� ��� �� �� ������ �� writeonly ������ - ������� nullptr
		virtual File* Create(const char* name) = 0; // ������� ��� ������� ���� � writeonly ������. ���� �����, �� ������� ��� ������ �������������, ���������� � ����. ������� nullptr, ���� ���� ���� ��� ������ � readonly ������.
		virtual size_t Read(File* f, char* buff, size_t len) = 0; // ��������� ������ �� �����. ������������ �������� - ������� ������� ���� ������� ���������
		virtual size_t Write(File* f, char* buff, size_t len) = 0; // �������� ������ � ����. ������������ �������� - ������� ������� ���� ������� ��������
		virtual void Close(File* f) = 0; // ������� ����

		virtual ~IVFS() = default;
	};
}