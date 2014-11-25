bin_PROGRAMS = ccfx picosel easytorq
lib_LTLIBRARIES = libpicosel.la libccfinderx.la libeasytorq.la

ACLOCAL_AMFLAGS = -I m4


global_compiler_flags = \
    -DOS_UBUNTU \
    -DLITTLE_ENDIAN \
    -DCXLM_NO_ENC \
    -DCODE_CONVERSION_SUPPORT \
    -DWSTRING_CONVERSION_SUPPORT \
    -DREQUIRE_RNR \
    -Wall \
    -Wextra \
    -g -O0 \
    -fno-default-inline \
    -Wno-sign-compare \
    -Wno-unused-parameter \
    -Wno-unused-variable \
    -Wno-unused-value \
    -Wno-type-limits \
    -Wno-unused-but-set-variable \
    -DUNICODE \
    $(ICU_CXXFLAGS) \
    $(OPENMP_CFLAGS) \
    $(BOOST_CPPFLAGS) \
    $(PYTHON_CPPFLAGS) \
    $(ccfx_include_files_cppflags)

global_linker_flags = \
    $(PYTHON_LDFLAGS) $(BOOST_THREAD_LDFLAGS) $(BOOST_THREAD_LIBS) $(ICU_LIBS)

libraries_compiler_flags = \
    -fPIC

libraries_linker_flags = \
    -fPIC \
    -shared


#-------------------------------------------------------------------------

ccfx_SOURCES = \
    @top_srcdir@/ccfx/ccfx.cpp \
    @top_srcdir@/ccfx/ccfxcommon.cpp \
    @top_srcdir@/ccfx/ccfxcommon.h \
    @top_srcdir@/ccfx/ccfxconstants.cpp \
    @top_srcdir@/ccfx/ccfxconstants.h \
    @top_srcdir@/ccfx/clonedataassembler.h \
    @top_srcdir@/ccfx/filteringmain.h \
    @top_srcdir@/ccfx/findfilemain.h \
    @top_srcdir@/ccfx/metricmain.h \
    @top_srcdir@/ccfx/preprocessorinvoker.h \
    @top_srcdir@/ccfx/prettyprintermain.cpp \
    @top_srcdir@/ccfx/prettyprintmain.h \
    @top_srcdir@/ccfx/rawclonepairdata.cpp \
    @top_srcdir@/ccfx/rawclonepairdata.h \
    @top_srcdir@/ccfx/shapedfragmentcalculator.h \
    @top_srcdir@/ccfx/transformermain.h \
    @top_srcdir@/common/allocaarray.h \
    @top_srcdir@/common/base64encoder.cpp \
    @top_srcdir@/common/base64encoder.h \
    @top_srcdir@/common/bitcounttable.h \
    @top_srcdir@/common/bitvector.cpp \
    @top_srcdir@/common/bitvector.h \
    @top_srcdir@/common/datastructureonfile.h \
    @top_srcdir@/common/ffuncrenamer.h \
    @top_srcdir@/common/filestructwrapper.h \
    @top_srcdir@/common/hash_map_includer.h \
    @top_srcdir@/common/hash_set_includer.h \
    @top_srcdir@/common/specialstringmap.h \
    @top_srcdir@/common/unportable.cpp \
    @top_srcdir@/common/unportable.h \
    @top_srcdir@/common/utf8support.cpp \
    @top_srcdir@/common/utf8support.h \
    @top_srcdir@/newengine/clonedetector.h \
    @top_srcdir@/repdet/repdet.h \
    @top_srcdir@/threadqueue/threadqueue.h

ccfx_CPPFLAGS = \
    $(ccfx_include_files_cppflags) \
    $(global_compiler_flags)


#Specify compilation includes and the source directories
ccfx_include_files_cppflags = \
    -I@top_srcdir@/ccfx \
    -I@top_srcdir@/common \
    -I@top_srcdir@/newengine \
    -I@top_srcdir@/threadqueue

ccfx_LDFLAGS = $(global_linker_flags)
ccfx_LDADD = -lrt -lpthread -lboost_system -lboost_thread

#-------------------------------------------------------------------------


picosel_SOURCES = \
    @top_srcdir@/picosel/picosel.cpp \
    @top_srcdir@/common/unportable.cpp \
    @top_srcdir@/common/unportable.h

picosel_CPPFLAGS = \
    $(ccfx_include_files_cppflags) \
    $(global_compiler_flags)

#-------------------------------------------------------------------------


easytorq_SOURCES = \
    @top_srcdir@/torq/interpreter.cpp \
    @top_srcdir@/torq/interpreter.h \
    @top_srcdir@/torq/texttoken.cpp \
    @top_srcdir@/torq/texttoken.h \
    @top_srcdir@/torq/torq.cpp \
    @top_srcdir@/torq/torqcommon.cpp \
    @top_srcdir@/torq/torqcommon.h \
    @top_srcdir@/torq/easytorq/easytorq.cpp \
    @top_srcdir@/torq/easytorq/easytorq.h \
    @top_srcdir@/torq/pyeasytorq/pyeasytorq.cpp \
    @top_srcdir@/common/unportable.cpp \
    @top_srcdir@/common/unportable.h \
    @top_srcdir@/common/utf8support.cpp \
    @top_srcdir@/common/utf8support.h

easytorq_CPPFLAGS = \
    $(ccfx_include_files_cppflags) \
    $(global_compiler_flags) \
    -DBUILD_TORQEXE

easytorq_LDFLAGS = $(global_linker_flags)
easytorq_LDADD = -lrt -lpthread -lboost_system -lboost_thread

#-------------------------------------------------------------------------

libpicosel_la_SOURCES = \
    @top_srcdir@/picosel/picosel.cpp

libpicosel_la_CPPFLAGS = \
    $(global_compiler_flags) \
    $(libraries_compiler_flags)

libpicosel_la_LDFLAGS = \
    $(global_linker_flags) \
    $(libraries_linker_flags)

#-------------------------------------------------------------------------

libccfinderx_la_SOURCES = \
    @top_srcdir@/ccfx/CCFinderXLib/CCFinderXLib.cpp \
    @top_srcdir@/common/base64encoder.cpp \
    @top_srcdir@/common/base64encoder.h \
    @top_srcdir@/GemX/ccfinderx_CCFinderX.h \
    @top_srcdir@/ccfx/ccfxcommon.cpp \
    @top_srcdir@/ccfx/ccfxcommon.h \
    @top_srcdir@/ccfx/ccfxconstants.cpp \
    @top_srcdir@/ccfx/ccfxconstants.h \
    @top_srcdir@/common/ffuncrenamer.h \
    @top_srcdir@/common/ffuncrenamer.h \
    @top_srcdir@/common/unportable.cpp \
    @top_srcdir@/common/unportable.h \
    @top_srcdir@/common/utf8support.cpp \
    @top_srcdir@/common/utf8support.h

libccfinderx_la_CPPFLAGS = \
    $(global_compiler_flags) \
    $(libraries_compiler_flags)

libccfinderx_la_LDFLAGS = \
    $(global_linker_flags) \
    $(libraries_linker_flags)

#-------------------------------------------------------------------------

libeasytorq_la_SOURCES = \
    @top_srcdir@/ccfx/CCFinderXLib/CCFinderXLib.cpp \
    @top_srcdir@/common/argvbuilder.h \
    @top_srcdir@/common/base64encoder.cpp \
    @top_srcdir@/common/base64encoder.h \
    @top_srcdir@/GemX/ccfinderx_CCFinderX.h \
    @top_srcdir@/ccfx/ccfxcommon.cpp \
    @top_srcdir@/ccfx/ccfxcommon.h \
    @top_srcdir@/ccfx/ccfxconstants.cpp \
    @top_srcdir@/ccfx/ccfxconstants.h \
    @top_srcdir@/common/ffuncrenamer.h \
    @top_srcdir@/common/ffuncrenamer.h \
    @top_srcdir@/common/unportable.cpp \
    @top_srcdir@/common/unportable.h \
    @top_srcdir@/common/utf8support.cpp \
    @top_srcdir@/common/utf8support.h \
    @top_srcdir@/torq/interpreter.cpp \
    @top_srcdir@/torq/interpreter.h \
    @top_srcdir@/torq/specialchars.h \
    @top_srcdir@/torq/texttoken.cpp \
    @top_srcdir@/torq/texttoken.h \
    @top_srcdir@/torq/torqcommon.cpp \
    @top_srcdir@/torq/torqcommon.h \
    @top_srcdir@/torq/torqparser.h \
    @top_srcdir@/torq/torqtokenizer.h \
    @top_srcdir@/torq/easytorq/easytorq.cpp \
    @top_srcdir@/torq/easytorq/easytorq.h \
    @top_srcdir@/torq/pyeasytorq/pyeasytorq.cpp

libeasytorq_la_CPPFLAGS = \
    $(global_compiler_flags) \
    $(libraries_compiler_flags)

libeasytorq_la_LDFLAGS = \
    $(global_linker_flags) \
    $(libraries_linker_flags)

all : libeasytorq.la copy_libeasytorq_to_script_dir

copy_libeasytorq_to_script_dir :
	cp @top_srcdir@/build/.libs/libeasytorq.so @top_srcdir@/build/scripts


#
#Ant related files
ANT_BUILD_FILE = @top_srcdir@/GemX/build.xml

all : gemx

gemx :
	CURRENT_DIR=`pwd`
	cd @top_srcdir@/GemX
	ant -f $(ANT_BUILD_FILE)
	cd $(CURRENT_DIR)

clean-local : gemx-clean

gemx-clean :
	CURRENT_DIR=`pwd`
	cd @top_srcdir@/GemX
	pwd
	ant -f $(ANT_BUILD_FILE) clean
	cd $(CURRENT_DIR)
