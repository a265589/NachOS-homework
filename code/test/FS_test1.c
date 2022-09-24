#include "syscall.h"

int main(void)
{
	static const char test[] = "abcdefghijklmnopqrstuvwxyz12345\n";
	int size = 32*1024;
	int success = Create("/file1", size);
	OpenFileId fid;
	int i,j;
	if (success != 1)
		MSG("Failed on creating file");
	fid = Open("/file1");
	if (fid < 0)
		MSG("Failed on opening file");
	for(j= 0; j < 1024; j++)
	{
		for (i = 0; i < 32; ++i)
		{
		int count = Write(test + i, 1, fid);
		if (count != 1)
			MSG("Failed on writing file");
		}
	}

	success = Close(fid);
	if (success != 1)
		MSG("Failed on closing file");
	Halt();
}
