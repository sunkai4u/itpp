/* itpp/config.h.  Generated from config.h.in by configure.  */
/* itpp/config.h.in.  Generated from configure.ac by autoheader.  */


#ifndef CONFIG_H
#define CONFIG_H


/* Define to dummy `main' function (if any) required to link to the Fortran
   libraries. */
/* #undef F77_DUMMY_MAIN */

/* Define if F77 and FC dummy `main' functions are identical. */
/* #undef FC_DUMMY_MAIN_EQ_F77 */

/* Define to 1 if you have the `acosh' function. */
#define HAVE_ACOSH 1

/* Define to 1 if you have the `asinh' function. */
#define HAVE_ASINH 1

/* Define to 1 if you have the `atanh' function. */
#define HAVE_ATANH 1

/* Define if you have a BLAS library. */
#define HAVE_BLAS 1

/* Define if you have an ACML BLAS library. */
/* #undef HAVE_BLAS_ACML */

/* Define if you have an ATLAS BLAS library. */
/* #undef HAVE_BLAS_ATLAS */

/* Define if you have an MKL BLAS library. */
/* #undef HAVE_BLAS_MKL */

/* Define to 1 if you have the `cbrt' function. */
#define HAVE_CBRT 1

/* Define to 1 if you have the <cmath> header file. */
#define HAVE_CMATH 1

/* Define to 1 if you have the <complex> header file. */
#define HAVE_COMPLEX 1

/* Define to 1 if you have the declaration of `isfinite', and to 0 if you
   don't. */
#define HAVE_DECL_ISFINITE 0

/* Define to 1 if you have the declaration of `isinf', and to 0 if you don't.
   */
#define HAVE_DECL_ISINF 0

/* Define to 1 if you have the declaration of `isnan', and to 0 if you don't.
   */
#define HAVE_DECL_ISNAN 0

/* Define to 1 if you have the declaration of `signgam', and to 0 if you
   don't. */
#define HAVE_DECL_SIGNGAM 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `erf' function. */
#define HAVE_ERF 1

/* Define to 1 if you have the `erfc' function. */
#define HAVE_ERFC 1

/* Define to 1 if you have the `expm1' function. */
#define HAVE_EXPM1 1

/* Define if you have FFT library. */
/* #undef HAVE_FFT */

/* Define if you have FFTW3 library. */
/* #undef HAVE_FFTW3 */

/* Define if you have ACML FFT library. */
/* #undef HAVE_FFT_ACML */

/* Define if you have MKL FFT library. */
/* #undef HAVE_FFT_MKL */

/* Define to 1 if you have the `finite' function. */
#define HAVE_FINITE 1

/* Define to 1 if you have the `fpclass' function. */
/* #undef HAVE_FPCLASS */

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `isfinite' function. */
/* #undef HAVE_ISFINITE */

/* Define to 1 if you have the `isinf' function. */
#define HAVE_ISINF 1

/* Define to 1 if you have the `isnan' function. */
#define HAVE_ISNAN 1

/* Define if you have LAPACK library. */
#define HAVE_LAPACK 1

/* Define to 1 if you have the `lgamma' function. */
#define HAVE_LGAMMA 1

/* Define to 1 if you have the `log1p' function. */
#define HAVE_LOG1P 1

/* Define to 1 if you have the `log2' function. */
#define HAVE_LOG2 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `rint' function. */
#define HAVE_RINT 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `std::isfinite' function. */
#define HAVE_STD_ISFINITE 1

/* Define to 1 if you have the `std::isinf' function. */
#define HAVE_STD_ISINF 1

/* Define to 1 if you have the `std::isnan' function. */
#define HAVE_STD_ISNAN 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the `tgamma' function. */
#define HAVE_TGAMMA 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if you want exceptions handling */
/* #undef ITPP_EXCEPTIONS */

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "itpp"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://sourceforge.net/projects/itpp/forums/forum/115656"

/* Define to the full name of this package. */
#define PACKAGE_NAME "IT++"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "IT++ 4.2"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "itpp"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "4.2"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "4.2"


#if defined(HAVE_CMATH)
#  include <cmath>
#endif

#endif /* #ifndef CONFIG_H */

