#pragma once
#include "IVFS.h"
#include <list>
namespace TestTask
{
	class VFS : public IVFS
	{
		std::list<File*> activeFiles;

	public:
		File* Open(const char* name) override;// Открыть файл в readonly режиме. Если нет такого файла или же он открыт во writeonly режиме - вернуть nullptr
		File* Create(const char* name) override;// Открыть или создать файл в writeonly режиме. Если нужно, то создать все нужные поддиректории, упомянутые в пути. Вернуть nullptr, если этот файл уже открыт в readonly режиме.
		size_t Read(File* f, char* buff, size_t len) override;// Прочитать данные из файла. Возвращаемое значение - сколько реально байт удалось прочитать
		size_t Write(File* f, char* buff, size_t len) override;// Записать данные в файл. Возвращаемое значение - сколько реально байт удалось записать
		void Close(File* f) override; // Закрыть файл

		~VFS()
		{
			while (!activeFiles.empty())
			{
				delete activeFiles.front();
				activeFiles.pop_front();
			}
		}
	};
}