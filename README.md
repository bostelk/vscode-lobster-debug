# vscode-lobster-debug

vscode-lobster-debug is a [visual studio code](https://code.visualstudio.com/Docs/editor/debugging) (vscode) extension to enable debugging a program written in [lobster](https://strlen.com/lobster/). This project is a work in progress and is incomplete at this time.

## Overview

This project is composed of two subprojects: lobster-debug and vscode. 

* [lobster-debug](lobster-debug) is a "concrete" debugger written in C++ that enables a development tool to interop with a lobster virtual machine/runtime. 
* [vscode](vscode) is a vscode extention written in typescript that can start a lobster debug session and can communicate with a debugger over [DAP](https://microsoft.github.io/debug-adapter-protocol/overview).

There is no existing debugger, so the debugger and adapter have been fused together. Where in other laguages they're typically seperate from each other.

## Getting Started
To get started working on the extension you have a few tasks to complete first. Download and install the required software which includes: [Visual Studio 2022](https://visualstudio.microsoft.com/) and [Node v18](https://nodejs.org/en/download). Then perform the following:

1. Fetch additional Git repositories, generate project files, and install node modules.

```
git submodule update --init

cd cppdap.
cmake ..

cd ..

cd vscode
npm install
```

2. Open lobster-debug soltuion in Visual Studio and add a project dependency to cppdap. This step is not necessary if the ccpdap project GUID is static.
3. Build the lobster-debug soltuion.
4. Open vscode folder in VS Code.
5. Open the "Run and Debug" pannel and hit the Play button next to "Run Extension".
6. A new VS Code window will open. Open the "samplesWorkspace" folder.
7. Open a lobster program.
8. Switch the Play button from "Run file" to "Debug file" and press the button.
9. The lobster program will start paused.

You can now set a breakpoint in the source file and restart the program to debug it.

## Publishing

To publish the extension open a terminal and run:

```
cd vscode
npm run package
```

A new file "lobster-debug-0.0.0.vsix" is output which can published to a marketplace or installed into vscode.

