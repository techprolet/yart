#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1360937237/ppmwriter.o \
	${OBJECTDIR}/_ext/1360937237/pixel.o \
	${OBJECTDIR}/_ext/1360937237/color.o \
	${OBJECTDIR}/_ext/1360937237/matrix.o \
	${OBJECTDIR}/_ext/1360937237/main.o \
	${OBJECTDIR}/_ext/1360937237/point.o \
	${OBJECTDIR}/_ext/1360937237/vector.o \
	${OBJECTDIR}/_ext/1360937237/glutwindow.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lglut -lboost_thread -lGL

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/netbeans

dist/Release/GNU-Linux-x86/netbeans: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/netbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1360937237/ppmwriter.o: ../src/ppmwriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/ppmwriter.o ../src/ppmwriter.cpp

${OBJECTDIR}/_ext/1360937237/pixel.o: ../src/pixel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/pixel.o ../src/pixel.cpp

${OBJECTDIR}/_ext/1360937237/color.o: ../src/color.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/color.o ../src/color.cpp

${OBJECTDIR}/_ext/1360937237/matrix.o: ../src/matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/matrix.o ../src/matrix.cpp

${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.cpp

${OBJECTDIR}/_ext/1360937237/point.o: ../src/point.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/point.o ../src/point.cpp

${OBJECTDIR}/_ext/1360937237/vector.o: ../src/vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/vector.o ../src/vector.cpp

${OBJECTDIR}/_ext/1360937237/glutwindow.o: ../src/glutwindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1360937237
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1360937237/glutwindow.o ../src/glutwindow.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/netbeans

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
