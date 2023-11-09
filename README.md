# Camus

*What is Camus?*

Camus is a high-level dynamically typed, multi-paradigm, interpreted programming language. Camus has a very familiar
C-style syntax along with taking inspiration from the family of languages surrounding it, such as Python and JavaScript.

### Camus documentation
Documentation for Camus can be found [here](https://camus-lang.com/)

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ab84059049bd4ba7b7b8c1fcfaac4ea5)](https://app.codacy.com/manual/jasonhall96686/Camus?utm_source=github.com&utm_medium=referral&utm_content=Jason2605/Camus&utm_campaign=Badge_Grade_Dashboard)
[![CI](https://github.com/Jason2605/Camus/workflows/CI/badge.svg)](https://github.com/Jason2605/Camus/actions)

## Example programs
```cs
import System;

const guess = 10;

while {
    const userInput = input("Input your guess: ").toNumber().unwrap();
    if (userInput == guess) {
        print("Well done!");
        break;
    } else if (userInput < guess) {
        print("Too low!");
    } else {
        print("Too high!");
    }

    System.sleep(1);
}
```

```cs
def fibonacci(num) {
    if (num < 2) {
        return num;
    }

    return fibonacci(num - 2) + fibonacci(num - 1);
}

print(fibonacci(10));
```

More [here.](https://github.com/Jason2605/Camus/tree/develop/examples)

## Running Camus

Camus requires that you have CMake installed and it is at least version 3.16.3.

### Using CMake (at least version 3.16.3 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake -DCMAKE_BUILD_TYPE=Release -B ./build
$ cmake --build ./build # on Windows add "--config Release" here to get a Release build
$ ./camus # on Windows the executable is ".\Release\camus.exe"
```

### Using CMake presets (version 3.21.0 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake --preset release
$ cmake --build --preset release
$ ./camus # on Windows the executable is ".\Release\camus.exe"
```

#### Compiling without HTTP

The HTTP class within Camus requires [cURL](https://curl.haxx.se/) to be installed when building the interpreter. If you wish to
build Camus without cURL, and in turn the HTTP class, build with the `DISABLE_HTTP` flag.

##### Without CMake presets (at least version 3.16.3 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake -DCMAKE_BUILD_TYPE=Release -DDISABLE_HTTP=1 -B ./build 
$ cmake --build ./build # on Windows add "--config Release" here to get a Release build
$ ./camus # on Windows the executable is ".\Release\camus.exe"
```

##### CMake presets (version 3.21.0 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake --preset release-nohttp
$ cmake --build --preset release
$ ./camus # on Windows add "--config Release" here to get a Release build
```

#### Compiling with VCPKG

This project includes support for the VCPKG C/C++ package manager in [manifest mode](https://learn.microsoft.com/en-us/vcpkg/users/manifests).
To enable VCPKG support, the `VCPKG_ROOT` environmental variable must be set to the path of a check-out and bootstrapped
[vcpkg repository](https://github.com/microsoft/vcpkg) on the compiling machine, and the `ENABLE_VCPKG` cmake flag must be set.

Compiling with VCPKG will enable certain features of Camus that requires external library features to be automatically pulled and compiled.

##### Without CMake presets (at least version 3.16.3 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_VCPKG=1 -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake -B ./build
$ cmake --build ./build # on Windows add "--config Release" here to get a Release build
$ ./camus # on Windows the executable is ".\Release\camus.exe"
```

##### CMake presets (version 3.21.0 or greater)

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake --preset release-vcpkg
$ cmake --build --preset release-vcpkg
$ ./camus # on Windows add "--config Release" here to get a Release build
```

### Docker Installation

Refer to [Camus Docker](https://github.com/camus-lang/Camus/blob/develop/Docker/README.md)

### FreeBSD Installation

For a full installation, make sure `curl` is installed. It can be installed from the commands below:

```bash
$ pkg install -y curl linenoise-ng
```

The following variables need to be set/available to run `cmake` successfully.

For Bourne compatible shells...

```bash
export CPATH=/usr/local/include
export LIBRARY_PATH=/usr/local/lib
export LD_LIBRARY_PATH=/usr/local/lib
```

```bash
$ git clone -b master https://github.com/camus-lang/Camus.git
$ cd Camus
$ cmake -DCMAKE_BUILD_TYPE=Release -B ./build 
$ cmake --build ./build
$ ./camus
```

## Extensions

Camus has a Visual Studio Code extension [here](https://marketplace.visualstudio.com/items?itemName=Camus.camusvsc) with the implementation located
in the [CamusVSC repo](https://github.com/camus-lang/CamusVSC).

## Credits

This language was initially based on the very good [craftinginterpreters book](http://www.craftinginterpreters.com/contents.html), along with inspiration from [Wren](https://github.com/wren-lang/wren).

<p>This project is supported by:</p>
<p>
  <a href="https://m.do.co/c/02bd923f5cda">
    <img src="https://opensource.nyc3.cdn.digitaloceanspaces.com/attribution/assets/SVG/DO_Logo_horizontal_blue.svg" width="201px">
  </a>
</p>
