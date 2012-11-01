#include<stdio.h>
#include<stlib.h>
#include<string>
#include<iostream>
#include<math.h>
#include<string.h>
#include<inttypes>
#include<ctype.h>
#include<algorithm>
#include<utility>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

int main()
{
	return 0;
}
