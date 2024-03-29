# Process this file with autoconf to produce a configure script
#-------------------------------------------------------------------
AC_PREREQ([2.60])
AC_INIT([IT++],[4.2],[http://sourceforge.net/projects/itpp/forums/forum/115656],[itpp])
AC_COPYRIGHT([
Copyright (C) 2006-2010  Adam Piatyszek <ediap@users.sourceforge.net>

This file is part of IT++ - a C++ library of mathematical, signal
processing, speech processing, and communications classes and functions.

IT++ is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any
later version.

IT++ is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along
with IT++.  If not, see <http://www.gnu.org/licenses/>.
])
AC_CONFIG_HEADER([itpp/config.h])
AC_CONFIG_SRCDIR([itpp/base/vec.cpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror])

# Shared library versioning
GENERIC_LIBRARY_VERSION="7:0:0"
#                        | | |
#                 +------+ | +---+
#                 |        |     |
#              current:revision:age
#                 |        |     |
#                 |        |     +- increment if interfaces have been added;
#                 |        |        set to zero if interfaces have been
#                 |        |        removed or changed
#                 |        +- increment if source code has changed;
#                 |           set to zero if current is incremented
#                 +- increment if interfaces have been added, removed
#                    or changed
AC_SUBST(GENERIC_LIBRARY_VERSION)

# Check for host and disable building a shared library in Windows
AC_CANONICAL_HOST
case $host_os in
  cygwin* | mingw*)
    AC_DISABLE_SHARED
    AC_ENABLE_STATIC
    if test "x$enable_shared" = xyes; then
      NO_UNDEFINED="-no-undefined"
      AC_SUBST(NO_UNDEFINED)
    fi
    ;;
  freebsd5* | freebsd6*)
    AC_ENABLE_SHARED
    AC_DISABLE_STATIC
    freebsd_broken_std_isnan=yes
    ;;
  darwin*)
    AC_ENABLE_SHARED
    AC_DISABLE_STATIC
    enable_explicit_deps=yes
    ;;
  *)
    AC_ENABLE_SHARED
    AC_DISABLE_STATIC
    ;;
esac

# Checks for programs
save_CXXFLAGS="$CXXFLAGS"
AC_PROG_CXX
AC_PROG_CXXCPP
CXXFLAGS="$save_CXXFLAGS"
AC_PROG_F77
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_SED

# See whether to include shared library dependencies (taken from gtk+)
AC_ARG_ENABLE(explicit-deps,
  [AS_HELP_STRING([--enable-explicit-deps=@<:@yes/no/auto@:>@],
                  [use explicit dependencies in .pc files [default=auto]])],,
  [enable_explicit_deps=auto])

AC_MSG_CHECKING([whether to use explicit library dependencies])
case $enable_explicit_deps in
  auto)
    if test "x$lt_cv_deplibs_check_method" != xpass_all || \
       test "x$enable_shared" = xno; then
      enable_explicit_deps=yes
    else
      enable_explicit_deps=no
    fi
  ;;
  yes|no)
  ;;
  *) AC_MSG_ERROR([Value given to --enable-explicit-deps must be one of yes, no or auto])
  ;;
esac
AC_MSG_RESULT($enable_explicit_deps)

# Set default language to C++
AC_LANG([C++])

# Check for debug switch
AC_ARG_ENABLE(debug,
              [AS_HELP_STRING([--enable-debug],
                              [build additional debugging library])])
test "x$enable_debug" != xyes && enable_debug=no
AM_CONDITIONAL([ENABLE_DEBUG], [test "x$enable_debug" = xyes])

# Check for exceptions switch
AC_ARG_ENABLE(exceptions,
              [AS_HELP_STRING([--enable-exceptions],
                              [enable exceptions handling mechanizm])],
              [AC_DEFINE([ITPP_EXCEPTIONS], [1],
                         [Define if you want exceptions handling])])
test "x$enable_exceptions" != xyes && enable_exceptions=no

# Check for html-doc switch
AC_ARG_ENABLE(html-doc,
              [AS_HELP_STRING([--disable-html-doc],
                              [do not generate HTML documentation])])
test "x$enable_html_doc" != xno && enable_html_doc=yes


# Check for optional modules
AC_ARG_ENABLE(comm,
              [AS_HELP_STRING([--disable-comm],
                              [do not include communications module])])
AC_ARG_ENABLE(fixed,
              [AS_HELP_STRING([--disable-fixed],
                              [do not include fixed-point module])])
AC_ARG_ENABLE(optim,
              [AS_HELP_STRING([--disable-optim],
                              [do not include optimization module])])
AC_ARG_ENABLE(protocol,
              [AS_HELP_STRING([--disable-protocol],
                              [do not include protocol module])])
AC_ARG_ENABLE(signal,
              [AS_HELP_STRING([--disable-signal],
                              [do not include signal processing module])])
AC_ARG_ENABLE(srccode,
              [AS_HELP_STRING([--disable-srccode],
                              [do not include source coding module])])

test "x$enable_fixed" != xno && enable_fixed=yes
test "x$enable_optim" != xno && enable_optim=yes
test "x$enable_protocol" != xno && enable_protocol=yes
test "x$enable_signal" != xno && enable_signal=yes
if test "x$enable_comm" != xno; then
  enable_signal=yes
  enable_comm=yes
fi
if test "x$enable_srccode" != xno; then
  enable_signal=yes
  enable_srccode=yes
fi

AM_CONDITIONAL([ENABLE_COMM], [test "x$enable_comm" = xyes])
AM_CONDITIONAL([ENABLE_FIXED], [test "x$enable_fixed" = xyes])
AM_CONDITIONAL([ENABLE_OPTIM], [test "x$enable_optim" = xyes])
AM_CONDITIONAL([ENABLE_PROTOCOL], [test "x$enable_protocol" = xyes])
AM_CONDITIONAL([ENABLE_SIGNAL], [test "x$enable_signal" = xyes])
AM_CONDITIONAL([ENABLE_SRCCODE], [test "x$enable_srccode" = xyes])


# Set optimised flags
if test "x$CXXFLAGS" = x; then
  CXXFLAGS_OPT="-DNDEBUG -O3"
  # Only for GCC compiler
  if test "x$GXX" = xyes; then
    CXXFLAGS_OPT="$CXXFLAGS_OPT -pipe"
  fi
else
  CXXFLAGS_OPT="$CXXFLAGS"
  CXXFLAGS=""
fi
# Remove redundant whitespace
CXXFLAGS_OPT="`echo \"$CXXFLAGS_OPT\" | $SED -e 's/  */ /g' -e 's/^ //' -e 's/ $//'`"
AC_SUBST(CXXFLAGS_OPT)


# Set debugging flags
if test "x$CXXFLAGS_DEBUG" = x; then
  # Only for GCC compiler
  if test "x$GXX" = xyes; then
    CXXFLAGS_DEBUG="-Wall -ggdb -pipe"
  else
    CXXFLAGS_DEBUG="-g"
  fi
fi
# Remove redundant whitespace
CXXFLAGS_DEBUG="`echo \"$CXXFLAGS_DEBUG\" | $SED -e 's/  */ /g' -e 's/^ //' -e 's/ $//'`"
AC_ARG_VAR(CXXFLAGS_DEBUG, [C++ compiler flags for the debugging library])


# Set debugging library name
if test "x$enable_debug" = xyes; then
  PACKAGE_DEBUG="$PACKAGE"_debug
else
  PACKAGE_DEBUG="$PACKAGE"
fi
AC_SUBST(PACKAGE_DEBUG)


# Checks for documentation build tools
AC_CHECK_PROG([doxygen_ok], [doxygen], [yes], [no])
AC_CHECK_PROG([latex_ok], [latex], [yes], [no])
AC_CHECK_PROG([dvips_ok], [dvips], [yes], [no])
AC_CHECK_PROG([gs_ok], [gs], [yes], [no])
if test "x$enable_html_doc" != xno; then
  test "x$doxygen_ok" != xyes && enable_html_doc=no
  test "x$latex_ok" != xyes && enable_html_doc=no
  test "x$dvips_ok" != xyes && enable_html_doc=no
  test "x$gs_ok" != xyes && enable_html_doc=no
  AC_PATH_PROG([PERL], [perl], [])
fi
AM_CONDITIONAL([HTML_DOC], [test "x$enable_html_doc" = xyes])


# Check for diff program used for tests
AC_PATH_PROGS(DIFF, [gdiff gnudiff diff], [no])
diff_ok=no
test "$DIFF" != no && diff_ok=yes
AM_CONDITIONAL([RUN_TESTS], [test "$DIFF" != no])


# Checks for header files
AC_HEADER_TIME
AC_CHECK_HEADERS([cmath \
  complex \
  ieeefp.h])


# Checks for global declarations
AC_CHECK_DECLS([signgam, isfinite, isinf, isnan],,,
[#if defined(HAVE_CMATH)
#  include <cmath>
#endif
#if defined(HAVE_IEEEFP_H)
#  include <ieeefp.h>
#endif
])

# Check for isfinite, isnan and isinf in std namespace
# except FreeBSD 5-6, where these functions are broken
if test "x$freebsd_broken_std_isnan" != xyes; then
  for f in std::isfinite std::isinf std::isnan; do
    AC_MSG_CHECKING([for $f])
    AC_LINK_IFELSE([AC_LANG_SOURCE(
[[#include <cmath>
int main() { return $f(0.7) ? 1 : 0; }
]])],
      [AC_MSG_RESULT([yes])
       if test $f = "std::isfinite"; then
         AC_DEFINE(HAVE_STD_ISFINITE, 1,
		   [Define to 1 if you have the `std::isfinite' function.])
       elif test $f = "std::isinf"; then
         AC_DEFINE(HAVE_STD_ISINF, 1,
                   [Define to 1 if you have the `std::isinf' function.])
       elif test $f = "std::isnan"; then
         AC_DEFINE(HAVE_STD_ISNAN, 1,
	           [Define to 1 if you have the `std::isnan' function.])
       fi],
      [AC_MSG_RESULT([no])])
  done
fi

# Checks for functions
AC_CHECK_FUNCS([asinh \
  acosh \
  atanh \
  cbrt \
  erf \
  erfc \
  expm1 \
  finite \
  fpclass \
  isfinite \
  isinf \
  isnan \
  lgamma \
  log1p \
  log2 \
  rint \
  tgamma])


# If we have a Fortran compiler
if test "x$F77" != x; then
  # Check for additional libs required for linking C/C++ with Fortran
  AC_F77_LIBRARY_LDFLAGS
  # Clean up -L/../.. paths from FLIBS
  MY_FLIBS="`echo \"$FLIBS\" | sed 's/-L[[^ ]]* //g'`"
  # Check for a Fortran name mangling scheme
  AC_F77_FUNC(sgemm)
  AC_F77_FUNC(dgemm)
  AC_F77_FUNC(cheev)
fi

# Checks for BLAS (ACML, MKL, ATLAS or NetLib's reference)
ACX_BLAS

# Checks for LAPACK (ACML, MKL, ATLAS or NetLib's reference)
ACX_LAPACK

# Checks for FFT (ACML, MKL or FFTW3)
ACX_FFT

# Set LIBS
test "x$BLAS_LIBS" != x && LIBS="$BLAS_LIBS $LIBS"
test "x$LAPACK_LIBS" != x && LIBS="$LAPACK_LIBS $LIBS"
test "x$FFT_LIBS" != x && LIBS="$FFT_LIBS $LIBS"

# Remove unnecesary white spaces from CPPFLAGS, LDFLAGS and LIBS
CPPFLAGS="`echo \"$CPPFLAGS\" | sed -e 's/  */ /g' -e 's/^ //' -e 's/ $//'`"
LDFLAGS="`echo \"$LDFLAGS\" | sed -e 's/  */ /g' -e 's/^ //' -e 's/ $//'`"
LIBS="`echo \"$LIBS\" | sed -e 's/  */ /g' -e 's/^ //' -e 's/ $//'`"
LDLIBS="`echo \"$LDFLAGS $LIBS\" | sed -e 's/^ //' -e 's/ $//'`"

if test $enable_explicit_deps = yes; then
  EXPLICIT_LIBS=" $LDLIBS" # the leading space is important here...
  PRIVATE_LIBS=""
else
  EXPLICIT_LIBS=""
  PRIVATE_LIBS=" $LDLIBS" # ... and also here!
fi
AC_SUBST(EXPLICIT_LIBS)
AC_SUBST(PRIVATE_LIBS)


# Set conditionals for runing test programs
AM_CONDITIONAL([RUN_LAPACK_TESTS], [test "x$acx_lapack_ok" = xyes])
AM_CONDITIONAL([RUN_FFT_TESTS], [test "x$acx_fft_ok" = xyes])


# config.h top and bottom
AH_TOP([
#ifndef CONFIG_H
#define CONFIG_H
])

AH_BOTTOM([
#if defined(HAVE_CMATH)
#  include <cmath>
#endif

#endif /* #ifndef CONFIG_H */
])


# Define configured files
AC_CONFIG_FILES([Makefile \
  itpp/Makefile \
  itpp/base/Makefile \
  itpp/base/algebra/Makefile \
  itpp/base/bessel/Makefile \
  itpp/base/math/Makefile \
  itpp/comm/Makefile \
  itpp/fixed/Makefile \
  itpp/optim/Makefile \
  itpp/protocol/Makefile \
  itpp/signal/Makefile \
  itpp/srccode/Makefile \
  itpp/stat/Makefile \
  doc/Makefile \
  doc/images/Makefile \
  doc/tutorial/Makefile \
  doc/tutorial/src/Makefile \
  doc/local/Makefile \
  doc/local/index.doc \
  doc/doxygen_html.cfg \
  extras/Makefile \
  tests/Makefile \
  win32/Makefile \
  win32/itpp_acml_tests/Makefile \
  win32/itpp_mkl_tests/Makefile \
  itpp.pc \
  itpp_debug.pc \
  itpp-config])

AC_OUTPUT

# Display configuration summary
AC_MSG_NOTICE([displaying configuration summary

------------------------------------------------------------------------------
$PACKAGE-$VERSION library configuration:
------------------------------------------------------------------------------

Directories:
  - prefix ......... : ${prefix}
  - exec_prefix .... : ${exec_prefix}
  - includedir ..... : ${includedir}
  - libdir ......... : ${libdir}
  - datarootdir .... : ${datarootdir}
  - docdir ......... : ${docdir}

Switches:
  - debug .......... : ${enable_debug}
  - exceptions ..... : ${enable_exceptions}
  - html-doc ....... : ${enable_html_doc}
  - shared ......... : ${enable_shared}
  - static ......... : ${enable_static}
  - explicit deps .. : ${enable_explicit_deps}

Documentation tools:
  - doxygen ........ : ${doxygen_ok}
  - latex .......... : ${latex_ok}
  - dvips .......... : ${dvips_ok}
  - ghostscript .... : ${gs_ok}

Testing tools:
  - diff ........... : ${diff_ok}

Optional modules:
  - comm ........... : ${enable_comm}
  - fixed .......... : ${enable_fixed}
  - optim .......... : ${enable_optim}
  - protocol ....... : ${enable_protocol}
  - signal ......... : ${enable_signal}
  - srccode ........ : ${enable_srccode}

External libs:
  - BLAS ........... : ${acx_blas_ok}
    * MKL .......... : ${blas_mkl_ok}
    * ACML ......... : ${blas_acml_ok}
    * ATLAS ........ : ${blas_atlas_ok}
  - LAPACK ......... : ${acx_lapack_ok}
  - FFT ............ : ${acx_fft_ok}
    * MKL .......... : ${fft_mkl_ok}
    * ACML ......... : ${fft_acml_ok}
    * FFTW ......... : ${fftw3_ok}

Compiler/linker flags/libs/defs:
  - CXX ............ : ${CXX}
  - F77 ............ : ${F77}
  - CXXFLAGS ....... : ${CXXFLAGS_OPT}
  - CXXFLAGS_DEBUG . : ${CXXFLAGS_DEBUG}
  - CPPFLAGS ....... : ${CPPFLAGS}
  - LDFLAGS ........ : ${LDFLAGS}
  - LIBS ........... : ${LIBS}

------------------------------------------------------------------------------
Now type 'make && make install' to build and install $PACKAGE-$VERSION library
------------------------------------------------------------------------------
])
