# libzydis - A C library

The `libzydis` C library provides a fast and lightweight x86/x86-64 disassembler engine.

## Usage

To start using `libzydis` in your project, add the following [`depends`](https://build2.org/bpkg/doc/build2-package-manager-manual.xhtml#manifest-package-depends) value to your [`manifest`](https://build2.org/bpkg/doc/build2-package-manager-manual.xhtml#manifests), adjusting the version constraint as appropriate:

```
depends: libzydis ^1.4.0
```

Then import the library in your [`buildfile`](https://build2.org/build2/doc/build2-build-system-manual.xhtml#intro-lang):

```
import libs = libzydis%lib{zydis}
```

## Importable targets

This package provides the following importable targets:

```
lib{zydis}
```

### Importable targets description

* `zydis` - Fast and lightweight x86/x86-64 disassembler and code generation library.
