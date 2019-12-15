#pragma once


#ifdef GIDEON_CS_DLL
#   ifdef GIDEON_CS_EXPORT
#       define GIDEON_CS_API __declspec(dllexport)
#   else
#       define GIDEON_CS_API __declspec(dllimport)
#   endif
#else
#   define GIDEON_CS_API
#endif // GIDEON_CS_DLL
