# libzydis - A C library

The `libzydis` C library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libzydis` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libzydis ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libzydis%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libzydis.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
