# -*- coding: utf-8 -*-

import os
import sys
sys.path.append("scons")
import help

#=== CLI parameters ====================================================================================================================
def createVariables(vars) :
    vars.Add(BoolVariable("withrandomdevice", "installation with random device support", False))
    vars.Add(BoolVariable("withmpi", "installation with MPI support", False))
    vars.Add(BoolVariable("withmultilanguage", "installation with multilanguage support", False))
    vars.Add(BoolVariable("withsources", "installation with source like nntp or something else", False))
    vars.Add(BoolVariable("withfiles", "installation with file reading support for CSV & HDF", True))
    vars.Add(BoolVariable("withlogger", "use the interal logger of the framework", False))
    vars.Add(BoolVariable("withsymbolicmath", "compile for using symbolic math expression (needed by gradient descent)", False))

    vars.Add(BoolVariable("withdebug", "compile with debug information", False))
    vars.Add(BoolVariable("withoptimize", "compile with CPU optimization code", True))

    vars.Add(EnumVariable("winver", "value of the Windows version", "win7", allowed_values=("win7", "srv2008", "vista", "srv2003sp1", "xpsp2", "srv2003", "xp", "w2000")))

    vars.Add(EnumVariable("atlaslink", "value of the atlas threadding (multi = tatlas, single = satlas)", "multi", allowed_values=("multi", "single")))

    vars.Add(EnumVariable("cputype", "value of the cpu type [see: http://gcc.gnu.org/onlinedocs/gcc/i386-and-x86_002d64-Options.html]", "native", allowed_values=("native", "generic", "i386", "i486", "i586", "i686", "pentium-mmx", "pentiumpro", "pentium2", "pentium3", "pentium-m", "pentium4", "prescott", "nocona", "core2", "corei7", "corei7-avx", "core-avx-i", "atom", "k6", "k6-2", "athlon", "athlon-4", "k8", "k8-sse3", "amdfam10", "winchip-c6", "winchip2", "c3", "c3-2", "geode" )))
    
    vars.Add(EnumVariable("atlaspointerwidth", "pointer width for compiling ATLAS (empty = system default, 32 = 32 Bit, 64 = 64 Bit)", "", allowed_values=("", "32", "64")))
    vars.Add(BoolVariable("atlascputhrottle", "enable / disable detection of CPU throtteling", False))
    vars.Add(ListVariable("skipbuild", "skipping library builds", "", ["atlas", "boost", "hdf", "ginac", "json"]))
    vars.Add(BoolVariable("skipbuilderror", "ignore / skip build errors", False))
    

#=== clean targets =====================================================================================================================
def cleantarget(env) :
    files = []
    
    files.extend( help.getRekusivFiles(os.curdir, env["OBJSUFFIX"]) )
    files.extend( help.getRekusivFiles(os.curdir, env["SHOBJSUFFIX"]) )
    files.extend( help.getRekusivFiles(os.curdir, env["SHLIBSUFFIX"]) )
    files.extend( help.getRekusivFiles(os.curdir, ".po~") )
    files.extend( help.getRekusivFiles(os.curdir, ".mo") )
    files.extend( help.getRekusivFiles(os.curdir, ".jar") )
    files.extend( help.getRekusivFiles(os.curdir, ".stackdump") )
    files.extend( help.getRekusivFiles(os.curdir, ".core") )
    files.extend( help.getRekusivFiles(os.curdir, ".pyc") )
    
    # don't ad the current path, because scons run the directories until "/"
    files.extend( ["build", "documentation", "install"] )

    env.Clean("clean", files)

    
#=== licence ===========================================================================================================================
def showlicence() :
    print "############################################################################"
    print "# LGPL License                                                             #"
    print "#                                                                          #"
    print "# This file is part of the Machine Learning Framework.                     #"
    print "# Copyright (c) 2010, Philipp Kraus, <philipp.kraus@flashpixx.de>          #"
    print "# This program is free software: you can redistribute it and/or modify     #"
    print "# it under the terms of the GNU Lesser General Public License as           #"
    print "# published by the Free Software Foundation, either version 3 of the       #"
    print "# License, or (at your option) any later version.                          #"
    print "#                                                                          #"
    print "# This program is distributed in the hope that it will be useful,          #"
    print "# but WITHOUT ANY WARRANTY; without even the implied warranty of           #"
    print "# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #"
    print "# GNU Lesser General Public License for more details.                      #"
    print "#                                                                          #"
    print "# You should have received a copy of the GNU Lesser General Public License #"
    print "# along with this program. If not, see <http://www.gnu.org/licenses/>.     #"
    print "############################################################################"
    print "\n\n"


#=== create environment and compiling ==================================================================================================
showlicence()

vars = Variables()
createVariables(vars)

env = Environment(variables=vars)
Help(vars.GenerateHelpText(env))
# Scons < 2: env.BuildDir("build", ".", duplicate=0)
env.VariantDir("build", ".", duplicate=0)
if os.environ.has_key("PATH") :
    env["ENV"]["PATH"] = [env["ENV"]["PATH"], os.environ["PATH"]]
cleantarget(env)

# adding target scripts
platformconfig = env["PLATFORM"].lower()
if not(os.path.isfile(os.path.join("scons", "platform", platformconfig+".py"))) :
    raise ImportError("platform configuration script ["+platformconfig+"] not found")


env.SConscript( os.path.join("scons", "platform", platformconfig+".py"), exports="env" )
env.SConscript( os.path.join("scons", "target", "documentation.py"), exports="env")
env.SConscript( os.path.join("scons", "target", "cppexample.py"), exports="env")
env.SConscript( os.path.join("scons", "target", "librarybuild.py"), exports="env")
env.SConscript( os.path.join("scons", "target", "language.py"), exports="env")
