#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    inf.readToken("[a-z]{8}");
    inf.readEoln();
    inf.readEof();
    return 0;
}