/*
Copyright (c) 2010, Ryan Salsamendi
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the organization nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL RYAN SALSAMENDI BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "pdb.h"


static void PrintHelp()
{
	fprintf(stderr, "Usage: pdbp [options] [pdb file]\n");
	fprintf(stderr, "Options:\n\n");
	fprintf(stderr, "\t-l or --list-streams\t\tList the streams in the PDB file.\n");
	fprintf(stderr, "\t-d [stream_num] or --dump-stream [stream_num]\t\tDump the data in the stream to stdout.\n");
}


int main(int argc, char** argv)
{
	PDB_FILE* pdb;

	if (argc < 2)
	{
		PrintHelp();
		return 1;
	}

	pdb = PdbOpen(argv[argc - 1]);

	if (!pdb)
	{
		fprintf(stderr, "Failed to open pdb file %s\n", argv[argc - 1]);
		return 2;
	}

	fprintf(stderr, "Successfully opened pdb.\n");
	fprintf(stderr, "This file contains %d streams.\n", PdbGetStreamCount(pdb));

	PdbClose(pdb);

	return 0;
}
