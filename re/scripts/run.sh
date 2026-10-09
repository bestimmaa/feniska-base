#!/bin/sh
# usage: run.sh <Script.java> args...   (headless, saves project changes)
export JAVA_HOME=$(brew --prefix openjdk@21)/libexec/openjdk.jdk/Contents/Home
S=$1; shift
exec $(brew --prefix ghidra)/libexec/support/analyzeHeadless /Users/hali/dev/feniska/re/proj feniska -process app0.elf -noanalysis -scriptPath /Users/hali/dev/feniska/re/scripts -postScript $S "$@" 2>&1 | grep -E "^(INFO|WARN|ERROR).*(DecompAt|Script|CREATED|WROTE|NO |fail)|CREATED|WROTE|NO |Exception" | grep -v "^INFO  Using" 