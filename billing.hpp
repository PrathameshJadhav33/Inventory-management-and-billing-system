#ifndef billing_CPP_INCLUDED
#define billing_CPP_INCLUDED
// ^^^ these are header guards, used to avoid multiple inclusions of the same header

// Declarations

// Notice that this does not define a global variable, it just says to the compiler "in some module there's a global named in this way, let me access it"
extern int AUselessGlobalVar;
int AddFive(int In);

#endif