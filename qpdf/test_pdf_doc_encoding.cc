#include <qpdf/QPDFObjectHandle.hh>
#include <qpdf/QUtil.hh>
#include <cstdlib>
#include <cstring>
#include <iostream>

static char const* whoami = nullptr;

void
usage()
{
    std::cerr << "Usage: " << whoami << " infile" << std::endl;
    exit(2);
}

int
main(int argc, char* argv[])
{
    whoami = QUtil::getWhoami(argv[0]);


    if (argc != 2) {
        usage();
    }
    char const* infilename = argv[1];
    for (auto const& line: QUtil::read_lines_from_file(infilename)) {
        QPDFObjectHandle str = QPDFObjectHandle::newString(line);
        std::cout << str.getUTF8Value() << std::endl;
    }
    return 0;
}
