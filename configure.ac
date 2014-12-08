# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([ccfinderx],[10.2.7.4],[radekg1000@gmail.com])

#Use tar-pax format to allow unlimited length file names
AM_INIT_AUTOMAKE([1.9 tar-pax foreign subdir-objects -Wall -Werror])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_CC_C_O
AC_PROG_AWK
AC_PROG_SED
AC_OPENMP
AM_PROG_AR

#Check for version of GCC
AX_CHECK_COMPILE_FLAG([-std=c++0x], [CXXFLAGS="$CXXFLAGS -std=c++0x -DSTD_CPP_0X"])

# Configure libtool
AC_ENABLE_SHARED
AC_DISABLE_STATIC
LT_INIT

AC_CONFIG_MACRO_DIR([m4])

# Checks for optional programs.

# Checks for libraries
AC_CHECK_LIB([gomp], [omp_get_num_threads])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([stddef.h stdlib.h string.h strings.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_STAT
AC_CHECK_FUNCS([rmdir strcasecmp strchr strdup strerror])


STD_INC_PATH="-I/usr/include -I/usr/local/include"
STD_LIB_PATH="-L/usr/local/lib"


dnl ---------------------------------------------------------------------------
dnl Check if boost library is available
dnl ---------------------------------------------------------------------------
BOOST_REQUIRE(1.53)
BOOST_SYSTEM
BOOST_THREADS

dnl ---------------------------------------------------------------------------
dnl Check if icu library is available
dnl ---------------------------------------------------------------------------
AC_CHECK_ICU([52],
    [AC_MSG_RESULT([yes])],
    [AC_MSG_ERROR([
		libicu must bee installed on your system.

		Please install libicu development package.])
    ]
)

# Check for java development kit
AX_JNI_INCLUDE_DIR
for JNI_INCLUDE_DIR in $JNI_INCLUDE_DIRS
do
    CPPFLAGS="$CPPFLAGS -I$JNI_INCLUDE_DIR"
done

# Check for python version
AX_PYTHON_DEVEL([>= '2.7.0'])

# Check for presence of ant to compile java packages
AC_CHECK_PROG(ANT, ant, ant, no)
if test "$ANT" = "no"; then
	AC_MSG_ERROR([ant is not installed.])
fi

#Check for presence of icu4j.jar
AC_CHECK_FILE(/usr/share/java/icu4j.jar,
    [ ],
    [AC_MSG_ERROR([
		icu4j.jar must bee installed on your system.

		Please install libicu4j-java development package.])
    ]
)

#Check for presence of swt.jar
AC_CHECK_FILE(/usr/share/java/swt.jar,
    [ ],
    [AC_MSG_ERROR([
		swt.jar must bee installed on your system.

		Please install libswt-gtk-3-java development package.])
    ]
)

#Check for presence of swt.jar
AC_CHECK_FILE(/usr/share/java/trove.jar,
    [ ],
    [AC_MSG_ERROR([
		trove.jar must bee installed on your system.

		Please install libtrove-java development package.])
    ]
)

#Check for presence of swt-cairo-gtk.so
AC_CHECK_FILE(/usr/lib/jni/libswt-cairo-gtk-3836.so,
    [ ],
    [AC_MSG_ERROR([
    libswt-cairo-gtk-3836.so  must bee installed on your system.

		Please install libswt-cairo-gtk-3-jni development package.])
    ]
)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
