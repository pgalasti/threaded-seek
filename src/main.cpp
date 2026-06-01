#include "TSeekFile.h"

#include <iostream>


int main(int argc, char** argv) {

  TSeek::File testFile(".", TSeek::File::SearchParams{"Testing", true});

  return 0;
}
