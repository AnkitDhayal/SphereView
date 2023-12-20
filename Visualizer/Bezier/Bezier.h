


// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BEZIER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BEZIER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BEZIER_EXPORTS
#define BEZIER_API __declspec(dllexport)
#else
#define BEZIER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class BEZIER_API Bezier {
public:
	Bezier(void);
	// TODO: add your methods here.
};

extern BEZIER_API int nBezier;

BEZIER_API int fnBezier(void);
