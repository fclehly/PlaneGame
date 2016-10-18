##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PlaneGame
ConfigurationName      :=Debug
WorkspacePath          :=F:/code/CodeLite/WorkSpace
ProjectPath            :=F:/code/CodeLite/WorkSpace/PlaneGame
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=fwz
Date                   :=18/10/2016
CodeLitePath           :="E:/Program Files/CodeLite"
LinkerName             :=E:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=E:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PlaneGame.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/TDM-GCC-64/bin/ar.exe rcu
CXX      := E:/TDM-GCC-64/bin/g++.exe
CC       := E:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cursor.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameConsole.cpp$(ObjectSuffix) $(IntermediateDirectory)/Plane.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerPlane.cpp$(ObjectSuffix) $(IntermediateDirectory)/Flyer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyPlane.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp

$(IntermediateDirectory)/Cursor.cpp$(ObjectSuffix): Cursor.cpp $(IntermediateDirectory)/Cursor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/Cursor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cursor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cursor.cpp$(DependSuffix): Cursor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cursor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cursor.cpp$(DependSuffix) -MM Cursor.cpp

$(IntermediateDirectory)/Cursor.cpp$(PreprocessSuffix): Cursor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cursor.cpp$(PreprocessSuffix)Cursor.cpp

$(IntermediateDirectory)/GameConsole.cpp$(ObjectSuffix): GameConsole.cpp $(IntermediateDirectory)/GameConsole.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/GameConsole.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameConsole.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameConsole.cpp$(DependSuffix): GameConsole.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameConsole.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameConsole.cpp$(DependSuffix) -MM GameConsole.cpp

$(IntermediateDirectory)/GameConsole.cpp$(PreprocessSuffix): GameConsole.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameConsole.cpp$(PreprocessSuffix)GameConsole.cpp

$(IntermediateDirectory)/Plane.cpp$(ObjectSuffix): Plane.cpp $(IntermediateDirectory)/Plane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/Plane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Plane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Plane.cpp$(DependSuffix): Plane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Plane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Plane.cpp$(DependSuffix) -MM Plane.cpp

$(IntermediateDirectory)/Plane.cpp$(PreprocessSuffix): Plane.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Plane.cpp$(PreprocessSuffix)Plane.cpp

$(IntermediateDirectory)/PlayerPlane.cpp$(ObjectSuffix): PlayerPlane.cpp $(IntermediateDirectory)/PlayerPlane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/PlayerPlane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerPlane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerPlane.cpp$(DependSuffix): PlayerPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerPlane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerPlane.cpp$(DependSuffix) -MM PlayerPlane.cpp

$(IntermediateDirectory)/PlayerPlane.cpp$(PreprocessSuffix): PlayerPlane.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerPlane.cpp$(PreprocessSuffix)PlayerPlane.cpp

$(IntermediateDirectory)/Flyer.cpp$(ObjectSuffix): Flyer.cpp $(IntermediateDirectory)/Flyer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/Flyer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Flyer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Flyer.cpp$(DependSuffix): Flyer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Flyer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Flyer.cpp$(DependSuffix) -MM Flyer.cpp

$(IntermediateDirectory)/Flyer.cpp$(PreprocessSuffix): Flyer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Flyer.cpp$(PreprocessSuffix)Flyer.cpp

$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix): Bullet.cpp $(IntermediateDirectory)/Bullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bullet.cpp$(DependSuffix): Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bullet.cpp$(DependSuffix) -MM Bullet.cpp

$(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix): Bullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix)Bullet.cpp

$(IntermediateDirectory)/EnemyPlane.cpp$(ObjectSuffix): EnemyPlane.cpp $(IntermediateDirectory)/EnemyPlane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/code/CodeLite/WorkSpace/PlaneGame/EnemyPlane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyPlane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyPlane.cpp$(DependSuffix): EnemyPlane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyPlane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyPlane.cpp$(DependSuffix) -MM EnemyPlane.cpp

$(IntermediateDirectory)/EnemyPlane.cpp$(PreprocessSuffix): EnemyPlane.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyPlane.cpp$(PreprocessSuffix)EnemyPlane.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


