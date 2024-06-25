# Zydis - Fast and lightweight x86/x86-64 disassembler and code generation library.

This is a [`build2`](https://build2.org/) package repository for [`zydis`](https://github.com/zyantific/zydis)

This file contains setup instructions and other details that are more appropriate for development rather than consumption. If you want to use [`zydis`](https://github.com/zyantific/zydis) in your [`build2`](https://build2.org/)-based project, then instead see the accompanying [`PACKAGE-README.md`](libzydis/PACKAGE-README.md) file.

The development setup for [`zydis`](https://github.com/zyantific/zydis) uses the standard [`bdep`](https://build2.org/bdep/doc/bdep.xhtml)-based workflow. For example:

```
git clone .../zydis.git
cd zydis

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
